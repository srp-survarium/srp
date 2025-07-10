void __thiscall vostok::render::game::renderer::show_text_manager(
        vostok::render::game::renderer *this,
        vostok::render::game::renderer *scene_view,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *tm,
        survarium::flash_text_manager *tma)
{
  void *(__thiscall *call_malloc)(vostok::memory::base_allocator *, unsigned int); // edx
  char v5; // bl
  __int32 v6; // ebp
  boost::function<void __cdecl(void)> *v7; // ecx
  vostok::render::base_scene_view *m_world; // eax
  bool v9; // zf
  void (__cdecl *v10)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v11)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  Scaleform::GFx::DrawTextManager *m_object; // [esp-14h] [ebp-6Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,survarium::flash_text_manager *>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<survarium::flash_text_manager *> > > v13; // [esp-10h] [ebp-68h] BYREF
  int v14; // [esp+0h] [ebp-58h]
  int v15; // [esp+14h] [ebp-44h]
  boost::function4<void,unsigned int,float,float,char const *> v16; // [esp+18h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+38h] [ebp-20h] BYREF

  call_malloc = vostok::render::logic::g_allocator->call_malloc;
  v5 = 0;
  v15 = 0;
  v6 = (int)call_malloc(vostok::render::logic::g_allocator, 152u);
  if ( v6 )
  {
    m_object = 0;
    if ( tm->m_object )
    {
      m_object = (Scaleform::GFx::DrawTextManager *)tm->m_object;
      _InterlockedExchangeAdd(&tm->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,unsigned int>(
      (boost::_bi::value<unsigned int>)tma,
      &v13,
      (void (__thiscall *)(vostok::render::engine::world *, const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, unsigned int))vostok::render::engine::world::show_text_manager,
      scene_view->m_render_engine_world,
      (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>)m_object);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(v7, v13, v14);
    v16.vtable = 0;
    *(_BYTE *)(v6 + 12) = 0;
    *(_BYTE *)(v6 + 13) = 1;
    *(_DWORD *)(v6 + 80) = 0;
    *(_DWORD *)v6 = &vostok::render::functor_command::`vftable';
    v13.l_.a3_.t_ = (survarium::flash_text_manager *)&f;
    v5 = 3;
    *(_DWORD *)(v6 + 88) = 0;
    boost::function0<void>::assign_to_own(
      (boost::function0<void> *)(v6 + 88),
      (const boost::function0<void> *)v13.l_.a3_.t_);
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&v16, v6 + 120);
  }
  else
  {
    v6 = 0;
  }
  m_world = (vostok::render::base_scene_view *)scene_view->m_world;
  v9 = scene_view->m_world->m_logic_channel.m_channel.m_forward_queue.m_tail->next == 0;
  *(_DWORD *)(v6 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_world->log_string, v6);
  m_world->__vftable = (vostok::render::base_scene_view_vtbl *)v6;
  if ( v9 )
    SetEvent(m_world->grm_satisfaction_tree_hook.right_);
  if ( (v5 & 2) != 0 )
  {
    v5 &= ~2u;
    if ( v16.vtable )
    {
      if ( ((int)v16.vtable & 1) == 0 )
      {
        v10 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v16.vtable & 0xFFFFFFFE);
        if ( v10 )
          v10(&v16.functor, &v16.functor, 2);
      }
      v16.vtable = 0;
    }
  }
  if ( (v5 & 1) != 0 && f.vtable && ((int)f.vtable & 1) == 0 )
  {
    v11 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
    if ( v11 )
      v11(&f.functor, &f.functor, 2);
  }
}
