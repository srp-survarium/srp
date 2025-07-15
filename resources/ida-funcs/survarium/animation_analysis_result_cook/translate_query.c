void __thiscall survarium::animation_analysis_result_cook::translate_query(
        survarium::animation_analysis_result_cook *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *parent)
{
  vostok::resources::unmanaged_resource *m_object; // esi
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  survarium::animation_analysis_result *v6; // ecx
  survarium::pure_game_effect_emitter_base *v7; // eax
  vostok::resources::query_result_for_cook *v8; // ecx
  vostok::resources::query_result_for_cook *v9; // ecx
  bool has_passed_filters; // al
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v11; // [esp-Ch] [ebp-4Ch] BYREF
  const vostok::resources::memory_type *v12; // [esp-8h] [ebp-48h]
  unsigned int v13; // [esp-4h] [ebp-44h]
  const char *v14; // [esp+0h] [ebp-40h]
  const char *v15; // [esp+4h] [ebp-3Ch]
  unsigned int v16; // [esp+8h] [ebp-38h]
  int v17; // [esp+Ch] [ebp-34h]
  survarium::animation_analysis_result_cook_user_data out_value; // [esp+10h] [ebp-30h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v19; // [esp+20h] [ebp-20h] BYREF

  m_object = parent[66].m_object;
  v17 = 0;
  out_value.animation.m_object = 0;
  if ( m_object
    && vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>(
         (vostok::variant<32> *)this,
         (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)m_object,
         &out_value) )
  {
    v3 = survarium::g_allocator;
    v4 = type_info::raw_name(&survarium::animation_analysis_result `RTTI Type Descriptor');
    if ( vostok::memory::doug_lea_allocator::malloc_impl(v5, (int)v3, 0x118u, v4, v14, v15, v16) )
      survarium::animation_analysis_result::animation_analysis_result(v6, out_value.legs_count);
    else
      v7 = 0;
    v13 = 280;
    v12 = &vostok::resources::nocache_memory;
    v11.m_object = (survarium::pure_game_effect_emitter_base *)v6;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v11,
      v7);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v8,
      parent,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v11.m_object,
      v12,
      v13);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v9,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"game_core",
                                 (const char *)2),
          this = (survarium::animation_analysis_result_cook *)v13,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
        &v19);
      v17 = 1;
      vostok::logging::append(
        &v19,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\animation_analysis_result_cook.cpp",
        0x1Bu,
        "void __thiscall survarium::animation_analysis_result_cook::translate_query(class vostok::resources::query_result_for_cook &)",
        "game_core",
        error,
        "Failed to get user data for animation_analysis_result_cook");
    }
    if ( (v17 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        (int *)&v19);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&out_value.animation);
}
