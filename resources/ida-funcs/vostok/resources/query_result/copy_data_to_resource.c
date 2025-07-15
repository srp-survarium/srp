void __thiscall vostok::resources::query_result::copy_data_to_resource(
        vostok::resources::query_result *this,
        vostok::const_buffer data,
        vostok::resources::managed_resource *count)
{
  const char *m_data; // ebx
  int v4; // eax
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v5; // edi
  vostok::resources::managed_resource *v6; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v7; // ecx
  const unsigned __int8 *v8; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v9; // [esp-4h] [ebp-20h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+10h] [ebp-Ch] BYREF
  const unsigned __int8 *v11; // [esp+14h] [ebp-8h]

  m_data = data.m_data;
  v4 = *((_DWORD *)data.m_data + 163);
  if ( v4 )
  {
    memcpy(
      (unsigned __int8 *)(v4 + *((_DWORD *)data.m_data + 172)),
      (unsigned __int8 *)data.m_size,
      (unsigned int)count);
  }
  else
  {
    if ( !*((_DWORD *)data.m_data + 41)
      || (v5 = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(data.m_data + 644),
          !vostok::vfs::vfs_iterator::is_compressed((vostok::vfs::vfs_iterator *)data.m_data + 10)) )
    {
      v5 = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(m_data + 648);
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data,
      v5);
    v9.m_object = v6;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &v9,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v7,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
      v9);
    v9.m_object = count;
    v8 = v11;
    memcpy((unsigned __int8 *)&v11[*((_DWORD *)m_data + 172)], (unsigned __int8 *)data.m_size, (unsigned int)count);
    if ( ptr.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        vostok::memory::managed_node_owner::unpin(v8);
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ptr);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
  }
}
