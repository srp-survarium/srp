int __usercall vostok::resources::query_result::creation_source_for_resource@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  vostok::resources::cook_base *cook; // eax

  if ( *(_DWORD *)(a2 + 208) || *(_DWORD *)(a2 + 212) )
    return 2;
  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( cook && (cook->m_flags.m_flags & 8) != 0 )
    return 5;
  else
    return 2 * ((*(_DWORD *)(a2 + 688) & 0x800) == 2048) + 1;
}
