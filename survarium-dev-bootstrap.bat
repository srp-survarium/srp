start "" "C:\Program Files\SysinternalsSuite\procexp64.exe"
start "" "C:\Program Files\IDA Free 9.1\ida.exe"

wt ^
new-tab -d "D:\Projects\srp"                      --title "nvim"           powershell -NoExit -Command "nvim +Ex"                                                         ; ^
new-tab -d "D:\Projects\srp"                      --title "cargo build"    powershell -NoExit -Command "$c='cargo check'                                \; iex $c"        ; ^
new-tab -d "D:\Projects\srp"                      --title "lobby server"   powershell -NoExit -Command "$c='cargo run --bin lobby-server'               \; iex $c"        ; ^
new-tab -d "D:\Projects\srp"                      --title "match server"   powershell -NoExit -Command "$c='cargo run --bin match-server'               \; iex $c"        ; ^
new-tab -d "D:\Projects\srp"                      --title "login server"   powershell -NoExit -Command "$c='cargo run --bin login-server'               \; iex $c"        ; ^
new-tab -d "D:\Projects\srp"                      --title "browser server" powershell -NoExit -Command "$c='cargo run --bin browser-server'             \; iex $c"        ; ^
new-tab -d "D:\Projects\Survarium\binaries\win32" --title "survarium"      powershell -NoExit -Command "$c='.\survarium.exe -client=''127.0.0.1:1234''' \; Write-Host $c" ; ^
new-tab -d "D:\Projects\srp"                      --title "notes"          powershell -NoExit -Command "nvim resources/notes/dev-notes.md"                                ; ^
focus-tab -t 0
