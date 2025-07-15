void __thiscall vostok::render::material_effects_instance_cook::on_material_ready(
        vostok::render::material_effects_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::material_effects_instance_cook_data *cook_data)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  vostok::render::material_effects_instance_cook_data *v4; // esi
  vostok::render::material_effects_instance_cook *v5; // ecx
  bool has_passed_filters; // al
  vostok::resources::query_result_for_cook *m_parent_query; // ecx
  vostok::fs_new::virtual_path_string *requested_path; // eax
  vostok::fs_new::virtual_path_string *v9; // ecx
  vostok::fs_new::virtual_path_string *fixed_request_path; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v11; // [esp-4h] [ebp-154h]
  const char *v12; // [esp+0h] [ebp-150h]
  const char *v13; // [esp+4h] [ebp-14Ch]
  unsigned int v14; // [esp+8h] [ebp-148h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v15; // [esp+10h] [ebp-140h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-13Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v17; // [esp+18h] [ebp-138h] BYREF
  vostok::buffer_string v18[23]; // [esp+3Ch] [ebp-114h] BYREF

  v15.m_object = 0;
  parent = (vostok::resources::query_result_for_cook *)this;
  if ( vostok::resources::query_result_for_user::is_successful(
         (vostok::resources::query_result_for_user *)this,
         (int)data->m_queries) )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v15,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
    v4 = cook_data;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      &v15,
      &cook_data->material);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v15);
    vostok::render::material_effects_instance_cook::query_effects(
      v5,
      (vostok::render::material_effects_instance_cook *)parent,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query,
      (int)v4);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"render_pc_dx11",
                                 (const char *)2),
          v3 = v11,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v3,
        &v17);
      m_parent_query = data->m_parent_query;
      v15.m_object = (survarium::pure_game_effect_emitter_base *)1;
      requested_path = (vostok::fs_new::virtual_path_string *)vostok::resources::query_result_for_user::get_requested_path(m_parent_query);
      fixed_request_path = vostok::render::get_fixed_request_path(v9, v18, requested_path);
      vostok::logging::append(
        &v17,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\material_effects_instance_cook.cpp",
        0xAFu,
        "void __thiscall vostok::render::material_effects_instance_cook::on_material_ready(class vostok::resources::queri"
        "es_result &,struct vostok::render::material_effects_instance_cook_data *)",
        "render_pc_dx11",
        error,
        "material not loaded: %s",
        fixed_request_path->m_string.m_begin);
    }
    if ( ((int)v15.m_object & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v3,
        (int *)&v17);
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v3,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
      result_success,
      assert_on_fail_false,
      result_out_of_memory|0x8);
    if ( cook_data->delete_in_cook )
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::material_effects_instance_cook_data>(
        vostok::render::g_allocator,
        &cook_data,
        v12,
        v13,
        v14);
  }
}
