char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetDisplayMatrix(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  int v3; // ecx
  float *v5; // eax
  float v6; // [esp+24h] [ebp-1Ch]
  float v7; // [esp+28h] [ebp-18h]
  float v8; // [esp+2Ch] [ebp-14h]
  float v9; // [esp+30h] [ebp-10h]
  float v10; // [esp+34h] [ebp-Ch]
  float v11; // [esp+38h] [ebp-8h]
  float v12; // [esp+3Ch] [ebp-4h]

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC || (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
    return 0;
  v5 = (float *)(*(int (__thiscall **)(_DWORD))(*(_DWORD *)pdata[12] + 8))(pdata[12]);
  v6 = v5[1];
  v7 = v5[2];
  v9 = v5[4];
  v10 = v5[5];
  v11 = v5[6];
  v8 = v5[3] * 0.05000000074505806;
  v12 = 0.05000000074505806 * v5[7];
  pmat->M[0][0] = *v5;
  pmat->M[0][1] = v6;
  pmat->M[0][2] = v7;
  pmat->M[0][3] = v8;
  pmat->M[1][0] = v9;
  pmat->M[1][1] = v10;
  pmat->M[1][2] = v11;
  pmat->M[1][3] = v12;
  return 1;
}
