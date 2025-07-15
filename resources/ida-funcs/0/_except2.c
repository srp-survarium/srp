long double __usercall _except2@<st0>(
        int a1@<ebp>,
        DWORD flags,
        unsigned int opcode,
        long double arg1,
        long double arg2,
        long double result,
        __int16 cw)
{
  __int16 v7; // fps
  int v8; // eax
  _FPIEEE_RECORD v10; // [esp+1Ch] [ebp-8Ch] BYREF
  int v11; // [esp+9Ch] [ebp-Ch]
  void *v12; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v11 = a1;
  v12 = retaddr;
  if ( !_handle_exc(flags, &result, cw) )
  {
    v10.Operand2.Value.Fp64Value = arg2;
    *((_DWORD *)&v10.Operand2 + 4) = *((_DWORD *)&v10.Operand2 + 4) & 0xFFFFFFE0 | 3;
    _raise_exc(v7, &v10, (unsigned int *)&cw, flags, opcode, &arg1, &result);
  }
  v8 = _errcode(flags);
  if ( !_matherr_flag && v8 )
    return _umatherr(v8, opcode, arg1, arg2, result);
  _set_errno_from_matherr(v8);
  _ctrlfp();
  return result;
}
