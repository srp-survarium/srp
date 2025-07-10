void __cdecl vostok::physics::get_non_compound_shapes_centers(
        btCollisionShape *shape,
        const btTransform *transform,
        vostok::vectora<vostok::math::float3> *centres_results)
{
  stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3> > *v3; // ecx
  btCollisionShape *v4; // eax
  vostok::math::float3 *M_finish; // eax
  int v6; // ecx
  int m_shapeType; // ebx
  int v8; // edi
  btCollisionShape_vtbl *v9; // eax
  float v10; // xmm5_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  char *v16; // eax
  float v17; // xmm7_4
  int v18; // xmm6_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm6_4
  float v25; // xmm5_4
  int v26; // xmm6_4
  float v27; // xmm3_4
  unsigned int v28; // xmm3_4
  unsigned int v29; // xmm4_4
  unsigned int v30; // xmm5_4
  float v31; // xmm7_4
  float v32; // xmm7_4
  int v33; // xmm6_4
  const stlp_std::__true_type *v34; // [esp+D0h] [ebp-A0h]
  unsigned int v35; // [esp+D4h] [ebp-9Ch]
  bool v36; // [esp+D8h] [ebp-98h]
  float v37; // [esp+DCh] [ebp-94h]
  __m128i __x; // [esp+E0h] [ebp-90h] BYREF
  float v39; // [esp+F0h] [ebp-80h]
  float v40; // [esp+F4h] [ebp-7Ch]
  float v41; // [esp+F8h] [ebp-78h]
  float v42; // [esp+FCh] [ebp-74h]
  __m128i v43; // [esp+100h] [ebp-70h] BYREF
  __m128i v44; // [esp+110h] [ebp-60h] BYREF
  __m128i v45; // [esp+120h] [ebp-50h] BYREF
  btTransform v46; // [esp+130h] [ebp-40h] BYREF

  v4 = shape;
  if ( shape->m_shapeType == 31 )
  {
    m_shapeType = shape[1].m_shapeType;
    if ( m_shapeType )
    {
      __x.m128i_i32[3] = 0;
      v8 = 0;
      while ( 1 )
      {
        v9 = v4[2].__vftable;
        v10 = *(float *)((char *)&v9->serializeSingleShape + v8);
        v11 = *(float *)((char *)&v9->serialize + v8);
        v12 = transform->m_basis.m_el[0].mVec128.m128_f32[1];
        v13 = transform->m_basis.m_el[0].mVec128.m128_f32[0];
        v14 = *(float *)((char *)&v9[1].~btCollisionShape + v8);
        v15 = transform->m_basis.m_el[0].mVec128.m128_f32[2];
        v16 = (char *)v9 + v8;
        v17 = transform->m_basis.m_el[1].mVec128.m128_f32[2];
        *(float *)__x.m128i_i32 = (float)((float)((float)(transform->m_basis.m_el[0].mVec128.m128_f32[0] * v11)
                                                + (float)(v12 * v10))
                                        + (float)(v15 * v14))
                                + transform->m_origin.mVec128.m128_f32[0];
        *(float *)&v18 = (float)((float)((float)(transform->m_basis.m_el[1].mVec128.m128_f32[1] * v10)
                                       + (float)(v17 * v14))
                               + (float)(v11 * transform->m_basis.m_el[1].mVec128.m128_f32[0]))
                       + transform->m_origin.mVec128.m128_f32[1];
        v19 = v11 * transform->m_basis.m_el[2].mVec128.m128_f32[0];
        __x.m128i_i32[1] = v18;
        v20 = transform->m_basis.m_el[2].mVec128.m128_f32[1] * v10;
        v21 = *((float *)v16 + 1) * transform->m_basis.m_el[2].mVec128.m128_f32[0];
        v22 = transform->m_basis.m_el[2].mVec128.m128_f32[2] * v14;
        v23 = *((float *)v16 + 10);
        v24 = v20 + v22;
        v25 = *((float *)v16 + 6);
        *(float *)&v26 = (float)(v24 + v19) + transform->m_origin.mVec128.m128_f32[2];
        v27 = transform->m_basis.m_el[2].mVec128.m128_f32[1];
        __x.m128i_i32[2] = v26;
        *(float *)&v28 = (float)((float)(v27 * v25) + (float)(transform->m_basis.m_el[2].mVec128.m128_f32[2] * v23))
                       + (float)(*((float *)v16 + 2) * transform->m_basis.m_el[2].mVec128.m128_f32[0]);
        *(float *)&v29 = (float)((float)(transform->m_basis.m_el[2].mVec128.m128_f32[1] * *((float *)v16 + 5))
                               + (float)(transform->m_basis.m_el[2].mVec128.m128_f32[2] * *((float *)v16 + 9)))
                       + v21;
        *(float *)&v30 = (float)((float)(transform->m_basis.m_el[2].mVec128.m128_f32[1] * *((float *)v16 + 4))
                               + (float)(transform->m_basis.m_el[2].mVec128.m128_f32[2] * *((float *)v16 + 8)))
                       + (float)(*(float *)v16 * transform->m_basis.m_el[2].mVec128.m128_f32[0]);
        v31 = transform->m_basis.m_el[1].mVec128.m128_f32[1];
        v42 = (float)((float)(v31 * *((float *)v16 + 6))
                    + (float)(transform->m_basis.m_el[1].mVec128.m128_f32[2] * *((float *)v16 + 10)))
            + (float)(*((float *)v16 + 2) * transform->m_basis.m_el[1].mVec128.m128_f32[0]);
        v37 = v31 * *((float *)v16 + 5);
        v32 = transform->m_basis.m_el[1].mVec128.m128_f32[1];
        v39 = (float)(v37 + (float)(transform->m_basis.m_el[1].mVec128.m128_f32[2] * *((float *)v16 + 9)))
            + (float)(*((float *)v16 + 1) * transform->m_basis.m_el[1].mVec128.m128_f32[0]);
        v40 = (float)((float)(v32 * *((float *)v16 + 4))
                    + (float)(transform->m_basis.m_el[1].mVec128.m128_f32[2] * *((float *)v16 + 8)))
            + (float)(*(float *)v16 * transform->m_basis.m_el[1].mVec128.m128_f32[0]);
        v41 = (float)((float)(v13 * *((float *)v16 + 2)) + (float)(v12 * *((float *)v16 + 6)))
            + (float)(v15 * *((float *)v16 + 10));
        *(float *)&v33 = (float)((float)(v13 * *((float *)v16 + 1)) + (float)(v12 * *((float *)v16 + 5)))
                       + (float)(v15 * *((float *)v16 + 9));
        *(float *)v43.m128i_i32 = (float)((float)(v13 * *(float *)v16) + (float)(v12 * *((float *)v16 + 4)))
                                + (float)(v15 * *((float *)v16 + 8));
        v44.m128i_i64[0] = __PAIR64__(LODWORD(v39), LODWORD(v40));
        v43.m128i_i64[1] = LODWORD(v41);
        v43.m128i_i32[1] = v33;
        v44.m128i_i64[1] = LODWORD(v42);
        v45.m128i_i64[0] = __PAIR64__(v29, v30);
        v45.m128i_i64[1] = v28;
        v46.m_basis.m_el[0] = (btVector3)_mm_load_si128(&v43);
        v46.m_basis.m_el[1] = (btVector3)_mm_load_si128(&v44);
        v46.m_basis.m_el[2] = (btVector3)_mm_load_si128(&v45);
        v46.m_origin = (btVector3)_mm_load_si128(&__x);
        vostok::physics::get_non_compound_shapes_centers(*((btCollisionShape **)v16 + 16), &v46, centres_results);
        v8 += 80;
        if ( !--m_shapeType )
          break;
        v4 = shape;
      }
    }
  }
  else
  {
    __x.m128i_i64[0] = transform->m_origin.mVec128.m128_i64[0];
    M_finish = centres_results->_M_impl._M_finish;
    *(float *)&__x.m128i_i32[2] = -transform->m_origin.mVec128.m128_f32[2];
    if ( M_finish == centres_results->_M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::math::float3,vostok::vectora_allocator<vostok::math::float3>>::_M_insert_overflow(
        v3,
        (unsigned __int8 **)centres_results,
        (int)M_finish,
        (const vostok::math::float3 *)&__x,
        v34,
        v35,
        v36);
    }
    else
    {
      if ( M_finish )
      {
        v6 = __x.m128i_i32[2];
        *(_QWORD *)&M_finish->x = __x.m128i_i64[0];
        LODWORD(M_finish->z) = v6;
      }
      ++centres_results->_M_impl._M_finish;
    }
  }
}
