void __thiscall vostok::sound::sound_scene::delete_sound_propagator(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_instance_proxy_internal *proxy,
        vostok::sound::new_sound_propagator *propagator)
{
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+37h] [ebp-4Dh] BYREF
  vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy> *allocator; // [esp+38h] [ebp-4Ch]
  char v6; // [esp+3Fh] [ebp-45h]
  void (__cdecl *f)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+58h] [ebp-2Ch]
  int v8; // [esp+5Ch] [ebp-28h]
  char v9; // [esp+62h] [ebp-22h]
  char v10; // [esp+63h] [ebp-21h]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v11; // [esp+64h] [ebp-20h] BYREF

  v8 = 0;
  if ( propagator )
  {
    v10 = 0;
    vostok::intrusive_list<vostok::sound::new_sound_propagator,vostok::sound::new_sound_propagator *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
      &proxy->m_propagators,
      propagator);
    v6 = 0;
    allocator = this->m_propagators_allocator.m_variable;
    call_destructor_predicate = 0;
    vostok::memory::detail::delete_helper_impl<vostok::memory::single_size_buffer_allocator<108,vostok::threading::single_threading_policy>,vostok::sound::new_sound_propagator,vostok::memory::detail::call_destructor_predicate>(
      allocator,
      &propagator,
      &call_destructor_predicate);
    v9 = 0;
    if ( !proxy->m_propagators.m_first )
      vostok::intrusive_list<vostok::sound::sound_instance_proxy_internal,vostok::sound::sound_instance_proxy_internal *,488,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::erase(
        &this->m_active_proxies,
        proxy);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
    {
      f = vostok::core::g_log_callback;
      v11.vtable = 0;
      boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        &v11,
        vostok::core::g_log_callback);
      v8 |= 1u;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v11,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\sound_scene_propagators.cpp",
        0xACu,
        "void __thiscall vostok::sound::sound_scene::delete_sound_propagator(class vostok::sound::sound_instance_proxy_in"
        "ternal &,class vostok::sound::new_sound_propagator *)",
        "sound:",
        error,
        "can't delete sound_propagator, pointer == 0");
    }
    if ( (v8 & 1) != 0 )
    {
      v8 &= ~1u;
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v11);
    }
  }
}
