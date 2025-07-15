bool __cdecl vostok::render::does_os_support_dx11()
{
  unsigned int major_version; // [esp+4h] [ebp-A8h] BYREF
  unsigned int minor_version; // [esp+8h] [ebp-A4h] BYREF
  _OSVERSIONINFOEXA OsVersionInfo; // [esp+Ch] [ebp-A0h] BYREF

  memset((int)&OsVersionInfo, 0, sizeof(OsVersionInfo));
  OsVersionInfo.dwOSVersionInfoSize = 156;
  return !GetVersionExA((LPOSVERSIONINFOA)&OsVersionInfo)
      || OsVersionInfo.dwMajorVersion > 6
      || OsVersionInfo.dwMajorVersion == 6
      && (OsVersionInfo.dwMinorVersion
       || OsVersionInfo.wServicePackMajor >= 2u
       && ((vostok::render::get_dx_version_via_dxdiag(&major_version, &minor_version) & 0x80000000) != 0
        || major_version >= 0xA));
}
