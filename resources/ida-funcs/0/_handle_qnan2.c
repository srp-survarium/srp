long double __cdecl _handle_qnan2(unsigned int opcode, long double x, long double y)
{
  long double retval; // [esp+1Ch] [ebp-8h]

  retval = x + y;
  if ( !_matherr_flag )
    return _umatherr(1, opcode, x, y, retval);
  *_errno() = 33;
  _ctrlfp();
  return retval;
}
