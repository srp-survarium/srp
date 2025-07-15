void __thiscall survarium::game::on_render_output_window_created(
        survarium::game *this,
        vostok::resources::queries_result *data)
{
  vostok::configs::binary_config *m_object; // edi
  vostok::configs::binary_config *v4; // eax
  vostok::resources::unmanaged_intrusive_base *v5; // ecx
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v7; // [esp-10h] [ebp-58h]
  int v8; // [esp+0h] [ebp-48h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+10h] [ebp-38h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+14h] [ebp-34h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+18h] [ebp-30h] BYREF
  vostok::resources::request requests[2]; // [esp+38h] [ebp-10h] BYREF

  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v10.m_object;
  v9.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v9,
    v10.m_object);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&this->m_render_output_window,
    (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&v9);
  v4 = v9.m_object;
  if ( v9.m_object )
  {
    v5 = &v9.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v9.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v5, v4);
  }
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  callback.vtable = (boost::detail::function::vtable_base *)survarium::game::on_base_resources_created;
  (&callback.vtable)[1] = 0;
  v7.f_.f_ = (void (__thiscall *__ptr64)(survarium::game *, vostok::resources::queries_result *))(unsigned int)survarium::game::on_base_resources_created;
  callback.functor.obj_ptr = this;
  requests[0].path = "items_dictionary";
  requests[0].id = items_dictionary_class;
  requests[1].path = "resources/flash_movies/chat.swf";
  requests[1].id = flash_movie_class;
  *(_QWORD *)&v7.l_.a1_.t_ = *(_QWORD *)&callback.functor.obj_ptr;
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    0,
    (int)&callback,
    (int)this,
    v7,
    v8);
  vostok::resources::query_resources(
    requests,
    2u,
    &callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0,
    0,
    assert_on_fail_true);
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v6 )
      v6(&callback.functor, &callback.functor, 2);
  }
}
