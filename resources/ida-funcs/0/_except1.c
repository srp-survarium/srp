long double __usercall _except1@<st0>(
        int a1@<ebp>,
        DWORD flags,
        unsigned int opcode,
        long double arg,
        long double result,
        __int16 cw)
{
  __int16 v6; // fps
  int v10; // eax
  _FPIEEE_RECORD v12; // [esp+1Ch] [ebp-8Ch] BYREF
  int v13; // [esp+9Ch] [ebp-Ch]
  void *v14; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v13 = a1;
  v14 = retaddr;
  if ( !_handle_exc(flags, &result, cw) )
  {
    *((_DWORD *)&v12.Operand2 + 4) &= ~1u;
    _raise_exc(v6, &v12, (unsigned int *)&cw, flags, opcode, &arg, &result);
  }
  v10 = _errcode(flags);
  if ( !_matherr_flag && v10 )
    return _umatherr(v10, opcode, arg, 0.0, result);
  _set_errno_from_matherr(v10);
  _ctrlfp();
  return result;
}
