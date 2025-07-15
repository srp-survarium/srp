float __userpurge btSparseSdf<3>::Evaluate@<xmm0>(
        btSparseSdf<3> *this@<ecx>,
        const btVector3 *x@<eax>,
        btCollisionShape *shape,
        btVector3 *normal,
        float margin)
{
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  int v10; // eax
  float v11; // xmm0_4
  int v12; // esi
  float v13; // xmm0_4
  btSparseSdf<3> *v14; // esi
  float v15; // xmm1_4
  int v16; // eax
  float v17; // xmm0_4
  int v18; // edx
  float v19; // xmm0_4
  int v20; // edx
  float v21; // xmm3_4
  int v22; // eax
  float v23; // xmm0_4
  int v24; // ebx
  float v25; // xmm0_4
  unsigned int v26; // ecx
  int v27; // edx
  btSparseSdf<3>::Cell **m_data; // eax
  unsigned __int8 *v29; // esi
  unsigned __int8 *v30; // eax
  btSparseSdf<3> *v31; // ecx
  float v32; // eax
  int v33; // edx
  int v34; // edx
  int v35; // ecx
  int v36; // eax
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // xmm4_4
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm0_4
  float v43; // xmm3_4
  long double v44; // st7
  float v45; // xmm4_4
  float v46; // xmm1_4
  float v47; // xmm2_4
  btSparseSdf<3>::Cell **v49; // [esp+2D0h] [ebp-94h]
  float v50; // [esp+2D0h] [ebp-94h]
  btVector3 pdata; // [esp+2D4h] [ebp-90h] BYREF
  float v52; // [esp+2E4h] [ebp-80h]
  int v53; // [esp+2E8h] [ebp-7Ch]
  int v54; // [esp+2ECh] [ebp-78h]
  float v55; // [esp+2F0h] [ebp-74h]
  btSparseSdf<3> *v56; // [esp+2F4h] [ebp-70h]
  int v57; // [esp+2F8h] [ebp-6Ch]
  float v58; // [esp+2FCh] [ebp-68h]
  float d[8]; // [esp+300h] [ebp-64h]
  float v60; // [esp+320h] [ebp-44h]
  int v61; // [esp+328h] [ebp-3Ch]
  float v62; // [esp+32Ch] [ebp-38h]
  float v63; // [esp+330h] [ebp-34h]
  float v64; // [esp+334h] [ebp-30h]
  float v65; // [esp+338h] [ebp-2Ch]
  float v66; // [esp+33Ch] [ebp-28h]
  float v67; // [esp+340h] [ebp-24h]
  float v68; // [esp+344h] [ebp-20h]
  float v69; // [esp+34Ch] [ebp-18h]
  float v70; // [esp+35Ch] [ebp-8h]

  v6 = *(float *)&clear_value / this->voxelsz;
  v7 = (float)(x->mVec128.m128_f32[0] * v6) * 0.33333334;
  v8 = x->mVec128.m128_f32[1] * v6;
  v9 = x->mVec128.m128_f32[2] * v6;
  if ( v7 >= 0.0 )
    v10 = 0;
  else
    v10 = (int)(float)(*(float *)&clear_value - v7);
  v11 = (float)v10 + v7;
  v12 = (int)v11;
  v13 = (float)(v11 - (float)(int)v11) * 3.0;
  v14 = (btSparseSdf<3> *)(v12 - v10);
  v15 = v8 * 0.33333334;
  v57 = (int)v13;
  v58 = v13 - (float)(int)v13;
  v56 = v14;
  if ( v15 >= 0.0 )
    v16 = 0;
  else
    v16 = (int)(float)(*(float *)&clear_value - v15);
  v17 = (float)v16 + v15;
  v18 = (int)v17;
  v19 = (float)(v17 - (float)(int)v17) * 3.0;
  v20 = v18 - v16;
  v21 = v9 * 0.33333334;
  v54 = (int)v19;
  v55 = v19 - (float)(int)v19;
  v53 = v20;
  if ( v21 >= 0.0 )
    v22 = 0;
  else
    v22 = (int)(float)(*(float *)&clear_value - v21);
  v23 = (float)v22 + v21;
  v24 = (int)v23 - v22;
  v25 = (float)(v23 - (float)(int)v23) * 3.0;
  v61 = (int)v25;
  v62 = v25 - (float)(int)v25;
  pdata.mVec128.m128_u64[0] = __PAIR64__(v20, (unsigned int)v14);
  pdata.mVec128.m128_u64[1] = __PAIR64__((unsigned int)shape, v24);
  *(float *)&v26 = COERCE_FLOAT(HsiehHash<4>(&pdata));
  v27 = v26 % this->cells.m_size;
  m_data = this->cells.m_data;
  v29 = (unsigned __int8 *)m_data[v27];
  v52 = *(float *)&v26;
  v49 = &m_data[v27];
  ++this->nqueries;
  if ( v29 )
  {
    while ( 1 )
    {
      ++this->nprobes;
      if ( *((_DWORD *)v29 + 68) == v26
        && *((btSparseSdf<3> **)v29 + 64) == v56
        && *((_DWORD *)v29 + 65) == v53
        && *((_DWORD *)v29 + 66) == v24
        && *((btCollisionShape **)v29 + 69) == shape )
      {
        break;
      }
      v29 = (unsigned __int8 *)*((_DWORD *)v29 + 70);
      if ( !v29 )
        goto LABEL_17;
    }
  }
  else
  {
LABEL_17:
    ++this->nprobes;
    ++this->ncells;
    v30 = (unsigned __int8 *)operator new(0x11Cu);
    v29 = v30;
    if ( v30 )
      memset(v30, 0, 0x11Cu);
    else
      v29 = 0;
    *((_DWORD *)v29 + 70) = *v49;
    v31 = v56;
    *v49 = (btSparseSdf<3>::Cell *)v29;
    v32 = v52;
    *((_DWORD *)v29 + 69) = shape;
    v33 = v53;
    *((float *)v29 + 68) = v32;
    *((_DWORD *)v29 + 64) = v31;
    *((_DWORD *)v29 + 65) = v33;
    *((_DWORD *)v29 + 66) = v24;
    btSparseSdf<3>::BuildCell(v31, (btSparseSdf<3>::Cell *)this);
  }
  v34 = v57;
  v35 = v54;
  *((_DWORD *)v29 + 67) = this->puid;
  v36 = v61 + 4 * (v35 + 4 * v34);
  v37 = *(float *)&v29[4 * v36];
  v38 = *(float *)&v29[4 * v36 + 4];
  v39 = *(float *)&v29[4 * v36 + 68];
  v40 = *(float *)&v29[4 * v36 + 84];
  v41 = *(float *)&v29[4 * v36 + 20];
  d[3] = *(float *)&v29[4 * v36 + 16];
  v42 = *(float *)&v29[4 * v36 + 64];
  pdata.mVec128.m128_f32[0] = v42 - v37;
  v65 = v42 - v37;
  d[7] = v41;
  pdata.mVec128.m128_f32[2] = v39 - v38;
  v66 = v39 - v38;
  d[1] = v42;
  v68 = d[3] - v37;
  d[2] = *(float *)&v29[4 * v36 + 80];
  d[0] = v37;
  d[4] = v38;
  v60 = v40 - v41;
  v70 = v41 - d[3];
  v63 = d[2] - d[3];
  v69 = v41 - v38;
  v43 = (float)((float)((float)(d[2] - v42) - (float)(d[3] - v37)) * v58) + (float)(d[3] - v37);
  v50 = (float)((float)((float)((float)((float)(v60 - pdata.mVec128.m128_f32[2]) * v55) + pdata.mVec128.m128_f32[2])
                      - (float)((float)((float)((float)(d[2] - d[3]) - pdata.mVec128.m128_f32[0]) * v55)
                              + pdata.mVec128.m128_f32[0]))
              * v62)
      + (float)((float)((float)((float)(d[2] - d[3]) - pdata.mVec128.m128_f32[0]) * v55) + pdata.mVec128.m128_f32[0]);
  v67 = (float)((float)((float)((float)((float)((float)(v40 - v39) - v69) * v58) + v69) - v43) * v62) + v43;
  v64 = (float)((float)((float)((float)((float)((float)(v40 - d[2]) - (float)(d[7] - d[3])) * v58) + (float)(d[7] - d[3]))
                      - (float)((float)((float)((float)(v39 - d[1]) - (float)(v38 - v37)) * v58) + (float)(v38 - v37)))
              * v55)
      + (float)((float)((float)((float)(v39 - d[1]) - (float)(v38 - v37)) * v58) + (float)(v38 - v37));
  v44 = sqrtf((float)((float)(v64 * v64) + (float)(v67 * v67)) + (float)(v50 * v50));
  v45 = v55;
  v52 = 1.0 / v44;
  pdata.mVec128.m128_f32[0] = v50 * v52;
  pdata.mVec128.m128_f32[1] = v67 * v52;
  v46 = v58;
  pdata.mVec128.m128_f32[2] = v64 * v52;
  pdata.mVec128.m128_i32[3] = 0;
  *normal = (btVector3)pdata.mVec128;
  v47 = (float)((float)((float)((float)(v63 * v46) + d[3]) - (float)((float)(v65 * v46) + d[0])) * v45)
      + (float)((float)(v65 * v46) + d[0]);
  return (float)((float)((float)((float)((float)((float)((float)((float)(v60 * v46) + d[7])
                                                       - (float)((float)(v66 * v46) + d[4]))
                                               * v45)
                                       + (float)((float)(v66 * v46) + d[4]))
                               - v47)
                       * v62)
               + v47)
       - margin;
}
