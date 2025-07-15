void __thiscall survarium::empty_hands_cook::on_empty_hands_config_loaded(
        survarium::empty_hands_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::configs::binary_config *m_object; // esi
  int v3; // esi
  void *v4; // esp
  vostok::resources::request *v5; // edi
  const char **pointer; // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v8; // eax
  vostok::resources::unmanaged_intrusive_base *v9; // ecx
  void (__thiscall *__ptr64 v10)(vostok::animation::skeleton_cook *, vostok::resources::queries_result *); // [esp-Ch] [ebp-78h]
  vostok::resources::request v11[2]; // [esp+0h] [ebp-6Ch] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+10h] [ebp-5Ch] BYREF
  vostok::configs::binary_config_value animations_node; // [esp+30h] [ebp-3Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::skeleton_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::skeleton_cook *>,boost::arg<1> > > v14; // [esp+4Ch] [ebp-20h]
  survarium::empty_hands_cook *v15; // [esp+5Ch] [ebp-10h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16; // [esp+60h] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+64h] [ebp-8h] BYREF

  v15 = this;
  v16.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v16,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v16.m_object;
  config.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &config,
    v16.m_object);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  animations_node = *vostok::configs::binary_config_value::operator[](config.m_object->m_root, "user_animations");
  v3 = 24 * HIWORD(*(_DWORD *)&animations_node.type) / 24;
  v4 = alloca(8 * v3);
  v5 = v11;
  if ( v3 )
  {
    pointer = (const char **)animations_node.data.pointer;
    do
    {
      if ( v5 )
      {
        v5->path = *pointer;
        v5->id = animation_class;
      }
      ++v5;
      pointer += 6;
      --v3;
    }
    while ( v3 );
  }
  HIDWORD(v10) = v15;
  LODWORD(v10) = 0;
  v14 = *boost::bind<void,survarium::empty_hands_cook,vostok::resources::queries_result &,survarium::empty_hands_cook *,boost::arg<1>>(
           (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::skeleton_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::skeleton_cook *>,boost::arg<1> > > *)&animations_node.id,
           (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::skeleton_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::skeleton_cook *>,boost::arg<1> > > *)survarium::empty_hands_cook::on_empty_hands_animations_loaded,
           v10);
  if ( survarium::generate_shaders_world::is_loading() )
  {
    callback.vtable = 0;
  }
  else
  {
    *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::animation::skeleton_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::animation::skeleton_cook *>,boost::arg<1> > > *)&callback.functor.obj_ptr = v14;
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::empty_hands_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::empty_hands_cook *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  vostok::resources::query_resources(
    v11,
    v5 - v11,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0,
    data->m_parent_query,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v7 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v7 )
        v7(&callback.functor, &callback.functor, 2);
    }
  }
  v8 = config.m_object;
  v9 = &config.m_object->vostok::resources::unmanaged_intrusive_base;
  if ( !_InterlockedExchangeAdd(&config.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(v9, v8);
}
