void __thiscall vostok::render::bake_decal_cook::on_texture_converted(
        vostok::render::bake_decal_cook *this,
        vostok::resources::queries_result *result,
        vostok::render::texture_converter_params *params,
        vostok::render::res_texture *surface)
{
  vostok::resources::queries_result *v4; // ebx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_size; // edi
  vostok::particle::particle_system_instance_impl *m_object; // edi
  vostok::particle::particle_system_instance_impl *v7; // esi
  unsigned int v8; // ebx
  vostok::fs_new::virtual_path_string *v9; // ecx
  vostok::fs_new::virtual_path_string *unique_user_name; // eax
  vostok::render::res_texture *v11; // eax
  vostok::render::resource_manager *v12; // ecx
  vostok::render::res_texture *v13; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_buffer; // esi
  vostok::memory::doug_lea_allocator *v16; // esi
  char *v17; // eax
  vostok::memory::doug_lea_allocator *v18; // ecx
  char *v19; // eax
  survarium::pure_game_effect_emitter_base *v20; // ecx
  survarium::pure_game_effect_emitter_base *v21; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // eax
  vostok::resources::query_result_for_cook *v23; // ecx
  vostok::resources::query_result_for_cook *v24; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v25; // [esp-Ch] [ebp-14Ch] BYREF
  const vostok::resources::memory_type *v26; // [esp-8h] [ebp-148h]
  unsigned int v27; // [esp-4h] [ebp-144h]
  const char *v28; // [esp+0h] [ebp-140h]
  const char *v29; // [esp+4h] [ebp-13Ch]
  unsigned int v30; // [esp+8h] [ebp-138h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+10h] [ebp-130h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *other; // [esp+14h] [ebp-12Ch]
  unsigned int *p_m_user_data; // [esp+18h] [ebp-128h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v34; // [esp+1Ch] [ebp-124h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v35; // [esp+20h] [ebp-120h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v36; // [esp+24h] [ebp-11Ch]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v37; // [esp+28h] [ebp-118h] BYREF
  _BYTE v38[276]; // [esp+2Ch] [ebp-114h] BYREF

  v4 = result;
  m_size = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)result->m_size;
  v34 = m_size;
  if ( m_size )
  {
    p_m_user_data = &params->m_user_data;
    other = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result->m_queries[0].m_unmanaged_resource;
    v36 = m_size;
    do
    {
      if ( vostok::resources::query_result_for_user::is_successful(
             (vostok::resources::query_result_for_user *)this,
             (int)&other[-55]) )
      {
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &v37,
          other);
        m_object = (vostok::particle::particle_system_instance_impl *)v37.m_object;
        v7 = 0;
        v35.m_object = 0;
        if ( v37.m_object )
        {
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v35);
          v7 = m_object;
          v35.m_object = m_object;
          _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v37);
        v8 = *p_m_user_data;
        unique_user_name = vostok::render::resource_manager::create_unique_user_name(v9, (int)v38);
        v11 = vostok::render::resource_manager::on_texture_loaded_res_impl(
                (vostok::render::resource_manager *)v7->m_lods[0].m_emitter_instance_list.m_size,
                vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                (unsigned int)v7->m_lods[0].m_template.m_object,
                (const char *)v7->m_lods[0].m_emitter_instance_list.m_size,
                unique_user_name->m_string.m_begin,
                0xFFFFFFFF,
                0);
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
          &object,
          v11);
        if ( !v8 )
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
            &object,
            surface);
        if ( v8 == 1 )
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
            &object,
            (vostok::render::res_texture *)&surface->vostok::render::resource_intrusive_base);
        if ( v8 == 2 )
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
            &object,
            (vostok::render::res_texture *)&surface->m_loaded);
        if ( v8 == 3 )
          vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
            &object,
            (vostok::render::res_texture *)&surface->num_mips);
        v13 = object.m_object;
        if ( object.m_object )
        {
          if ( object.m_object->m_reference_count-- == 1 )
            vostok::render::resource_manager::release(
              v12,
              (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
              v13);
        }
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v35);
        v4 = result;
        m_size = v34;
      }
      other += 184;
      p_m_user_data += 215;
      v36 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)((char *)v36 - 1);
    }
    while ( v36 );
    if ( m_size )
    {
      p_m_buffer = &params->m_buffer;
      do
      {
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&p_m_buffer[1]);
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(p_m_buffer);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&p_m_buffer[-1]);
        p_m_buffer += 215;
        m_size = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)((char *)m_size - 1);
      }
      while ( m_size );
    }
  }
  if ( params )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      (char *)params,
      v28,
      v29,
      v30);
  v16 = vostok::render::g_allocator;
  v17 = type_info::raw_name(&vostok::render::bake_decal_result_resource `RTTI Type Descriptor');
  v19 = vostok::memory::doug_lea_allocator::malloc_impl(v18, (int)v16, 0x108u, v17, v28, v29, v30);
  v21 = (survarium::pure_game_effect_emitter_base *)v19;
  if ( v19 )
  {
    vostok::resources::unmanaged_resource::unmanaged_resource(v20, v19, fs_iterator_class);
    v21->__vftable = (survarium::pure_game_effect_emitter_base_vtbl *)&vostok::render::bake_decal_result_resource::`vftable';
  }
  else
  {
    v21 = 0;
  }
  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v4->m_parent_query;
  v27 = 264;
  v26 = &vostok::resources::nocache_memory;
  v25.m_object = v20;
  v34 = m_parent_query;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v25,
    v21);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v23,
    v34,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v25.m_object,
    v26,
    v27);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v24,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v4->m_parent_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
