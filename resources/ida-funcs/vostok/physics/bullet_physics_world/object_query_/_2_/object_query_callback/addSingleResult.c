double __thiscall vostok::physics::bullet_physics_world::object_query_::_2_::object_query_callback::addSingleResult(
        vostok::physics::bullet_physics_world::object_query::__l2::object_query_callback *this,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  float *m_hitCollisionObject; // esi
  btCollisionWorld::LocalShapeInfo *m_localShapeInfo; // edi
  btVector3 *p_m_hitNormalLocal; // esi
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float *v20; // esi
  vostok::vectora<vostok::physics::closest_ray_result> *m_results; // eax
  float m_hitFraction; // xmm0_4
  float v24; // [esp+4h] [ebp-50h] BYREF
  float v25; // [esp+8h] [ebp-4Ch]
  float v26; // [esp+Ch] [ebp-48h]
  int v27; // [esp+10h] [ebp-44h]
  float v28; // [esp+14h] [ebp-40h]
  float v29; // [esp+18h] [ebp-3Ch]
  int v30; // [esp+1Ch] [ebp-38h]
  int v31; // [esp+20h] [ebp-34h]
  stlp_std::vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<void *> > v32; // [esp+2Ch] [ebp-28h] BYREF
  float v33; // [esp+3Ch] [ebp-18h]
  float v34; // [esp+40h] [ebp-14h]
  int v35; // [esp+44h] [ebp-10h]
  int m_triangleIndex; // [esp+48h] [ebp-Ch]
  bool m_is_shape_index; // [esp+4Ch] [ebp-8h]
  float v38; // [esp+50h] [ebp-4h]

  v4 = convexResult->m_hitPointLocal.mVec128.m128_f32[1];
  v5 = convexResult->m_hitPointLocal.mVec128.m128_f32[2];
  v6 = convexResult->m_hitPointLocal.mVec128.m128_f32[0];
  v7 = (float)((float)((float)(this->m_modify_result_transform.m_basis.m_el[0].mVec128.m128_f32[1] * v4)
                     + (float)(this->m_modify_result_transform.m_basis.m_el[0].mVec128.m128_f32[2] * v5))
             + (float)(this->m_modify_result_transform.m_basis.m_el[0].mVec128.m128_f32[0] * v6))
     + this->m_modify_result_transform.m_origin.mVec128.m128_f32[0];
  v8 = v6 * this->m_modify_result_transform.m_basis.m_el[2].mVec128.m128_f32[0];
  v9 = (float)((float)((float)(this->m_modify_result_transform.m_basis.m_el[1].mVec128.m128_f32[1] * v4)
                     + (float)(this->m_modify_result_transform.m_basis.m_el[1].mVec128.m128_f32[2] * v5))
             + (float)(convexResult->m_hitPointLocal.mVec128.m128_f32[0]
                     * this->m_modify_result_transform.m_basis.m_el[1].mVec128.m128_f32[0]))
     + this->m_modify_result_transform.m_origin.mVec128.m128_f32[1];
  v10 = this->m_modify_result_transform.m_basis.m_el[2].mVec128.m128_f32[1] * v4;
  v11 = this->m_modify_result_transform.m_basis.m_el[2].mVec128.m128_f32[2];
  v24 = v7;
  v12 = (float)((float)(v10 + (float)(v11 * v5)) + v8) + this->m_modify_result_transform.m_origin.mVec128.m128_f32[2];
  v25 = v9;
  LODWORD(v26) = LODWORD(v12) ^ _mask__NegFloat_;
  *(float *)&v32._M_impl._M_finish = v7;
  *(float *)&v32._M_impl._M_end_of_storage.m_allocator = v9;
  v32._M_impl._M_end_of_storage._M_data = (vostok::physics::closest_ray_result *)(LODWORD(v12) ^ _mask__NegFloat_);
  m_hitCollisionObject = (float *)convexResult->m_hitCollisionObject;
  m_localShapeInfo = convexResult->m_localShapeInfo;
  v32._M_impl._M_start = (vostok::physics::closest_ray_result *)convexResult->m_hitCollisionObject->m_userObjectPointer;
  m_triangleIndex = m_localShapeInfo->m_triangleIndex;
  m_is_shape_index = m_localShapeInfo->m_is_shape_index;
  if ( normalInWorldSpace )
  {
    p_m_hitNormalLocal = &convexResult->m_hitNormalLocal;
  }
  else
  {
    v16 = convexResult->m_hitNormalLocal.mVec128.m128_f32[2];
    v17 = convexResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v18 = convexResult->m_hitNormalLocal.mVec128.m128_f32[0];
    v19 = m_hitCollisionObject[10];
    v24 = (float)((float)(m_hitCollisionObject[5] * v17) + (float)(m_hitCollisionObject[6] * v16))
        + (float)(v18 * m_hitCollisionObject[4]);
    v25 = (float)((float)(m_hitCollisionObject[9] * v17) + (float)(v19 * v16)) + (float)(m_hitCollisionObject[8] * v18);
    v26 = (float)((float)(m_hitCollisionObject[13] * v17) + (float)(m_hitCollisionObject[14] * v16))
        + (float)(m_hitCollisionObject[12] * v18);
    v27 = 0;
    p_m_hitNormalLocal = (btVector3 *)&v24;
  }
  v28 = p_m_hitNormalLocal->mVec128.m128_f32[0];
  v20 = &p_m_hitNormalLocal->mVec128.m128_f32[1];
  v29 = *v20++;
  v30 = *(_DWORD *)v20;
  m_results = this->m_results;
  v31 = *((_DWORD *)v20 + 1);
  v24 = v28;
  v25 = v29;
  LODWORD(v26) = v30 ^ _mask__NegFloat_;
  m_hitFraction = convexResult->m_hitFraction;
  v33 = v28;
  v34 = v29;
  v35 = v30 ^ _mask__NegFloat_;
  v38 = m_hitFraction;
  stlp_std::vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<void *>>::push_back(
    &v32,
    (int)m_results);
  return convexResult->m_hitFraction;
}
