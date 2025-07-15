vostok::vfs::base_node<1> *__usercall vostok::resources::query_result::raw_buffer_size@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>)
{
  vostok::vfs::base_node<1> *v2; // esi
  vostok::resources::query_result *v3; // ecx
  vostok::const_buffer raw_buffer; // [esp+8h] [ebp-Ch] BYREF

  vostok::resources::query_result::pin_raw_buffer(this, a2, (vostok::mutable_buffer *)&raw_buffer);
  v2 = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&raw_buffer);
  vostok::resources::query_result::unpin_raw_buffer(
    v3,
    a2,
    (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_buffer);
  return v2;
}
