void __thiscall survarium::messaging_client::on_error(
        survarium::messaging_client *this,
        vostok::network_core::client_error_codes_enum client_error_code,
        boost::system::error_code system_error_code)
{
  char v4; // bl
  char *M_data; // ecx
  void (__cdecl *v6)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // esi
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v7; // eax
  char *v8; // eax
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > result; // [esp+10h] [ebp-38h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-20h] BYREF

  v4 = 0;
  survarium::chat_handler::add_message(
    (survarium::chat_handler *)this,
    this->m_chat_handler,
    (survarium::flash_value *)2,
    L"Lost connection to messaging server. Reconnecting...",
    L"System");
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game:", error) )
  {
    v6 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v6 )
    {
      log_callback.functor.obj_ptr = v6;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v4 = 3;
    v7 = boost::system::error_code::message(&system_error_code, &result);
    v8 = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::c_str(v7);
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\messaging_client.cpp",
      0x68u,
      "void __thiscall survarium::messaging_client::on_error(enum vostok::network_core::client_error_codes_enum,class boo"
      "st::system::error_code)",
      "game:",
      error,
      "%s",
      v8);
  }
  if ( (v4 & 2) != 0 )
  {
    M_data = result._M_start_of_storage._M_data;
    v4 &= ~2u;
    if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)result._M_start_of_storage._M_data != &result )
    {
      if ( result._M_start_of_storage._M_data )
      {
        if ( (unsigned int)(result._M_buffers._M_end_of_storage - result._M_start_of_storage._M_data) <= 0x80 )
          stlp_std::__node_alloc::_M_deallocate(
            (_STLP_atomic_freelist::item *)result._M_start_of_storage._M_data,
            result._M_buffers._M_end_of_storage - result._M_start_of_storage._M_data);
        else
          operator delete(result._M_start_of_storage._M_data);
      }
    }
  }
  if ( (v4 & 1) != 0 )
  {
    if ( log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v9 )
          v9(&log_callback.functor, &log_callback.functor, 2);
      }
    }
  }
  survarium::messaging_client::disconnect((survarium::messaging_client *)M_data, (int)this);
  ++this->m_connection_info.connection_error_count;
  this->m_connection_info.need_resolve = 1;
}
