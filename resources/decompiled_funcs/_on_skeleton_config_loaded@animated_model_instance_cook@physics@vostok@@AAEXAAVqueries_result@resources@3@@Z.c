void __thiscall vostok::physics::animated_model_instance_cook::on_skeleton_config_loaded(
        vostok::physics::animated_model_instance_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config *v5; // edi
  const char **v6; // eax
  void (__cdecl *v7)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > v8; // [esp-8h] [ebp-48h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+Ch] [ebp-34h] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> skeleton_config; // [esp+10h] [ebp-30h] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+14h] [ebp-2Ch]
  vostok::resources::request requests[1]; // [esp+18h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-20h] BYREF

  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  parent = data->m_parent_query;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v9.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v9,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
    m_object = v9.m_object;
    skeleton_config.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &skeleton_config,
      v9.m_object);
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    v5 = skeleton_config.m_object;
    v6 = (const char **)vostok::configs::binary_config_value::operator[](skeleton_config.m_object->m_root, "skeleton");
    v8.l_.a1_.t_ = this;
    v8.f_.f_ = vostok::physics::animated_model_instance_cook::on_subresources_loaded;
    requests[0].path = *v6;
    requests[0].id = skeleton_class;
    callback.vtable = 0;
    boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1>>>>(
      (boost::function1<void,vostok::resources::queries_result &> *)requests[0].path,
      (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::physics::animated_model_instance_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::physics::animated_model_instance_cook *>,boost::arg<1> > > *)&callback,
      v8);
    vostok::resources::query_resources(
      requests,
      1u,
      (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
      this->m_allocator,
      0,
      parent,
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
    if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
}
