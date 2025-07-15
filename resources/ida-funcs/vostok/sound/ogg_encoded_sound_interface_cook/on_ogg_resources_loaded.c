void __thiscall vostok::sound::ogg_encoded_sound_interface_cook::on_ogg_resources_loaded(
        vostok::sound::ogg_encoded_sound_interface_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::resources::queries_result *v3; // esi
  vostok::resources::managed_resource *v4; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v5; // ecx
  int v6; // ebx
  unsigned int v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  vostok::sound::ogg_encoded_sound_interface *unmanaged_memory; // esi
  vostok::resources::managed_resource *m_object; // ecx
  survarium::pure_game_effect_emitter_base *v12; // ecx
  const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v13; // edi
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v15; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v16; // [esp-Ch] [ebp-34h] BYREF
  assert_on_fail_bool v17; // [esp-8h] [ebp-30h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v18; // [esp-4h] [ebp-2Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+Ch] [ebp-1Ch] BYREF
  int v20; // [esp+10h] [ebp-18h]
  float *rms_data; // [esp+18h] [ebp-10h]
  unsigned int rms_length_in_msec; // [esp+1Ch] [ebp-Ch]
  unsigned int rms_count; // [esp+20h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ogg_file; // [esp+24h] [ebp-4h] BYREF

  v3 = data;
  vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[0], &ogg_file);
  vostok::resources::query_result_for_user::get_managed_resource(
    &v3->m_queries[1],
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
  v18.m_object = v4;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v18,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v5,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
    v18);
  rms_length_in_msec = *(_DWORD *)(v20 + 4);
  v6 = v20 + 8;
  rms_count = *(_DWORD *)(v20 + 8);
  v7 = 4 * rms_count;
  v8 = type_info::name(&float `RTTI Type Descriptor', &__type_info_root_node);
  rms_data = (float *)vostok::resources::allocate_unmanaged_memory(v7, v8);
  memcpy((unsigned __int8 *)rms_data, (unsigned __int8 *)(v6 + 4), v7);
  v9 = type_info::name(&vostok::sound::ogg_encoded_sound_interface `RTTI Type Descriptor', &__type_info_root_node);
  unmanaged_memory = (vostok::sound::ogg_encoded_sound_interface *)vostok::resources::allocate_unmanaged_memory(
                                                                     0x410u,
                                                                     v9);
  m_object = v18.m_object;
  if ( unmanaged_memory )
  {
    vostok::sound::ogg_encoded_sound_interface::ogg_encoded_sound_interface(
      unmanaged_memory,
      &ogg_file,
      (vostok::resources::unmanaged_resource *)v18.m_object,
      rms_data,
      rms_count,
      rms_length_in_msec);
    v18.m_object = (vostok::resources::managed_resource *)1040;
    v17 = (assert_on_fail_bool)&vostok::resources::unmanaged_memory;
    v16.m_object = v12;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v16,
      (survarium::pure_game_effect_emitter_base *)unmanaged_memory);
    v13 = (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v14,
      parent,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v16.m_object,
      (const vostok::resources::memory_type *)v17,
      (unsigned int)v18.m_object);
    v18.m_object = 0;
    v17 = assert_on_fail_true;
    v16.m_object = (survarium::pure_game_effect_emitter_base *)3;
  }
  else
  {
    v13 = (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent;
    v18.m_object = 0;
    v17 = assert_on_fail_true;
    parent[81].m_object = (vostok::resources::unmanaged_resource *)&vostok::resources::unmanaged_memory;
    v13[6].m_max_count = 1040;
    v16.m_object = (survarium::pure_game_effect_emitter_base *)5;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)m_object,
    v13,
    (vostok::resources::cook_base::result_enum)v16.m_object,
    v17,
    (vostok::resources::cook_base::result_enum)v18.m_object);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v15);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ogg_file);
}
