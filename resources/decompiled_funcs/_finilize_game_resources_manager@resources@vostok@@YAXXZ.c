void __cdecl vostok::resources::finilize_game_resources_manager()
{
  void (__cdecl *v0)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::game_resources_manager *v1; // ecx
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(vostok::resources::resource_base *)> v3; // [esp-20h] [ebp-6Ch]
  boost::function<void __cdecl(vostok::resources::query_result *)> v4; // [esp+8h] [ebp-44h] BYREF
  boost::function<void __cdecl(vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)> v5; // [esp+28h] [ebp-24h] BYREF

  v3.vtable = 0;
  vostok::resources::set_query_finished_callback(v3);
  v4.vtable = 0;
  boost::function<void __cdecl (vostok::resources::query_result *)>::operator=(&v4);
  if ( v4.vtable )
  {
    if ( ((int)v4.vtable & 1) == 0 )
    {
      v0 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v4.vtable & 0xFFFFFFFE);
      if ( v0 )
        v0(&v4.functor, &v4.functor, 2);
    }
    v4.vtable = 0;
  }
  v5.vtable = 0;
  boost::function<void __cdecl (vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)>::operator=(&v5);
  if ( v5.vtable )
  {
    if ( ((int)v5.vtable & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v5.vtable & 0xFFFFFFFE);
      if ( v2 )
        v2(&v5.functor, &v5.functor, 2);
    }
    v5.vtable = 0;
  }
  vostok::resources::game_resources_manager::~game_resources_manager(
    v1,
    (vostok::resources::releasing_functionality)vostok::resources::g_game_resources_manager.m_variable);
  vostok::resources::g_game_resources_manager.m_initialized = 0;
}
