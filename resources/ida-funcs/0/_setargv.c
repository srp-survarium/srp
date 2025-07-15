int __cdecl _setargv()
{
  int v0; // edi
  unsigned int v1; // eax
  char **v2; // esi
  unsigned int v4; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v5; // [esp+10h] [ebp-8h] BYREF
  char *v6; // [esp+14h] [ebp-4h]

  if ( !__mbctype_initialized )
    __initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(0, pgmname, 0x104u);
  _pgmptr = pgmname;
  if ( !_acmdln || (v6 = _acmdln, !*_acmdln) )
    v6 = pgmname;
  parse_cmdline(v6, (int *)&v4, 0, 0, (int *)&v5);
  if ( v5 >= 0x3FFFFFFF )
    return -1;
  if ( v4 == -1 )
    return -1;
  v0 = v5;
  v1 = 4 * v5 + v4;
  if ( v1 < v4 )
    return -1;
  v2 = (char **)_malloc_crt(v1);
  if ( !v2 )
    return -1;
  parse_cmdline(v6, (int *)&v4, v2, (char *)&v2[v0], (int *)&v5);
  __argc = v5 - 1;
  __argv = v2;
  return 0;
}
