int __cdecl _ioinit()
{
  stlp_std::ioinfo *v0; // eax
  unsigned int *j; // ecx
  int v2; // edi
  unsigned __int8 *v3; // ebx
  stlp_std::ioinfo *v4; // eax
  stlp_std::ioinfo **v5; // ecx
  unsigned int k; // edx
  char *v7; // esi
  int m; // ebx
  char *v9; // esi
  DWORD v10; // eax
  HANDLE StdHandle; // eax
  HANDLE v12; // edi
  DWORD FileType; // eax
  _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-64h] BYREF
  int i; // [esp+54h] [ebp-20h]
  int *posfhnd; // [esp+58h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+5Ch] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  GetStartupInfoA(&StartupInfo);
  ms_exc.registration.TryLevel = -2;
  v0 = (stlp_std::ioinfo *)_calloc_crt(0x20u, 0x40u);
  if ( !v0 )
    return -1;
  __pioinfo[0] = v0;
  _nhandle = 32;
  for ( j = &v0[56].lock.SpinCount; v0 < (stlp_std::ioinfo *)j; j = &__pioinfo[0][56].lock.SpinCount )
  {
    v0->osfile = 0;
    v0->osfhnd = -1;
    v0->pipech = 10;
    v0->lockinitflag = 0;
    LOBYTE(v0[1].osfhnd) = 0;
    BYTE1(v0[1].osfhnd) = 10;
    BYTE2(v0[1].osfhnd) = 10;
    v0[1].lock.RecursionCount = 0;
    LOBYTE(v0[1].lock.LockCount) = 0;
    v0 = (stlp_std::ioinfo *)((char *)v0 + 64);
  }
  if ( StartupInfo.cbReserved2 && StartupInfo.lpReserved2 )
  {
    v2 = *(_DWORD *)StartupInfo.lpReserved2;
    v3 = StartupInfo.lpReserved2 + 4;
    posfhnd = (int *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( v2 >= 2048 )
      v2 = 2048;
    i = 1;
    while ( (int)_nhandle < v2 )
    {
      v4 = (stlp_std::ioinfo *)_calloc_crt(0x20u, 0x40u);
      if ( !v4 )
      {
        v2 = _nhandle;
        break;
      }
      v5 = &__pioinfo[i];
      *v5 = v4;
      _nhandle += 32;
      for ( k = (unsigned int)&v4[56].lock.SpinCount; (unsigned int)v4 < k; k = (unsigned int)&(*v5)[56].lock.SpinCount )
      {
        v4->osfile = 0;
        v4->osfhnd = -1;
        v4->pipech = 10;
        v4->lockinitflag = 0;
        LOBYTE(v4[1].osfhnd) &= 0x80u;
        BYTE1(v4[1].osfhnd) = 10;
        BYTE2(v4[1].osfhnd) = 10;
        v4[1].lock.RecursionCount = 0;
        LOBYTE(v4[1].lock.LockCount) = 0;
        v4 = (stlp_std::ioinfo *)((char *)v4 + 64);
      }
      ++i;
    }
    for ( i = 0; i < v2; ++posfhnd )
    {
      if ( *posfhnd != -1 && *posfhnd != -2 && (*v3 & 1) != 0 && ((*v3 & 8) != 0 || GetFileType((HANDLE)*posfhnd)) )
      {
        v7 = (char *)__pioinfo[i >> 5] + 64 * (i & 0x1F);
        *(_DWORD *)v7 = *posfhnd;
        v7[4] = *v3;
        if ( !__crtInitCritSecAndSpinCount((_RTL_CRITICAL_SECTION *)(v7 + 12), 0xFA0u) )
          return -1;
        ++*((_DWORD *)v7 + 2);
      }
      ++i;
      ++v3;
    }
  }
  for ( m = 0; m < 3; ++m )
  {
    v9 = (char *)__pioinfo[0] + 64 * m;
    if ( *(_DWORD *)v9 == -1 || *(_DWORD *)v9 == -2 )
    {
      v9[4] = -127;
      if ( m )
        v10 = -(m != 1) - 11;
      else
        v10 = -10;
      StdHandle = GetStdHandle(v10);
      v12 = StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle && (FileType = GetFileType(StdHandle)) != 0 )
      {
        *(_DWORD *)v9 = v12;
        if ( (unsigned __int8)FileType == 2 )
        {
          v9[4] |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v9[4] |= 8u;
        }
        if ( !__crtInitCritSecAndSpinCount((_RTL_CRITICAL_SECTION *)(v9 + 12), 0xFA0u) )
          return -1;
        ++*((_DWORD *)v9 + 2);
      }
      else
      {
        v9[4] |= 0x40u;
        *(_DWORD *)v9 = -2;
      }
    }
    else
    {
      v9[4] |= 0x80u;
    }
  }
  SetHandleCount(_nhandle);
  return 0;
}
