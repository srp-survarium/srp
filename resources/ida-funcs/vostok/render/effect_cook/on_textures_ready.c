void __thiscall vostok::render::effect_cook::on_textures_ready(
        vostok::render::effect_cook *this,
        vostok::memory::doug_lea_allocator **in_textures,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *in_out_query,
        survarium::pure_game_effect_emitter_base *effect_resource,
        vostok::render::effect_compile_data *compile_data,
        vostok::resources::queries_result *data)
{
  bool has_passed_filters; // al
  const char *requested_path; // eax
  const char **v8; // esi
  vostok::render::resource_manager *v9; // edi
  stlp_std::priv::_Rb_tree_node_base *texture; // eax
  survarium::pure_game_effect_emitter_base *v11; // eax
  vostok::resources::query_result_for_cook *v12; // ecx
  vostok::resources::query_result_for_cook *v13; // ecx
  vostok::memory::doug_lea_allocator *v14; // ecx
  vostok::memory::doug_lea_allocator *v15; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v16; // [esp-10h] [ebp-50h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v17; // [esp-Ch] [ebp-4Ch] BYREF
  const vostok::resources::memory_type *v18; // [esp-8h] [ebp-48h]
  unsigned int v19; // [esp-4h] [ebp-44h]
  const char *v20; // [esp+0h] [ebp-40h]
  const char *v21; // [esp+4h] [ebp-3Ch]
  unsigned int v22; // [esp+8h] [ebp-38h]
  int v23; // [esp+10h] [ebp-30h]
  vostok::resources::query_result_for_user *m_queries; // [esp+14h] [ebp-2Ch]
  int v25; // [esp+18h] [ebp-28h]
  unsigned int v26; // [esp+1Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v27; // [esp+20h] [ebp-20h] BYREF

  v23 = 0;
  v26 = 0;
  if ( data->m_size )
  {
    v25 = 0;
    m_queries = data->m_queries;
    do
    {
      if ( vostok::resources::query_result_for_user::is_successful(
             (vostok::resources::query_result_for_user *)this,
             (int)m_queries) )
      {
        v8 = (const char **)((char *)*in_textures + v25);
        v9 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
        texture = vostok::render::resource_manager::find_texture(
                    (vostok::render::resource_manager *)this,
                    (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                    v8[68]);
        if ( texture && !LOBYTE(texture->_M_left) )
        {
          v11 = (survarium::pure_game_effect_emitter_base *)*v8;
          v19 = 1;
          v18 = (const vostok::resources::memory_type *)v8[137];
          v17.m_object = v11;
          v16.m_object = (vostok::resources::managed_resource *)this;
          vostok::resources::query_result_for_user::get_managed_resource(m_queries, &v16);
          vostok::render::resource_manager::on_texture_loaded_res(
            v9,
            v16,
            (char *)v17.m_object,
            (unsigned int)v18,
            (vostok::resources::managed_resource *)v19);
        }
      }
      else
      {
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                     (const char *)2),
              this = (vostok::render::effect_cook *)v19,
              has_passed_filters) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)this,
            &v27);
          v23 |= 1u;
          requested_path = vostok::resources::query_result_for_user::get_requested_path(m_queries);
          vostok::logging::append(
            &v27,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\effect_cook.cpp",
            0x111u,
            "void __thiscall vostok::render::effect_cook::on_textures_ready(void *,class vostok::resources::query_result_"
            "for_cook *,class vostok::render::res_effect *,struct vostok::render::effect_compile_data *,class vostok::res"
            "ources::queries_result &)",
            (char *)&initiator_raw.initiator_tree,
            error,
            "Texture %s not found",
            requested_path);
        }
        if ( (v23 & 1) != 0 )
        {
          v23 &= ~1u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
            (int *)&v27);
        }
      }
      ++v26;
      v25 += 552;
      m_queries = (vostok::resources::query_result_for_user *)((char *)m_queries + 736);
    }
    while ( v26 < data->m_size );
  }
  v19 = 22200;
  v18 = &vostok::resources::nocache_memory;
  v17.m_object = (survarium::pure_game_effect_emitter_base *)this;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v17,
    effect_resource);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v12,
    in_out_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v17.m_object,
    v18,
    v19);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v13,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)in_out_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  if ( in_textures )
  {
    v14 = *in_textures;
    v15 = vostok::render::g_allocator;
    v19 = (unsigned int)in_textures;
    in_textures[1] = v14;
    vostok::memory::doug_lea_allocator::free_impl(v14, (int)v15, (char *)v19, v20, v21, v22);
  }
}
