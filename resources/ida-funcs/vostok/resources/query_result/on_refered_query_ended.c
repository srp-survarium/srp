void __userpurge vostok::resources::query_result::on_refered_query_ended(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>,
        vostok::resources::query_result *refered_query)
{
  vostok::resources::query_result *v3; // ebp
  vostok::resources::query_result *v5; // eax
  vostok::resources::managed_resource *m_object; // eax
  vostok::resources::cook_base::result_enum m_create_resource_result; // eax
  vostok::resources::query_result *v8; // ecx
  int v9; // ecx
  vostok::resources::cook_base *cook; // eax
  int v11; // ecx
  vostok::resources::cook_base *v12; // eax
  _DWORD *v13; // eax
  vostok::resources::query_result_for_cook *v14; // ecx
  vostok::resources::query_result *v15; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v16; // [esp+10h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v17; // [esp+14h] [ebp-Ch] BYREF
  vostok::mutable_buffer v18; // [esp+18h] [ebp-8h] BYREF

  v3 = refered_query;
  refered_query = 0;
  *(_DWORD *)(a2 + 256) = v3->m_error_type;
  refered_query = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&refered_query,
    &v3->m_raw_managed_resource);
  v5 = refered_query;
  refered_query = *(vostok::resources::query_result **)(a2 + 632);
  *(_DWORD *)(a2 + 632) = v5;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&refered_query);
  *(vostok::mutable_buffer *)(a2 + 636) = v3->m_raw_unmanaged_buffer;
  v16.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v16,
    &v3->m_managed_resource);
  m_object = v16.m_object;
  v16.m_object = *(vostok::resources::managed_resource **)(a2 + 216);
  *(_DWORD *)(a2 + 216) = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v16);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    (vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 220),
    &v3->m_unmanaged_resource);
  m_create_resource_result = v3->m_create_resource_result;
  if ( m_create_resource_result == result_postponed )
  {
    if ( (((unsigned int)&loc_1FFFFE + 2) & *(_DWORD *)(a2 + 688)) == 0 )
      *(_DWORD *)(a2 + 260) = 2;
  }
  else
  {
    *(_DWORD *)(a2 + 256) = v3->m_error_type;
    *(_DWORD *)(a2 + 260) = m_create_resource_result;
  }
  vostok::threading::interlocked_or((volatile int *)(a2 + 688), 0x2000u);
  vostok::resources::query_result::clear_reference(v8, a2);
  if ( v3->m_error_type == error_type_unset )
  {
    cook = vostok::resources::resources_manager::find_cook(v9, *(vostok::resources::class_id_enum *)(a2 + 132));
    if ( cook && cook->m_reuse_type == reuse_raw )
    {
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(a2 + 220),
        0);
      v17.m_object = *(vostok::resources::managed_resource **)(a2 + 216);
      *(_DWORD *)(a2 + 216) = 0;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v17);
      v12 = vostok::resources::resources_manager::find_cook(v11, *(vostok::resources::class_id_enum *)(a2 + 132));
      if ( !v12 || (v12->m_flags.m_flags & 0x10) == 0x10 )
      {
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
          (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(a2 + 632),
          0);
        boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
          &v18,
          0,
          0);
        *(_DWORD *)(a2 + 636) = *v13;
        *(_DWORD *)(a2 + 640) = v13[1];
      }
      if ( *(_DWORD *)(a2 + 632) || vostok::mutable_buffer::operator bool((vostok::mutable_buffer *)(a2 + 636)) )
      {
        vostok::threading::interlocked_or((volatile int *)(a2 + 688), (unsigned int)&loc_7FFFE + 2);
        vostok::resources::query_result::prepare_final_resource(v15, (vostok::resources::query_result *)a2);
      }
      else
      {
        vostok::resources::query_result_for_cook::finish_query_impl(v14, a2, result_requery, assert_on_fail_true, 0);
      }
      return;
    }
    vostok::threading::interlocked_or((volatile int *)(a2 + 688), (unsigned int)&loc_3FFFF + 1);
  }
  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(a2 + 684), 0xFFFFFFFF) )
    vostok::resources::query_result::end_query_might_destroy_this_impl(
      (vostok::resources::query_result *)(a2 + 684),
      (vostok::resources::query_result *)a2);
}
