void __thiscall survarium::rifle_scope_cook::on_config_loaded(
        survarium::rifle_scope_cook *this,
        vostok::resources::queries_result *data)
{
  volatile int m_result; // eax
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config_value *v4; // esi
  const char *pointer; // eax
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v6; // ecx
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::configs::binary_config *v8; // eax
  vostok::resources::unmanaged_intrusive_base *v9; // ecx
  void (__thiscall *__ptr64 v10)(survarium::rifle_scope_cook *, vostok::resources::queries_result *, const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *); // [esp-20h] [ebp-68h] BYREF
  void (__thiscall *__ptr64 v11)(survarium::rifle_scope_cook *, vostok::resources::queries_result *, const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *); // [esp-18h] [ebp-60h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v12; // [esp-10h] [ebp-58h] BYREF
  int v13; // [esp+0h] [ebp-48h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> object; // [esp+Ch] [ebp-3Ch] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // [esp+10h] [ebp-38h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *result; // [esp+14h] [ebp-34h]
  vostok::resources::request requests[2]; // [esp+18h] [ebp-30h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+28h] [ebp-20h] BYREF

  m_result = data->m_result;
  result = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &>,boost::_bi::list3<boost::_bi::value<survarium::rifle_scope_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)this;
  if ( m_result == 1 )
  {
    v15.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v15,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v15.m_object;
    object.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &object,
      v15.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v4 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   object.m_object->m_root,
                                                   "data");
    requests[0].path = (const char *)vostok::configs::binary_config_value::operator[](v4, "idle_model")->data.pointer;
    requests[0].id = static_model_instance_class;
    pointer = (const char *)vostok::configs::binary_config_value::operator[](v4, "aimed_model")->data.pointer;
    requests[1].id = static_model_instance_class;
    requests[1].path = pointer;
    v11 = (void (__thiscall *__ptr64)(survarium::rifle_scope_cook *, vostok::resources::queries_result *, const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *))(unsigned int)survarium::rifle_scope_cook::on_subresources_loaded;
    HIDWORD(v10) = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10
    + 1,
      &object);
    LODWORD(v10) = (unsigned __int8)1_110;
    boost::bind<void,survarium::rifle_scope_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> const &,survarium::rifle_scope_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (int)&v12,
      (survarium::rifle_scope_cook *)result,
      v10,
      v11);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      v6,
      v12,
      v13);
    vostok::resources::query_resources(
      requests,
      2u,
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
    v8 = object.m_object;
    v9 = &object.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&object.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v9, v8);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (int)data->m_parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
}
