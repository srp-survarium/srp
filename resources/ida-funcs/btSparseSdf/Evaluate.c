float __userpurge btSparseSdf<3>::Evaluate@<xmm0>(
        btSparseSdf<3> *this@<ecx>,
        float *eax0@<eax>,
        btCollisionShape *shape,
        btVector3 *normal,
        float margin)
{
  float v6; // xmm1_4
  float v8; // xmm0_4
  unsigned int v9; // ecx
  btGjkEpaSolver2::sResults *v10; // ebx
  btSparseSdf<3>::Cell *status; // edi
  btSparseSdf<3>::Cell *v12; // eax
  btMatrix3x3 *v13; // ecx
  int i; // ecx
  int v15; // edx
  int v16; // eax
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm7_4
  float v20; // xmm6_4
  float v21; // xmm2_4
  float v22; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm3_4
  float f; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm2_4
  float v31; // xmm5_4
  float v32; // xmm0_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm3_4
  float v36; // xmm1_4
  float v37; // xmm0_4
  btMatrix3x3 *v39; // [esp-10h] [ebp-94h]
  btSparseSdf<3>::Cell *v40; // [esp+8h] [ebp-7Ch]
  unsigned int v41; // [esp+Ch] [ebp-78h]
  float v42; // [esp+Ch] [ebp-78h]
  btSparseSdf<3>::IntFrac y; // [esp+10h] [ebp-74h] BYREF
  btSparseSdf<3>::IntFrac z; // [esp+1Ch] [ebp-68h] BYREF
  btSparseSdf<3>::IntFrac v45; // [esp+28h] [ebp-5Ch] BYREF
  float v46; // [esp+34h] [ebp-50h]
  float v47; // [esp+38h] [ebp-4Ch]
  float v48; // [esp+3Ch] [ebp-48h]
  float v49; // [esp+40h] [ebp-44h]
  float v50; // [esp+54h] [ebp-30h]
  float v51; // [esp+58h] [ebp-2Ch]
  float v52; // [esp+5Ch] [ebp-28h]
  int v53; // [esp+60h] [ebp-24h]
  float v54; // [esp+64h] [ebp-20h]
  float v55; // [esp+70h] [ebp-14h]
  float v56; // [esp+74h] [ebp-10h]
  float v57; // [esp+78h] [ebp-Ch]
  float v58; // [esp+7Ch] [ebp-8h]
  float v59; // [esp+80h] [ebp-4h]

  v6 = *eax0;
  v8 = s_bm_current_air_resistance / this->voxelsz;
  v51 = eax0[1] * v8;
  v52 = eax0[2] * v8;
  btSparseSdf<3>::Decompose(&v45, v6 * v8);
  btSparseSdf<3>::Decompose(&y, v51);
  btSparseSdf<3>::Decompose(&z, v52);
  v9 = btSparseSdf<3>::Hash(v45.b, y.b, z.b, shape);
  v41 = v9;
  v10 = (btGjkEpaSolver2::sResults *)&this->cells.m_data[v9 % this->cells.m_size];
  status = (btSparseSdf<3>::Cell *)v10->status;
  ++this->nqueries;
  if ( !status )
    goto LABEL_9;
  do
  {
    ++this->nprobes;
    if ( status->hash == v9
      && status->c[0] == v45.b
      && status->c[1] == y.b
      && status->c[2] == z.b
      && status->pclient == shape )
    {
      break;
    }
    status = status->next;
  }
  while ( status );
  if ( !status )
  {
LABEL_9:
    ++this->nprobes;
    ++this->ncells;
    v12 = (btSparseSdf<3>::Cell *)operator new(0x11Cu);
    v13 = v39;
    v40 = v12;
    if ( v12 )
    {
      memset((int)v12, 0, sizeof(btSparseSdf<3>::Cell));
      status = v40;
    }
    else
    {
      status = 0;
    }
    status->next = (btSparseSdf<3>::Cell *)v10->status;
    v10->status = (btGjkEpaSolver2::sResults::eStatus)status;
    status->pclient = shape;
    status->hash = v41;
    status->c[0] = v45.b;
    status->c[1] = y.b;
    status->c[2] = z.b;
    btSparseSdf<3>::BuildCell(this, status, v13, v10);
  }
  i = y.i;
  v15 = z.i;
  status->puid = this->puid;
  v16 = v15 + 4 * (i + 4 * v45.i);
  v17 = status->d[1][1][v16 + 1];
  v18 = status->d[0][1][v16];
  v19 = status->d[0][0][v16];
  v20 = status->d[0][0][v16 + 1];
  v57 = status->d[1][0][v16 + 1];
  v58 = v17;
  v21 = status->d[1][0][v16];
  v59 = status->d[0][1][v16 + 1];
  v56 = v20;
  v22 = status->d[1][1][v16];
  v55 = v18;
  v23 = v22 - v18;
  v50 = v18 - v19;
  v52 = v59 - v20;
  v46 = v20 - v19;
  v47 = v57 - v21;
  v24 = v57 - v20;
  v48 = v59 - v55;
  v25 = v58 - v22;
  v26 = (float)(v22 - v21) - (float)(v55 - v19);
  v42 = v58 - v59;
  v49 = v25;
  v27 = v21 - v19;
  v54 = v19;
  f = v45.f;
  v29 = (float)((float)((float)((float)((float)((float)(v58 - v59) - v24) * y.f) + v24)
                      - (float)((float)((float)(v23 - v27) * y.f) + v27))
              * z.f)
      + (float)((float)((float)(v23 - v27) * y.f) + v27);
  v30 = (float)((float)((float)((float)((float)((float)(v58 - v57) - v52) * v45.f) + v52)
                      - (float)((float)(v26 * v45.f) + v50))
              * z.f)
      + (float)((float)(v26 * v45.f) + v50);
  normal->mVec128.m128_f32[0] = v29;
  normal->mVec128.m128_f32[1] = v30;
  v31 = (float)((float)((float)((float)((float)(v49 - v48) * f) + v48) - (float)((float)((float)(v47 - v46) * f) + v46))
              * y.f)
      + (float)((float)((float)(v47 - v46) * f) + v46);
  v32 = s_bm_current_air_resistance / fsqrt((float)((float)(v31 * v31) + (float)(v30 * v30)) + (float)(v29 * v29));
  normal->mVec128.m128_f32[2] = v31;
  v53 = 0;
  v51 = v30 * v32;
  v33 = v45.f;
  v52 = v31 * v32;
  normal->mVec128.m128_f32[0] = v29 * v32;
  normal->mVec128.m128_f32[1] = v51;
  v34 = (float)(v42 * v33) + v59;
  normal->mVec128.m128_f32[2] = v52;
  v35 = (float)(v27 * v33) + v54;
  v36 = (float)((float)((float)(v23 * v33) + v55) - v35) * y.f;
  v37 = (float)((float)(v34 - (float)((float)(v24 * v33) + v56)) * y.f) + (float)((float)(v24 * v33) + v56);
  normal->mVec128.m128_i32[3] = v53;
  return (float)((float)((float)(v37 - (float)(v36 + v35)) * z.f) + (float)(v36 + v35)) - margin;
}
