void __thiscall vostok::core::configs::binary_config_cook::translate_query(
        vostok::core::configs::binary_config_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  char *requested_path; // eax
  vostok::fixed_string<260> *v4; // ecx
  vostok::particle::particle_action *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  bool do_debug_break; // [esp+Fh] [ebp-269h] BYREF
  void (__thiscall *v8)(vostok::core::configs::binary_config_cook *, vostok::resources::queries_result *); // [esp+10h] [ebp-268h]
  vostok::core::configs::binary_config_cook *v9; // [esp+14h] [ebp-264h]
  vostok::resources::request v10; // [esp+18h] [ebp-260h] BYREF
  char *m_begin; // [esp+20h] [ebp-258h]
  int v12; // [esp+24h] [ebp-254h]
  int v13[8]; // [esp+28h] [ebp-250h] BYREF
  vostok::fs_new::virtual_path_string format; // [esp+48h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string v15; // [esp+160h] [ebp-118h] BYREF

  requested_path = (char *)vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fixed_string<260>::fixed_string<260>(v4, &v15.m_string, requested_path);
  format.m_string.m_begin = format.m_string.m_buffer;
  format.m_string.m_end = format.m_string.m_buffer;
  format.m_string.m_max_end = &format.m_separator;
  v15.m_separator = 47;
  format.m_string.m_buffer[0] = 0;
  format.m_separator = 47;
  vostok::core::configs::make_source_path(&format, &v15);
  if ( !debug_macro_helper_ignore_always_32 )
  {
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      0,
      "assertion_failed",
      "fatal error",
      ".\\configs_binary_config_cook.cpp",
      "vostok::core::configs::binary_config_cook::translate_query",
      (const char *)0x81,
      "using binary_config_cook in VOSTOK_CONVERTED_RESOURCES_ONLY not allowed. [%s]!",
      format.m_string.m_begin);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
  v10.path = format.m_string.m_begin;
  m_begin = v15.m_string.m_begin;
  v8 = vostok::core::configs::binary_config_cook::on_fs_iterators_ready;
  v10.id = fs_iterator_class;
  v12 = 1;
  v9 = this;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v5) )
  {
    v13[0] = 0;
  }
  else
  {
    v13[2] = (int)v8;
    v13[3] = (int)v9;
    v13[0] = (int)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::core::configs::binary_config_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::core::configs::binary_config_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
           + 1;
  }
  vostok::resources::query_resources(
    &v10,
    2u,
    &vostok::memory::g_resources_helper_allocator,
    0,
    (const vostok::variant<32> **)parent,
    assert_on_fail_true);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, v13);
}
