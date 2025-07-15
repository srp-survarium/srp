void __thiscall vostok::render::scene_renderer::update_light(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *scene,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *id,
        vostok::render::light_props *props,
        vostok::render::light_props *propsa)
{
  char v5; // bl
  __int32 v6; // edi
  boost::function<void __cdecl(void)> *v7; // ecx
  vostok::render::base_scene *m_channel; // eax
  bool v9; // zf
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> v12; // [esp-18h] [ebp-6Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *> > > v13; // [esp-14h] [ebp-68h] BYREF
  int v14; // [esp+0h] [ebp-54h]
  boost::function4<void,unsigned int,float,float,char const *> v15; // [esp+10h] [ebp-44h] BYREF
  boost::function0<void> f; // [esp+30h] [ebp-24h] BYREF

  v5 = 0;
  v6 = (__int32)scene->m_allocator->call_malloc(scene->m_allocator, 152);
  if ( v6 )
  {
    v12.m_object = 0;
    if ( id->m_object )
    {
      v12.m_object = id->m_object;
      _InterlockedExchangeAdd(&id->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,unsigned int,vostok::render::light_props *>(
      (boost::_bi::value<unsigned int>)props,
      propsa,
      &v13,
      vostok::render::engine::world::update_light,
      scene->m_render_engine_world,
      v12);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v7, v13, v14);
    v15.vtable = 0;
    *(_BYTE *)(v6 + 12) = 0;
    *(_DWORD *)(v6 + 80) = 0;
    *(_BYTE *)(v6 + 13) = 1;
    *(_DWORD *)v6 = &vostok::render::functor_command::`vftable';
    *(_DWORD *)(v6 + 88) = 0;
    v5 = 3;
    boost::function0<void>::assign_to_own((boost::function0<void> *)(v6 + 88), &f);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v15, v6 + 120);
  }
  else
  {
    v6 = 0;
  }
  m_channel = (vostok::render::base_scene *)scene->m_channel;
  v9 = *(_DWORD *)(m_channel->m_parent_resources.m_lock + 4) == 0;
  *(_DWORD *)(v6 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_channel->log_string, v6);
  m_channel->__vftable = (vostok::render::base_scene_vtbl *)v6;
  if ( v9 )
    SetEvent(m_channel->grm_satisfaction_tree_hook.right_);
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( v15.vtable )
    {
      if ( ((int)v15.vtable & 1) == 0 )
      {
        v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v15.vtable & 0xFFFFFFFE);
        if ( v10 )
          v10(&v15.functor, &v15.functor, 2);
      }
      v15.vtable = 0;
    }
  }
  if ( (v5 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v11 )
      v11(&f.functor, &f.functor, 2);
  }
}
