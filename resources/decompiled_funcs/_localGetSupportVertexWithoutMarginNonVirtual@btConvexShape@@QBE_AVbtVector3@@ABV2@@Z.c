btVector3 *__thiscall btConvexShape::localGetSupportVertexWithoutMarginNonVirtual(
        btConvexShape *this,
        btVector3 *result,
        const btVector3 *localDir)
{
  btVector3 *v4; // eax
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  btConvexShape *v10; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  int v14; // ecx
  int v15; // ecx
  __int64 v16; // xmm0_8
  btConvexShape *v17; // ecx
  btConvexShape_vtbl *v18; // ecx
  int v19; // ebx
  int v20; // edi
  int v21; // esi
  long double v22; // st7
  bool v23; // cc
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  btConvexShape_vtbl *v28; // edi
  float v29; // xmm1_4
  float v30; // xmm1_4
  const vostok::math::float4x4 *v31; // xmm7_4
  float v32; // xmm6_4
  float v33; // xmm5_4
  long double v34; // st7
  void *m_userPointer; // xmm4_4
  btConvexShape_vtbl *v36; // xmm2_4
  int v37; // xmm3_4
  btConvexShape_vtbl *v38; // xmm2_4
  float v39; // xmm3_4
  void *v40; // xmm4_4
  btConvexShape_vtbl *v41; // xmm2_4
  int v42; // xmm3_4
  btConvexShape_vtbl *v43; // xmm2_4
  int v44; // xmm3_4
  btConvexShape_vtbl *v45; // eax
  float v46; // [esp+3ECh] [ebp-54h]
  float v47; // [esp+3ECh] [ebp-54h]
  int v48; // [esp+3F0h] [ebp-50h]
  float v49; // [esp+3F0h] [ebp-50h]
  float v50; // [esp+3F4h] [ebp-4Ch]
  float v51; // [esp+3F8h] [ebp-48h]
  float v52; // [esp+3FCh] [ebp-44h]
  float _X; // [esp+3FCh] [ebp-44h]
  __m128i v54; // [esp+400h] [ebp-40h] BYREF
  __m128i v55; // [esp+410h] [ebp-30h]
  __m128i v56; // [esp+420h] [ebp-20h] BYREF
  float v57; // [esp+438h] [ebp-8h]

  switch ( this->m_shapeType )
  {
    case 0:
      v5 = *(float *)&this[2].m_userPointer;
      if ( localDir->mVec128.m128_f32[2] < 0.0 )
        v5 = -v5;
      v6 = *(float *)&this[2].m_shapeType;
      if ( localDir->mVec128.m128_f32[1] < 0.0 )
        v6 = -v6;
      v7 = *(float *)&this[2].__vftable;
      if ( localDir->mVec128.m128_f32[0] < 0.0 )
        v7 = -v7;
      v4 = result;
      result->mVec128.m128_f32[0] = v7;
      result->mVec128.m128_f32[1] = v6;
      result->mVec128.m128_u64[1] = LODWORD(v5);
      return v4;
    case 1:
      v8 = localDir->mVec128.m128_f32[1];
      v9 = localDir->mVec128.m128_f32[2];
      v10 = this + 5;
      v11 = (float)((float)(*(float *)&this[5].m_shapeType * v8) + (float)(*(float *)&this[5].m_userPointer * v9))
          + (float)(*(float *)&this[5].__vftable * localDir->mVec128.m128_f32[0]);
      v12 = (float)((float)(*(float *)&this[6].m_shapeType * v8) + (float)(*(float *)&this[6].m_userPointer * v9))
          + (float)(*(float *)&this[6].__vftable * localDir->mVec128.m128_f32[0]);
      v13 = (float)((float)(*(float *)&this[7].m_shapeType * v8) + (float)(*(float *)&this[7].m_userPointer * v9))
          + (float)(*(float *)&this[7].__vftable * localDir->mVec128.m128_f32[0]);
      if ( v12 > v11 )
      {
        if ( v13 <= v12 )
        {
          v14 = 1;
          goto LABEL_16;
        }
        goto LABEL_14;
      }
      if ( v13 > v11 )
      {
LABEL_14:
        v14 = 2;
        goto LABEL_16;
      }
      v14 = 0;
LABEL_16:
      v15 = v14;
      v16 = *(_QWORD *)&v10[v15].__vftable;
      v17 = &v10[v15];
      v4 = result;
      v56.m128i_i64[0] = v16;
      v56.m128i_i64[1] = *(_QWORD *)&v17->m_userPointer;
      result->mVec128.m128_i32[0] = v16;
      *(unsigned __int64 *)((char *)result->mVec128.m128_u64 + 4) = *(unsigned __int64 *)((char *)v56.m128i_u64 + 4);
      result->mVec128.m128_i32[3] = 0;
      return v4;
    case 4:
      v45 = (btConvexShape_vtbl *)*((_DWORD *)&this[8].btCollisionShape + 3);
      goto LABEL_39;
    case 5:
      v45 = this[8].__vftable;
LABEL_39:
      convexHullSupport((const btVector3 *)&this[1], localDir, result, (const btVector3 *)v45, this[8].m_shapeType);
      return result;
    case 8:
      v4 = result;
      result->mVec128.m128_u64[0] = 0;
      result->mVec128.m128_u64[1] = 0;
      return v4;
    case 0xA:
      v26 = localDir->mVec128.m128_f32[1];
      v27 = localDir->mVec128.m128_f32[2];
      v28 = this[4].__vftable;
      v29 = *((float *)&this[2].__vftable + (_DWORD)v28);
      v56.m128i_i32[0] = localDir->mVec128.m128_i32[0];
      v56.m128i_i64[1] = LODWORD(v27);
      v47 = -9.9999998e17;
      *(float *)&v56.m128i_i32[1] = v26;
      v54 = _mm_load_si128(&v56);
      v49 = v29;
      v55.m128i_i64[0] = 0;
      v55.m128i_i32[2] = 0;
      _X = (float)((float)(*(float *)v56.m128i_i32 * *(float *)v56.m128i_i32) + (float)(v27 * v27)) + (float)(v26 * v26);
      v30 = *((float *)&this[2].__vftable + ((int)&v28->~btConvexShape + 2) % 3);
      if ( _X >= 0.000099999997 )
      {
        v30 = *((float *)&this[2].__vftable + ((int)&v28->~btConvexShape + 2) % 3);
        v34 = 1.0 / sqrtf(_X);
        *(float *)v54.m128i_i32 = *(float *)v56.m128i_i32 * v34;
        v31 = (const vostok::math::float4x4 *)v54.m128i_i32[0];
        *(float *)&v54.m128i_i32[1] = *(float *)&v54.m128i_i32[1] * v34;
        v32 = *(float *)&v54.m128i_i32[1];
        *(float *)&v54.m128i_i32[2] = v34 * *(float *)&v54.m128i_i32[2];
        v33 = *(float *)&v54.m128i_i32[2];
      }
      else
      {
        v31 = clear_value;
        v32 = 0.0;
        v33 = 0.0;
      }
      m_userPointer = this[1].m_userPointer;
      memset(&v54, 0, 12);
      *(float *)&v54.m128i_i32[(_DWORD)v28] = v49;
      v36 = this[3].__vftable;
      *(float *)v56.m128i_i32 = *(float *)&v31 * *(float *)&v36;
      *(float *)&v56.m128i_i32[1] = v32 * *(float *)&v36;
      *(float *)&v37 = v33 * *(float *)&v36;
      v38 = this[1].__vftable;
      v56.m128i_i32[2] = v37;
      *(float *)&v54.m128i_i32[1] = (float)((float)((float)(*(float *)&this[1].m_shapeType * v32) * v30)
                                          + *(float *)&v54.m128i_i32[1])
                                  - *(float *)&v56.m128i_i32[1];
      v57 = (float)((float)(*(float *)&m_userPointer * v33) * v30) + *(float *)&v54.m128i_i32[2];
      *(float *)v54.m128i_i32 = (float)((float)((float)(*(float *)&v38 * *(float *)&v31) * v30) + *(float *)v54.m128i_i32)
                              - *(float *)v56.m128i_i32;
      *(float *)&v54.m128i_i32[2] = v57 - *(float *)&v37;
      v39 = (float)(v57 - *(float *)&v37) * v33;
      v54.m128i_i32[3] = 0;
      if ( (float)((float)((float)(*(float *)v54.m128i_i32 * *(float *)&v31) + (float)(*(float *)&v54.m128i_i32[1] * v32))
                 + v39) > -9.9999998e17 )
      {
        v47 = (float)((float)(*(float *)v54.m128i_i32 * *(float *)&v31) + (float)(*(float *)&v54.m128i_i32[1] * v32))
            + v39;
        v55 = _mm_load_si128(&v54);
      }
      v40 = this[1].m_userPointer;
      memset(&v54, 0, 12);
      *(float *)&v54.m128i_i32[(_DWORD)v28] = -v49;
      v41 = this[3].__vftable;
      *(float *)v56.m128i_i32 = *(float *)&v31 * *(float *)&v41;
      *(float *)&v56.m128i_i32[1] = v32 * *(float *)&v41;
      *(float *)&v42 = v33 * *(float *)&v41;
      v43 = this[1].__vftable;
      v56.m128i_i32[2] = v42;
      *(float *)&v44 = (float)((float)((float)(*(float *)&this[1].m_shapeType * v32) * v30) + *(float *)&v54.m128i_i32[1])
                     - *(float *)&v56.m128i_i32[1];
      *(float *)v54.m128i_i32 = (float)((float)((float)(*(float *)&v43 * *(float *)&v31) * v30) + *(float *)v54.m128i_i32)
                              - *(float *)v56.m128i_i32;
      v54.m128i_i32[1] = v44;
      *(float *)&v54.m128i_i32[2] = (float)((float)((float)(*(float *)&v40 * v33) * v30) + *(float *)&v54.m128i_i32[2])
                                  - *(float *)&v56.m128i_i32[2];
      v54.m128i_i32[3] = 0;
      if ( (float)((float)((float)(*(float *)v54.m128i_i32 * *(float *)&v31) + (float)(*(float *)&v44 * v32))
                 + (float)(*(float *)&v54.m128i_i32[2] * v33)) > v47 )
        v55 = _mm_load_si128(&v54);
      v4 = result;
      result->mVec128.m128_u64[0] = v55.m128i_i64[0];
      result->mVec128.m128_u64[1] = v55.m128i_u32[2];
      return v4;
    case 0xD:
      v18 = this[4].__vftable;
      v56 = (__m128i)this[2];
      v55.m128i_i64[0] = localDir->mVec128.m128_u64[0];
      v19 = 0;
      v55.m128i_i64[1] = localDir->mVec128.m128_u32[2];
      v20 = 1;
      v21 = 2;
      if ( v18 )
      {
        if ( v18 == (btConvexShape_vtbl *)1 )
        {
          v20 = 0;
          v19 = 1;
        }
        else if ( v18 == (btConvexShape_vtbl *)2 )
        {
          v19 = 2;
          v20 = 0;
          v21 = 1;
        }
      }
      else
      {
        v19 = 0;
      }
      v48 = v56.m128i_i32[v20];
      v46 = *(float *)&v56.m128i_i32[(_DWORD)v18];
      v51 = *(float *)&v55.m128i_i32[v20];
      v52 = *(float *)&v55.m128i_i32[v21];
      v22 = sqrtf((float)(v51 * v51) + (float)(v52 * v52));
      v50 = v22;
      if ( v22 == 0.0 )
      {
        v23 = *(float *)&v55.m128i_i32[v19] >= 0.0;
        v54.m128i_i32[v20] = v48;
        v25 = v46;
        if ( !v23 )
          v25 = -v46;
        v4 = result;
        *(float *)&v54.m128i_i32[v19] = v25;
        v54.m128i_i32[v21] = 0;
        result->mVec128.m128_u64[0] = v54.m128i_i64[0];
        result->mVec128.m128_u64[1] = v54.m128i_u32[2];
      }
      else
      {
        v23 = *(float *)&v55.m128i_i32[v19] >= 0.0;
        *(float *)&v54.m128i_i32[v20] = v51 * (float)(*(float *)&v48 / v50);
        v24 = v46;
        if ( !v23 )
          v24 = -v46;
        v4 = result;
        *(float *)&v54.m128i_i32[v19] = v24;
        *(float *)&v54.m128i_i32[v21] = v52 * (float)(*(float *)&v48 / v50);
        result->mVec128.m128_u64[0] = v54.m128i_i64[0];
        result->mVec128.m128_u64[1] = v54.m128i_u32[2];
      }
      return v4;
    default:
      this->localGetSupportingVertexWithoutMargin(this, result, localDir);
      return result;
  }
}
