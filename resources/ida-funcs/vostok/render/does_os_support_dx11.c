bool __cdecl vostok::render::does_os_support_dx11()
{
  _BYTE dst[156]; // [esp+0h] [ebp-A8h] BYREF
  unsigned int minor_version; // [esp+A0h] [ebp-8h] BYREF
  unsigned int major_version; // [esp+A4h] [ebp-4h] BYREF

  memset((int)dst, 0, sizeof(dst));
  *(_DWORD *)dst = 156;
  return !GetVersionExA((LPOSVERSIONINFOA)dst)
      || *(_DWORD *)&dst[4] > 6u
      || *(_DWORD *)&dst[4] == 6
      && (*(_DWORD *)&dst[8]
       || *(_WORD *)&dst[148] >= 2u
       && (vostok::render::get_dx_version_via_dxdiag(&major_version, &minor_version) < 0 || major_version >= 0xA));
}
