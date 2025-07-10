void __thiscall vostok::render::scene_renderer::build_lpv_geometry(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *scene,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scenea)
{
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v3; // esi
  vostok::render::base_scene *m_allocator; // ecx
  void (__thiscall *decrease_quality)(struct vostok::resources::resource_base *, unsigned int); // edx
  char v6; // bl
  __int32 v7; // edi
  boost::function<void __cdecl(void)> *v8; // ecx
  vostok::render::base_scene *v9; // eax
  bool v10; // zf
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::unmanaged_resource *m_object; // [esp-10h] [ebp-60h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list2<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> > > > v14; // [esp-Ch] [ebp-5Ch] BYREF
  int v15; // [esp+0h] [ebp-50h]
  int v16; // [esp+Ch] [ebp-44h]
  boost::function4<void,unsigned int,float,float,char const *> v17; // [esp+10h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+30h] [ebp-20h] BYREF

  v3 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  m_allocator = (vostok::render::base_scene *)scene->m_allocator;
  decrease_quality = m_allocator->decrease_quality;
  v6 = 0;
  v16 = 0;
  v7 = ((int (__thiscall *)(vostok::render::base_scene *, int))decrease_quality)(m_allocator, 152);
  if ( v7 )
  {
    m_object = 0;
    if ( scenea->m_object )
    {
      m_object = scenea->m_object;
      _InterlockedExchangeAdd(&scenea->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>(
      scene->m_render_engine_world,
      &v14,
      m_object);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v8, v14, v15);
    v17.vtable = 0;
    *(_BYTE *)(v7 + 12) = 0;
    *(_BYTE *)(v7 + 13) = 1;
    *(_DWORD *)(v7 + 80) = 0;
    *(_DWORD *)v7 = &vostok::render::functor_command::`vftable';
    v14.l_.a2_.t_.m_object = (vostok::render::base_scene *)&f;
    v6 = 3;
    *(_DWORD *)(v7 + 88) = 0;
    boost::function0<void>::assign_to_own(
      (boost::function0<void> *)(v7 + 88),
      (const boost::function0<void> *)v14.l_.a2_.t_.m_object);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v17, v7 + 120);
    v3 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  }
  else
  {
    v7 = 0;
  }
  v9 = v3[1].m_object;
  v10 = *(_DWORD *)(v9->m_parent_resources.m_lock + 4) == 0;
  *(_DWORD *)(v7 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&v9->log_string, v7);
  v9->__vftable = (vostok::render::base_scene_vtbl *)v7;
  if ( v10 )
    SetEvent(v9->grm_satisfaction_tree_hook.right_);
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
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
  if ( (v6 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v12 )
      v12(&f.functor, &f.functor, 2);
  }
}
