unsigned __int64 OPENSSL_ia32_cpuid()
{
  unsigned int v1; // kr00_4
  unsigned int v2; // kr04_4
  unsigned int v9; // edi
  BOOL v10; // eax
  int v11; // ebp
  BOOL v12; // esi
  int v13; // esi
  unsigned int v24; // esi
  bool v28; // cf
  int v29; // edi

  _EDX = 0;
  v1 = __readeflags();
  __writeeflags((unsigned int)&loc_200000 ^ v1);
  v2 = __readeflags();
  _ECX = v2 ^ v1;
  if ( ((v2 ^ v1) & 0x200000) != 0 )
  {
    _EAX = 0;
    __asm { cpuid }
    v9 = _EAX;
    v10 = _ECX != 1818588270;
    v11 = v10 || _EDX != 1231384169 || _EBX != 1970169159;
    if ( !v11 )
      goto $L001intel;
    LOBYTE(v10) = _EBX != 1752462657;
    v12 = v10;
    LOBYTE(v10) = _EDX != 1769238117;
    v13 = v10 || v12;
    LOBYTE(v10) = _ECX != 1145913699;
    if ( v10 | v13 )
      goto $L001intel;
    _EAX = 0x80000000;
    __asm { cpuid }
    if ( _EAX < 0x80000008 )
    {
$L001intel:
      v28 = v9 < 4;
      v29 = -1;
      if ( !v28 )
      {
        _EAX = 4;
        __asm { cpuid }
        v29 = (_EAX >> 14) & 0xFFF;
      }
      _EAX = 1;
      __asm { cpuid }
      if ( !v11 && (BYTE1(_EAX) & 0xF) == 0xF )
        _EDX |= (unsigned int)&loc_100000;
      if ( (_EDX & 0x10000000) != 0 )
      {
        _EDX &= ~0x10000000u;
        if ( v29 )
        {
          _EDX |= 0x10000000u;
          if ( BYTE2(_EBX) <= 1u )
            _EDX &= ~0x10000000u;
        }
      }
    }
    else
    {
      _EAX = -2147483640;
      __asm { cpuid }
      v24 = (unsigned __int8)_ECX + 1;
      _EAX = 1;
      __asm { cpuid }
      if ( (_EDX & 0x10000000) != 0 && BYTE2(_EBX) <= v24 )
        _EDX &= ~0x10000000u;
    }
  }
  return __PAIR64__(_ECX, _EDX);
}
