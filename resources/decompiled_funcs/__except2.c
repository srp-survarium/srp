long double __usercall _except2@<st0>(
        int a1@<ebp>,
        int flags,
        int opcode,
        long double arg1,
        long double arg2,
        long double result,
        unsigned int cw)
{
  int v7; // eax
  int v9; // [esp+1Ch] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+28h] [ebp-80h]
  int v11; // [esp+9Ch] [ebp-Ch]
  void *v12; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v11 = a1;
  v12 = retaddr;
  if ( !_handle_exc(flags, &result, cw) )
  {
    *(double *)((char *)&rec.Operand1 + 20) = arg2;
    rec.Operand2.Value.Fp128Value.W[1] = rec.Operand2.Value.Fp128Value.W[1] & 0xFFFFFFE0 | 3;
    _raise_exc((_FPIEEE_RECORD *)&v9, &cw, flags, opcode, &arg1, &result);
  }
  v7 = _errcode(flags);
  if ( !_matherr_flag && v7 )
    return _umatherr(v7, opcode, arg1, arg2, result, cw);
  _set_errno_from_matherr(v7);
  _ctrlfp(cw, 0xFFFFu);
  return result;
}
