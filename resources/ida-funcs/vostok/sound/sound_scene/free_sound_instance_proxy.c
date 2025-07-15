void __thiscall vostok::sound::sound_scene::free_sound_instance_proxy(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_instance_proxy *proxy)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+43h] [ebp-41h] BYREF
  vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy> *allocator; // [esp+44h] [ebp-40h]
  char v5; // [esp+4Bh] [ebp-39h]
  unsigned int m_id; // [esp+54h] [ebp-30h]
  void (__cdecl *f)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+58h] [ebp-2Ch]
  char *v8; // [esp+5Ch] [ebp-28h]
  int v9; // [esp+60h] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+64h] [ebp-20h] BYREF

  v9 = 0;
  if ( !vostok::core::g_log_filter_tree
    || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", info) )
  {
    f = vostok::core::g_log_callback;
    log_callback.vtable = 0;
    if ( boost::detail::function::basic_vtable9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
           &`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable,
           vostok::core::g_log_callback,
           &log_callback.functor) )
    {
      v8 = (char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
         + 1;
      log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                   + 1);
    }
    else
    {
      log_callback.vtable = 0;
    }
    v9 |= 1u;
    m_id = proxy->m_id;
    vostok::logging::append(
      &log_callback,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\sound_scene_proxies.cpp",
      0x55u,
      "void __thiscall vostok::sound::sound_scene::free_sound_instance_proxy(class vostok::sound::sound_instance_proxy *)",
      "sound:",
      info,
      "sound instance proxy with id %d is deallocated",
      m_id);
  }
  if ( (v9 & 1) != 0 )
  {
    v9 &= ~1u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&log_callback);
  }
  v5 = 0;
  allocator = this->m_proxies_allocator.m_variable;
  call_destructor_predicate = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::single_size_buffer_allocator<536,vostok::threading::multi_threading_policy>,vostok::sound::sound_instance_proxy,vostok::memory::detail::call_destructor_predicate>(
    allocator,
    &proxy,
    &call_destructor_predicate);
}
