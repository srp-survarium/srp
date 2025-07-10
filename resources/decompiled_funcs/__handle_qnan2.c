long double __cdecl _handle_qnan2(unsigned int opcode, long double x, long double y, unsigned int savedcw)
{
  long double result; // [esp+1Ch] [ebp-8h]

  result = x + y;
  if ( !_matherr_flag )
    return _umatherr(1, opcode, x, y, result, savedcw);
  *_errno() = 33;
  _ctrlfp(savedcw, 0xFFFFu);
  return result;
}
