void __usercall vostok::render::vertex_buffer::vertex_buffer(
        vostok::render::vertex_buffer *this@<esi>,
        unsigned int size@<eax>,
        bool a3@<dil>)
{
  char v3; // bl
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v5; // ecx
  vostok::render::untyped_buffer *m_object; // edi
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::resource_manager *v10; // [esp-14h] [ebp-48h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+10h] [ebp-24h] BYREF

  v3 = 0;
  v10 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  this->m_buffer.m_object = 0;
  this->m_size = size;
  this->m_position = 0;
  this->m_discard_id = 0;
  this->m_lock_count = 0;
  this->m_lock_stride = 0;
  buffer = vostok::render::resource_manager::create_buffer(
             size,
             a3,
             v10,
             0,
             enum_buffer_type_vertex,
             (vostok::render::untyped_buffer *)1,
             0);
  v5 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v5 = buffer;
  }
  m_object = this->m_buffer.m_object;
  this->m_buffer.m_object = v5;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::res_state *)m_object,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "render:", info) )
  {
    v8 = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
      `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
        &log_callback.functor,
        &log_callback.functor,
        destroy_functor_tag);
    if ( v8 )
    {
      log_callback.functor.obj_ptr = v8;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v3 = 1;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\vertex_buffer.cpp",
      0x1Cu,
      "__thiscall vostok::render::vertex_buffer::vertex_buffer(unsigned int)",
      "render:",
      info,
      " vertex buffer created: %dKb",
      this->m_size >> 10);
  }
  if ( (v3 & 1) != 0 && log_callback.vtable && ((int)log_callback.vtable & 1) == 0 )
  {
    v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
    if ( v9 )
      v9(&log_callback.functor, &log_callback.functor, 2);
  }
}
