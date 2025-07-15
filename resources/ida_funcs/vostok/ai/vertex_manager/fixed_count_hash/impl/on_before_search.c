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


void __thiscall vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type>::on_before_search(
        vostok::ai::vertex_manager::fixed_count_hash::impl<vostok::sound::search::search_service::vertex_allocator_impl_type,vostok::sound::search::search_service::look_up_cell_type> *this)
{
  this->m_allocator->m_vertex_current = this->m_allocator->m_vertices;
  this->m_vertex_count = 0;
  if ( !++this->m_current_path_id )
  {
    this->m_current_path_id = 1;
    vostok::memory::zero(this->m_hash, 4 * this->m_hash_size);
    vostok::memory::zero(this->m_vertices, 24 * this->m_fix_size);
  }
}
