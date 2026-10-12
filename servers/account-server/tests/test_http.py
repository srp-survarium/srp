# SPDX-License-Identifier: GPL-3.0-or-later
import http.client
import json
from pathlib import Path
import sys
import tempfile
import threading
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from server import Server
from store import Store


class HttpTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp = tempfile.TemporaryDirectory()
        cls.store = Store(Path(cls.temp.name) / 'http.sqlite3')
        cls.store.initialize()
        cls.token = 'test-' + 'x'*40
        cls.server = Server(('127.0.0.1', 0), cls.store, cls.token)
        cls.thread = threading.Thread(target=cls.server.serve_forever, daemon=True)
        cls.thread.start()

    @classmethod
    def tearDownClass(cls):
        cls.server.shutdown()
        cls.server.server_close()
        cls.thread.join()
        cls.temp.cleanup()

    def request(self, method, path, body=None, auth=False, headers=None):
        conn = http.client.HTTPConnection('127.0.0.1', self.server.server_port, timeout=3)
        actual = {'Authorization': 'Bearer '+self.token} if auth else {}
        actual.update(headers or {})
        try:
            conn.request(method, path, body=body, headers=actual)
            response = conn.getresponse()
            return response.status, dict(response.getheaders()), response.read()
        finally:
            conn.close()

    def test_public_site_is_static_and_private_data_requires_authentication(self):
        status, headers, page = self.request('GET', '/')
        self.assertEqual(status, 200)
        self.assertIn(b'https://discord.gg/hDp78JMC4a', page)
        self.assertNotIn(b'<script', page)
        self.assertIn('frame-ancestors', headers['Content-Security-Policy'])
        self.assertEqual(self.request('GET', '/api/v1/catalog')[0], 401)
        self.assertEqual(self.request('GET', '/api/v1/catalog', auth=True)[0], 200)
        self.assertEqual(self.request('GET', '/../store.py')[0], 404)
        self.assertEqual(self.request('GET', '/accounts.sqlite3')[0], 404)

    def test_head_and_health(self):
        status, headers, body = self.request('HEAD', '/')
        self.assertEqual(status, 200)
        self.assertEqual(body, b'')
        self.assertGreater(int(headers['Content-Length']), 0)
        self.assertEqual(self.request('GET', '/healthz')[0], 200)

    def test_write_requires_token_and_json(self):
        body = json.dumps({'request_id': 'http-account', 'action': 'create_account', 'username': 'http_player'})
        self.assertEqual(self.request('POST', '/api/v1/commands', body)[0], 401)
        self.assertEqual(self.request('POST', '/api/v1/commands', body, True)[0], 415)
        status, _, data = self.request('POST', '/api/v1/commands', body, True, {'Content-Type': 'application/json'})
        self.assertEqual(status, 200)
        account = json.loads(data)['account_id']
        self.assertEqual(self.request('GET', '/api/v1/accounts/'+account)[0], 401)
        self.assertEqual(self.request('GET', '/api/v1/accounts/'+account, auth=True)[0], 200)

    def test_bad_json_and_size_limit(self):
        for payload in ('{', '[]', 'null', '{"value": NaN}'):
            self.assertEqual(self.request('POST', '/api/v1/commands', payload, True,
                                         {'Content-Type': 'application/json'})[0], 400)
        self.assertEqual(self.request('POST', '/api/v1/commands', b'', True,
                                     {'Content-Type': 'application/json', 'Content-Length': '262145'})[0], 413)


if __name__ == '__main__':
    unittest.main()
