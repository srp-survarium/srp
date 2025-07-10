void __usercall vostok::resources::game_resources_manager::dispatch_capture(
        vostok::resources::game_resources_manager *this@<ecx>,
        vostok::resources::game_resources_manager *a2@<eax>,
        double a3@<st0>)
{
  char v4; // dl
  volatile signed __int32 *v5; // eax
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_intrusive_base *v7; // ecx
  vostok::resources::managed_resource *v8; // [esp-4h] [ebp-18h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> unmanaged_resource; // [esp+Ch] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> managed_resource; // [esp+10h] [ebp-4h] BYREF

  vostok::resources::game_resources_manager::capture_resource(
    (vostok::intrusive_double_linked_list<vostok::resources::resource_base,vostok::resources::resource_base *,156,152,vostok::threading::single_threading_policy,vostok::size_policy,vostok::debug_policy> *)this,
    a3,
    a2);
  v8 = (unsigned __int8)((this->m_resources_to_capture.m_mutex.m_mutex[0] & 1) - 1) == 0
     ? (vostok::resources::managed_resource *)this
     : 0;
  managed_resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &managed_resource,
    v8);
  v4 = this->m_resources_to_capture.m_mutex.m_mutex[0] & 4;
  unmanaged_resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&unmanaged_resource,
    v4 != 4 ? 0 : (vostok::configs::binary_config *)this);
  if ( (this->m_resources_to_capture.m_mutex.m_mutex[0] & 1) != 0 && this )
  {
    v5 = (volatile signed __int32 *)&this[1].m_resources_to_capture.m_mutex.m_mutex[1] + 1;
  }
  else if ( (this->m_resources_to_capture.m_mutex.m_mutex[0] & 4) != 0 && this )
  {
    v5 = (volatile signed __int32 *)&this[1].m_resources_to_capture.vostok::threading::mutex;
  }
  else
  {
    v5 = 0;
  }
  _InterlockedExchangeAdd(v5, 0xFFFFFFFF);
  vostok::threading::interlocked_and(v5 + 1, 0xFFFFFFFD);
  m_object = unmanaged_resource.m_object;
  if ( unmanaged_resource.m_object )
  {
    v7 = &unmanaged_resource.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&unmanaged_resource.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v7, m_object);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&managed_resource);
}
