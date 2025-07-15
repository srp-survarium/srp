void __cdecl on_mounted_resources(
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> *out_mount,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *out_config_ptr,
        vostok::intrusive_ptr<vostok::resources::fs_task_unmount,vostok::resources::intrusive_fs_task_unmount_base,vostok::threading::simple_lock> result)
{
  vostok::resources::fs_task_unmount *m_object; // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *> > > v5; // [esp-8h] [ebp-38h]
  vostok::resources::intrusive_fs_task_unmount_base *v6; // [esp+0h] [ebp-30h]
  vostok::variant<32> *user_data; // [esp+4h] [ebp-2Ch] BYREF
  vostok::resources::request requests; // [esp+8h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+10h] [ebp-20h] BYREF

  if ( !result.m_object )
    vostok::debug::terminate("Cannot mount resources. Please reinstall an application and try again.");
  _InterlockedExchangeAdd(&result.m_object->m_reference_count, 1u);
  m_object = out_mount->m_object;
  out_mount->m_object = result.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(m_object, v6);
  v5.l_.a2_.t_ = out_config_ptr;
  v5.f_ = (void (__cdecl *)(vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *))on_shader_masks_ready;
  callback.vtable = 0;
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *>>>>(
    (boost::function1<void,vostok::resources::queries_result &> *)out_config_ptr,
    (boost::_bi::bind_t<void,void (__cdecl*)(vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *),boost::_bi::list2<boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *> > > *)&callback,
    v5);
  requests.path = "resources/shaders/masks";
  requests.id = binary_config_class_impl;
  user_data = 0;
  vostok::resources::query_resources(
    &requests,
    1u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    &vostok::memory::g_mt_allocator,
    (const vostok::variant<32> **)&user_data,
    0,
    assert_on_fail_true);
  if ( callback.vtable )
  {
    if ( ((int)callback.vtable & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v4 )
        v4(&callback.functor, &callback.functor, 2);
    }
  }
  if ( !_InterlockedExchangeAdd(&result.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::intrusive_fs_task_unmount_base::destroy(result.m_object, v6);
}
