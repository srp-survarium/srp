void __thiscall survarium::booby_trap::draw(survarium::booby_trap *this)
{
  unsigned int m_collision_geometries_count; // eax
  float x; // ecx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v4; // eax
  unsigned __int16 *v5; // edi
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // edi
  survarium::collision_geometry **v7; // eax
  vostok::particle::particle_system_instance_impl *v8; // ecx
  vostok::particle::particle_system_instance_impl *v9; // eax
  const vostok::math::float4x4 *v10; // eax
  int v11; // eax
  survarium::pure_game_effect_emitter_base *v12; // ecx
  int v13; // eax
  unsigned __int16 *v14; // edi
  char *v15; // esi
  const vostok::math::float3_pod *v16; // eax
  survarium::collision_geometry **m_collision_geometries; // ebx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v18; // edi
  vostok::render::scene_renderer *v19; // ebx
  const vostok::math::float4x4 *v20; // eax
  vostok::particle::particle_system_instance_impl *m_object; // edi
  int v22; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v23; // [esp-14h] [ebp-28h] BYREF
  const vostok::math::float4x4 *v24; // [esp-10h] [ebp-24h]
  vostok::math::float4x4 *v25; // [esp-Ch] [ebp-20h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v26; // [esp-8h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v27; // [esp-4h] [ebp-18h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v28; // [esp+Ch] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v29; // [esp+10h] [ebp-4h] BYREF

  m_collision_geometries_count = this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries_count;
  x = this[-1].m_transform.c.x;
  if ( m_collision_geometries_count == LODWORD(x) )
  {
    v14 = &this->m_group + 2 * m_collision_geometries_count;
    if ( *(_DWORD *)v14 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v15 = (char *)&this[-1].survarium::link_resolver;
        v16 = (const vostok::math::float3_pod *)((int (__thiscall *)(survarium::link_resolver *))this[-1].survarium::booby_trap_core::survarium::usable_object::survarium::link_resolver::__vftable[7].resolve_links)(&this[-1].survarium::link_resolver);
        v29.m_object = (vostok::particle::particle_system_instance_impl *)&this->m_is_active;
        if ( !vostok::math::operator==(v16 + 4, (const vostok::math::float3_pod *)&this->m_is_active) )
        {
          m_collision_geometries = this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries;
          v18 = *(const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)v14;
          v28.m_object = (vostok::particle::particle_system_instance_impl *)(m_collision_geometries + 1);
          v19 = *(vostok::render::scene_renderer **)((char *)&dword_200060
                                                   + (unsigned int)m_collision_geometries[40][5].m_subscribers._M_impl._M_finish);
          v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(int (__thiscall **)(char *))(*(_DWORD *)v15 + 28))(v15);
          v20 = (const vostok::math::float4x4 *)(*(int (__thiscall **)(char *))(*(_DWORD *)v15 + 28))(v15);
          vostok::render::scene_renderer::update_model(
            v18 + 66,
            v19,
            (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v28.m_object,
            v20,
            (const vostok::math::float4x4 *)v27);
          m_object = v29.m_object;
          v22 = (*(int (__thiscall **)(char *))(*(_DWORD *)v15 + 28))(v15) + 48;
          v29.m_object->__vftable = *(vostok::particle::particle_system_instance_impl_vtbl **)v22;
          m_object = (vostok::particle::particle_system_instance_impl *)((char *)m_object + 4);
          m_object->__vftable = *(vostok::particle::particle_system_instance_impl_vtbl **)(v22 + 4);
          m_object->type = *(_DWORD *)(v22 + 8);
        }
      }
    }
  }
  else
  {
    v4 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)*((_DWORD *)&this->m_group + m_collision_geometries_count);
    v5 = &this->m_group + 2 * LODWORD(x);
    if ( v4
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::scene_renderer::remove_model(
        v4 + 66,
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*((_DWORD *)this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries
                                                         + 40)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries
      + 1);
    }
    v6 = *(const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)v5;
    if ( v6
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v7 = this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries;
      v8 = (vostok::particle::particle_system_instance_impl *)(v7 + 1);
      v9 = *(vostok::particle::particle_system_instance_impl **)((char *)&dword_200060
                                                               + (unsigned int)v7[40][5].m_subscribers._M_impl._M_finish);
      v28.m_object = v8;
      v29.m_object = v9;
      v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((int (__thiscall *)(survarium::link_resolver *))this[-1].survarium::booby_trap_core::survarium::usable_object::survarium::link_resolver::__vftable[7].resolve_links)(&this[-1].survarium::link_resolver);
      v10 = (const vostok::math::float4x4 *)((int (__thiscall *)(survarium::link_resolver *))this[-1].survarium::booby_trap_core::survarium::usable_object::survarium::link_resolver::__vftable[7].resolve_links)(&this[-1].survarium::link_resolver);
      vostok::render::scene_renderer::add_model(
        v6 + 66,
        (vostok::render::scene_renderer *)v29.m_object,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v28.m_object,
        v10,
        (const vostok::math::float4x4 *)v27);
      v11 = ((int (__thiscall *)(survarium::link_resolver *))this[-1].survarium::booby_trap_core::survarium::usable_object::survarium::link_resolver::__vftable[7].resolve_links)(&this[-1].survarium::link_resolver)
          + 48;
      *(_DWORD *)&this->m_is_active = *(_DWORD *)v11;
      *(_DWORD *)this->gap30 = *(_DWORD *)(v11 + 4);
      this->survarium::booby_trap_core::survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = *(survarium::usable_object_vtbl **)(v11 + 8);
    }
    if ( LODWORD(this[-1].m_transform.c.x) == 2 )
    {
      v28.m_object = 0;
      v29.m_object = 0;
      v27 = &v28;
      v26 = &v29;
      v25 = (vostok::math::float4x4 *)((int (__thiscall *)(survarium::link_resolver *))this[-1].survarium::booby_trap_core::survarium::usable_object::survarium::link_resolver::__vftable[7].resolve_links)(&this[-1].survarium::link_resolver);
      v24 = (const vostok::math::float4x4 *)((int (__thiscall *)(survarium::link_resolver *))this[-1].survarium::booby_trap_core::survarium::usable_object::survarium::link_resolver::__vftable[7].resolve_links)(&this[-1].survarium::link_resolver);
      v23.m_object = v12;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v23,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_old_objects._M_impl._M_finish);
      vostok::render::scene_renderer::play_particle_system(
        (vostok::render::scene_renderer *)(this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries
                                         + 1),
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*((_DWORD *)this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries + 40) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries
      + 1,
        (const vostok::math::float4x4 *)v23.m_object,
        v24,
        v25,
        v26,
        v27);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v29);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v28);
      v13 = ((int (__thiscall *)(survarium::link_resolver *))this[-1].survarium::booby_trap_core::survarium::usable_object::survarium::link_resolver::__vftable[7].resolve_links)(&this[-1].survarium::link_resolver);
      ((void (__thiscall *)(survarium::collision_geometry **, stlp_std::priv::_STLP_alloc_proxy<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *,vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>,survarium::std_allocator<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > > *, int))(*this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries)->m_ghost_object)(
        this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries,
        &this->m_old_objects._M_impl._M_end_of_storage,
        v13 + 48);
    }
    this->survarium::booby_trap_core::survarium::collision_sensor::m_collision_geometries_count = LODWORD(this[-1].m_transform.c.x);
  }
}
