void __usercall vostok::resources::query_resources_and_wait(
        const vostok::resources::query_resource_params *in_params@<eax>)
{
  vostok::resources::query_resource_params *v2; // ecx
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::resources_manager *m_initialized; // ecx
  vostok::command_line::key::type_enum m_type; // eax
  vostok::resources::resources_manager *v6; // ecx
  vostok::command_line::key::type_enum v7; // eax
  vostok::resources::resources_manager *v8; // ecx
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::query_resources_and_wait_callback_proxy_pred,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::resources::query_resources_and_wait_callback_proxy_pred *>,boost::arg<1> > > v11; // [esp-8h] [ebp-D8h]
  vostok::resources::query_result *v12; // [esp+0h] [ebp-D0h]
  vostok::resources::query_resources_and_wait_callback_proxy_pred callback_proxy; // [esp+20h] [ebp-B0h] BYREF
  boost::function4<void,unsigned int,float,float,char const *> v14; // [esp+48h] [ebp-88h] BYREF
  vostok::resources::query_resource_params params; // [esp+68h] [ebp-68h] BYREF

  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)&in_params->callback,
    (int)&v14);
  callback_proxy.receieved_callback_ = 0;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    &v14,
    (int)&callback_proxy.callback_);
  if ( v14.vtable )
  {
    if ( ((int)v14.vtable & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v14.vtable & 0xFFFFFFFE);
      if ( v3 )
        v3(&v14.functor, &v14.functor, 2);
    }
  }
  vostok::resources::query_resource_params::query_resource_params(v2, &params.requests, in_params);
  v11.l_.a1_.t_ = &callback_proxy;
  v11.f_.f_ = vostok::resources::query_resources_and_wait_callback_proxy_pred::callback;
  boost::function<void __cdecl (vostok::resources::queries_result &)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::resources::query_resources_and_wait_callback_proxy_pred,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::resources::query_resources_and_wait_callback_proxy_pred *>,boost::arg<1>>>>(
    (boost::function<void __cdecl(vostok::resources::queries_result &)> *)&callback_proxy,
    &params.callback,
    v11);
  vostok::resources::resources_manager::query_resources_impl(
    vostok::resources::g_resources_manager.m_variable,
    vostok::resources::g_resources_manager.m_variable,
    (vostok::resources::query_result **)&params,
    v12);
  while ( !callback_proxy.receieved_callback_ )
  {
    m_type = vostok::threading::g_debug_single_thread.m_type;
    if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
    {
      vostok::threading::g_debug_single_thread.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      m_type = vostok::threading::g_debug_single_thread.m_type;
    }
    if ( m_type != type_recursive )
    {
      if ( m_type == type_unset )
      {
        vostok::threading::g_debug_single_thread.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        m_type = vostok::threading::g_debug_single_thread.m_type;
      }
      if ( m_type != type_recursive )
      {
        vostok::resources::resources_manager::resources_thread_tick(m_initialized);
        vostok::resources::resources_manager::cooker_thread_tick(v6);
      }
    }
    m_initialized = (vostok::resources::resources_manager *)vostok::resources::g_resources_manager.m_initialized;
    if ( vostok::resources::g_resources_manager.m_initialized )
    {
      v7 = vostok::threading::g_debug_single_thread.m_type;
      if ( vostok::threading::g_debug_single_thread.m_type == type_unset )
      {
        vostok::threading::g_debug_single_thread.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        v7 = vostok::threading::g_debug_single_thread.m_type;
      }
      if ( v7 != type_recursive )
      {
        if ( v7 == type_unset )
        {
          vostok::threading::g_debug_single_thread.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
          v7 = vostok::threading::g_debug_single_thread.m_type;
        }
        if ( v7 != type_recursive )
        {
          vostok::resources::resources_manager::resources_thread_tick(m_initialized);
          vostok::resources::resources_manager::cooker_thread_tick(v8);
        }
      }
      vostok::resources::resources_manager::dispatch_callbacks(vostok::resources::g_resources_manager.m_variable, 0);
    }
  }
  if ( params.callback.vtable )
  {
    if ( ((int)params.callback.vtable & 1) == 0 )
    {
      v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)params.callback.vtable & 0xFFFFFFFE);
      if ( v9 )
        v9(&params.callback.functor, &params.callback.functor, 2);
    }
    params.callback.vtable = 0;
  }
  if ( callback_proxy.callback_.vtable && ((int)callback_proxy.callback_.vtable & 1) == 0 )
  {
    v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback_proxy.callback_.vtable & 0xFFFFFFFE);
    if ( v10 )
      v10(&callback_proxy.callback_.functor, &callback_proxy.callback_.functor, 2);
  }
}
