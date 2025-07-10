void __cdecl _raise_exc_ex(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        float *parg1,
        float *presult,
        int isfloat)
{
  char v7; // cl
  unsigned int *v8; // esi
  char v9; // al
  int v10; // eax
  _FPIEEE_RECORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _FPIEEE_RECORD *v14; // eax
  unsigned int v15; // ecx
  float *v16; // edi
  _FPIEEE_RECORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax

  v7 = flags;
  prec->Cause = 0;
  prec->Enable = 0;
  prec->Status = 0;
  if ( (v7 & 0x10) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 1u;
    flags = -1073741681;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 2u;
    flags = -1073741677;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 4u;
    flags = -1073741679;
  }
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 8u;
    flags = -1073741682;
  }
  if ( (v7 & 8) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 0x10u;
    flags = -1073741680;
  }
  v8 = pcw;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(16 * *pcw)) & 0x10;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(2 * *v8)) & 8;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 1)) & 4;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 3)) & 2;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 5)) & 1;
  v9 = _statfp();
  if ( (v9 & 1) != 0 )
    *(_DWORD *)&prec->Status |= 0x10u;
  if ( (v9 & 4) != 0 )
    *(_DWORD *)&prec->Status |= 8u;
  if ( (v9 & 8) != 0 )
    *(_DWORD *)&prec->Status |= 4u;
  if ( (v9 & 0x10) != 0 )
    *(_DWORD *)&prec->Status |= 2u;
  if ( (v9 & 0x20) != 0 )
    *(_DWORD *)&prec->Status |= 1u;
  v10 = *v8 & 0xC00;
  switch ( v10 )
  {
    case 0:
      *(_DWORD *)prec &= 0xFFFFFFFC;
      break;
    case 1024:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 2;
LABEL_27:
      *(_DWORD *)v11 = v12;
      break;
    case 3072:
      *(_DWORD *)prec |= 3u;
      break;
  }
  v13 = *v8 & 0x300;
  switch ( v13 )
  {
    case 0:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 4;
LABEL_36:
      *(_DWORD *)v14 = v15;
      break;
    case 768:
      *(_DWORD *)prec &= 0xFFFFFFE3;
      break;
  }
  *(_DWORD *)prec ^= (unsigned int)&loc_1FFE0 & (*(_DWORD *)prec ^ (32 * opcode));
  *((_DWORD *)&prec->Operand1 + 4) |= 1u;
  v16 = presult;
  if ( isfloat )
  {
    *((_DWORD *)&prec->Operand1 + 4) &= 0xFFFFFFE1;
    prec->Operand1.Value.Fp32Value = *parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) &= 0xFFFFFFE1;
    prec->Result.Value.Fp32Value = *v16;
  }
  else
  {
    *((_DWORD *)&prec->Operand1 + 4) = *((_DWORD *)&prec->Operand1 + 4) & 0xFFFFFFE1 | 2;
    prec->Operand1.Value.Fp64Value = *(double *)parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) = *((_DWORD *)&prec->Result + 4) & 0xFFFFFFE1 | 2;
    prec->Result.Value.Fp64Value = *(double *)v16;
  }
  _clrfp();
  RaiseException(flags, 0, 1u, (const ULONG_PTR *)&prec);
  v17 = prec;
  if ( (*(_BYTE *)&prec->Enable & 0x10) != 0 )
    *v8 &= ~1u;
  if ( (*(_BYTE *)&v17->Enable & 8) != 0 )
    *v8 &= ~4u;
  if ( (*(_BYTE *)&v17->Enable & 4) != 0 )
    *v8 &= ~8u;
  if ( (*(_BYTE *)&v17->Enable & 2) != 0 )
    *v8 &= ~0x10u;
  if ( (*(_BYTE *)&v17->Enable & 1) != 0 )
    *v8 &= ~0x20u;
  v18 = *(_DWORD *)v17 & 3;
  if ( !v18 )
  {
    *v8 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v19 = v18 - 1;
  if ( !v19 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v20 = v19 - 1;
  if ( !v20 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v8 = v21;
    goto LABEL_59;
  }
  if ( v20 == 1 )
    *v8 |= 0xC00u;
LABEL_59:
  v22 = (*(_DWORD *)v17 >> 2) & 7;
  if ( !v22 )
  {
    v24 = *v8 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v23 = v22 - 1;
  if ( !v23 )
  {
    v24 = *v8 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v8 = v24;
    goto LABEL_66;
  }
  if ( v23 == 1 )
    *v8 &= 0xFFFFF3FF;
LABEL_66:
  if ( isfloat )
    *v16 = v17->Result.Value.Fp32Value;
  else
    *(double *)v16 = v17->Result.Value.Fp64Value;
}
