char __thiscall vostok::resources::device_manager::process_write_query(
        vostok::resources::device_manager *this,
        vostok::resources::device_manager *file,
        vostok::resources::query_result *query,
        const vostok::fs_new::synchronous_device_interface *device)
{
  vostok::fs_new::device_file_system_proxy_base *v5; // ecx
  bool v6; // zf
  vostok::resources::save_generated_data *m_save_generated_data; // eax
  unsigned int m_size; // esi
  int v9; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v10; // ecx
  vostok::resources::managed_resource *m_object; // eax
  vostok::vfs::base_node<1> *m_link_target; // ecx
  vostok::resources::query_result *v13; // ecx
  vostok::const_buffer *v14; // eax
  unsigned int v15; // eax
  vostok::resources::query_result *v16; // ecx
  unsigned __int64 v18; // [esp-4h] [ebp-60h] BYREF
  bool v19; // [esp+4h] [ebp-58h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+10h] [ebp-4Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_ptr; // [esp+1Ch] [ebp-40h]
  __int32 v22[2]; // [esp+20h] [ebp-3Ch] BYREF
  _DWORD v23[4]; // [esp+28h] [ebp-34h] BYREF
  vostok::const_buffer v24; // [esp+38h] [ebp-24h] BYREF
  unsigned __int64 filea; // [esp+40h] [ebp-1Ch]
  void *m_data; // [esp+4Ch] [ebp-10h] BYREF
  unsigned int file_pos; // [esp+50h] [ebp-Ch]
  unsigned __int64 file_pos_4; // [esp+54h] [ebp-8h] BYREF
  char v29; // [esp+67h] [ebp+Bh]
  bool query_3; // [esp+6Bh] [ebp+Fh]

  v5 = 0;
  v6 = (query->m_flags & 8) == 8;
  m_data = 0;
  file_pos = 0;
  query_3 = v6;
  p_ptr = &ptr;
  v22[0] = 0;
  filea = 0;
  v22[1] = 0;
  if ( v6 )
  {
    m_save_generated_data = query->m_save_generated_data;
    m_size = m_save_generated_data->m_data.m_size;
    if ( m_save_generated_data->m_data.m_data || m_size )
    {
      m_data = m_save_generated_data->m_data.m_data;
      file_pos = m_size;
    }
    else
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&file_pos_4,
        &m_save_generated_data->m_resource);
      LODWORD(v18) = v9;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&v18,
        (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&file_pos_4);
      vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
        v10,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
        (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v18);
      _InterlockedExchange(v22, 1);
      m_object = p_ptr[2].m_object;
      m_data = p_ptr[1].m_object;
      file_pos = (unsigned int)m_object;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&file_pos_4);
    }
  }
  else
  {
    v23[0] = query->m_fat_it.m_hashset;
    v23[1] = query->m_fat_it.m_node;
    m_link_target = query->m_fat_it.m_link_target;
    v23[3] = query->m_fat_it.m_type;
    v23[2] = m_link_target;
    filea = vostok::vfs::vfs_iterator::get_file_offs((vostok::vfs::vfs_iterator *)m_link_target, (int)v23);
    v14 = vostok::resources::query_result::pin_compressed_or_raw_file(v13, query, &v24);
    v5 = (vostok::fs_new::device_file_system_proxy_base *)v14->m_data;
    v15 = v14->m_size;
    m_data = v5;
    file_pos = v15;
  }
  LODWORD(v18) = file_pos;
  v29 = vostok::resources::device_manager::do_async_operation(
          query,
          device,
          v5,
          file,
          (void **)filea,
          (vostok::mutable_buffer)__PAIR64__((unsigned int)m_data, HIDWORD(filea)),
          v18,
          v19);
  if ( !query_3 )
    vostok::resources::query_result::unpin_compressed_or_raw_file(
      v16,
      (vostok::vfs::vfs_iterator *)query,
      (vostok::const_buffer *)&m_data);
  if ( v22[0] )
  {
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>((vostok::resources::pinned_ptr_const<unsigned char> *)v16);
    v22[0] = 0;
  }
  return v29;
}
