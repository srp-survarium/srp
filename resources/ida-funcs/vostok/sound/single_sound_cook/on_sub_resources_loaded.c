void __thiscall vostok::sound::single_sound_cook::on_sub_resources_loaded(
        vostok::sound::single_sound_cook *this,
        survarium::pure_game_effect_emitter_base *data,
        vostok::sound::sound_options options)
{
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v3; // ebx
  vostok::particle::particle_system_instance_impl *v4; // esi
  survarium::pure_game_effect_emitter_base *m_object; // esi
  vostok::sound::sound_spl **v6; // eax
  vostok::sound::sound_spl *v7; // ecx
  const char *v8; // eax
  _DWORD *unmanaged_memory; // esi
  survarium::pure_game_effect_emitter_base *v10; // ecx
  const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v11; // edi
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v14; // [esp-Ch] [ebp-2Ch] BYREF
  const vostok::resources::memory_type *v15; // [esp-8h] [ebp-28h]
  unsigned int v16; // [esp-4h] [ebp-24h]
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *m_uid; // [esp+10h] [ebp-10h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp+14h] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v19; // [esp+18h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> other; // [esp+1Ch] [ebp-4h] BYREF

  v3 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)data;
  m_uid = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_uid;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data[1].m_children_resources);
  v4 = (vostok::particle::particle_system_instance_impl *)data;
  other.m_object = 0;
  if ( data )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&other);
    other.m_object = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v19,
    v3 + 259);
  m_object = v19.m_object;
  data = 0;
  if ( v19.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v18,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  v7 = *v6;
  *v6 = options.spl.m_object;
  options.spl.m_object = v7;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v18);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19);
  v8 = type_info::name(&vostok::sound::single_sound `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = vostok::resources::allocate_unmanaged_memory(0x128u, v8);
  v10 = (survarium::pure_game_effect_emitter_base *)v16;
  data = (survarium::pure_game_effect_emitter_base *)unmanaged_memory;
  if ( unmanaged_memory )
  {
    vostok::sound::sound_emitter::sound_emitter((vostok::sound::sound_emitter *)v16, unmanaged_memory);
    *unmanaged_memory = &vostok::sound::single_sound::`vftable'{for `vostok::sound::sound_emitter'};
    unmanaged_memory[66] = &vostok::sound::single_sound::`vftable'{for `vostok::sound::sound_propagator_emitter'};
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)unmanaged_memory
    + 67,
      &other);
    vostok::sound::sound_options::sound_options(
      (vostok::sound::sound_options *)&data[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&options);
  }
  else
  {
    data = 0;
  }
  v16 = 296;
  v15 = &vostok::resources::nocache_memory;
  v14.m_object = v10;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v14,
    data);
  v11 = m_uid;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v12,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)m_uid,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v14.m_object,
    v15,
    v16);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v13,
    v11,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&other);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&options);
}
