void __usercall vostok::render::grass_patch::sort_instances(
        vostok::render::grass_patch *this@<ecx>,
        const vostok::math::float3 *view_position@<eax>)
{
  unsigned int m_current_lod_index; // ebx
  unsigned __int8 *v4; // ebp
  vostok::render::grass_patch::sort_info *v5; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi
  int v7; // [esp+4h] [ebp-20h]
  unsigned int i; // [esp+8h] [ebp-1Ch]
  unsigned __int16 *merged_indices_copy; // [esp+Ch] [ebp-18h]
  vostok::render::sort_indices_predicate v10; // [esp+10h] [ebp-14h]

  m_current_lod_index = this->m_current_lod_index;
  v10.m_view_pos = *view_position;
  v10.m_patch = this;
  stlp_std::sort<vostok::render::grass_patch::sort_info *,vostok::render::sort_indices_predicate>(
    this->m_sort_info[m_current_lod_index],
    &this->m_sort_info[m_current_lod_index][this->m_instances._M_impl._M_finish - this->m_instances._M_impl._M_start - 1],
    v10);
  v4 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                            2 * this->m_num_merged_indices[m_current_lod_index]);
  merged_indices_copy = (unsigned __int16 *)v4;
  i = 0;
  if ( this->m_instances._M_impl._M_finish - this->m_instances._M_impl._M_start )
  {
    v7 = 0;
    do
    {
      v5 = &this->m_sort_info[m_current_lod_index][v7];
      memcpy(v4, (unsigned __int8 *)&this->m_merged_indices[m_current_lod_index][v5->index_offset], 2 * v5->num_indices);
      ++v7;
      v4 += 2 * v5->num_indices;
      ++i;
    }
    while ( i < this->m_instances._M_impl._M_finish - this->m_instances._M_impl._M_start );
    v4 = (unsigned __int8 *)merged_indices_copy;
  }
  (*(void (__stdcall **)(int, ID3D11Buffer *, _DWORD, _DWORD, unsigned __int8 *, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                                                + 192))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    this->m_geometry[m_current_lod_index].m_object->m_ib.m_object->m_hardware_buffer,
    0,
    0,
    v4,
    0,
    0);
  if ( v4 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v4);
  }
}
