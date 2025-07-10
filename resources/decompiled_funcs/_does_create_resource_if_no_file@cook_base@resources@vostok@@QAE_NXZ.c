bool __thiscall vostok::resources::cook_base::does_create_resource_if_no_file(vostok::resources::cook_base *this)
{
  unsigned int m_flags; // eax
  _DWORD *v3; // eax
  fastdelegate::FastDelegate2<vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,void> *v4; // ecx
  _BYTE v5[12]; // [esp+0h] [ebp-Ch] BYREF

  m_flags = this->m_flags.m_flags;
  if ( (m_flags & 8) != 0 )
    return 0;
  v3 = (_DWORD *)((int (__thiscall *)(vostok::resources::cook_base *, _BYTE *))this->__vftable[1].translate_request_path)(
                   this,
                   v5);
  return fastdelegate::FastDelegate3<vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,unsigned int &,void>::operator void (__cdecl *fastdelegate::FastDelegate3<vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,unsigned int &,void>::SafeBoolStruct::*)(vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,unsigned int &)(
           v4,
           v3) != -1;
}
