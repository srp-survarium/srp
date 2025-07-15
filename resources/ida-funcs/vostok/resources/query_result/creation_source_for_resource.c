int __usercall vostok::resources::query_result::creation_source_for_resource@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + 208) || *(_DWORD *)(a2 + 212) )
    return 2;
  if ( vostok::resources::cook_base::find_translate_query_cook(*(vostok::resources::class_id_enum *)(a2 + 132)) )
    return 5;
  return (*(_DWORD *)(a2 + 704) & 0x800) != 2048 ? 1 : 3;
}
