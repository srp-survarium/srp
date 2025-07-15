bool __usercall vostok::resources::cook_base::does_create_resource_if_no_file@<al>(
        vostok::resources::cook_base *this@<ecx>,
        vostok::resources::inplace_managed_cook *a2@<eax>)
{
  unsigned int m_flags; // ecx
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,unsigned int &)> *v4; // eax
  bool v5; // al
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,unsigned int &)> *v7; // eax
  fastdelegate::FastDelegate2<vostok::resources::query_result_for_cook &,vostok::mutable_buffer,void> *v8; // ecx
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,unsigned int &)> v9; // [esp+0h] [ebp-8h] BYREF

  m_flags = a2->m_flags.m_flags;
  if ( (m_flags & 8) != 0 )
    return 0;
  if ( (m_flags & 0x10) != 0 )
  {
    if ( (m_flags & 0x20) != 0 )
    {
      a2 = vostok::resources::cook_base::cast_inplace_managed_cook((vostok::resources::cook_base *)m_flags, a2);
      goto LABEL_6;
    }
    a2 = (vostok::resources::inplace_managed_cook *)vostok::resources::cook_base::cast_inplace_unmanaged_cook(
                                                      (vostok::resources::cook_base *)m_flags,
                                                      (vostok::resources::inplace_unmanaged_cook *)a2);
  }
  else if ( (m_flags & 0x20) != 0 )
  {
LABEL_6:
    v4 = a2->get_create_resource_if_no_file_delegate(a2, &v9);
    v5 = !v4->m_Closure.m_pthis && !v4->m_Closure.m_pFunction;
    return !v5;
  }
  v7 = a2->get_create_resource_if_no_file_delegate(a2, &v9);
  return (void (__cdecl **)(vostok::resources::query_result_for_cook *, vostok::mutable_buffer))((char *)fastdelegate::FastDelegate2<vostok::resources::query_result_for_cook &,vostok::mutable_buffer,void>::operator void (__cdecl *fastdelegate::FastDelegate2<vostok::resources::query_result_for_cook &,vostok::mutable_buffer,void>::SafeBoolStruct::*)(vostok::resources::query_result_for_cook &,vostok::mutable_buffer)(v8, v7)
                                                                                               + 1) != 0;
}


bool __cdecl vostok::resources::cook_base::does_create_resource_if_no_file(
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::inplace_managed_cook *cook; // eax
  vostok::resources::cook_base *v3; // [esp-4h] [ebp-4h]

  cook = (vostok::resources::inplace_managed_cook *)vostok::resources::resources_manager::find_cook(resource_class);
  return cook && vostok::resources::cook_base::does_create_resource_if_no_file(v3, cook);
}
