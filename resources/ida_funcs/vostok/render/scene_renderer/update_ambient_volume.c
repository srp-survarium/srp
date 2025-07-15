void __thiscall vostok::render::scene_renderer::update_ambient_volume(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *scene,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *id,
        const vostok::render::ambient_volume_properties *properties,
        const vostok::render::ambient_volume_properties *propertiesa)
{
  char v5; // bl
  vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::ambient_volume_properties> *v6; // edi
  boost::function<void __cdecl(vostok::render::ambient_volume_properties const &)> *v7; // ecx
  __int32 v8; // eax
  vostok::render::base_scene *m_channel; // ecx
  bool v10; // dl
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::unmanaged_resource *m_object; // [esp-18h] [ebp-6Ch]
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> v14; // [esp-14h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::ambient_volume_properties const &>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::arg<1> > > v15; // [esp-10h] [ebp-64h] BYREF
  int v16; // [esp+0h] [ebp-54h]
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+10h] [ebp-44h] BYREF
  boost::function<void __cdecl(vostok::render::ambient_volume_properties const &)> on_execute; // [esp+30h] [ebp-24h] BYREF

  v5 = 0;
  v6 = (vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::ambient_volume_properties> *)scene->m_allocator->call_malloc(scene->m_allocator, 224);
  if ( v6 )
  {
    v14.m_object = (vostok::render::base_scene *)(unsigned __int8)1_19;
    m_object = 0;
    if ( id->m_object )
    {
      m_object = id->m_object;
      _InterlockedExchangeAdd(&id->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::ambient_volume_properties const &,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,unsigned int,boost::arg<1>>(
      (boost::_bi::value<unsigned int>)properties,
      &v15,
      scene->m_render_engine_world,
      m_object,
      v14);
    boost::function<void __cdecl (vostok::render::ambient_volume_properties const &)>::function<void __cdecl (vostok::render::ambient_volume_properties const &)>(
      v7,
      v15,
      v16);
    v5 = 3;
    on_defer_execution.vtable = 0;
    vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::ambient_volume_properties>::functor_with_big_buffer_to_copy_command<vostok::render::ambient_volume_properties>(
      (boost::function4<void,unsigned int,float,float,char const *> *)&on_execute,
      (boost::function4<void,unsigned int,float,float,char const *> *)&on_defer_execution,
      v6,
      propertiesa);
  }
  else
  {
    v8 = 0;
  }
  m_channel = (vostok::render::base_scene *)scene->m_channel;
  v10 = *(_DWORD *)(m_channel->m_parent_resources.m_lock + 4) == 0;
  *(_DWORD *)(v8 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_channel->log_string, v8);
  m_channel->__vftable = (vostok::render::base_scene_vtbl *)v8;
  if ( v10 )
    SetEvent(m_channel->grm_satisfaction_tree_hook.right_);
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( on_defer_execution.vtable )
    {
      if ( ((int)on_defer_execution.vtable & 1) == 0 )
      {
        v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_defer_execution.vtable & 0xFFFFFFFE);
        if ( v11 )
          v11(&on_defer_execution.functor, &on_defer_execution.functor, 2);
      }
      on_defer_execution.vtable = 0;
    }
  }
  if ( (v5 & 1) != 0 && on_execute.vtable && ((int)on_execute.vtable & 1) == 0 )
  {
    v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_execute.vtable & 0xFFFFFFFE);
    if ( v12 )
      v12(&on_execute.functor, &on_execute.functor, 2);
  }
}
