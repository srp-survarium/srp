long double __cdecl _handle_qnan1(unsigned int opcode, long double x, unsigned int savedcw)
{
  if ( !_matherr_flag )
    return _umatherr(1, opcode, x, 0.0, x, savedcw);
  *_errno() = 33;
  _ctrlfp(savedcw, 0xFFFFu);
  return x;
}
