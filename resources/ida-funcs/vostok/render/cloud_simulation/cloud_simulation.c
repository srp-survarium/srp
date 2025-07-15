void __fastcall vostok::render::cloud_simulation::cloud_simulation(
        unsigned int in_size_z,
        unsigned int in_size_y,
        vostok::render::cloud_simulation *this,
        unsigned int in_size_x)
{
  vostok::memory::doug_lea_allocator *v4; // esi
  unsigned int v5; // edi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  char *v8; // eax
  vostok::render::cloud_simulation::voxel *v9; // esi
  unsigned int v10; // edi
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // ecx
  char *v14; // eax
  float *v15; // eax
  float *v16; // edi
  float *i; // edx
  const char *v18; // [esp+0h] [ebp-58h]
  const char *v19; // [esp+0h] [ebp-58h]
  const char *v20; // [esp+4h] [ebp-54h]
  const char *v21; // [esp+4h] [ebp-54h]
  unsigned int v22; // [esp+8h] [ebp-50h]
  unsigned int v23; // [esp+8h] [ebp-50h]
  vostok::math::float4x4 v24; // [esp+Ch] [ebp-4Ch] BYREF
  int v25; // [esp+4Ch] [ebp-Ch]
  float v26; // [esp+50h] [ebp-8h]
  float v27; // [esp+54h] [ebp-4h]

  this->m_clouds_size_x = in_size_x;
  v4 = vostok::render::g_allocator;
  this->m_clouds_size_z = in_size_z;
  this->m_clouds_size_y = in_size_y;
  v5 = in_size_z * in_size_y * in_size_x;
  v6 = type_info::raw_name(&vostok::render::cloud_simulation::voxel `RTTI Type Descriptor');
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v4, 4 * v5 + 8, v6, v18, v20, v22);
  *(_DWORD *)v8 = v5;
  v8 += 4;
  v9 = (vostok::render::cloud_simulation::voxel *)(v8 + 4);
  *(_DWORD *)v8 = 4;
  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)4);
  v10 = this->m_clouds_size_x * this->m_clouds_size_z * this->m_clouds_size_y;
  this->m_voxels = v9;
  v11 = vostok::render::g_allocator;
  v12 = type_info::raw_name(&float `RTTI Type Descriptor');
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(v13, (int)v11, 4 * v10 + 8, v12, v19, v21, v23);
  *(_DWORD *)v14 = v10;
  v14 += 4;
  *(_DWORD *)v14 = 4;
  v15 = (float *)(v14 + 4);
  v16 = &v15[v10];
  for ( i = v15; i != v16; ++i )
  {
    if ( i )
      *i = 0.0;
  }
  v25 = 0;
  v26 = 0.0;
  v27 = 0.0;
  this->cloud_offset.x = 0.0;
  this->cloud_offset.y = v26;
  this->m_densities = v15;
  this->cloud_offset.z = v27;
  qmemcpy(
    &this->world_to_cloud,
    vostok::math::float4x4::identity((vostok::math::float4x4 *)4, &v24),
    sizeof(this->world_to_cloud));
  this->interp_alpha = 0.0;
}
