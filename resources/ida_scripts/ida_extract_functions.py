import idaapi
import idautils
import idc
import os

# Output directory for extracted functions
output_dir = idaapi.ask_str("decompiled_funcs", 0, "Enter output folder for decompiled functions")
if not output_dir:
    print("Cancelled.")
    exit()

if not os.path.exists(output_dir):
    os.makedirs(output_dir)

# Ensure decompiler is available
if not idaapi.init_hexrays_plugin():
    print("Hex-Rays decompiler not available!")
    exit()

# Clean filename for filesystem
def sanitize_filename(name):
    invalid = '<>:"/\\|?*'
    for ch in invalid:
        name = name.replace(ch, '_')
    return name

# Iterate over all functions
for func_ea in idautils.Functions():
    func_name = idc.get_name(func_ea)

    try:
        cfunc = idaapi.decompile(func_ea)
        decompiled_code = str(cfunc)
    except Exception as e:
        print(f"[!] Failed to decompile {func_name} at {hex(func_ea)}: {e}")
        continue

    safe_name = sanitize_filename(func_name)
    out_file_path = os.path.join(output_dir, f"{safe_name}.c")

    try:
        with open(out_file_path, 'w', encoding='utf-8') as f:
            f.write(decompiled_code)
        print(f"[+] Saved {func_name} -> {out_file_path}")
    except Exception as e:
        print(f"[!] Failed to write file {out_file_path}: {e}")
