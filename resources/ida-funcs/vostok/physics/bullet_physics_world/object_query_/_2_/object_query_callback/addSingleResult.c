double __userpurge vostok::physics::bullet_physics_world::object_query_::_2_::object_query_callback::addSingleResult@<st0>(
        vostok::physics::bullet_physics_world::object_query::__l2::object_query_callback *this@<ecx>,
        const vostok::physics::closest_ray_result *a2@<edi>,
        btCollisionWorld::LocalConvexResult *convexResult,
        bool normalInWorldSpace)
{
  float v4; // xmm5_4
  float v5; // xmm4_4
  float v6; // xmm3_4
  unsigned int v7; // xmm1_4
  unsigned int v8; // xmm2_4
  float *m_hitCollisionObject; // ecx
  btCollisionWorld::LocalShapeInfo *m_localShapeInfo; // edi
  bool m_is_shape_index; // dl
  btVector3 *p_m_hitNormalLocal; // ecx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm5_4
  float m_hitFraction; // xmm0_4
  unsigned __int64 v20; // [esp+70h] [ebp-50h] BYREF
  float v21; // [esp+78h] [ebp-48h]
  int v22; // [esp+7Ch] [ebp-44h]
  unsigned __int64 v23; // [esp+80h] [ebp-40h]
  unsigned __int64 v24; // [esp+88h] [ebp-38h]
  stlp_std::priv::_Impl_vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<vostok::physics::closest_ray_result> > v25; // [esp+98h] [ebp-28h] BYREF
  unsigned __int64 v26; // [esp+A8h] [ebp-18h]
  int v27; // [esp+B0h] [ebp-10h]
  int m_triangleIndex; // [esp+B4h] [ebp-Ch]
  bool v29; // [esp+B8h] [ebp-8h]
  float v30; // [esp+BCh] [ebp-4h]

  v4 = convexResult->m_hitPointLocal.mVec128.m128_f32[1];
  v5 = convexResult->m_hitPointLocal.mVec128.m128_f32[2];
  v6 = convexResult->m_hitPointLocal.mVec128.m128_f32[0];
  *(float *)&v7 = (float)((float)((float)(this->m_modify_result_transform.m_basis.m_el[0].mVec128.m128_f32[1] * v4)
                                + (float)(this->m_modify_result_transform.m_basis.m_el[0].mVec128.m128_f32[2] * v5))
                        + (float)(this->m_modify_result_transform.m_basis.m_el[0].mVec128.m128_f32[0] * v6))
                + this->m_modify_result_transform.m_origin.mVec128.m128_f32[0];
  *(float *)&v8 = (float)((float)((float)(this->m_modify_result_transform.m_basis.m_el[1].mVec128.m128_f32[1] * v4)
                                + (float)(this->m_modify_result_transform.m_basis.m_el[1].mVec128.m128_f32[2] * v5))
                        + (float)(v6 * this->m_modify_result_transform.m_basis.m_el[1].mVec128.m128_f32[0]))
                + this->m_modify_result_transform.m_origin.mVec128.m128_f32[1];
  v21 = -(float)((float)((float)((float)(this->m_modify_result_transform.m_basis.m_el[2].mVec128.m128_f32[1] * v4)
                               + (float)(this->m_modify_result_transform.m_basis.m_el[2].mVec128.m128_f32[2] * v5))
                       + (float)(v6 * this->m_modify_result_transform.m_basis.m_el[2].mVec128.m128_f32[0]))
               + this->m_modify_result_transform.m_origin.mVec128.m128_f32[2]);
  *(float *)&v25._M_end_of_storage._M_data = v21;
  m_hitCollisionObject = (float *)convexResult->m_hitCollisionObject;
  m_localShapeInfo = convexResult->m_localShapeInfo;
  v25._M_start = (vostok::physics::closest_ray_result *)convexResult->m_hitCollisionObject->m_userObjectPointer;
  m_triangleIndex = m_localShapeInfo->m_triangleIndex;
  m_is_shape_index = m_localShapeInfo->m_is_shape_index;
  v20 = __PAIR64__(v8, v7);
  *(_QWORD *)&v25._M_finish = __PAIR64__(v8, v7);
  v29 = m_is_shape_index;
  if ( normalInWorldSpace )
  {
    p_m_hitNormalLocal = &convexResult->m_hitNormalLocal;
  }
  else
  {
    v13 = convexResult->m_hitNormalLocal.mVec128.m128_f32[2];
    v14 = convexResult->m_hitNormalLocal.mVec128.m128_f32[1];
    v15 = convexResult->m_hitNormalLocal.mVec128.m128_f32[0];
    v16 = m_hitCollisionObject[10];
    *(float *)&v20 = (float)((float)(m_hitCollisionObject[5] * v14) + (float)(m_hitCollisionObject[6] * v13))
                   + (float)(v15 * m_hitCollisionObject[4]);
    *((float *)&v20 + 1) = (float)((float)(m_hitCollisionObject[9] * v14) + (float)(v16 * v13))
                         + (float)(m_hitCollisionObject[8] * v15);
    v21 = (float)((float)(m_hitCollisionObject[13] * v14) + (float)(m_hitCollisionObject[14] * v13))
        + (float)(m_hitCollisionObject[12] * v15);
    v22 = 0;
    p_m_hitNormalLocal = (btVector3 *)&v20;
  }
  v23 = p_m_hitNormalLocal->mVec128.m128_u64[0];
  v24 = p_m_hitNormalLocal->mVec128.m128_u64[1];
  v20 = v23;
  LODWORD(v21) = v24 ^ 0x80000000;
  v26 = v23;
  m_hitFraction = convexResult->m_hitFraction;
  v27 = v24 ^ 0x80000000;
  v30 = m_hitFraction;
  stlp_std::priv::_Impl_vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<vostok::physics::closest_ray_result>>::push_back(
    &v25,
    a2);
  return convexResult->m_hitFraction;
}
