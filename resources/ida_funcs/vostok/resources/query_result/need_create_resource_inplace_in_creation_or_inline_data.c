bool __usercall vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>)
{
  vostok::vfs::base_node<1> *v2; // eax
  vostok::resources::cook_base *cook; // eax
  vostok::resources::query_result *v5; // ecx
  vostok::resources::cook_base *v6; // esi
  unsigned int m_flags; // eax
  _DWORD *v8; // eax
  _BYTE v9[12]; // [esp+8h] [ebp-Ch] BYREF

  if ( !*(_DWORD *)(a2 + 164)
    || (v2 = vostok::vfs::vfs_iterator::data_node((vostok::vfs::vfs_iterator *)(a2 + 160)),
        !vostok::vfs::base_node<1>::is_inlined(v2))
    || vostok::vfs::vfs_iterator::is_compressed((vostok::vfs::vfs_iterator *)(a2 + 160)) )
  {
    if ( !*(_DWORD *)(a2 + 208) && !*(_DWORD *)(a2 + 212) )
      return 0;
  }
  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  v6 = cook;
  if ( !cook )
    return 0;
  m_flags = cook->m_flags.m_flags;
  if ( (m_flags & 0x20) != 0 || (m_flags & 0x10) == 0 || (m_flags & 8) != 0 )
    return 0;
  if ( vostok::resources::query_result::has_uncompressed_inline_data(v5) )
    v8 = (_DWORD *)v6->__vftable[1].calculate_quality_levels_count(
                     v6,
                     (const vostok::resources::query_result_for_cook *)v9);
  else
    v8 = (_DWORD *)((int (__thiscall *)(vostok::resources::cook_base *, _BYTE *))v6->__vftable[1].satisfaction_with)(
                     v6,
                     v9);
  return *v8 || v8[1];
}
