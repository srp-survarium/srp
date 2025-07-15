char __usercall btConvexPolyhedron::testContainment@<al>(btConvexPolyhedron *this@<ecx>, int a2@<eax>)
{
  int v2; // ebx
  int v3; // edx
  float v4; // xmm4_4
  float v5; // xmm5_4
  float v6; // xmm2_4
  float *v7; // esi
  int v8; // xmm2_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  int v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  int v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm2_4
  int v21; // xmm3_4
  float v22; // xmm4_4
  int v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm2_4
  float *v26; // esi
  float *v27; // ecx
  int v29; // [esp+0h] [ebp-94h]
  float v30; // [esp+4h] [ebp-90h]
  float v31; // [esp+8h] [ebp-8Ch]
  float v32; // [esp+Ch] [ebp-88h]
  float v33[4]; // [esp+14h] [ebp-80h] BYREF
  _DWORD v34[4]; // [esp+24h] [ebp-70h] BYREF
  _DWORD v35[4]; // [esp+34h] [ebp-60h] BYREF
  _DWORD v36[4]; // [esp+44h] [ebp-50h] BYREF
  float v37[4]; // [esp+54h] [ebp-40h] BYREF
  float v38[4]; // [esp+64h] [ebp-30h] BYREF
  _DWORD v39[4]; // [esp+74h] [ebp-20h] BYREF
  _DWORD v40[4]; // [esp+84h] [ebp-10h] BYREF

  v2 = 0;
  v29 = *(_DWORD *)(a2 + 40);
  while ( 1 )
  {
    v3 = 0;
    if ( v2 )
    {
      switch ( v2 )
      {
        case 1:
          v8 = *(_DWORD *)(a2 + 104);
          v9 = *(float *)(a2 + 80) + *(float *)(a2 + 96);
          *(float *)&v35[1] = *(float *)(a2 + 84) + *(float *)(a2 + 100);
          v10 = *(float *)(a2 + 88) + COERCE_FLOAT(v8 ^ _mask__NegFloat_);
          *(float *)v35 = v9;
          *(float *)&v35[2] = v10;
          v35[3] = 0;
          v7 = (float *)v35;
          break;
        case 2:
          v11 = *(_DWORD *)(a2 + 100);
          v12 = *(float *)(a2 + 104);
          v33[0] = *(float *)(a2 + 96) + *(float *)(a2 + 80);
          v33[1] = *(float *)(a2 + 84) + COERCE_FLOAT(v11 ^ _mask__NegFloat_);
          v33[2] = *(float *)(a2 + 88) + v12;
          v33[3] = 0.0;
          v7 = v33;
          break;
        case 3:
          v13 = *(float *)(a2 + 84) + COERCE_FLOAT(*(_DWORD *)(a2 + 100) ^ _mask__NegFloat_);
          v14 = *(float *)(a2 + 88) + COERCE_FLOAT(*(_DWORD *)(a2 + 104) ^ _mask__NegFloat_);
          v37[0] = *(float *)(a2 + 80) + *(float *)(a2 + 96);
          v37[1] = v13;
          v37[2] = v14;
          v37[3] = 0.0;
          v7 = v37;
          break;
        case 4:
          v15 = *(float *)(a2 + 104);
          v16 = *(float *)(a2 + 80) + COERCE_FLOAT(*(_DWORD *)(a2 + 96) ^ _mask__NegFloat_);
          *(float *)&v34[1] = *(float *)(a2 + 84) + *(float *)(a2 + 100);
          v17 = *(float *)(a2 + 88) + v15;
          *(float *)v34 = v16;
          *(float *)&v34[2] = v17;
          v34[3] = 0;
          v7 = (float *)v34;
          break;
        case 5:
          v18 = *(_DWORD *)(a2 + 104);
          v19 = *(float *)(a2 + 80) + COERCE_FLOAT(*(_DWORD *)(a2 + 96) ^ _mask__NegFloat_);
          *(float *)&v36[1] = *(float *)(a2 + 84) + *(float *)(a2 + 100);
          v20 = *(float *)(a2 + 88) + COERCE_FLOAT(v18 ^ _mask__NegFloat_);
          *(float *)v36 = v19;
          *(float *)&v36[2] = v20;
          v36[3] = 0;
          v7 = (float *)v36;
          break;
        case 6:
          v21 = *(_DWORD *)(a2 + 100);
          v22 = *(float *)(a2 + 104);
          v38[0] = COERCE_FLOAT(*(_DWORD *)(a2 + 96) ^ _mask__NegFloat_) + *(float *)(a2 + 80);
          v38[1] = *(float *)(a2 + 84) + COERCE_FLOAT(v21 ^ _mask__NegFloat_);
          v38[2] = *(float *)(a2 + 88) + v22;
          v38[3] = 0.0;
          v7 = v38;
          break;
        case 7:
          v23 = *(_DWORD *)(a2 + 104);
          v24 = *(float *)(a2 + 80) + COERCE_FLOAT(*(_DWORD *)(a2 + 96) ^ _mask__NegFloat_);
          *(float *)&v40[1] = *(float *)(a2 + 84) + COERCE_FLOAT(*(_DWORD *)(a2 + 100) ^ _mask__NegFloat_);
          v25 = *(float *)(a2 + 88) + COERCE_FLOAT(v23 ^ _mask__NegFloat_);
          *(float *)v40 = v24;
          *(float *)&v40[2] = v25;
          v40[3] = 0;
          v7 = (float *)v40;
          break;
        default:
          goto LABEL_19;
      }
    }
    else
    {
      v4 = *(float *)(a2 + 104);
      v5 = *(float *)(a2 + 80) + *(float *)(a2 + 96);
      *(float *)&v39[1] = *(float *)(a2 + 84) + *(float *)(a2 + 100);
      v6 = *(float *)(a2 + 88) + v4;
      *(float *)v39 = v5;
      *(float *)&v39[2] = v6;
      v39[3] = 0;
      v7 = (float *)v39;
    }
    v30 = *v7;
    v26 = v7 + 1;
    v31 = *v26;
    v32 = v26[1];
LABEL_19:
    if ( v29 > 0 )
      break;
LABEL_23:
    if ( ++v2 >= 8 )
      return 1;
  }
  v27 = (float *)(*(_DWORD *)(a2 + 48) + 24);
  while ( (float)((float)((float)((float)(v32 * v27[1]) + (float)(v31 * *v27)) + (float)(v30 * *(v27 - 1))) + v27[2]) <= 0.0 )
  {
    ++v3;
    v27 += 9;
    if ( v3 >= v29 )
      goto LABEL_23;
  }
  return 0;
}
