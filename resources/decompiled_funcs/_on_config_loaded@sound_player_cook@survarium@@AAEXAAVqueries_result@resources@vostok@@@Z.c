void __thiscall survarium::sound_player_cook::on_config_loaded(
        survarium::sound_player_cook *this,
        vostok::resources::unmanaged_resource *data)
{
  vostok::resources::query_result_for_cook *m_lock; // ecx
  vostok::resources::query_result_for_cook *m_uid; // edi
  vostok::resources::unmanaged_resource *v4; // esi
  vostok::resources::unmanaged_resource *v5; // esi
  const vostok::configs::binary_config_value *v6; // eax
  vostok::configs::binary_config_value *pointer; // edi
  int v8; // ecx
  void *v9; // esp
  int *v10; // ebx
  const void *v11; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v12; // ecx
  void (__cdecl *v13)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::resources::unmanaged_intrusive_base *v14; // ecx
  void (__thiscall *__ptr64 v15)(survarium::animation_space_graph_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>); // [esp-20h] [ebp-64h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::sound_player_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<survarium::sound_player_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v16; // [esp-10h] [ebp-54h] BYREF
  int v17[4]; // [esp+0h] [ebp-44h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+10h] [ebp-34h] BYREF
  const vostok::resources::request *requests; // [esp+30h] [ebp-14h]
  vostok::resources::query_result_for_cook *parent; // [esp+34h] [ebp-10h]
  survarium::sound_player_cook *v21; // [esp+38h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+3Ch] [ebp-8h] BYREF

  v21 = this;
  m_lock = (vostok::resources::query_result_for_cook *)data->m_parent_resources.m_lock;
  m_uid = (vostok::resources::query_result_for_cook *)data->m_uid;
  parent = m_uid;
  if ( m_lock == (vostok::resources::query_result_for_cook *)1 )
  {
    it_end = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&it_end,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data[1].m_children_resources);
    v4 = (vostok::resources::unmanaged_resource *)it_end;
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (vostok::configs::binary_config *)it_end);
    if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
    v5 = data;
    v6 = vostok::configs::binary_config_value::operator[](
           (vostok::configs::binary_config_value *)data[1].__vftable,
           "sounds");
    pointer = (vostok::configs::binary_config_value *)v6->data.pointer;
    v8 = 24 * v6->count;
    it_end = (const vostok::configs::binary_config_value *)((char *)v6->data.pointer + v8);
    v9 = alloca(8 * (v8 / 24));
    v10 = v17;
    for ( requests = (const vostok::resources::request *)v17; pointer != it_end; v10 += 2 )
    {
      v11 = vostok::configs::binary_config_value::operator[](pointer, "filename")->data.pointer;
      if ( v10 )
      {
        *v10 = (int)v11;
        v10[1] = 258;
      }
      ++pointer;
    }
    _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
    HIDWORD(v15) = v21;
    LODWORD(v15) = 0;
    boost::bind<void,survarium::sound_player_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,survarium::sound_player_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16,
      (vostok::configs::binary_config *)survarium::sound_player_cook::on_sounds_loaded,
      v15,
      (survarium::animation_space_graph_cook *)*(unsigned __int8 *)&1_104,
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)v5);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v12,
      v16,
      v17[0]);
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
        v13 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
        if ( v13 )
          v13(&callback.functor, &callback.functor, 2);
      }
    }
    v14 = &data->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&data->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v14, data);
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
