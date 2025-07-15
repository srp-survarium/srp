void __thiscall vostok::render::texture_options_binary_cooker::on_binary_config_loaded(
        vostok::render::texture_options_binary_cooker *this,
        vostok::resources::queries_result *result)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // ebx
  vostok::render::texture_options_binary_cooker *v4; // ecx
  survarium::pure_game_effect_emitter_base *v5; // ecx
  vostok::resources::query_result_for_cook *v6; // ecx
  char *requested_path; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_options_binary_cooker,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_options_binary_cooker *>,boost::arg<1> > > v10; // [esp-8h] [ebp-158h] BYREF
  int v11; // [esp+0h] [ebp-150h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+10h] [ebp-140h] BYREF
  const vostok::resources::memory_usage_type *p_m_memory_usage_self; // [esp+14h] [ebp-13Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::texture_options_binary_cooker,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::render::texture_options_binary_cooker *>,boost::arg<1> > > v14[4]; // [esp+18h] [ebp-138h] BYREF
  vostok::fs_new::path_string_impl v15; // [esp+38h] [ebp-118h] BYREF

  m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)result->m_parent_query;
  if ( vostok::resources::query_result_for_user::is_successful(
         (vostok::resources::query_result_for_user *)this,
         (int)result->m_queries) )
  {
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v12,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&result->m_queries[0].m_unmanaged_resource);
    v10.l_.a1_.t_ = v4;
    p_m_memory_usage_self = &v12.m_object->m_memory_usage_self;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v10.l_,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v12);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      p_m_memory_usage_self,
      v5,
      m_parent_query,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base>)v10.l_.a1_.t_);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v6,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
  }
  else
  {
    v15.m_string.m_begin = v15.m_string.m_buffer;
    v15.m_string.m_end = v15.m_string.m_buffer;
    v15.m_string.m_max_end = &v15.m_separator;
    v15.m_string.m_buffer[0] = 0;
    v15.m_separator = 47;
    requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path((vostok::resources::query_result_for_user *)m_parent_query);
    vostok::fs_new::path_string_impl::assign_replace(&v15, requested_path);
    v10.l_.a1_.t_ = this;
    v10.f_.f_ = vostok::render::texture_options_binary_cooker::on_lua_options_loaded;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v8,
      v14,
      v10,
      v11);
    vostok::resources::query_resource(
      v15.m_string.m_begin,
      (vostok::variant<32> *)0x34,
      &vostok::memory::g_resources_unmanaged_allocator,
      0,
      (const vostok::variant<32> **)m_parent_query,
      assert_on_fail_true);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v9,
      (int *)v14);
  }
}
