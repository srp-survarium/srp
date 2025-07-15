void __thiscall vostok::physics::bullet_physics_world::ray_query(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::distance_predicate *ray_from,
        const vostok::math::float3 *ray_dir,
        const float ray_length,
        vostok::vectora<vostok::physics::closest_ray_result> *results,
        __int16 filter_group,
        __int16 filter_mask)
{
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  vostok::physics::distance_predicate *v11; // esi
  float z; // xmm3_4
  float y; // xmm1_4
  btSoftRigidDynamicsWorld *m_dynamicsWorld; // ecx
  vostok::physics::closest_ray_result *z_low; // ecx
  int v16; // ebx
  int v17; // xmm1_4
  vostok::physics::closest_ray_result *v18; // eax
  vostok::physics::closest_ray_result *M_finish; // ebx
  float *p_y; // esi
  int v21; // eax
  int v22; // edx
  vostok::physics::closest_ray_result v23; // [esp-Ch] [ebp-14Ch]
  int v24; // [esp+1Ch] [ebp-124h]
  float v25; // [esp+1Ch] [ebp-124h]
  btVector3 v26; // [esp+20h] [ebp-120h] BYREF
  btVector3 v27; // [esp+30h] [ebp-110h] BYREF
  vostok::physics::closest_ray_result *v28; // [esp+4Ch] [ebp-F4h]
  vostok::memory::base_allocator *v29; // [esp+50h] [ebp-F0h]
  int v30; // [esp+54h] [ebp-ECh]
  stlp_std::vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<void *> > v31; // [esp+58h] [ebp-E8h] BYREF
  int v32; // [esp+68h] [ebp-D8h]
  float fraction; // [esp+6Ch] [ebp-D4h]
  int v34; // [esp+70h] [ebp-D0h]
  int v35; // [esp+74h] [ebp-CCh]
  int v36; // [esp+78h] [ebp-C8h]
  int v37; // [esp+7Ch] [ebp-C4h]
  btVector3 v38; // [esp+80h] [ebp-C0h] BYREF
  int v39; // [esp+90h] [ebp-B0h]
  int v40; // [esp+9Ch] [ebp-A4h]
  int v41; // [esp+A4h] [ebp-9Ch]
  int v42; // [esp+DCh] [ebp-64h]
  int v43; // [esp+F0h] [ebp-50h]
  int v44; // [esp+118h] [ebp-28h]
  int v45; // [esp+12Ch] [ebp-14h]

  v8 = ray_dir->z * ray_length;
  v9 = ray_dir->x * ray_length;
  v10 = ray_dir->y * ray_length;
  v11 = ray_from;
  z = ray_from->m_from.z;
  y = ray_from->m_from.y;
  v26.mVec128.m128_i32[0] = LODWORD(ray_from->m_from.x);
  v26.mVec128.m128_f32[1] = y;
  v26.mVec128.m128_u64[1] = LODWORD(z) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  v27.mVec128.m128_f32[0] = v26.mVec128.m128_f32[0] + v9;
  v27.mVec128.m128_f32[1] = y + v10;
  v27.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(z + v8) ^ (unsigned __int64)(unsigned int)_mask__NegFloat_;
  btCollisionWorld::AllHitsRayResultCallback::AllHitsRayResultCallback(
    (btCollisionWorld::AllHitsRayResultCallback *)this,
    &v38,
    &v26,
    &v27);
  m_dynamicsWorld = this->m_dynamicsWorld;
  v39 |= 2u;
  v38.mVec128.m128_i16[6] = filter_group;
  v38.mVec128.m128_i16[7] = filter_mask;
  m_dynamicsWorld->rayTest(m_dynamicsWorld, &v26, &v27, (btCollisionWorld::RayResultCallback *)&v38);
  z_low = 0;
  if ( v38.mVec128.m128_i32[2] )
  {
    v16 = 0;
    v23.triangle_index = v40;
    if ( v40 > 0 )
    {
      for ( v23.hit_normal_world.z = 0.0; ; z_low = (vostok::physics::closest_ray_result *)LODWORD(v23.hit_normal_world.z) )
      {
        v17 = *(_DWORD *)((char *)&z_low->hit_point_world.y + v43);
        v28 = *(vostok::physics::closest_ray_result **)((char *)&z_low->object + v43);
        v18 = *(vostok::physics::closest_ray_result **)(*(_DWORD *)(v41 + 4 * v16) + 248);
        v29 = *(vostok::memory::base_allocator **)((char *)&z_low->hit_point_world.x + v43);
        v30 = v17 ^ _mask__NegFloat_;
        v31._M_impl._M_finish = v28;
        v31._M_impl._M_end_of_storage.m_allocator = v29;
        v31._M_impl._M_end_of_storage._M_data = (vostok::physics::closest_ray_result *)(v17 ^ _mask__NegFloat_);
        v31._M_impl._M_start = v18;
        v35 = *(_DWORD *)(v44 + 4 * v16);
        LOBYTE(v36) = *(_BYTE *)(v45 + v16);
        v23.fraction = *(float *)((char *)&z_low->hit_point_world.x + v42);
        v24 = *(_DWORD *)((char *)&z_low->hit_point_world.y + v42) ^ _mask__NegFloat_;
        v32 = *(int *)((char *)&z_low->object + v42);
        fraction = v23.fraction;
        v34 = v24;
        v37 = v38.mVec128.m128_i32[1];
        stlp_std::vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<void *>>::push_back(
          &v31,
          (int)results);
        LODWORD(v23.hit_normal_world.z) += 16;
        if ( ++v16 >= v23.triangle_index )
          break;
      }
      v11 = ray_from;
    }
    z_low = results->_M_impl._M_start;
    M_finish = results->_M_impl._M_finish;
    *(float *)&v23.is_shape_index = v11->m_from.x;
    p_y = &v11->m_from.y;
    v23.fraction = *p_y;
    v23.triangle_index = (int)results->_M_impl._M_start;
    v25 = p_y[1];
    if ( results->_M_impl._M_start != M_finish )
    {
      v21 = M_finish - z_low;
      v22 = 0;
      while ( v21 != 1 )
      {
        ++v22;
        v21 >>= 1;
      }
      stlp_std::priv::__introsort_loop<vostok::physics::closest_ray_result *,vostok::physics::closest_ray_result,int,vostok::physics::distance_predicate>(
        z_low,
        M_finish,
        0,
        2 * v22,
        *ray_from);
      *(_QWORD *)&v23.object = *(_QWORD *)&v23.is_shape_index;
      v23.hit_point_world.y = v25;
      stlp_std::priv::__final_insertion_sort<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate>(
        M_finish,
        v23);
    }
  }
  btCollisionWorld::AllHitsRayResultCallback::~AllHitsRayResultCallback(
    (btCollisionWorld::AllHitsRayResultCallback *)z_low,
    (int)&v38);
}
