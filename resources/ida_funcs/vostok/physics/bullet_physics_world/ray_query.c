void __thiscall vostok::physics::bullet_physics_world::ray_query(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::distance_predicate *ray_from,
        const vostok::math::float3 *ray_dir,
        float ray_length,
        vostok::vectora<vostok::physics::closest_ray_result> *results,
        unsigned __int16 filter_group,
        unsigned __int16 filter_mask)
{
  float z; // xmm2_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v11; // xmm5_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  btCollisionWorld::AllHitsRayResultCallback *v14; // ecx
  int v15; // ebx
  btVector3 *m_data; // ecx
  btVector3 *v17; // edx
  int v18; // edi
  int v19; // eax
  int v20; // xmm0_4
  float v21; // xmm0_4
  vostok::physics::closest_ray_result *M_finish; // eax
  const stlp_std::__true_type *v23; // [esp+4E4h] [ebp-140h]
  unsigned int v24; // [esp+4E8h] [ebp-13Ch]
  bool v25; // [esp+4ECh] [ebp-138h]
  int m_size; // [esp+4F8h] [ebp-12Ch]
  unsigned __int64 v27; // [esp+4FCh] [ebp-128h]
  __int64 v28; // [esp+508h] [ebp-11Ch]
  btVector3 rayToWorld; // [esp+514h] [ebp-110h] BYREF
  btVector3 rayFromWorld; // [esp+524h] [ebp-100h] BYREF
  vostok::physics::closest_ray_result __x; // [esp+53Ch] [ebp-E8h] BYREF
  btCollisionWorld::AllHitsRayResultCallback v32; // [esp+564h] [ebp-C0h] BYREF

  z = ray_from->m_from.z;
  x = ray_from->m_from.x;
  y = ray_from->m_from.y;
  v11 = ray_dir->z;
  v12 = ray_dir->y;
  rayFromWorld.mVec128.m128_f32[2] = -z;
  rayFromWorld.mVec128.m128_i32[3] = 0;
  v13 = ray_dir->x;
  rayFromWorld.mVec128.m128_u64[0] = __PAIR64__(LODWORD(y), LODWORD(x));
  rayToWorld.mVec128.m128_f32[0] = x + (float)(v13 * ray_length);
  rayToWorld.mVec128.m128_f32[1] = y + (float)(v12 * ray_length);
  rayToWorld.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(-(float)(z + (float)(v11 * ray_length)));
  btCollisionWorld::AllHitsRayResultCallback::AllHitsRayResultCallback(&v32, &rayFromWorld, &rayToWorld);
  v32.m_flags |= 2u;
  v32.m_collisionFilterGroup = filter_group;
  v32.m_collisionFilterMask = filter_mask;
  this->m_dynamicsWorld->rayTest(this->m_dynamicsWorld, &rayFromWorld, &rayToWorld, &v32);
  if ( v32.m_collisionObject )
  {
    v15 = 0;
    m_size = v32.m_collisionObjects.m_size;
    if ( v32.m_collisionObjects.m_size > 0 )
    {
      m_data = v32.m_hitPointWorld.m_data;
      v17 = v32.m_hitNormalWorld.m_data;
      v18 = 0;
      do
      {
        v27 = m_data[v18].mVec128.m128_u64[0];
        __x.hit_point_world.z = -m_data[v18].mVec128.m128_f32[2];
        __x.object = (vostok::physics::base_physics_object *)v32.m_collisionObjects.m_data[v15]->m_userObjectPointer;
        v19 = v32.m_triangleIndex.m_data[v15];
        *(_QWORD *)&__x.hit_point_world.x = v27;
        v20 = v17[v18].mVec128.m128_i32[0];
        __x.triangle_index = v19;
        LODWORD(v28) = v20;
        HIDWORD(v28) = v17[v18].mVec128.m128_i32[1];
        v21 = -v17[v18].mVec128.m128_f32[2];
        __x.is_shape_index = v32.m_is_shape_index.m_data[v15];
        __x.hit_normal_world.z = v21;
        M_finish = results->_M_impl._M_finish;
        *(_QWORD *)&__x.hit_normal_world.x = v28;
        __x.fraction = v32.m_closestHitFraction;
        if ( M_finish == results->_M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<vostok::physics::closest_ray_result>>::_M_insert_overflow(
            (stlp_std::priv::_Impl_vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<vostok::physics::closest_ray_result> > *)&__x,
            (unsigned __int8 **)results,
            M_finish,
            (int)&__x,
            v23,
            v24,
            v25);
          m_data = v32.m_hitPointWorld.m_data;
          v17 = v32.m_hitNormalWorld.m_data;
        }
        else
        {
          if ( M_finish )
          {
            *(_QWORD *)&M_finish->object = *(_QWORD *)&__x.object;
            *(_QWORD *)&M_finish->hit_point_world.elements[1] = *(_QWORD *)&__x.hit_point_world.elements[1];
            *(_QWORD *)&M_finish->hit_normal_world.x = v28;
            *(_QWORD *)&M_finish->hit_normal_world.elements[2] = *(_QWORD *)&__x.hit_normal_world.elements[2];
            *(_QWORD *)&M_finish->is_shape_index = *(_QWORD *)&__x.is_shape_index;
            m_data = v32.m_hitPointWorld.m_data;
            v17 = v32.m_hitNormalWorld.m_data;
          }
          ++results->_M_impl._M_finish;
        }
        ++v15;
        ++v18;
      }
      while ( v15 < m_size );
    }
    stlp_std::sort<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(
      results->_M_impl._M_start,
      results->_M_impl._M_finish,
      *ray_from);
  }
  btCollisionWorld::AllHitsRayResultCallback::~AllHitsRayResultCallback(v14, (int)&v32);
}
