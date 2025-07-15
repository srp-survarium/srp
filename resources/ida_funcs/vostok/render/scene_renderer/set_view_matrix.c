void __thiscall vostok::render::scene_renderer::set_view_matrix(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *scene_view,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *view_and_culling_matrix,
        const vostok::math::float4x4 *view_and_culling_matrixa)
{
  bool v4; // zf
  const vostok::math::float4x4 *v5; // eax
  const void *v6; // eax
  vostok::render::functor_with_big_buffer_to_copy_command<vostok::math::float4x4> *v7; // ebx
  boost::function<void __cdecl(vostok::math::float4x4 const &)> *v8; // ecx
  __int32 v9; // eax
  vostok::render::base_scene_view *m_channel; // ebp
  char v11; // bl
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  float v14; // [esp-14h] [ebp-104h]
  boost::arg<1> v15; // [esp-10h] [ebp-100h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > v16; // [esp-Ch] [ebp-FCh] BYREF
  int v17; // [esp+0h] [ebp-F0h]
  int v18; // [esp+14h] [ebp-DCh]
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+18h] [ebp-D8h] BYREF
  boost::function<void __cdecl(vostok::math::float4x4 const &)> on_execute; // [esp+38h] [ebp-B8h] BYREF
  vostok::math::frustum v21; // [esp+78h] [ebp-78h] BYREF

  v4 = scene_view->m_frustum_listener == 0;
  v18 = 0;
  qmemcpy((void *)&scene_view->m_view, view_and_culling_matrixa, sizeof(scene_view->m_view));
  if ( !v4 )
  {
    v16.l_.a2_.t_.m_object = (vostok::render::base_scene_view *)&on_execute;
    v5 = vostok::math::mul4x4(&scene_view->m_view, &scene_view->m_projection);
    vostok::math::frustum::frustum(&v21, v5);
    qmemcpy(scene_view->m_frustum_listener, v6, sizeof(vostok::math::frustum));
  }
  v7 = (vostok::render::functor_with_big_buffer_to_copy_command<vostok::math::float4x4> *)scene_view->m_allocator->call_malloc(
                                                                                            scene_view->m_allocator,
                                                                                            216);
  if ( v7 )
  {
    v15 = 1_19;
    v14 = 0.0;
    if ( view_and_culling_matrix->m_object )
    {
      v14 = *(float *)&view_and_culling_matrix->m_object;
      _InterlockedExchangeAdd(&view_and_culling_matrix->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>,boost::arg<1>>(
      scene_view->m_render_engine_world,
      &v16,
      vostok::render::engine::world::set_view_matrix,
      LODWORD(v14),
      v15);
    boost::function<void __cdecl (vostok::math::float4x4 const &)>::function<void __cdecl (vostok::math::float4x4 const &)>(
      v8,
      v16,
      v17);
    v18 = 3;
    on_defer_execution.vtable = 0;
    vostok::render::functor_with_big_buffer_to_copy_command<vostok::math::float4x4>::functor_with_big_buffer_to_copy_command<vostok::math::float4x4>(
      (boost::function4<void,unsigned int,float,float,char const *> *)&on_execute,
      (boost::function4<void,unsigned int,float,float,char const *> *)&on_defer_execution,
      v7,
      view_and_culling_matrixa);
  }
  else
  {
    v9 = 0;
  }
  m_channel = (vostok::render::base_scene_view *)scene_view->m_channel;
  v4 = *(_DWORD *)(m_channel->m_parent_resources.m_lock + 4) == 0;
  *(_DWORD *)(v9 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_channel->log_string, v9);
  m_channel->__vftable = (vostok::render::base_scene_view_vtbl *)v9;
  if ( v4 )
    SetEvent(m_channel->grm_satisfaction_tree_hook.right_);
  v11 = v18;
  if ( (v18 & 2) != 0 )
  {
    v11 = v18 & 0xFD;
    if ( on_defer_execution.vtable )
    {
      if ( ((int)on_defer_execution.vtable & 1) == 0 )
      {
        v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_defer_execution.vtable & 0xFFFFFFFE);
        if ( v12 )
          v12(&on_defer_execution.functor, &on_defer_execution.functor, 2);
      }
      on_defer_execution.vtable = 0;
    }
  }
  if ( (v11 & 1) != 0 && on_execute.vtable && ((int)on_execute.vtable & 1) == 0 )
  {
    v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_execute.vtable & 0xFFFFFFFE);
    if ( v13 )
      v13(&on_execute.functor, &on_execute.functor, 2);
  }
}
