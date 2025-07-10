void __thiscall vostok::render::scene_renderer::update_lpv_occluder(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *scene,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *id,
        const vostok::math::float4x4 *transform,
        const vostok::math::float4x4 *transforma)
{
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v5; // esi
  vostok::render::base_scene *m_allocator; // ecx
  void (__thiscall *decrease_quality)(struct vostok::resources::resource_base *, unsigned int); // edx
  char v8; // bl
  vostok::render::functor_with_big_buffer_to_copy_command<vostok::math::float4x4> *v9; // edi
  boost::function<void __cdecl(vostok::math::float4x4 const &)> *v10; // ecx
  __int32 v11; // eax
  vostok::render::base_scene *v12; // ecx
  bool v13; // zf
  void (__cdecl *v14)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v15)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::unmanaged_resource *m_object; // [esp-18h] [ebp-68h]
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> v17; // [esp-14h] [ebp-64h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::math::float4x4 const &>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int>,boost::arg<1> > > v18; // [esp-10h] [ebp-60h] BYREF
  int v19; // [esp+0h] [ebp-50h]
  int v20; // [esp+Ch] [ebp-44h]
  boost::function<void __cdecl(vostok::render::base_command &)> on_defer_execution; // [esp+10h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::math::float4x4 const &)> on_execute; // [esp+30h] [ebp-20h] BYREF

  v5 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  m_allocator = (vostok::render::base_scene *)scene->m_allocator;
  decrease_quality = m_allocator->decrease_quality;
  v8 = 0;
  v20 = 0;
  v9 = (vostok::render::functor_with_big_buffer_to_copy_command<vostok::math::float4x4> *)((int (__thiscall *)(vostok::render::base_scene *, int))decrease_quality)(
                                                                                            m_allocator,
                                                                                            216);
  if ( v9 )
  {
    v17.m_object = (vostok::render::base_scene *)(unsigned __int8)1_19;
    m_object = 0;
    if ( id->m_object )
    {
      m_object = id->m_object;
      _InterlockedExchangeAdd(&id->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,unsigned int,vostok::math::float4x4 const &,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,unsigned int,boost::arg<1>>(
      (boost::_bi::value<unsigned int>)transform,
      &v18,
      scene->m_render_engine_world,
      m_object,
      v17);
    boost::function<void __cdecl (vostok::math::float4x4 const &)>::function<void __cdecl (vostok::math::float4x4 const &)>(
      v10,
      v18,
      v19);
    v8 = 3;
    on_defer_execution.vtable = 0;
    vostok::render::functor_with_big_buffer_to_copy_command<vostok::math::float4x4>::functor_with_big_buffer_to_copy_command<vostok::math::float4x4>(
      (boost::function4<void,unsigned int,float,float,char const *> *)&on_execute,
      (boost::function4<void,unsigned int,float,float,char const *> *)&on_defer_execution,
      v9,
      transforma);
    v5 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  }
  else
  {
    v11 = 0;
  }
  v12 = v5[1].m_object;
  v13 = *(_DWORD *)(v12->m_parent_resources.m_lock + 4) == 0;
  *(_DWORD *)(v11 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&v12->log_string, v11);
  v12->__vftable = (vostok::render::base_scene_vtbl *)v11;
  if ( v13 )
    SetEvent(v12->grm_satisfaction_tree_hook.right_);
  if ( (v8 & 2) != 0 )
  {
    v8 &= ~2u;
    if ( on_defer_execution.vtable )
    {
      if ( ((int)on_defer_execution.vtable & 1) == 0 )
      {
        v14 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_defer_execution.vtable & 0xFFFFFFFE);
        if ( v14 )
          v14(&on_defer_execution.functor, &on_defer_execution.functor, 2);
      }
      on_defer_execution.vtable = 0;
    }
  }
  if ( (v8 & 1) != 0 && on_execute.vtable && ((int)on_execute.vtable & 1) == 0 )
  {
    v15 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_execute.vtable & 0xFFFFFFFE);
    if ( v15 )
      v15(&on_execute.functor, &on_execute.functor, 2);
  }
}
