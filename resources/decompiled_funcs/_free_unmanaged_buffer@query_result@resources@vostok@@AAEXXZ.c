void __usercall vostok::resources::query_result::free_unmanaged_buffer(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  char **v3; // ebp
  bool v4; // zf
  char **v5; // eax
  unsigned int v6; // edx
  vostok::configs::binary_config *m_data; // edi
  vostok::resources::query_result *v8; // ecx
  vostok::resources::unmanaged_resource *m_object; // edi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> ptr; // [esp+14h] [ebp-20h] BYREF
  vostok::mutable_buffer unmanaged_buffer; // [esp+18h] [ebp-1Ch] BYREF
  vostok::vfs::vfs_iterator result; // [esp+20h] [ebp-14h] BYREF

  v3 = (char **)(a2 + 636);
  v4 = !vostok::mutable_buffer::operator bool((vostok::mutable_buffer *)(a2 + 636));
  v5 = v3;
  if ( v4 )
    v5 = (char **)(a2 + 644);
  v6 = (unsigned int)v5[1];
  unmanaged_buffer.m_data = *v5;
  unmanaged_buffer.m_size = v6;
  if ( vostok::mutable_buffer::operator bool(&unmanaged_buffer) )
  {
    m_data = (vostok::configs::binary_config *)unmanaged_buffer.m_data;
    if ( unmanaged_buffer.m_data )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(
        (vostok::resources::unmanaged_resource *)unmanaged_buffer.m_data,
        1u);
      m_data->__vftable = (vostok::configs::binary_config_vtbl *)&vostok::resources::helper_unmanaged_resource::`vftable';
    }
    else
    {
      m_data = 0;
    }
    ptr.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&ptr,
      m_data);
    vostok::resources::query_result::set_deleter_object(v8, ptr.m_object);
    if ( (*(_DWORD *)(a2 + 688) & 0x800) != 0 )
      vostok::vfs::vfs_iterator::end(&result);
    else
      vostok::vfs::vfs_iterator::vfs_iterator(&result, (const vostok::vfs::vfs_iterator *)(a2 + 160));
    m_object = ptr.m_object;
    ptr.m_object->m_fat_it = result;
    m_object->m_memory_usage_self.size = (unsigned int)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&unmanaged_buffer);
    m_object->m_creation_source = creation_source_deallocate_buffer_helper;
    m_object->m_memory_usage_self.vostok::resources::resource_base::vostok::resources::resource_quality::type = &vostok::resources::nocache_memory;
    *v3 = 0;
    v3[1] = 0;
    *(_DWORD *)(a2 + 644) = 0;
    *(_DWORD *)(a2 + 648) = 0;
    if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
  }
}
