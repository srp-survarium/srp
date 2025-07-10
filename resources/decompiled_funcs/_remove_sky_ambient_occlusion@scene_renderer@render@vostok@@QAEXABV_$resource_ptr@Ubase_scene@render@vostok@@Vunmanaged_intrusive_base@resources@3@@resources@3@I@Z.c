void __thiscall vostok::render::scene_renderer::remove_sky_ambient_occlusion(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *scene,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *id,
        unsigned int ida)
{
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v4; // esi
  vostok::render::base_scene *m_allocator; // ecx
  void (__thiscall *decrease_quality)(struct vostok::resources::resource_base *, unsigned int); // edx
  __int32 v7; // ebx
  boost::function<void __cdecl(void)> *v8; // ecx
  vostok::render::base_scene *m_object; // eax
  bool v10; // zf
  char v11; // bl
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> v14; // [esp-14h] [ebp-64h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int> > > v15; // [esp-10h] [ebp-60h] BYREF
  int v16; // [esp+0h] [ebp-50h]
  int v17; // [esp+Ch] [ebp-44h]
  boost::function4<void,unsigned int,float,float,char const *> v18; // [esp+10h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+30h] [ebp-20h] BYREF

  v4 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  m_allocator = (vostok::render::base_scene *)scene->m_allocator;
  decrease_quality = m_allocator->decrease_quality;
  v17 = 0;
  v7 = ((int (__thiscall *)(vostok::render::base_scene *, int))decrease_quality)(m_allocator, 152);
  if ( v7 )
  {
    v14.m_object = 0;
    if ( id->m_object )
    {
      v14.m_object = id->m_object;
      _InterlockedExchangeAdd(&id->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,unsigned int>(
      (boost::_bi::value<unsigned int>)ida,
      &v15,
      vostok::render::engine::world::remove_sky_ambient_occlusion,
      scene->m_render_engine_world,
      v14);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v8, v15, v16);
    v18.vtable = 0;
    *(_BYTE *)(v7 + 12) = 0;
    *(_BYTE *)(v7 + 13) = 1;
    *(_DWORD *)(v7 + 80) = 0;
    *(_DWORD *)v7 = &vostok::render::functor_command::`vftable';
    v15.l_.a3_.t_ = (unsigned int)&f;
    v17 = 3;
    *(_DWORD *)(v7 + 88) = 0;
    boost::function0<void>::assign_to_own(
      (boost::function0<void> *)(v7 + 88),
      (const boost::function0<void> *)v15.l_.a3_.t_);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v18, v7 + 120);
    v4 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  }
  else
  {
    v7 = 0;
  }
  m_object = v4[1].m_object;
  v10 = *(_DWORD *)(m_object->m_parent_resources.m_lock + 4) == 0;
  *(_DWORD *)(v7 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_object->log_string, v7);
  m_object->__vftable = (vostok::render::base_scene_vtbl *)v7;
  if ( v10 )
    SetEvent(m_object->grm_satisfaction_tree_hook.right_);
  v11 = v17;
  if ( (v17 & 2) != 0 )
  {
    v11 = v17 & 0xFD;
    if ( v18.vtable )
    {
      if ( ((int)v18.vtable & 1) == 0 )
      {
        v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v18.vtable & 0xFFFFFFFE);
        if ( v12 )
          v12(&v18.functor, &v18.functor, 2);
      }
      v18.vtable = 0;
    }
  }
  if ( (v11 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v13 )
      v13(&f.functor, &f.functor, 2);
  }
}
