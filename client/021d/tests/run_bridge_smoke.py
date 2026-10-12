#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Run x86 native identity and real WinHTTP tests with a loopback test server."""
import argparse
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
import os
from pathlib import Path
import subprocess
import threading
import time
from urllib.parse import parse_qs


class Handler(BaseHTTPRequestHandler):
    def do_POST(self):
        length = int(self.headers.get("Content-Length", "0"))
        if self.path != "/v1/menu" or not 0 < length <= 4096:
            self.send_error(400)
            return
        fields = parse_qs(self.rfile.read(length).decode("ascii"))
        native = fields.get("op") in (["native"], ["native-enabled"], ["native-recovery"])
        expected = "SRP-Native-021d 12345678" if native else None
        # Return success only when the actual native HTTP header is correct.
        if self.headers.get("Authorization") != expected:
            self.send_error(403)
            return
        protocol = "SRP1-48" if fields.get("op") == ["native-enabled"] else None
        if fields.get("op") == ["native-recovery"]:
            protocol = "SRP1-48-R1"
        if self.headers.get("X-SRP-Match-Protocol") != protocol:
            self.send_error(409)
            return
        time.sleep(0.2)
        payload = json.dumps({"ok": True, "result": {"fixture": True}}).encode()
        self.send_response(200)
        self.send_header("Content-Length", str(len(payload)))
        self.end_headers()
        self.wfile.write(payload)

    def log_message(self, *_args):
        pass


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cc", default="i686-w64-mingw32-gcc")
    parser.add_argument("--library-dir", action="append", default=[], type=Path)
    parser.add_argument("--work", required=True, type=Path)
    parser.add_argument("--wine")
    parser.add_argument("--wine-prefix", type=Path)
    args = parser.parse_args()
    if os.name != "nt" and (not args.wine or not args.wine_prefix):
        parser.error("Non-Windows execution requires --wine and --wine-prefix")
    root = Path(__file__).resolve().parents[1]
    args.work.mkdir(parents=True, exist_ok=True)
    executables = []
    for name, library in [("native_session", "native_session"), ("http_bridge", "menu_http")]:
        output = args.work.resolve() / (name + "-smoke.exe")
        subprocess.run([args.cc, "-std=c11", "-O2", "-Wall", "-Wextra", "-Werror", "-static",
                        str(root / "tests" / (name + "_smoke.c")),
                        str(root / "dll" / (library + ".c")), "-o", str(output)]
                       + ["-L" + str(p) for p in args.library_dir]
                       + (["-lwinhttp"] if library == "menu_http" else []), check=True)
        executables.append(output)
    server = ThreadingHTTPServer(("127.0.0.1", 0), Handler)
    thread = threading.Thread(target=server.serve_forever, daemon=True)
    thread.start()
    env = os.environ.copy()
    env["SRP_MENU_API"] = f"http://127.0.0.1:{server.server_port}/v1/menu"
    if os.name != "nt":
        env.update(WINEPREFIX=str(args.wine_prefix.resolve()), WINEDEBUG="-all")
    try:
        for output in executables:
            command = [str(output)] if os.name == "nt" else [args.wine, str(output)]
            subprocess.run(command, env=env, check=True, timeout=60)
    finally:
        server.shutdown()
        server.server_close()
        thread.join()


if __name__ == "__main__":
    main()
