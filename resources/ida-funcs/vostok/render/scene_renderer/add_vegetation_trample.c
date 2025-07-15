void __thiscall vostok::render::scene_renderer::add_vegetation_trample(
        vostok::render::scene_renderer *this,
        vostok::render::scene_renderer *scene,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *desc,
        const vostok::render::trample_desc *desca)
{
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *v4; // esi
  vostok::render::base_scene *m_allocator; // ecx
  void (__thiscall *decrease_quality)(struct vostok::resources::resource_base *, unsigned int); // edx
  char v7; // bl
  int v8; // ebp
  boost::function<void __cdecl(vostok::render::trample_desc const &)> *v9; // ecx
  __int32 v10; // eax
  vostok::render::base_scene *m_object; // ecx
  bool v12; // dl
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  void (__cdecl *v14)(_BYTE *, _BYTE *, int); // eax
  float v15; // [esp-14h] [ebp-6Ch]
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> v16; // [esp-10h] [ebp-68h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::render::trample_desc const &>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > v17; // [esp-Ch] [ebp-64h] BYREF
  const boost::function<void __cdecl(vostok::render::base_command &)> *v18; // [esp+0h] [ebp-58h]
  int v19; // [esp+14h] [ebp-44h]
  boost::function4<void,unsigned int,float,float,char const *> data; // [esp+18h] [ebp-40h] BYREF
  int v21; // [esp+38h] [ebp-20h] BYREF
  _BYTE v22[24]; // [esp+40h] [ebp-18h] BYREF

  v4 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  m_allocator = (vostok::render::base_scene *)scene->m_allocator;
  decrease_quality = m_allocator->decrease_quality;
  v7 = 0;
  v19 = 0;
  v8 = ((int (__thiscall *)(vostok::render::base_scene *, int))decrease_quality)(m_allocator, 176);
  if ( v8 )
  {
    v16.m_object = (vostok::render::base_scene *)(unsigned __int8)1_19;
    v15 = 0.0;
    if ( desc->m_object )
    {
      v15 = *(float *)&desc->m_object;
      _InterlockedExchangeAdd(&desc->m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::render::trample_desc const &,vostok::render::engine::world *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,boost::arg<1>>(
      scene->m_render_engine_world,
      &v17,
      (vostok::resources::unmanaged_resource *)LODWORD(v15),
      v16);
    boost::function<void __cdecl (vostok::render::trample_desc const &)>::function<void __cdecl (vostok::render::trample_desc const &)>(
      v9,
      v17,
      (int)v18);
    v7 = 3;
    data.vtable = 0;
    vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::trample_desc>::functor_with_big_buffer_to_copy_command<vostok::render::trample_desc>(
      (vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::trample_desc> *)&v21,
      v8,
      desca,
      &data,
      v18);
    v4 = (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)scene;
  }
  else
  {
    v10 = 0;
  }
  m_object = v4[1].m_object;
  v12 = *(_DWORD *)(m_object->m_parent_resources.m_lock + 4) == 0;
  *(_DWORD *)(v10 + 4) = 0;
  _InterlockedExchange((volatile __int32 *)&m_object->log_string, v10);
  m_object->__vftable = (vostok::render::base_scene_vtbl *)v10;
  if ( v12 )
    SetEvent(m_object->grm_satisfaction_tree_hook.right_);
  if ( (v7 & 2) != 0 )
  {
    v7 &= ~2u;
    if ( data.vtable )
    {
      if ( ((int)data.vtable & 1) == 0 )
      {
        v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)data.vtable & 0xFFFFFFFE);
        if ( v13 )
          v13(&data.functor, &data.functor, 2);
      }
      data.vtable = 0;
    }
  }
  if ( (v7 & 1) != 0 && v21 && (v21 & 1) == 0 )
  {
    v14 = *(void (__cdecl **)(_BYTE *, _BYTE *, int))(v21 & 0xFFFFFFFE);
    if ( v14 )
      v14(v22, v22, 2);
  }
}
