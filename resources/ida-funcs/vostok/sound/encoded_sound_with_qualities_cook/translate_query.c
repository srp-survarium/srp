void __thiscall vostok::sound::encoded_sound_with_qualities_cook::translate_query(
        vostok::sound::encoded_sound_with_qualities_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  const char *v2; // eax
  void *unmanaged_memory; // eax
  survarium::pure_game_effect_emitter_base *v4; // ecx
  survarium::pure_game_effect_emitter_base *v5; // edi
  survarium::pure_game_effect_emitter_base *v6; // eax
  unsigned int m_object; // ebp
  vostok::resources::query_result_for_cook *v8; // ecx
  float v9; // xmm0_4
  survarium::pure_game_effect_emitter_base_vtbl *v10; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v12; // [esp-8h] [ebp-18h]
  unsigned int v13; // [esp-4h] [ebp-14h]

  v2 = type_info::name(&vostok::sound::encoded_sound_with_qualities `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = vostok::resources::allocate_unmanaged_memory(0x238u, v2);
  v4 = (survarium::pure_game_effect_emitter_base *)v13;
  if ( unmanaged_memory )
  {
    vostok::sound::encoded_sound_with_qualities::encoded_sound_with_qualities(
      (vostok::sound::encoded_sound_with_qualities *)v13,
      (int)unmanaged_memory);
    v5 = v6;
  }
  else
  {
    v5 = 0;
  }
  m_object = (unsigned int)parent[32].m_object;
  v13 = 568;
  v12 = &vostok::resources::nocache_memory;
  v11.m_object = v4;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v11,
    v5);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v8,
    parent,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v11.m_object,
    v12,
    v13);
  v9 = *(float *)&parent[29].m_object;
  v10 = v5->__vftable;
  v13 = (unsigned int)parent;
  v5->m_target_quality_level = m_object;
  v5->m_target_satisfaction = v9;
  v10->increase_quality_to_target(v5, (vostok::resources::query_result_for_cook *)v13);
}
