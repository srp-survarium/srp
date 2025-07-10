void __thiscall survarium::victory_item_cook::on_config_loaded(
        survarium::victory_item_cook *this,
        vostok::resources::queries_result *data)
{
  boost::_bi::list3<boost::_bi::value<survarium::victory_item_cook *>,boost::arg<1>,boost::_bi::value<survarium::victory_item *> > v2; // rdi
  int v3; // eax
  vostok::configs::binary_config *m_object; // ebx
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::victory_item_cook,vostok::resources::queries_result &,survarium::victory_item *>,boost::_bi::list3<boost::_bi::value<survarium::victory_item_cook *>,boost::arg<1>,boost::_bi::value<survarium::victory_item *> > > v6; // [esp-10h] [ebp-50h]
  int v7; // [esp+0h] [ebp-40h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+Ch] [ebp-34h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> cfg; // [esp+10h] [ebp-30h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-2Ch]
  vostok::resources::request requests[1]; // [esp+18h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-20h] BYREF

  v2.a1_.t_ = this;
  parent = data->m_parent_query;
  v8.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v8,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  v2.a3_.t_ = (survarium::victory_item *)v8.m_object;
  cfg.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &cfg,
    v8.m_object);
  if ( v2.a3_.t_ && !_InterlockedExchangeAdd((volatile signed __int32 *)&v2.a3_.t_->m_name_registry_entry, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)&v2.a3_.t_->m_name_registry_entry,
      (vostok::resources::unmanaged_resource *)v2.a3_.t_);
  v3 = (int)v2.a1_.t_->create_resource(v2.a1_.t_);
  m_object = cfg.m_object;
  v2.a3_.t_ = (survarium::victory_item *)v3;
  (*(void (__thiscall **)(int, vostok::configs::binary_config_value *))(*(_DWORD *)v3 + 12))(v3, cfg.m_object->m_root);
  requests[0].id = static_model_instance_class;
  requests[0].path = (const char *)vostok::configs::binary_config_value::operator[](m_object->m_root, "model")->data.pointer;
  callback.vtable = (boost::detail::function::vtable_base *) __thiscall survarium::victory_item_cook::`vcall'{44,{flat}};
  (&callback.vtable)[1] = 0;
  *(boost::_bi::list3<boost::_bi::value<survarium::victory_item_cook *>,boost::arg<1>,boost::_bi::value<survarium::victory_item *> > *)&callback.functor.obj_ptr = v2;
  v6.f_.f_ = (void (__thiscall *__ptr64)(survarium::victory_item_cook *, vostok::resources::queries_result *, survarium::victory_item *))(unsigned int) __thiscall survarium::victory_item_cook::`vcall'{44,{flat}};
  v6.l_ = v2;
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    0,
    (int)&callback,
    (int)v2.a3_.t_,
    v6,
    v7);
  vostok::resources::query_resources(
    requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    0,
    parent,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&callback.functor, &callback.functor, 2);
    }
  }
  if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
}
