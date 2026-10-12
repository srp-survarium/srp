#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Launch a verified SRP 0.21d installation using one local service profile."""
import argparse
from contextlib import ExitStack
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys

from install_client import check_closed, installation_lock, verify_installation


def fields(value, required, optional, label):
    if not isinstance(value, dict) or not required <= value.keys() or value.keys() - required - optional:
        raise ValueError(f"Invalid {label} fields")
    return value


def text(value, label):
    if not isinstance(value, str) or not value or "\0" in value:
        raise ValueError(f"Invalid {label}")
    return value


def boolean(value, label):
    if type(value) is not bool:
        raise ValueError(f"{label} must be true or false")
    return value


def config_path(value, parent, label):
    path = Path(text(value, label))
    return (parent / path).resolve() if not path.is_absolute() else path.resolve()


def executable(value, parent):
    value = text(value, "runtime executable")
    if "/" in value or "\\" in value:
        path = config_path(value, parent, "runtime executable")
    else:
        found = shutil.which(value)
        if not found:
            raise ValueError(f"Runtime executable not found: {value}")
        path = Path(found)
    if not path.is_file() or (os.name != "nt" and not os.access(path, os.X_OK)):
        raise ValueError(f"Runtime executable is unavailable: {path}")
    return str(path)


def plan(profile_path, environ=None, platform=None):
    profile_path = profile_path.resolve(strict=True)
    parent = profile_path.parent
    config = fields(json.loads(profile_path.read_text(encoding="utf-8")),
                    {"version", "game", "service_port", "runtime"},
                    {"language", "hash_step_50ms"}, "profile")
    if type(config["version"]) is not int or config["version"] != 1:
        raise ValueError("Unsupported profile version")
    port = config["service_port"]
    if type(port) is not int or not 1024 <= port <= 65530:
        raise ValueError("service_port must leave room for all five local services")
    language = text(config.get("language", "english"), "language")
    if not re.fullmatch("[a-z][a-z0-9_-]{0,31}", language):
        raise ValueError("Invalid localization name")
    game = config_path(config["game"], parent, "game directory")
    if not game.is_dir():
        raise ValueError(f"Game directory does not exist: {game}")
    runtime = fields(config["runtime"], {"kind"},
                     {"executable", "server", "prefix", "desktop", "vram_floor"}, "runtime")
    native = (os.name == "nt") if platform is None else platform == "nt"
    # Diagnostic environment from another development shell must not silently
    # change a normal launch into preview, snapshot capture or round-trip mode.
    env = {key: value for key, value in (os.environ if environ is None else environ).items()
           if not key.upper().startswith("SRP_")}
    overrides = {"SRP_MENU_API": f"http://127.0.0.1:{port + 4}/v1/menu", "SRP_MATCH_PROTOCOL": "1"}
    if boolean(config.get("hash_step_50ms", False), "hash_step_50ms"):
        overrides["SRP_MATCH_HASH_STEP"] = "1"
    arguments = ["-no_splash_screen", f"-localization={language}", f"-client=127.0.0.1:{port}",
                 "-minimum_resources_memory_size=768"]
    game_exe = game / "binaries/x86/survarium.exe"
    prefix = None
    server_command = None
    if runtime["kind"] == "native":
        if set(runtime) != {"kind"} or not native:
            raise ValueError("Native runtime requires Windows and no Wine settings")
        command = [str(game_exe), *arguments]
    elif runtime["kind"] == "wine":
        if native or not {"executable", "prefix"} <= runtime.keys():
            raise ValueError("Wine requires executable and dedicated prefix on a non-Windows host")
        wine = executable(runtime["executable"], parent)
        server = executable(runtime.get("server", str(Path(wine).with_name("wineserver"))), parent)
        prefix = config_path(runtime["prefix"], parent, "Wine prefix")
        if prefix == game or game in prefix.parents or prefix in game.parents:
            raise ValueError("Wine prefix must be separate from the game directory")
        overrides["WINEPREFIX"] = str(prefix)
        if boolean(runtime.get("vram_floor", False), "vram_floor"):
            overrides["SRP_WINE_VRAM_FLOOR"] = "1"
        desktop = runtime.get("desktop")
        if desktop is not None:
            fields(desktop, {"name", "width", "height"}, set(), "desktop")
            name = text(desktop["name"], "desktop name")
            if not re.fullmatch("[A-Za-z][A-Za-z0-9_-]{0,31}", name):
                raise ValueError("Invalid Wine desktop name")
            width, height = desktop["width"], desktop["height"]
            if type(width) is not int or type(height) is not int or not 800 <= width <= 7680 or not 600 <= height <= 4320:
                raise ValueError("Unsupported desktop dimensions")
            command = [wine, "explorer", f"/desktop={name},{width}x{height}",
                       "start.exe", "/wait", "/unix", str(game_exe), *arguments]
        else:
            command = [wine, str(game_exe), *arguments]
        # explorer may hand work to an existing Wine process and return early.
        # The dedicated prefix remains locked until its server has no clients.
        server_command = [server, "-w"]
    else:
        raise ValueError("runtime.kind must be native or wine")
    env.update(overrides)
    return {"game": game, "prefix": prefix, "command": command, "server_command": server_command,
            "cwd": game_exe.parent, "env": env, "overrides": overrides,
            "login": f"127.0.0.1:{port}", "menu": overrides["SRP_MENU_API"]}


def wait(process):
    while True:
        try:
            return process.wait()
        except KeyboardInterrupt:
            print("Close the game to finish; the installation remains locked.", file=sys.stderr, flush=True)


def launch(profile_path, check=False):
    launch_plan = plan(profile_path)
    with ExitStack() as stack:
        stack.enter_context(installation_lock(launch_plan["game"]))
        print("Verifying installed client files and recovery backups...", flush=True)
        verify_installation(launch_plan["game"])
        if check:
            print(json.dumps({key: str(launch_plan[key]) for key in ("game", "cwd", "login", "menu")}
                             | {"command": launch_plan["command"], "environment": launch_plan["overrides"]}, indent=2))
            return 0
        check_closed(launch_plan["game"])
        if launch_plan["prefix"]:
            launch_plan["prefix"].mkdir(parents=True, exist_ok=True)
            stack.enter_context(installation_lock(launch_plan["prefix"]))
        print(f"Launching SRP 0.21d; login {launch_plan['login']}; menu {launch_plan['menu']}", flush=True)
        process = subprocess.Popen(launch_plan["command"], cwd=launch_plan["cwd"], env=launch_plan["env"])
        try:
            result = wait(process)
        finally:
            if launch_plan["server_command"]:
                # Keep the lock even if the explorer/start wrapper exits before
                # the game. No other applications should share this prefix.
                wait(subprocess.Popen(launch_plan["server_command"], env=launch_plan["env"]))
        return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("profile", type=Path)
    parser.add_argument("--check", action="store_true", help="verify installation and show launch settings without starting it")
    args = parser.parse_args()
    try:
        return launch(args.profile, args.check)
    except (OSError, ValueError, KeyError, TypeError) as error:
        parser.exit(1, f"Cannot launch: {error}\n")


if __name__ == "__main__":
    raise SystemExit(main())
