# SPDX-License-Identifier: GPL-3.0-or-later
import concurrent.futures
import hashlib
import json
import os
from pathlib import Path
import sys
import tempfile
import time
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import install_client as installer
import launch_client as launcher


class LaunchProfile(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="srp launcher ")
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.game = self.root / "game"
        self.game.mkdir()
        self.profile = self.root / "profile.json"
        self.config = {"version": 1, "game": "game", "service_port": 19031,
                       "runtime": {"kind": "wine", "executable": sys.executable,
                                   "server": sys.executable, "prefix": "prefix",
                                   "desktop": {"name": "SRP", "width": 1280, "height": 720},
                                   "vram_floor": True}}
        self.save()

    def save(self):
        self.profile.write_text(json.dumps(self.config))

    def installed(self):
        originals = {name: hashlib.sha256(name.encode()).hexdigest() if value else None
                     for name, value in installer.ORIGINALS.items()}
        self.addCleanup(patch.stopall)
        patch.dict(installer.ORIGINALS, originals, clear=True).start()
        package = self.root / "package"
        manifest = {"schema": "srp-client-package-v1", "target": "retail-0.21d-build-2010", "files": {}}
        for name, before in originals.items():
            target = self.game / name
            target.parent.mkdir(parents=True, exist_ok=True)
            if before:
                target.write_bytes(name.encode())
            replacement = package / "payload" / name
            replacement.parent.mkdir(parents=True, exist_ok=True)
            replacement.write_bytes(b"patched:" + name.encode())
            manifest["files"][name] = {"before": before, "after": installer.sha256(replacement)}
        (package / "package.json").write_text(json.dumps(manifest))
        installer.install(self.game, package)

    def test_paired_endpoints_and_only_explicit_srp_flags(self):
        result = launcher.plan(self.profile, environ={"DISPLAY": ":99", "SRP_MENU_PREVIEW": "1",
             "SRP_MATCH_CAPTURE": "1", "SRP_MATCH_ROUNDTRIP": "1", "SRP_MATCH_HASH_STEP": "1",
             "SRP_MENU_API": "wrong", "srp_unknown": "1"}, platform="posix")
        self.assertEqual(result["login"], "127.0.0.1:19031")
        self.assertEqual(result["menu"], "http://127.0.0.1:19035/v1/menu")
        self.assertEqual(result["env"], {"DISPLAY": ":99", "SRP_MENU_API": result["menu"],
            "SRP_MATCH_PROTOCOL": "1", "SRP_WINE_VRAM_FLOOR": "1", "WINEPREFIX": str(self.root / "prefix")})
        self.assertIn(str(self.game / "binaries/x86/survarium.exe"), result["command"])
        self.assertEqual(result["cwd"], self.game / "binaries/x86")
        self.assertIn("/desktop=SRP,1280x720", result["command"])
        self.config["hash_step_50ms"] = True
        self.save()
        self.assertEqual(launcher.plan(self.profile)["env"]["SRP_MATCH_HASH_STEP"], "1")

    def test_native_profile_has_no_wine_settings(self):
        self.config["runtime"] = {"kind": "native"}
        self.save()
        result = launcher.plan(self.profile, environ={}, platform="nt")
        self.assertEqual(result["command"][0], str(self.game / "binaries/x86/survarium.exe"))
        self.assertIsNone(result["server_command"])
        self.assertIsNone(result["prefix"])
        self.assertEqual(set(result["overrides"]), {"SRP_MATCH_PROTOCOL", "SRP_MENU_API"})
        with self.assertRaisesRegex(ValueError, "requires Windows"):
            launcher.plan(self.profile, platform="posix")

    def test_invalid_profiles_are_rejected_before_launch(self):
        original = json.loads(self.profile.read_text())
        for key, value in (("version", True), ("service_port", True), ("service_port", 65531),
                           ("service_port", 80), ("language", "english -client=other"),
                           ("hash_step_50ms", "false"), ("menu_url", "http://elsewhere")):
            with self.subTest(key=key, value=value):
                self.config = dict(original, **{key: value})
                self.save()
                with self.assertRaises(ValueError):
                    launcher.plan(self.profile)
        self.config = original
        self.config["runtime"]["prefix"] = "game/prefix"
        self.save()
        with self.assertRaisesRegex(ValueError, "separate"):
            launcher.plan(self.profile)

    def test_check_verifies_installation_without_starting_runtime(self):
        self.installed()
        with patch.object(launcher.subprocess, "Popen", side_effect=AssertionError("must not start")):
            self.assertEqual(launcher.launch(self.profile, check=True), 0)
        self.assertFalse((self.root / "prefix").exists())
        (self.game / "resources.db").write_bytes(b"changed outside installer")
        with self.assertRaisesRegex(ValueError, "wrong build"):
            launcher.launch(self.profile, check=True)

    def test_incomplete_install_is_not_launched(self):
        self.installed()
        state = self.game / installer.STATE
        journal = installer.read_journal(state)
        journal["phase"] = "installing"
        installer.write_journal(state, journal)
        with self.assertRaisesRegex(ValueError, "incomplete"):
            launcher.launch(self.profile, check=True)

    @unittest.skipIf(os.name == "nt", "Unix process supervisor test")
    def test_early_wine_exit_keeps_both_locks_until_server_finishes(self):
        self.installed()
        wine, server = self.root / "wine runner", self.root / "wine server"
        wine.write_text(f"#!{sys.executable}\nimport json,os,sys\nfrom pathlib import Path\n"
                        "Path(os.environ['WINEPREFIX'],'arguments.json').write_text(json.dumps(sys.argv[1:]))\n")
        server.write_text(f"#!{sys.executable}\nimport os,time\nfrom pathlib import Path\n"
                          "p=Path(os.environ['WINEPREFIX'])\n(p/'waiting').touch()\n"
                          "end=time.monotonic()+10\n"
                          "while not (p/'release').exists() and time.monotonic()<end: time.sleep(.05)\n")
        wine.chmod(0o700)
        server.chmod(0o700)
        self.config["runtime"].update(executable=str(wine), server=str(server))
        self.save()
        prefix = self.root / "prefix"
        with concurrent.futures.ThreadPoolExecutor(max_workers=1) as pool:
            future = pool.submit(launcher.launch, self.profile)
            try:
                deadline = time.monotonic() + 10
                while not (prefix / "waiting").exists():
                    if future.done():
                        future.result()
                        self.fail("launcher exited before waiting for the Wine server")
                    if time.monotonic() > deadline:
                        self.fail("Wine supervisor did not start")
                    time.sleep(.05)
                for directory in (self.game, prefix):
                    with self.assertRaisesRegex(ValueError, "Another installer"):
                        with installer.installation_lock(directory):
                            pass
                self.assertFalse(future.done())
            finally:
                prefix.mkdir(exist_ok=True)
                (prefix / "release").touch()
            self.assertEqual(future.result(timeout=10), 0)
        args = json.loads((prefix / "arguments.json").read_text())
        self.assertIn(str(self.game / "binaries/x86/survarium.exe"), args)
        self.assertIn("-client=127.0.0.1:19031", args)
        with installer.installation_lock(self.game):
            installer.verify_installation(self.game)


if __name__ == "__main__":
    unittest.main()
