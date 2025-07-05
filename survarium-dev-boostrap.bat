wt ^
new-tab -p "PowerShell" -d "D:\Projects\srp" --title "nvim" powershell -NoExit -Command "nvim +Ex" ; ^
new-tab -d "D:\Projects\srp" --title "cargo build"  powershell -NoExit -Command "cargo check" ; ^
new-tab -d "D:\Projects\srp" --title "lobby server"  powershell -NoExit -Command "cargo run --bin lobby-server" ; ^
new-tab -d "D:\Projects\srp" --title "match server"  powershell -NoExit -Command "cargo run --bin match-server" ; ^
new-tab -d "D:\Projects\srp" --title "login server"  powershell -NoExit -Command "cargo run --bin login-server" ; ^
new-tab -d "D:\Projects\srp" --title "browser server"  powershell -NoExit -Command "cargo run --bin browser-server" ; ^
new-tab -d "D:\Projects\Survarium\binaries\win32" --title "survarium"  powershell -NoExit -Command "Write-Output '.\survarium.exe -client=''127.0.0.1:1234'' -log_verbosity=debug -write_errors_to_stderr'" ; ^
new-tab -d "D:\Projects\srp" --title "notes"  powershell -NoExit -Command "nvim resources/notes/dev-notes.md" ; ^
focus-tab -t 0
