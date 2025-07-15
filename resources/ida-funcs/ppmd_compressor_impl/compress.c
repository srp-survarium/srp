void __thiscall ppmd_compressor_impl::compress(
        ppmd_compressor_impl *this,
        vostok::const_buffer src,
        vostok::mutable_buffer dest,
        unsigned int *out_size)
{
  int v5; // [esp+0h] [ebp-20h]
  compression::ppmd::stream dest_stream; // [esp+8h] [ebp-18h] BYREF
  compression::ppmd::stream source_stream; // [esp+14h] [ebp-Ch] BYREF

  source_stream.m_buffer_size = (unsigned int)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&src);
  source_stream.m_buffer = (unsigned __int8 *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&src);
  source_stream.m_pointer = source_stream.m_buffer;
  dest_stream.m_buffer_size = (unsigned int)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&dest);
  dest_stream.m_buffer = (unsigned __int8 *)dest.m_data;
  dest_stream.m_pointer = (unsigned __int8 *)dest.m_data;
  ppmd_compressor_impl::EncodeFile(this, this->m_MRMethod, &dest_stream, &source_stream, v5);
  *out_size = dest_stream.m_pointer - dest_stream.m_buffer + 1;
}
