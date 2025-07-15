void __fastcall vostok::render::cloud_simulation::cloud_simulation(
        unsigned int in_size_z,
        unsigned int in_size_y,
        vostok::render::cloud_simulation *this,
        unsigned int in_size_x)
{
  unsigned int v4; // esi
  unsigned int *v5; // eax
  vostok::render::cloud_simulation::voxel *v6; // edi
  unsigned int v7; // esi
  unsigned int *v8; // eax
  float *v9; // eax
  float *v10; // edx
  float *i; // ecx
  vostok::math::float4x4 v12; // [esp+18h] [ebp-44h] BYREF

  this->m_clouds_size_x = in_size_x;
  v4 = in_size_z * in_size_y * in_size_x;
  this->m_clouds_size_y = in_size_y;
  this->m_clouds_size_z = in_size_z;
  v5 = (unsigned int *)vostok::memory::doug_lea_allocator::malloc_impl(
                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                         4 * v4 + 8);
  *v5++ = v4;
  v6 = (vostok::render::cloud_simulation::voxel *)(v5 + 1);
  *v5 = 4;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v5[v4 + 1]);
  v7 = this->m_clouds_size_x * this->m_clouds_size_z * this->m_clouds_size_y;
  this->m_voxels = v6;
  v8 = (unsigned int *)vostok::memory::doug_lea_allocator::malloc_impl(
                         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                         4 * v7 + 8);
  *v8 = v7;
  v9 = (float *)(v8 + 2);
  *((_DWORD *)v9 - 1) = 4;
  v10 = &v9[v7];
  for ( i = v9; i != v10; ++i )
  {
    if ( i )
      *i = 0.0;
  }
  this->m_densities = v9;
  *(_QWORD *)&this->cloud_offset.x = 0;
  this->cloud_offset.z = 0.0;
  qmemcpy((void *)&this->world_to_cloud, vostok::math::float4x4::identity(&v12), sizeof(this->world_to_cloud));
  this->interp_alpha = 0.0;
}
