int __cdecl _setargv()
{
  int v0; // edi
  unsigned int v1; // eax
  char **v2; // esi
  int numchars; // [esp+Ch] [ebp-Ch] BYREF
  int numargs; // [esp+10h] [ebp-8h] BYREF
  char *cmdstart; // [esp+14h] [ebp-4h]

  if ( !__mbctype_initialized )
    __initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(0, pgmname, 0x104u);
  _pgmptr = pgmname;
  if ( !_acmdln || (cmdstart = _acmdln, !*_acmdln) )
    cmdstart = pgmname;
  parse_cmdline(cmdstart, &numchars, 0, 0, &numargs);
  if ( (unsigned int)numargs >= 0x3FFFFFFF )
    return -1;
  if ( numchars == -1 )
    return -1;
  v0 = numargs;
  v1 = 4 * numargs + numchars;
  if ( v1 < numchars )
    return -1;
  v2 = (char **)_malloc_crt(v1);
  if ( !v2 )
    return -1;
  parse_cmdline(cmdstart, &numchars, v2, (char *)&v2[v0], &numargs);
  __argc = numargs - 1;
  __argv = v2;
  return 0;
}
