void __thiscall survarium::animation_space_graph_cook::on_options_received(
        survarium::animation_space_graph_cook *this,
        vostok::resources::unmanaged_resource *data)
{
  vostok::resources::query_result_for_cook *m_lock; // ecx
  vostok::resources::query_result_for_cook *m_uid; // edi
  vostok::resources::unmanaged_resource *v4; // esi
  vostok::configs::binary_config_value *v5; // eax
  const vostok::configs::binary_config_value *v6; // edi
  void *v7; // esp
  vostok::configs::binary_config_value *pointer; // esi
  const vostok::configs::binary_config_value *v9; // edi
  int *v10; // ebx
  const vostok::configs::binary_config_value *v11; // eax
  int *v12; // ecx
  int v13; // edx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v14; // ecx
  void (__cdecl *v15)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::unmanaged_intrusive_base *v16; // ecx
  void (__thiscall *__ptr64 v17)(survarium::animation_space_graph_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>); // [esp-20h] [ebp-64h]
  vostok::resources::unmanaged_resource *v18; // [esp-14h] [ebp-58h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animation_space_graph_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<survarium::animation_space_graph_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v19; // [esp-10h] [ebp-54h] BYREF
  int v20[4]; // [esp+0h] [ebp-44h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+10h] [ebp-34h] BYREF
  const vostok::resources::request *requests; // [esp+30h] [ebp-14h]
  vostok::resources::query_result_for_cook *parent; // [esp+34h] [ebp-10h]
  survarium::animation_space_graph_cook *v24; // [esp+38h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end_groups; // [esp+3Ch] [ebp-8h] BYREF

  v24 = this;
  m_lock = (vostok::resources::query_result_for_cook *)data->m_parent_resources.m_lock;
  m_uid = (vostok::resources::query_result_for_cook *)data->m_uid;
  parent = m_uid;
  if ( m_lock == (vostok::resources::query_result_for_cook *)1 )
  {
    it_end_groups = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&it_end_groups,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data[1].m_children_resources);
    v4 = (vostok::resources::unmanaged_resource *)it_end_groups;
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (vostok::configs::binary_config *)it_end_groups);
    if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
    v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   (vostok::configs::binary_config_value *)data[1].__vftable,
                                                   "animation_space_graph");
    v6 = vostok::configs::binary_config_value::operator[](v5, "groups");
    v7 = alloca(8 * survarium::get_animation_vertices_count(v6));
    pointer = (vostok::configs::binary_config_value *)v6->data.pointer;
    v9 = (const vostok::configs::binary_config_value *)((char *)v6->data.pointer + 24 * v6->count);
    v10 = v20;
    requests = (const vostok::resources::request *)v20;
    for ( it_end_groups = v9; pointer != v9; ++pointer )
    {
      v11 = vostok::configs::binary_config_value::operator[](pointer, "vertices");
      v12 = (int *)v11->data.pointer;
      v13 = (int)v11->data.pointer + 24 * v11->count;
      if ( v11->data.pointer != (const void *)v13 )
      {
        do
        {
          if ( v10 )
          {
            *v10 = *v12;
            v10[1] = 61;
          }
          v12 += 6;
          v10 += 2;
        }
        while ( v12 != (int *)v13 );
        v9 = it_end_groups;
      }
    }
    v18 = data;
    _InterlockedExchangeAdd(&data->m_reference_count, 1u);
    HIDWORD(v17) = v24;
    LODWORD(v17) = 0;
    boost::bind<void,survarium::sound_player_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::sound_player_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v19,
      (vostok::configs::binary_config *)survarium::animation_space_graph_cook::on_animations_loaded,
      v17,
      (survarium::animation_space_graph_cook *)*(unsigned __int8 *)&1_106,
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)v18);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v14,
      v19,
      v20[0]);
    vostok::resources::query_resources(
      requests,
      ((char *)v10 - (char *)requests) >> 3,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
      0,
      parent,
      assert_on_fail_true);
    if ( callback.vtable )
    {
      if ( ((int)callback.vtable & 1) == 0 )
      {
        v15 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v15 )
          v15(&callback.functor, &callback.functor, 2);
      }
    }
    v16 = &data->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&data->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v16, data);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_lock,
      (int)m_uid,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
