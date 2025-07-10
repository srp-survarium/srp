void __usercall vostok::resources::query_result::unpin_compressed_or_raw_file(
        vostok::resources::query_result *this@<eax>,
        vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *pinned_file@<esi>,
        vostok::resources::query_result *a3@<ecx>)
{
  if ( this->m_fat_it.m_node && vostok::vfs::vfs_iterator::is_compressed(&this->m_fat_it) )
    vostok::resources::query_result::unpin_compressed_file(a3, (int)this, pinned_file);
  else
    vostok::resources::query_result::unpin_raw_file(a3, (int)this, (vostok::vfs::vfs_iterator *)pinned_file);
}
