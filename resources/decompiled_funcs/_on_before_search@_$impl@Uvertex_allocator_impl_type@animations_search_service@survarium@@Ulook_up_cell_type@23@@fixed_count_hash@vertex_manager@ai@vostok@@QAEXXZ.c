void __usercall vostok::ai::vertex_manager::fixed_count_hash::impl<survarium::animations_search_service::vertex_allocator_impl_type,survarium::animations_search_service::look_up_cell_type>::on_before_search(
        vostok::ai::vertex_manager::fixed_count_hash::impl<survarium::animations_search_service::vertex_allocator_impl_type,survarium::animations_search_service::look_up_cell_type> *this@<ecx>,
        int a2@<esi>)
{
  bool v2; // zf
  unsigned int v3; // [esp-4h] [ebp-4h]

  *(_DWORD *)(*(_DWORD *)a2 + 12) = *(_DWORD *)(*(_DWORD *)a2 + 4);
  v2 = (*(_DWORD *)(a2 + 24))++ == -1;
  *(_DWORD *)(a2 + 12) = 0;
  if ( v2 )
  {
    v3 = 4 * *(_DWORD *)(a2 + 16);
    *(_DWORD *)(a2 + 24) = 1;
    memset(*(unsigned __int8 **)(a2 + 8), 0, v3);
    memset(*(unsigned __int8 **)(a2 + 4), 0, 24 * *(_DWORD *)(a2 + 20));
  }
}
