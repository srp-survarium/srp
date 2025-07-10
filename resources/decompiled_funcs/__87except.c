void __usercall _87except(int a1@<ebp>, int opcode, _exception *exc, unsigned __int16 *pcw16)
{
  __int16 v4; // cx
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // [esp-Ch] [ebp-94h] BYREF
  DWORD v13; // [esp-8h] [ebp-90h]
  int v14; // [esp-4h] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+8h] [ebp-80h]
  int v16; // [esp+7Ch] [ebp-Ch]
  void *v17; // [esp+80h] [ebp-8h]
  void *retaddr; // [esp+88h] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  v4 = *pcw16;
  v6 = exc->type - 1;
  v5 = exc->type == 1;
  v12 = *pcw16;
  if ( v5 )
    goto LABEL_13;
  v7 = v6 - 1;
  if ( !v7 )
  {
    v13 = 4;
    goto LABEL_14;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    v13 = 17;
    goto LABEL_14;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v13 = 18;
    goto LABEL_14;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
LABEL_13:
    v13 = 8;
LABEL_14:
    if ( !_handle_exc(v13, &exc->retval, v4) )
    {
      if ( opcode == 16 || opcode == 22 || opcode == 29 )
      {
        *(double *)((char *)&rec.Operand1 + 20) = exc->arg2;
        rec.Operand2.Value.Fp128Value.W[1] = rec.Operand2.Value.Fp128Value.W[1] & 0xFFFFFFE0 | 3;
      }
      else
      {
        rec.Operand2.Value.Fp128Value.W[1] &= ~1u;
      }
      _raise_exc((_FPIEEE_RECORD *)&v14, &v12, v13, opcode, &exc->arg1, &exc->retval);
    }
    goto LABEL_21;
  }
  v11 = v10 - 2;
  if ( !v11 )
  {
    exc->type = 1;
    goto LABEL_21;
  }
  if ( v11 == 1 )
  {
    v13 = 16;
    goto LABEL_14;
  }
LABEL_21:
  _ctrlfp();
  if ( exc->type == 8 || _matherr_flag || !__init_collate() )
    _set_errno_from_matherr(exc->type);
}
