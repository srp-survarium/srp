#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Static instructions + private persistence API; Python 3.11+, no dependencies."""
import argparse
import hmac
import json
import logging
import os
import sqlite3
import sys
import threading
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import urlsplit

from store import Conflict, Invalid, Missing, Store, encoded

STATIC = Path(__file__).resolve().parent / 'static'
LIMIT = 256 * 1024


class Server(ThreadingHTTPServer):
    daemon_threads = True
    block_on_close = False

    def __init__(self, address, store, token=None):
        if token is not None and (len(token) < 32 or not token.isascii() or not token.isprintable()):
            raise Invalid('SRP_ACCOUNT_TOKEN must contain at least 32 printable ASCII characters')
        self.store = store
        self.token = token
        self.slots = threading.BoundedSemaphore(32)
        super().__init__(address, Handler)

    def process_request(self, request, address):
        if not self.slots.acquire(blocking=False):
            self.shutdown_request(request)
            return
        try:
            super().process_request(request, address)
        except BaseException:
            self.slots.release()
            raise

    def process_request_thread(self, request, address):
        try:
            request.settimeout(10)
            super().process_request_thread(request, address)
        finally:
            self.slots.release()


class Handler(BaseHTTPRequestHandler):
    server_version = 'SRP'
    sys_version = ''

    def log_message(self, message, *args):
        # Do not log payloads, credentials, account IDs or arbitrary URL text.
        logging.info('http request completed')

    def reply(self, status, body, kind='application/json; charset=utf-8', cache=False):
        if not isinstance(body, bytes):
            body = encoded(body).encode()
        self.send_response(status)
        self.send_header('Content-Type', kind)
        self.send_header('Content-Length', str(len(body)))
        self.send_header('Cache-Control', 'public, max-age=300' if cache else 'no-store')
        self.send_header('X-Content-Type-Options', 'nosniff')
        self.send_header('Referrer-Policy', 'no-referrer')
        self.send_header('Content-Security-Policy', "default-src 'none'; style-src 'self'; img-src 'self'; base-uri 'none'; frame-ancestors 'none'; form-action 'none'")
        self.send_header('Connection', 'close')
        self.end_headers()
        self.close_connection = True
        if self.command != 'HEAD':
            self.wfile.write(body)

    def authorized(self):
        token = self.server.token
        authorization = self.headers.get('Authorization', '')
        if token is None or not hmac.compare_digest(authorization.encode(), ('Bearer ' + token).encode()):
            self.reply(401, {'error': 'server credential required'})
            return False
        return True

    def do_HEAD(self):
        self.do_GET()

    def do_GET(self):
        path = urlsplit(self.path).path
        files = {'/': ('index.html', 'text/html; charset=utf-8'),
                 '/index.html': ('index.html', 'text/html; charset=utf-8'),
                 '/style.css': ('style.css', 'text/css; charset=utf-8'),
                 '/favicon.svg': ('favicon.svg', 'image/svg+xml')}
        if path in files:
            file, kind = files[path]
            self.reply(200, (STATIC / file).read_bytes(), kind, cache=True)
        elif path == '/healthz':
            try:
                with self.server.store.connection() as db:
                    db.execute('SELECT 1 FROM accounts LIMIT 1').fetchone()
                self.reply(200, {'status': 'ok'})
            except sqlite3.Error:
                self.reply(503, {'error': 'database unavailable'})
        elif path.startswith('/api/v1/'):
            if not self.authorized():
                return
            try:
                if path == '/api/v1/catalog':
                    self.reply(200, {'catalog': self.server.store.catalog()})
                elif path.startswith('/api/v1/accounts/') and len(path.split('/')) == 5:
                    self.reply(200, self.server.store.account(path.rsplit('/', 1)[1]))
                else:
                    self.reply(404, {'error': 'not found'})
            except Missing as error:
                self.reply(404, {'error': str(error)})
            except sqlite3.Error:
                self.reply(503, {'error': 'database unavailable'})
        else:
            self.reply(404, {'error': 'not found'})

    def do_POST(self):
        if urlsplit(self.path).path != '/api/v1/commands':
            self.reply(404, {'error': 'not found'})
            return
        if not self.authorized():
            return
        try:
            if self.headers.get('Transfer-Encoding') is not None:
                raise Invalid('chunked requests are not supported')
            lengths = self.headers.get_all('Content-Length', [])
            if len(lengths) != 1 or not lengths[0].isascii() or not lengths[0].isdecimal():
                raise Invalid('one Content-Length header is required')
            length = int(lengths[0])
            if not 0 < length <= LIMIT:
                self.reply(413, {'error': 'request body must be 1–262144 bytes'})
                return
            if self.headers.get_content_type() != 'application/json':
                self.reply(415, {'error': 'application/json required'})
                return
            raw = self.rfile.read(length)
            if len(raw) != length:
                raise Invalid('incomplete request')
            data = json.loads(raw, parse_constant=lambda _: (_ for _ in ()).throw(Invalid('non-finite number')))
            self.reply(200, self.server.store.command(data))
        except Missing as error:
            self.reply(404, {'error': str(error)})
        except Conflict as error:
            self.reply(409, {'error': str(error)})
        except (Invalid, ValueError, TypeError, UnicodeError, RecursionError) as error:
            self.reply(400, {'error': 'invalid command' if not isinstance(error, Invalid) else str(error)})
        except (TimeoutError, ConnectionError):
            self.close_connection = True
        except sqlite3.Error:
            logging.exception('database operation failed')
            self.reply(503, {'error': 'database unavailable'})


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=['init', 'serve', 'command', 'account', 'backup'])
    parser.add_argument('--db', default=str(Path('target/accounts.sqlite3')))
    parser.add_argument('--host', default='127.0.0.1')
    parser.add_argument('--port', type=int, default=8080)
    parser.add_argument('--account-id')
    parser.add_argument('--output', help='backup destination')
    args = parser.parse_args()
    store = Store(args.db)
    try:
        store.initialize()
        if args.command == 'init':
            print(f'Initialized {args.db}')
        elif args.command == 'command':
            raw = sys.stdin.buffer.read(LIMIT + 1)
            if len(raw) > LIMIT:
                raise Invalid('command exceeds 256 KiB')
            print(encoded(store.command(json.loads(raw))))
        elif args.command == 'account':
            if not args.account_id:
                raise Invalid('--account-id required')
            print(json.dumps(store.account(args.account_id), indent=2))
        elif args.command == 'backup':
            if not args.output:
                raise Invalid('--output required')
            store.backup(args.output)
            print(f'Backup saved to {args.output}')
        else:
            logging.basicConfig(level=logging.INFO, format='%(levelname)s %(message)s')
            server = Server((args.host, args.port), store, os.getenv('SRP_ACCOUNT_TOKEN'))
            print(f'SRP website: http://{args.host}:{server.server_port}', flush=True)
            print('Private API enabled' if server.token else 'Private API disabled (use CLI or set SRP_ACCOUNT_TOKEN)', flush=True)
            try:
                server.serve_forever()
            except KeyboardInterrupt:
                pass
            finally:
                server.server_close()
    except (Invalid, ValueError, sqlite3.Error, OSError) as error:
        parser.exit(1, f'error: {error}\n')


if __name__ == '__main__':
    main()
