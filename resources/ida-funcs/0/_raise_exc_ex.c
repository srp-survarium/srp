void __usercall _raise_exc_ex(
        __int16 a1@<fpstat>,
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        float *parg1,
        float *presult,
        int isfloat)
{
  char v8; // cl
  unsigned int *v9; // esi
  char v10; // al
  int v11; // eax
  _FPIEEE_RECORD *v12; // eax
  unsigned int v13; // ecx
  int v14; // eax
  _FPIEEE_RECORD *v15; // eax
  unsigned int v16; // ecx
  float *v17; // edi
  __int16 v18; // fps
  _FPIEEE_RECORD *v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  int v27; // eax
  int v28; // eax
  unsigned int v29; // eax

  v8 = flags;
  prec->Cause = 0;
  prec->Enable = 0;
  prec->Status = 0;
  if ( (v8 & 0x10) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 1u;
    flags = -1073741681;
  }
  if ( (v8 & 2) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 2u;
    flags = -1073741677;
  }
  if ( (v8 & 1) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 4u;
    flags = -1073741679;
  }
  if ( (v8 & 4) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 8u;
    flags = -1073741682;
  }
  if ( (v8 & 8) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 0x10u;
    flags = -1073741680;
  }
  v9 = pcw;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(16 * *pcw)) & 0x10;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(2 * *v9)) & 8;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v9 >> 1)) & 4;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v9 >> 3)) & 2;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v9 >> 5)) & 1;
  v10 = _statfp(a1);
  if ( (v10 & 1) != 0 )
    *(_DWORD *)&prec->Status |= 0x10u;
  if ( (v10 & 4) != 0 )
    *(_DWORD *)&prec->Status |= 8u;
  if ( (v10 & 8) != 0 )
    *(_DWORD *)&prec->Status |= 4u;
  if ( (v10 & 0x10) != 0 )
    *(_DWORD *)&prec->Status |= 2u;
  if ( (v10 & 0x20) != 0 )
    *(_DWORD *)&prec->Status |= 1u;
  v11 = *v9 & 0xC00;
  switch ( v11 )
  {
    case 0:
      *(_DWORD *)prec &= 0xFFFFFFFC;
      break;
    case 1024:
      v12 = prec;
      v13 = *(_DWORD *)prec & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v12 = prec;
      v13 = *(_DWORD *)prec & 0xFFFFFFFC | 2;
LABEL_27:
      *(_DWORD *)v12 = v13;
      break;
    case 3072:
      *(_DWORD *)prec |= 3u;
      break;
  }
  v14 = *v9 & 0x300;
  switch ( v14 )
  {
    case 0:
      v15 = prec;
      v16 = *(_DWORD *)prec & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v15 = prec;
      v16 = *(_DWORD *)prec & 0xFFFFFFE3 | 4;
LABEL_36:
      *(_DWORD *)v15 = v16;
      break;
    case 768:
      *(_DWORD *)prec &= 0xFFFFFFE3;
      break;
  }
  *(_DWORD *)prec ^= (*(_DWORD *)prec ^ (32 * opcode)) & 0x1FFE0;
  *((_DWORD *)&prec->Operand1 + 4) |= 1u;
  v17 = presult;
  if ( isfloat )
  {
    *((_DWORD *)&prec->Operand1 + 4) &= 0xFFFFFFE1;
    prec->Operand1.Value.Fp32Value = *parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) &= 0xFFFFFFE1;
    prec->Result.Value.Fp32Value = *v17;
  }
  else
  {
    *((_DWORD *)&prec->Operand1 + 4) = *((_DWORD *)&prec->Operand1 + 4) & 0xFFFFFFE1 | 2;
    prec->Operand1.Value.Fp64Value = *(double *)parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) = *((_DWORD *)&prec->Result + 4) & 0xFFFFFFE1 | 2;
    prec->Result.Value.Fp64Value = *(double *)v17;
  }
  _clrfp(v18);
  RaiseException(flags, 0, 1u, (const ULONG_PTR *)&prec);
  v22 = prec;
  if ( (*(_BYTE *)&prec->Enable & 0x10) != 0 )
    *v9 &= ~1u;
  if ( (*(_BYTE *)&v22->Enable & 8) != 0 )
    *v9 &= ~4u;
  if ( (*(_BYTE *)&v22->Enable & 4) != 0 )
    *v9 &= ~8u;
  if ( (*(_BYTE *)&v22->Enable & 2) != 0 )
    *v9 &= ~0x10u;
  if ( (*(_BYTE *)&v22->Enable & 1) != 0 )
    *v9 &= ~0x20u;
  v23 = *(_DWORD *)v22 & 3;
  if ( !v23 )
  {
    *v9 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v24 = v23 - 1;
  if ( !v24 )
  {
    v26 = *v9 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v25 = v24 - 1;
  if ( !v25 )
  {
    v26 = *v9 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v9 = v26;
    goto LABEL_59;
  }
  if ( v25 == 1 )
    *v9 |= 0xC00u;
LABEL_59:
  v27 = (*(_DWORD *)v22 >> 2) & 7;
  if ( !v27 )
  {
    v29 = *v9 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v28 = v27 - 1;
  if ( !v28 )
  {
    v29 = *v9 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v9 = v29;
    goto LABEL_66;
  }
  if ( v28 == 1 )
    *v9 &= 0xFFFFF3FF;
LABEL_66:
  if ( isfloat )
    *v17 = v22->Result.Value.Fp32Value;
  else
    *(double *)v17 = v22->Result.Value.Fp64Value;
}
