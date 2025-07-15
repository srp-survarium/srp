void __thiscall vostok::render::scene_renderer::update_volume_fog(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *scene,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *id,
        const vostok::render::volume_fog_parameters *in_parameters,
        const vostok::render::volume_fog_parameters *in_parametersa)
{
  char v5; // bl
  int v6; // edi
  boost::function<void __cdecl(vostok::render::volume_fog_parameters const &)> *v7; // ecx
  __int32 v8; // eax
  vostok::render::base_scene *m_channel; // ecx
  bool v10; // dl
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v12)(_BYTE *, _BYTE *, int); // eax
  vostok::resources::unmanaged_resource *m_object; // [esp-18h] [ebp-6Ch]
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> v14; // [esp-14h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::volume_fog_parameters const &>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::arg<1> > > v15; // [esp-10h] [ebp-64h] BYREF
  const boost::function<void __cdecl(vostok::render::base_command &)> *v16; // [esp+0h] [ebp-54h]
  boost::function4<void,unsigned int,float,float,char const *> v17; // [esp+10h] [ebp-44h] BYREF
  int v18; // [esp+30h] [ebp-24h] BYREF
  _BYTE v19[28]; // [esp+38h] [ebp-1Ch] BYREF

  v5 = 0;
  v6 = (int)scene->m_allocator->call_malloc(scene->m_allocator, 272);
  if ( v6 )
  {
    v14.m_object = (vostok::render::base_scene *)(unsigned __int8)1_19;
    m_object = 0;
    if ( id->m_object )
    {
      m_object = id->m_object;
      _InterlockedExchangeAdd(&id->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::volume_fog_parameters const &,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,unsigned int,boost::arg<1>>(
      (boost::_bi::value<unsigned int>)in_parameters,
      &v15,
      scene->m_render_engine_world,
      m_object,
      v14);
    boost::function<void __cdecl (vostok::render::volume_fog_parameters const &)>::function<void __cdecl (vostok::render::volume_fog_parameters const &)>(
      v7,
      v15,
      (int)v16);
    v5 = 3;
    v17.vtable = 0;
    vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::volume_fog_parameters>::functor_with_big_buffer_to_copy_command<vostok::render::volume_fog_parameters>(
      (vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::volume_fog_parameters> *)&v18,
      v6,
      in_parametersa,
      &v17,
      v16);
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
    if ( v17.vtable )
    {
      if ( ((int)v17.vtable & 1) == 0 )
      {
        v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v17.vtable & 0xFFFFFFFE);
        if ( v11 )
          v11(&v17.functor, &v17.functor, 2);
      }
      v17.vtable = 0;
    }
  }
  if ( (v5 & 1) != 0 && v18 && (v18 & 1) == 0 )
  {
    v12 = *(void (__cdecl **)(_BYTE *, _BYTE *, int))(v18 & 0xFFFFFFFE);
    if ( v12 )
      v12(v19, v19, 2);
  }
}
