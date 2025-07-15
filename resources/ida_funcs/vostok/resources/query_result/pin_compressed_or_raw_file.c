vostok::const_buffer *__userpurge vostok::resources::query_result::pin_compressed_or_raw_file@<eax>(
        vostok::resources::query_result *this@<ecx>,
        vostok::vfs::vfs_iterator *a2@<eax>,
        vostok::const_buffer *result)
{
  const char **v4; // eax
  unsigned int v5; // edx
  vostok::mutable_buffer v7; // [esp+10h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp+18h] [ebp-8h] BYREF

  if ( a2[10].m_node && vostok::vfs::vfs_iterator::is_compressed(a2 + 10) )
    v4 = (const char **)vostok::resources::query_result::pin_compressed_file(this, a2, &v7);
  else
    v4 = (const char **)vostok::resources::query_result::pin_raw_file(this, &v8, (vostok::resources::query_result *)a2);
  v5 = (unsigned int)v4[1];
  result->m_data = *v4;
  result->m_size = v5;
  return result;
}
