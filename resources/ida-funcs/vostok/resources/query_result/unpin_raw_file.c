void __usercall vostok::resources::query_result::unpin_raw_file(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  int v2; // edx
  vostok::resources::query_result_vtbl *v3; // esi
  vostok::const_buffer pinned_raw_buffer; // [esp+4h] [ebp-8h] BYREF

  v2 = *(_DWORD *)(a2 + 688);
  v3 = this->__vftable;
  pinned_raw_buffer.m_size = v2 + this->type;
  pinned_raw_buffer.m_data = (char *)v3 - v2;
  vostok::resources::query_result::unpin_raw_buffer(
    (vostok::resources::query_result *)&pinned_raw_buffer,
    &pinned_raw_buffer);
}
