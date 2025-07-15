char __thiscall vostok::resources::device_manager::pre_allocate(
        vostok::resources::device_manager *this,
        vostok::resources::device_manager *query,
        vostok::resources::query_result *querya)
{
  unsigned int m_size; // edx
  vostok::resources::query_result *v4; // ecx
  _RTL_CRITICAL_SECTION *p_m_pre_allocated_mutex; // esi
  vostok::fs_new::asynchronous_device_interface *v7; // ecx
  boost::function<bool __cdecl(vostok::fs_new::synchronous_device_interface &)> *v8; // ecx
  vostok::resources::query_result *v9; // ecx
  vostok::vfs::base_node<1> *v10; // esi
  vostok::resources::query_result *v11; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,vostok::resources::device_manager,vostok::resources::query_result *,vostok::fs_new::synchronous_device_interface const &>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1> > > v12; // [esp-50h] [ebp-ECh]
  boost::function<bool __cdecl(vostok::fs_new::synchronous_device_interface &)> v13; // [esp-44h] [ebp-E0h] BYREF
  boost::function<void __cdecl(bool)> v14; // [esp-24h] [ebp-C0h] BYREF
  vostok::threading::event *v15; // [esp-4h] [ebp-A0h]
  vostok::const_buffer *v16; // [esp+0h] [ebp-9Ch]
  vostok::fs_new::asynchronous_device_interface *async_device; // [esp+14h] [ebp-88h]
  vostok::mutable_buffer v18; // [esp+18h] [ebp-84h] BYREF
  vostok::vfs::vfs_iterator v19; // [esp+20h] [ebp-7Ch] BYREF
  __int64 v20; // [esp+30h] [ebp-6Ch]
  __int64 v21; // [esp+3Ch] [ebp-60h]
  vostok::fs_new::query_custom_operation_args args; // [esp+48h] [ebp-54h] BYREF

  if ( (querya->m_flags & 2) != 0 )
  {
    m_size = querya->m_raw_unmanaged_buffer.m_size;
    v18.m_data = querya->m_raw_unmanaged_buffer.m_data;
    v18.m_size = m_size;
    if ( !vostok::mutable_buffer::operator bool(&v18)
      && !querya->m_raw_managed_resource.m_object
      && vostok::resources::query_result::allocate_raw_managed_resource_if_needed(v4) == allocation_result_failed )
    {
      vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::resources::query_result,vostok::resources::query_result *,608,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)querya,
        &query->m_finished.m_size);
      return 0;
    }
  }
  if ( querya->m_error_type == error_type_out_of_memory )
    return 0;
  p_m_pre_allocated_mutex = (_RTL_CRITICAL_SECTION *)&query->m_pre_allocated_mutex;
  v19.m_link_target = (vostok::vfs::base_node<1> *)&query->m_pre_allocated_mutex;
  vostok::threading::mutex::lock(&query->m_pre_allocated_mutex);
  v7 = *(vostok::fs_new::asynchronous_device_interface **)((char *)&loc_205F8
                                                         + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  v15 = (vostok::threading::event *)((char *)&dword_203D0
                                   + (unsigned int)vostok::resources::g_resources_manager.m_variable);
  async_device = v7;
  LODWORD(v21) = vostok::resources::device_manager::on_query_processed;
  HIDWORD(v21) = query;
  *(_QWORD *)(&v13.functor.data + 12) = v21;
  LODWORD(v20) = vostok::resources::device_manager::process_query;
  HIDWORD(v20) = query;
  v13.functor.vostok_pointer_size_alignment[5] = querya;
  boost::function<void __cdecl (bool)>::function<void __cdecl (bool)>(
    (boost::function<void __cdecl(bool)> *)querya,
    (int)&v14,
    (unsigned int)&query->m_pre_allocated_mutex,
    *((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1> > > *)&v13.functor.data
    + 1),
    (int)v14.vtable);
  *(_QWORD *)&v12.f_.f_ = v20;
  v12.l_.a2_.t_ = querya;
  boost::function<bool __cdecl (vostok::fs_new::synchronous_device_interface &)>::function<bool __cdecl (vostok::fs_new::synchronous_device_interface &)>(
    v8,
    (int)&v13,
    (unsigned int)&query->m_pre_allocated_mutex,
    v12,
    (int)v13.vtable);
  vostok::fs_new::query_custom_operation_args::query_custom_operation_args(&args, v13, v14, v15);
  if ( (querya->m_flags & 2) != 0 )
  {
    vostok::resources::query_result::pin_raw_buffer(v9, v16);
    v10 = vostok::mutable_buffer::size(&v19);
    vostok::resources::query_result::unpin_raw_buffer(v11, (const vostok::const_buffer *)&v19);
    query->m_pre_allocated_size += (int)v10;
    p_m_pre_allocated_mutex = (_RTL_CRITICAL_SECTION *)v19.m_link_target;
  }
  vostok::fs_new::asynchronous_device_interface::query_custom_operation(
    async_device,
    &args,
    &vostok::memory::g_resources_helper_allocator);
  vostok::fs_new::query_custom_operation_args::~query_custom_operation_args(&args);
  LeaveCriticalSection(p_m_pre_allocated_mutex);
  return 1;
}
