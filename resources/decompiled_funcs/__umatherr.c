long double __cdecl _umatherr(
        int type,
        unsigned int opcode,
        long double arg1,
        long double arg2,
        long double retval,
        unsigned int cw)
{
  int v6; // eax
  char *v7; // eax

  v6 = 0;
  while ( dword_9AECD0[2 * v6] != opcode )
  {
    if ( ++v6 >= 29 )
    {
      v7 = 0;
      goto LABEL_5;
    }
  }
  v7 = (&off_9AECD4)[2 * v6];
LABEL_5:
  if ( v7 )
  {
    _ctrlfp(cw, 0xFFFFu);
    if ( !__init_collate() )
      _set_errno_from_matherr(type);
    return retval;
  }
  else
  {
    _ctrlfp(cw, 0xFFFFu);
    _set_errno_from_matherr(type);
    return retval;
  }
}
