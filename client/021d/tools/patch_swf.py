#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Edit only retail lobby DoABC data; preserve all other SWF tags verbatim."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import zlib

RETAIL_SHA256 = "1370380ff8029fabbe7f564b44574ccd5aafbd5675868b4f5a140b1b2956c8b9"


def digest(data):
    return hashlib.sha256(data).hexdigest()


def unpack(data):
    if len(data) < 8 or data[:3] not in (b"CWS", b"FWS"):
        raise ValueError("Expected a CWS/FWS movie")
    body = zlib.decompress(data[8:]) if data[:3] == b"CWS" else data[8:]
    if len(body) + 8 != struct.unpack_from("<I", data, 4)[0]:
        raise ValueError("SWF length mismatch")
    rect_size = (5 + 4 * (body[0] >> 3) + 7) // 8
    header = body[:rect_size + 4]
    pos, tags = len(header), []
    while pos < len(body):
        start = pos
        if pos + 2 > len(body):
            raise ValueError("Truncated SWF tag header")
        word = struct.unpack_from("<H", body, pos)[0]
        pos += 2
        kind, size = word >> 6, word & 63
        if size == 63:
            if pos + 4 > len(body):
                raise ValueError("Truncated SWF tag size")
            size = struct.unpack_from("<I", body, pos)[0]
            pos += 4
        if pos + size > len(body):
            raise ValueError("Truncated SWF tag payload")
        payload = body[pos:pos + size]
        pos += size
        tags.append((kind, payload, body[start:pos]))
        if kind == 0:
            if size or pos != len(body):
                raise ValueError("Unexpected bytes after End tag")
            break
    if not tags or tags[-1][0] != 0:
        raise ValueError("Missing SWF End tag")
    return data[3], header, tags


def pack(version, header, tags, compressed=True):
    body = header + b"".join(tag[2] for tag in tags)
    return ((b"CWS" if compressed else b"FWS") + bytes([version])
            + struct.pack("<I", len(body) + 8)
            + (zlib.compress(body, 9) if compressed else body))


def patch(source, script, ffdec, java, javac, work):
    original = source.read_bytes()
    if digest(original) != RETAIL_SHA256:
        raise ValueError("Input is not the verified retail 0.21d lobby SWF")
    version, header, tags = unpack(original)
    # Scaleform display tags are not reliably interpreted by standard editors.
    # Feed only ABC + attributes to the editor; transplant edited ABC afterward.
    code_tags = [t for t in tags if t[0] in (69, 82, 0)]
    code = work / "code.swf"
    code.write_bytes(pack(version, header, code_tags, False))
    log = work / "ffdec.log"
    helper = Path(__file__).with_name("AddMenu.java")
    subprocess.run([javac, "-cp", str(ffdec.resolve()), "-d", str(work), str(helper)], check=True)
    import os
    classpath = str(work) + os.pathsep + str(ffdec.resolve())
    base = [java, "-Djava.awt.headless=true", "-Duser.home=" + str(work),
            "-cp", classpath, "AddMenu"]
    with log.open("w") as out:
        edited = work / "edited.swf"
        subprocess.run(base + [str(code), str(script), str(edited)], stdout=out, stderr=subprocess.STDOUT,
                       check=True)
    _, _, edited_tags = unpack(edited.read_bytes())
    replacements = [t for t in edited_tags if t[0] == 82]
    old_abc = [t for t in tags if t[0] == 82]
    if len(replacements) != len(old_abc) or not replacements:
        raise ValueError("ABC count changed unexpectedly")
    if all(a[2] == b[2] for a, b in zip(old_abc, replacements)):
        raise ValueError("Editor did not modify the ABC")
    replacement_iter = iter(replacements)
    result_tags = [next(replacement_iter) if t[0] == 82 else t for t in tags]
    result = pack(version, header, result_tags)
    _, new_header, new_tags = unpack(result)
    if new_header != header or [t[2] for t in new_tags if t[0] != 82] != [
            t[2] for t in tags if t[0] != 82]:
        raise ValueError("Non-script content changed")
    return result, {"input_sha256": digest(original), "output_sha256": digest(result),
                    "preserved_non_abc_tags": sum(t[0] != 82 for t in tags),
                    "abc_blocks": len(replacements), "mode": "srp-match-menu"}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--ffdec", required=True, type=Path)
    parser.add_argument("--java", default="java")
    parser.add_argument("--javac", default="javac")
    parser.add_argument("--work", required=True, type=Path)
    args = parser.parse_args()
    if args.output.exists():
        parser.error("Output already exists; choose a new path")
    args.work.mkdir(parents=True, exist_ok=True)
    script = Path(__file__).resolve().parents[1] / "ui/SrpMenu.as"
    result, manifest = patch(args.source, script, args.ffdec, args.java, args.javac, args.work.resolve())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(result)
    args.output.with_suffix(".manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    print(json.dumps(manifest, indent=2))


if __name__ == "__main__":
    main()
