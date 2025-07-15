long double __cdecl _handle_qnan1(unsigned int opcode, long double x)
{
  if ( !_matherr_flag )
    return _umatherr(1, opcode, x, 0.0, x);
  *_errno() = 33;
  _ctrlfp();
  return x;
}
