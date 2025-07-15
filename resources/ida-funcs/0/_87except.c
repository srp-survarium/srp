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
  __int16 v12; // fps
  unsigned int v16; // [esp-88h] [ebp-94h] BYREF
  DWORD v17; // [esp-84h] [ebp-90h]
  _FPIEEE_RECORD v18; // [esp-80h] [ebp-8Ch] BYREF
  int v19; // [esp+0h] [ebp-Ch]
  void *v20; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v19 = a1;
  v20 = retaddr;
  v4 = *pcw16;
  v6 = exc->type - 1;
  v5 = exc->type == 1;
  v16 = *pcw16;
  if ( v5 )
    goto LABEL_13;
  v7 = v6 - 1;
  if ( !v7 )
  {
    v17 = 4;
    goto LABEL_14;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    v17 = 17;
    goto LABEL_14;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v17 = 18;
    goto LABEL_14;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
LABEL_13:
    v17 = 8;
LABEL_14:
    if ( !_handle_exc(v17, &exc->retval, v4) )
    {
      if ( opcode == 16 || opcode == 22 || opcode == 29 )
      {
        v18.Operand2.Value.Fp64Value = exc->arg2;
        *((_DWORD *)&v18.Operand2 + 4) = *((_DWORD *)&v18.Operand2 + 4) & 0xFFFFFFE0 | 3;
      }
      else
      {
        *((_DWORD *)&v18.Operand2 + 4) &= ~1u;
      }
      _raise_exc(v12, &v18, &v16, v17, opcode, &exc->arg1, &exc->retval);
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
    v17 = 16;
    goto LABEL_14;
  }
LABEL_21:
  _ctrlfp();
  if ( exc->type == 8 || _matherr_flag || !__init_collate() )
    _set_errno_from_matherr(exc->type);
}
