void __thiscall vostok::render::batched_geometry<vostok::render::lpv_vertex>::finalize_batch(
        vostok::render::batched_geometry<vostok::render::lpv_vertex> *this,
        int a2)
{
  vostok::render::untyped_buffer *v2; // eax
  vostok::render::untyped_buffer *v3; // eax
  vostok::render::resource_manager *v4; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::particle::particle_system_instance_impl *v6; // ecx
  int v7; // eax
  vostok::buffer_vector<vostok::render::geometry_batch> *v8; // ecx
  vostok::render::res_pass *v9; // eax
  bool v10; // zf
  vostok::render::untyped_buffer *v11; // esi
  vostok::render::untyped_buffer *v12; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp-4h] [ebp-44h] BYREF
  vostok::render::hw_buffer_pool *v14; // [esp+0h] [ebp-40h]
  vostok::render::res_geometry *geom; // [esp+10h] [ebp-30h] BYREF
  vostok::render::untyped_buffer *v16; // [esp+14h] [ebp-2Ch]
  vostok::render::untyped_buffer *ib; // [esp+18h] [ebp-28h]
  vostok::render::geometry_batch v18; // [esp+1Ch] [ebp-24h] BYREF

  if ( *(_DWORD *)(a2 + 10520) != *(_DWORD *)(a2 + 10524)
    && *(_DWORD *)(a2 + 1321252) != *(_DWORD *)((char *)&loc_142928 + a2) )
  {
    vostok::render::resource_manager::create_buffer(
      20 * ((*(_DWORD *)(a2 + 10524) - *(_DWORD *)(a2 + 10520)) / 20),
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)0x14,
      *(vostok::render::enum_buffer_type *)(a2 + 10520),
      0,
      0,
      0);
    ib = 0;
    if ( v2 )
    {
      ++v2->m_reference_count;
      ib = v2;
    }
    vostok::render::resource_manager::create_buffer(
      2 * ((*(_DWORD *)((char *)&loc_142928 + a2) - *(_DWORD *)(a2 + 1321252)) >> 1),
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)2,
      *(vostok::render::enum_buffer_type *)(a2 + 1321252),
      1,
      0,
      0);
    v16 = 0;
    if ( v3 )
    {
      ++v3->m_reference_count;
      v16 = v3;
    }
    geometry = vostok::render::resource_manager::create_geometry(
                 v4,
                 (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                 *(vostok::render::res_declaration **)(a2 + 10480),
                 (vostok::render::untyped_buffer *)0x14,
                 ib,
                 v16);
    geom = 0;
    if ( geometry )
    {
      ++geometry->m_reference_count;
      geom = geometry;
    }
    v13.m_object = v6;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v13,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_162945 + a2 + 3));
    vostok::render::geometry_batch::geometry_batch(
      (const vostok::math::aabb *)((char *)&loc_162930 + a2),
      &v18,
      (const vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&geom,
      (*(_DWORD *)((char *)&loc_142928 + a2) - *(_DWORD *)(a2 + 1321252)) >> 1,
      v13);
    vostok::buffer_vector<vostok::render::geometry_batch>::push_back(
      v8,
      (const vostok::render::geometry_batch *)(a2 + 4),
      v7);
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&v18.geometry);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v18.mtl);
    v9 = (vostok::render::res_pass *)geom;
    if ( geom )
    {
      v10 = geom->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_manager::release(vostok::quasi_singleton<vostok::render::resource_manager>::pinst, v9);
    }
    qmemcpy((char *)&loc_162930 + a2, vostok::math::create_zero_aabb(&v18.bbox), 0x18u);
    v11 = v16;
    *(_DWORD *)((char *)&loc_142928 + a2) = *(_DWORD *)(a2 + 1321252);
    *(_DWORD *)(a2 + 10524) = *(_DWORD *)(a2 + 10520);
    if ( v11 )
    {
      v10 = v11->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v11, v14);
    }
    v12 = ib;
    if ( ib )
    {
      v10 = ib->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v12, v14);
    }
  }
}


void __thiscall vostok::render::batched_geometry<vostok::render::shadow_vertex>::finalize_batch(
        vostok::render::batched_geometry<vostok::render::shadow_vertex> *this,
        int a2)
{
  vostok::render::untyped_buffer *v2; // eax
  vostok::render::untyped_buffer *v3; // eax
  vostok::render::resource_manager *v4; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::particle::particle_system_instance_impl *v6; // ecx
  int v7; // eax
  vostok::buffer_vector<vostok::render::geometry_batch> *v8; // ecx
  vostok::render::res_pass *v9; // eax
  bool v10; // zf
  vostok::render::untyped_buffer *v11; // esi
  vostok::render::untyped_buffer *v12; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp-4h] [ebp-44h] BYREF
  vostok::render::hw_buffer_pool *v14; // [esp+0h] [ebp-40h]
  vostok::render::res_geometry *geom; // [esp+10h] [ebp-30h] BYREF
  vostok::render::untyped_buffer *v16; // [esp+14h] [ebp-2Ch]
  vostok::render::untyped_buffer *ib; // [esp+18h] [ebp-28h]
  vostok::render::geometry_batch v18; // [esp+1Ch] [ebp-24h] BYREF

  if ( *(_DWORD *)(a2 + 10520) != *(_DWORD *)(a2 + 10524)
    && *(_DWORD *)((char *)&loc_202924 + a2) != *(_DWORD *)(a2 + 2107688) )
  {
    vostok::render::resource_manager::create_buffer(
      32 * ((*(_DWORD *)(a2 + 10524) - *(_DWORD *)(a2 + 10520)) >> 5),
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)0x20,
      *(vostok::render::enum_buffer_type *)(a2 + 10520),
      0,
      0,
      0);
    ib = 0;
    if ( v2 )
    {
      ++v2->m_reference_count;
      ib = v2;
    }
    vostok::render::resource_manager::create_buffer(
      2 * ((*(_DWORD *)(a2 + 2107688) - *(_DWORD *)((char *)&loc_202924 + a2)) >> 1),
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)2,
      *(vostok::render::enum_buffer_type *)((char *)&loc_202924 + a2),
      1,
      0,
      0);
    v16 = 0;
    if ( v3 )
    {
      ++v3->m_reference_count;
      v16 = v3;
    }
    geometry = vostok::render::resource_manager::create_geometry(
                 v4,
                 (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                 *(vostok::render::res_declaration **)(a2 + 10480),
                 (vostok::render::untyped_buffer *)0x20,
                 ib,
                 v16);
    geom = 0;
    if ( geometry )
    {
      ++geometry->m_reference_count;
      geom = geometry;
    }
    v13.m_object = v6;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v13,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 2238792));
    vostok::render::geometry_batch::geometry_batch(
      (const vostok::math::aabb *)(a2 + 2238768),
      &v18,
      (const vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&geom,
      (*(_DWORD *)(a2 + 2107688) - *(_DWORD *)((char *)&loc_202924 + a2)) >> 1,
      v13);
    vostok::buffer_vector<vostok::render::geometry_batch>::push_back(
      v8,
      (const vostok::render::geometry_batch *)(a2 + 4),
      v7);
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&v18.geometry);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v18.mtl);
    v9 = (vostok::render::res_pass *)geom;
    if ( geom )
    {
      v10 = geom->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_manager::release(vostok::quasi_singleton<vostok::render::resource_manager>::pinst, v9);
    }
    qmemcpy((void *)(a2 + 2238768), vostok::math::create_zero_aabb(&v18.bbox), 0x18u);
    v11 = v16;
    *(_DWORD *)(a2 + 2107688) = *(_DWORD *)((char *)&loc_202924 + a2);
    *(_DWORD *)(a2 + 10524) = *(_DWORD *)(a2 + 10520);
    if ( v11 )
    {
      v10 = v11->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v11, v14);
    }
    v12 = ib;
    if ( ib )
    {
      v10 = ib->m_reference_count-- == 1;
      if ( v10 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(v12, v14);
    }
  }
}
