void __thiscall vostok::journaling::match_client::on_dispatch_callbacks(vostok::journaling::match_client *this)
{
  vostok::journaling::reader *v1; // esi
  vostok::resources::managed_resource *v2; // ebx
  void *v3; // esp
  vostok::fs_new::device_file_system_proxy_base *v4; // ecx
  vostok::journaling::data_chunk_type_enum v5[4]; // [esp+0h] [ebp-28h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> a1[3]; // [esp+10h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *a0; // [esp+1Ch] [ebp-Ch]
  vostok::journaling::match_client *v8; // [esp+20h] [ebp-8h]
  vostok::journaling::reader *v9; // [esp+24h] [ebp-4h] BYREF

  v8 = this;
  while ( 1 )
  {
    vostok::journaling::journal::try_start_reading(
      (vostok::journaling::journal *)this,
      (int)vostok::core::g_journal.m_variable,
      &v9,
      (vostok::journaling::reader_ptr *)6,
      v5[0]);
    v1 = v9;
    if ( !v9 )
      break;
    LOBYTE(a0) = vostok::journaling::reader::r<unsigned char>(v9);
    v2 = (vostok::resources::managed_resource *)vostok::journaling::reader::r<unsigned int>(v1);
    v3 = alloca((int)v2);
    vostok::fs_new::device_file_system_proxy_base::read(
      v4,
      &v1->m_device->m_device_file_system,
      v1->m_file,
      v5,
      (unsigned int)v2);
    this = (vostok::journaling::match_client *)-(v8->m_on_packet_received.vtable != 0);
    if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & (unsigned int)this) != 0 )
    {
      a1[0].m_object = (vostok::resources::managed_resource *)v5;
      a1[1].m_object = (vostok::resources::managed_resource *)v5;
      a1[2].m_object = v2;
      boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::operator()(
        (boost::function2<unsigned short,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> const &> *)a1,
        &v8->m_on_packet_received.vtable,
        a0,
        a1);
    }
  }
}
