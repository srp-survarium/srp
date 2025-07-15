vostok::const_buffer *__fastcall vostok::resources::query_result::pin_compressed_or_raw_file(
        vostok::resources::query_result *this,
        vostok::resources::query_result *a2,
        vostok::const_buffer *result)
{
  void *v3; // eax
  const char *v4; // ecx
  vostok::resources::query_result_for_cook *v6; // [esp+10h] [ebp-14h] BYREF
  vostok::const_buffer v7; // [esp+18h] [ebp-Ch] BYREF

  if ( a2->m_fat_it.m_node && vostok::vfs::vfs_iterator::is_compressed(&a2->m_fat_it) )
    v3 = vostok::resources::query_result::pin_compressed_file(a2, &v7);
  else
    v3 = vostok::resources::query_result::pin_raw_file(this, &v6, a2);
  v4 = *(const char **)v3;
  result->m_size = *((_DWORD *)v3 + 1);
  result->m_data = v4;
  return result;
}
