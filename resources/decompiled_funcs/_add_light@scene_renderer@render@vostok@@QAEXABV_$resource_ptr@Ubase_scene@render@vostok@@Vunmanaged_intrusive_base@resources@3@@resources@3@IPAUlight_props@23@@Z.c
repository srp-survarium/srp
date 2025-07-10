void __thiscall vostok::render::scene_renderer::add_light(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *scene,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *id,
        vostok::render::light_props *props,
        vostok::render::light_props *propsa)
{
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v5; // esi
  vostok::render::base_scene *m_allocator; // ecx
  void (__thiscall *decrease_quality)(struct vostok::resources::resource_base *, unsigned int); // edx
  char v8; // bl
  __int32 v9; // edi
  boost::function<void __cdecl(void)> *v10; // ecx
  vostok::render::base_scene *m_object; // eax
  bool v12; // zf
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> v15; // [esp-18h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::_bi::value<vostok::render::light_props *> > > v16; // [esp-14h] [ebp-64h] BYREF
  int v17; // [esp+0h] [ebp-50h]
  int v18; // [esp+Ch] [ebp-44h]
  boost::function4<void,unsigned int,float,float,char const *> v19; // [esp+10h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+30h] [ebp-20h] BYREF

  v5 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  m_allocator = (vostok::render::base_scene *)scene->m_allocator;
  decrease_quality = m_allocator->decrease_quality;
  v8 = 0;
  v18 = 0;
  v9 = ((int (__thiscall *)(vostok::render::base_scene *, int))decrease_quality)(m_allocator, 152);
  if ( v9 )
  {
    v15.m_object = 0;
    if ( id->m_object )
    {
      v15.m_object = id->m_object;
      _InterlockedExchangeAdd(&id->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::light_props *,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,unsigned int,vostok::render::light_props *>(
      (boost::_bi::value<unsigned int>)props,
      propsa,
      &v16,
      vostok::render::engine::world::add_light,
      scene->m_render_engine_world,
      v15);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v10, v16, v17);
    v19.vtable = 0;
    *(_BYTE *)(v9 + 12) = 0;
    *(_DWORD *)(v9 + 80) = 0;
    *(_BYTE *)(v9 + 13) = 1;
    *(_DWORD *)v9 = &vostok::render::functor_command::`vftable';
    *(_DWORD *)(v9 + 88) = 0;
    v8 = 3;
    boost::function0<void>::assign_to_own((boost::function0<void> *)(v9 + 88), &f);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v19, v9 + 120);
    v5 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  }
  else
  {
    v9 = 0;
  }
  m_object = v5[1].m_object;
  v12 = *(_DWORD *)(m_object->m_parent_resources.m_lock + 4) == 0;
  *(_DWORD *)(v9 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_object->log_string, v9);
  m_object->__vftable = (vostok::render::base_scene_vtbl *)v9;
  if ( v12 )
    SetEvent(m_object->grm_satisfaction_tree_hook.right_);
  if ( (v8 & 2) != 0 )
  {
    v8 &= ~2u;
    if ( v19.vtable )
    {
      if ( ((int)v19.vtable & 1) == 0 )
      {
        v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v19.vtable & 0xFFFFFFFE);
        if ( v13 )
          v13(&v19.functor, &v19.functor, 2);
      }
      v19.vtable = 0;
    }
  }
  if ( (v8 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v14 )
      v14(&f.functor, &f.functor, 2);
  }
}
