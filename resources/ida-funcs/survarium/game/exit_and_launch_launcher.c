void __thiscall survarium::game::exit_and_launch_launcher(survarium::game *this, survarium::game *a2)
{
  _STARTUPINFOA StartupInfo; // [esp+4h] [ebp-54h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+48h] [ebp-10h] BYREF

  memset((int)&StartupInfo.lpReserved, 0, 0x40u);
  StartupInfo.cb = 68;
  CreateProcessA(0, (LPSTR)"survarium_launcher.exe", 0, 0, 0, 0, 0, 0, &StartupInfo, &ProcessInformation);
  survarium::game::exit(a2, "switch to launcher");
}
