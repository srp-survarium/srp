void __thiscall vostok::resources::releasing_functionality::release_resource(
        vostok::resources::releasing_functionality *this,
        vostok::resources::resource_base *resource,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> a3)
{
  survarium::pure_game_effect_emitter_base *m_object; // ebx
  char v4; // al
  vostok::resources::managed_resource *v5; // esi
  vostok::resources::quality_increase_functionality *v6; // ecx
  vostok::resources::base_of_intrusive_base *v7; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v8; // [esp+10h] [ebp-8h] BYREF
  vostok::resources::quality_increase_functionality v9; // [esp+14h] [ebp-4h] BYREF

  m_object = (survarium::pure_game_effect_emitter_base *)a3.m_object;
  if ( (vostok::resources::resource_flags::cast_base_of_intrusive_base(a3.m_object)->m_flags.m_flags & 1) != 0 )
  {
    v4 = (m_object->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
        & 1)
       - 1;
    a3.m_object = 0;
    v5 = v4 == 0 ? (vostok::resources::managed_resource *)m_object : 0;
    if ( v5 )
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
      a3.m_object = v5;
      _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
    }
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v8,
      (unsigned __int8)((m_object->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                       & 4)
                      - 4) == 0
    ? m_object
    : 0);
    vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy>::erase(
      &m_object->m_memory_usage_self.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type->resources,
      m_object);
    if ( (m_object->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
        & 0x80u) != 0 )
    {
      vostok::resources::quality_increase_functionality::quality_increase_functionality(
        &v9,
        (vostok::resources::game_resources_manager_data *)resource->__vftable);
      vostok::resources::quality_increase_functionality::erase_from_increase_quality_tree(
        v6,
        (vostok::resources::resource_base_vtbl **)&v9,
        (vostok::resources::compare_by_target_satisfaction *)m_object,
        m_object);
    }
    vostok::resources::resource_base::clean_sub_fat_and_fat_it(m_object);
    v7 = vostok::resources::resource_flags::cast_base_of_intrusive_base(m_object);
    _InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF);
    _InterlockedAnd(&v7->m_flags.m_flags, 0xFFFFFFFE);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&a3);
  }
}
