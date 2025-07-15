unsigned int __thiscall vostok::resources::query_result::raw_buffer_size(
        vostok::resources::query_result *this,
        vostok::resources::query_result *a2)
{
  vostok::resources::query_result *v2; // ecx
  vostok::const_buffer pinned_raw_buffer; // [esp+8h] [ebp-Ch] BYREF

  vostok::resources::query_result::pin_raw_buffer(a2, &pinned_raw_buffer.m_data);
  vostok::resources::query_result::unpin_raw_buffer(v2, &pinned_raw_buffer);
  return pinned_raw_buffer.m_size;
}
