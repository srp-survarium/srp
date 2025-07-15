btVector3 *__thiscall btConvexShape::localGetSupportVertexWithoutMarginNonVirtual(
        btConvexShape *this,
        btVector3 *result,
        const btVector3 *localDir)
{
  int m_shapeType; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // xmm0_4
  btConvexShape_vtbl *v13; // ebx
  int v14; // xmm0_4
  int v15; // esi
  int v16; // eax
  int v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  int v20; // edx
  float v21; // xmm3_4
  float v22; // xmm5_4
  bool v23; // cc
  float v24; // xmm2_4
  btVector3 *v25; // eax
  int v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  btConvexShape_vtbl *v29; // ecx
  int v30; // xmm4_4
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm3_4
  float v34; // xmm7_4
  float v35; // xmm1_4
  btConvexShape_vtbl *v36; // xmm2_4
  float v37; // xmm6_4
  float v38; // xmm5_4
  float v39; // xmm1_4
  int v40; // xmm2_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  void *v43; // xmm3_4
  btConvexShape_vtbl *v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  float v47; // xmm5_4
  float v48; // xmm6_4
  unsigned int v49; // xmm0_4
  btConvexShape_vtbl *v50; // edi
  float v51; // xmm4_4
  float v52; // xmm5_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  btConvexShape *v56; // esi
  unsigned int m_userPointer; // xmm3_4
  int v58; // xmm2_4
  float v59; // [esp+18h] [ebp-48h]
  float v60; // [esp+1Ch] [ebp-44h]
  unsigned __int64 v61; // [esp+20h] [ebp-40h]
  float v62; // [esp+28h] [ebp-38h]
  int v63; // [esp+2Ch] [ebp-34h]
  unsigned __int64 v64; // [esp+30h] [ebp-30h]
  int v65; // [esp+38h] [ebp-28h]
  int v66; // [esp+3Ch] [ebp-24h]
  unsigned __int64 v67; // [esp+40h] [ebp-20h]
  float v68; // [esp+48h] [ebp-18h]
  int v69; // [esp+4Ch] [ebp-14h]
  float v70; // [esp+58h] [ebp-8h]

  m_shapeType = this->m_shapeType;
  v5 = 0;
  if ( !m_shapeType )
  {
    m_userPointer = (unsigned int)this[2].m_userPointer;
    if ( localDir->mVec128.m128_f32[2] < 0.0 )
      m_userPointer ^= _mask__NegFloat_;
    v58 = this[2].m_shapeType;
    if ( localDir->mVec128.m128_f32[1] < 0.0 )
      v58 ^= _mask__NegFloat_;
    v49 = (unsigned int)this[2].__vftable;
    if ( localDir->mVec128.m128_f32[0] < 0.0 )
      v49 ^= _mask__NegFloat_;
    v25 = result;
    result->mVec128.m128_i32[1] = v58;
    result->mVec128.m128_u64[1] = m_userPointer;
    goto LABEL_52;
  }
  v6 = m_shapeType - 1;
  if ( !v6 )
  {
    v51 = localDir->mVec128.m128_f32[1];
    v52 = localDir->mVec128.m128_f32[2];
    v53 = (float)((float)(*(float *)&this[5].m_shapeType * v51) + (float)(*(float *)&this[5].m_userPointer * v52))
        + (float)(*(float *)&this[5].__vftable * localDir->mVec128.m128_f32[0]);
    v54 = (float)((float)(*(float *)&this[6].m_shapeType * v51) + (float)(*(float *)&this[6].m_userPointer * v52))
        + (float)(*(float *)&this[6].__vftable * localDir->mVec128.m128_f32[0]);
    v55 = (float)((float)(*(float *)&this[7].m_shapeType * v51) + (float)(*(float *)&this[7].m_userPointer * v52))
        + (float)(*(float *)&this[7].__vftable * localDir->mVec128.m128_f32[0]);
    if ( v54 <= v53 )
    {
      if ( v55 <= v53 )
        goto LABEL_43;
    }
    else if ( v55 <= v54 )
    {
      v5 = 1;
LABEL_43:
      v56 = &this[v5 + 5];
      v25 = result;
      LODWORD(v67) = v56->__vftable;
      v56 = (btConvexShape *)((char *)v56 + 4);
      HIDWORD(v67) = v56->__vftable;
      v56 = (btConvexShape *)((char *)v56 + 4);
      v68 = *(float *)&v56->__vftable;
      v69 = v56->m_shapeType;
      result->mVec128.m128_u64[0] = v67;
      result->mVec128.m128_f32[2] = v68;
      goto LABEL_44;
    }
    v5 = 2;
    goto LABEL_43;
  }
  v7 = v6 - 3;
  if ( !v7 )
  {
    v50 = (btConvexShape_vtbl *)*((_DWORD *)&this[8].btCollisionShape + 3);
    goto LABEL_35;
  }
  v8 = v7 - 1;
  if ( !v8 )
  {
    v50 = this[8].__vftable;
LABEL_35:
    convexHullSupport(localDir, (const btVector3 *)v50, (const btVector3 *)&this[1], result, this[8].m_shapeType);
    return result;
  }
  v9 = v8 - 3;
  if ( v9 )
  {
    v10 = 2;
    v11 = v9 - 2;
    if ( !v11 )
    {
      v27 = localDir->mVec128.m128_f32[1];
      v28 = localDir->mVec128.m128_f32[0];
      v29 = this[4].__vftable;
      v30 = *((_DWORD *)&this[2].__vftable + (_DWORD)v29);
      v68 = localDir->mVec128.m128_f32[2];
      v67 = __PAIR64__(LODWORD(v27), LODWORD(v28));
      v69 = 0;
      v61 = __PAIR64__(LODWORD(v27), LODWORD(v28));
      v62 = v68;
      v64 = 0;
      v65 = 0;
      v63 = 0;
      v59 = *((float *)&this[2].__vftable + ((int)&v29->~btConvexShape + 2) % 3);
      v60 = FLOAT_N9_9999998e17;
      v31 = (float)((float)(v28 * v28) + (float)(v68 * v68)) + (float)(v27 * v27);
      if ( v31 >= 0.000099999997 )
      {
        v35 = s_bm_current_air_resistance / fsqrt(v31);
        v32 = v28 * v35;
        v33 = *((float *)&v61 + 1) * v35;
        v34 = v62 * v35;
      }
      else
      {
        v32 = s_bm_current_air_resistance;
        v33 = 0.0;
        v34 = 0.0;
      }
      v36 = this[3].__vftable;
      v37 = v33 * *(float *)&v36;
      v61 = __PAIR64__(LODWORD(v33), LODWORD(v32));
      v38 = v32 * *(float *)&v36;
      v39 = v34 * *(float *)&v36;
      v40 = this[1].m_shapeType;
      v70 = v39;
      v41 = (float)(*(float *)&this[1].__vftable * *(float *)&v61) * v59;
      v42 = (float)(*(float *)&v40 * v33) * v59;
      v43 = this[1].m_userPointer;
      v67 = 0;
      v68 = 0.0;
      *((_DWORD *)&v67 + (_DWORD)v29) = v30;
      *(float *)&v67 = (float)(v41 + *(float *)&v67) - v38;
      *((float *)&v67 + 1) = (float)(v42 + *((float *)&v67 + 1)) - v37;
      v68 = (float)((float)((float)(*(float *)&v43 * v34) * v59) + v68) - v70;
      v62 = v34;
      v69 = 0;
      if ( (float)((float)((float)(*(float *)&v67 * *(float *)&v61)
                         + (float)(*((float *)&v67 + 1) * *((float *)&v61 + 1)))
                 + (float)(v68 * v34)) > -9.9999998e17 )
      {
        v64 = v67;
        v65 = LODWORD(v68);
        v60 = (float)((float)(*(float *)&v67 * *(float *)&v61) + (float)(*((float *)&v67 + 1) * *((float *)&v61 + 1)))
            + (float)(v68 * v34);
        v66 = v69;
      }
      v44 = this[3].__vftable;
      v45 = (float)(*(float *)&this[1].m_shapeType * *((float *)&v61 + 1)) * v59;
      v46 = (float)(*(float *)&this[1].m_userPointer * v62) * v59;
      v47 = *((float *)&v61 + 1) * *(float *)&v44;
      v48 = v62 * *(float *)&v44;
      v67 = 0;
      v68 = 0.0;
      *((_DWORD *)&v67 + (_DWORD)v29) = v30 ^ _mask__NegFloat_;
      *(float *)&v67 = (float)((float)((float)(*(float *)&this[1].__vftable * *(float *)&v61) * v59) + *(float *)&v67)
                     - (float)(*(float *)&v61 * *(float *)&v44);
      *((float *)&v67 + 1) = (float)(v45 + *((float *)&v67 + 1)) - v47;
      v68 = (float)(v46 + v68) - v48;
      v69 = 0;
      if ( (float)((float)((float)(*(float *)&v67 * *(float *)&v61)
                         + (float)(*((float *)&v67 + 1) * *((float *)&v61 + 1)))
                 + (float)(v68 * v62)) > v60 )
      {
        v64 = v67;
        v65 = LODWORD(v68);
        v66 = v69;
      }
      v25 = result;
      result->mVec128.m128_u64[0] = v64;
      v26 = v65;
      goto LABEL_21;
    }
    if ( v11 != 3 )
    {
      this->localGetSupportingVertexWithoutMargin(this, result, localDir);
      return result;
    }
    v12 = localDir->mVec128.m128_i32[0];
    v13 = this[4].__vftable;
    v67 = *(_QWORD *)&this[2].__vftable;
    v68 = *(float *)&this[2].m_userPointer;
    LODWORD(v64) = v12;
    v14 = localDir->mVec128.m128_i32[1];
    v69 = *((_DWORD *)&this[2].btCollisionShape + 3);
    HIDWORD(v64) = v14;
    v15 = 0;
    v65 = localDir->mVec128.m128_i32[2];
    v66 = 0;
    v16 = 1;
    if ( v13 )
    {
      if ( v13 != (btConvexShape_vtbl *)1 )
      {
        if ( v13 == (btConvexShape_vtbl *)2 )
        {
          v16 = 0;
          v15 = 2;
          v10 = 1;
        }
        goto LABEL_16;
      }
      v16 = 0;
      v15 = 1;
    }
    else
    {
      v15 = 0;
    }
    v10 = 2;
LABEL_16:
    v17 = *((_DWORD *)&v67 + (_DWORD)v13);
    v18 = *((float *)&v64 + v16);
    v19 = *((float *)&v67 + v16);
    v20 = 4 * v10;
    v21 = *(float *)((char *)&v64 + v20);
    v22 = fsqrt((float)(v18 * v18) + (float)(v21 * v21));
    if ( v22 == 0.0 )
    {
      v23 = *((float *)&v64 + v15) >= 0.0;
      *((float *)&v61 + v16) = v19;
      if ( !v23 )
        v17 ^= _mask__NegFloat_;
      *((_DWORD *)&v61 + v15) = v17;
      *(_DWORD *)((char *)&v61 + v20) = 0;
    }
    else
    {
      v23 = *((float *)&v64 + v15) >= 0.0;
      v24 = v19 / v22;
      *((float *)&v61 + v16) = v18 * v24;
      if ( !v23 )
        v17 ^= _mask__NegFloat_;
      *((_DWORD *)&v61 + v15) = v17;
      *(float *)((char *)&v61 + v20) = v21 * v24;
    }
    v25 = result;
    result->mVec128.m128_u64[0] = v61;
    v26 = LODWORD(v62);
LABEL_21:
    v25->mVec128.m128_i32[2] = v26;
LABEL_44:
    v25->mVec128.m128_i32[3] = 0;
    return v25;
  }
  v25 = result;
  v49 = 0;
  *(unsigned __int64 *)((char *)result->mVec128.m128_u64 + 4) = 0;
  result->mVec128.m128_i32[3] = 0;
LABEL_52:
  v25->mVec128.m128_i32[0] = v49;
  return v25;
}
