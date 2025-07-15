void __thiscall vostok::core::configs::binary_config_cook::on_fs_iterators_ready(
        vostok::core::configs::binary_config_cook *this,
        vostok::resources::queries_result *results)
{
  vostok::resources::query_result_for_cook *m_parent_query; // ebx
  char *requested_path; // eax
  vostok::fixed_string<260> *v4; // ecx
  vostok::resources::query_result_for_cook *v5; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v6; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::core::configs::binary_config_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<vostok::core::configs::binary_config_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v8; // [esp-10h] [ebp-4F0h]
  bool do_debug_break; // [esp+Fh] [ebp-4D1h] BYREF
  vostok::resources::query_result_for_cook *v10; // [esp+10h] [ebp-4D0h]
  void (__thiscall *v11)(vostok::core::configs::binary_config_cook *, survarium::pure_game_effect_emitter_base *, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *); // [esp+14h] [ebp-4CCh]
  vostok::resources::query_result_for_cook *v12; // [esp+18h] [ebp-4C8h]
  vostok::resources::query_result_for_cook *v13; // [esp+1Ch] [ebp-4C4h]
  int f[8]; // [esp+20h] [ebp-4C0h] BYREF
  vostok::fs_new::virtual_path_string format; // [esp+40h] [ebp-4A0h] BYREF
  vostok::fs_new::virtual_path_string v16; // [esp+158h] [ebp-388h] BYREF
  vostok::fs_new::physical_path_info v17; // [esp+270h] [ebp-270h] BYREF
  vostok::fs_new::physical_path_info v18; // [esp+3A8h] [ebp-138h] BYREF

  m_parent_query = results->m_parent_query;
  v10 = (vostok::resources::query_result_for_cook *)this;
  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(m_parent_query);
  vostok::fixed_string<260>::fixed_string<260>(v4, &v16.m_string, requested_path);
  format.m_string.m_begin = format.m_string.m_buffer;
  format.m_string.m_end = format.m_string.m_buffer;
  format.m_string.m_max_end = &format.m_separator;
  v16.m_separator = 47;
  format.m_string.m_buffer[0] = 0;
  format.m_separator = 47;
  vostok::core::configs::make_source_path(&format, &v16);
  if ( results->m_queries[1].m_result_iterator.m_node )
  {
    vostok::resources::get_physical_path_info(&results->m_queries[0].m_result_iterator, &v18);
    vostok::resources::get_physical_path_info(&results->m_queries[1].m_result_iterator, &v17);
    if ( v17.data.type && v18.data.last_time_of_write < v17.data.last_time_of_write )
    {
      v12 = v10;
      v11 = vostok::core::configs::binary_config_cook::on_binary_config_loaded;
      v13 = m_parent_query;
      v8.l_.a1_.t_ = (vostok::core::configs::binary_config_cook *)vostok::core::configs::binary_config_cook::on_binary_config_loaded;
      v8.l_.a3_.t_ = v10;
      v8.f_.f_ = (void (__thiscall *)(vostok::core::configs::binary_config_cook *, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *))f;
      boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
        v6,
        v8,
        (int)m_parent_query);
      vostok::resources::query_resource(
        v16.m_string.m_begin,
        (vostok::variant<32> *)0x20,
        &vostok::memory::g_resources_helper_allocator,
        0,
        (const vostok::variant<32> **)m_parent_query,
        assert_on_fail_true);
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v7, f);
    }
    else if ( !debug_macro_helper_ignore_always_33 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        &do_debug_break,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        ".\\configs_binary_config_cook.cpp",
        "vostok::core::configs::binary_config_cook::on_fs_iterators_ready",
        (const char *)0xD5,
        "cannot find binary config [%s]!",
        format.m_string.m_begin);
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      v5,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query,
      result_success,
      assert_on_fail_false,
      result_success);
  }
}
