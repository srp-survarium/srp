long double __usercall _except1@<st0>(
        int a1@<ebp>,
        int flags,
        int opcode,
        long double arg,
        long double result,
        unsigned int cw)
{
  int v6; // eax
  int v8; // [esp+1Ch] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+28h] [ebp-80h]
  int v10; // [esp+9Ch] [ebp-Ch]
  void *v11; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v10 = a1;
  v11 = retaddr;
  if ( !_handle_exc(flags, &result, cw) )
  {
    rec.Operand2.Value.Fp128Value.W[1] &= ~1u;
    _raise_exc((_FPIEEE_RECORD *)&v8, &cw, flags, opcode, &arg, &result);
  }
  v6 = _errcode(flags);
  if ( !_matherr_flag && v6 )
    return _umatherr(v6, opcode, arg, 0.0, result, cw);
  _set_errno_from_matherr(v6);
  _ctrlfp(cw, 0xFFFFu);
  return result;
}
