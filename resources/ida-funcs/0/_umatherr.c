long double __cdecl _umatherr(int type, unsigned int opcode, long double arg1, long double arg2, long double retval)
{
  int v5; // eax
  char *v6; // eax

  v5 = 0;
  while ( dword_86FDF8[2 * v5] != opcode )
  {
    if ( ++v5 >= 29 )
    {
      v6 = 0;
      goto LABEL_5;
    }
  }
  v6 = (&off_86FDFC)[2 * v5];
LABEL_5:
  if ( v6 )
  {
    _ctrlfp();
    if ( !__init_collate() )
      _set_errno_from_matherr(type);
    return retval;
  }
  else
  {
    _ctrlfp();
    _set_errno_from_matherr(type);
    return retval;
  }
}
