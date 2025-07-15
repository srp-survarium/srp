void __userpurge vostok::resources::query_result::unpin_compressed_file(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>,
        vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *pinned_compressed_data)
{
  volatile signed __int32 *p_m_next_in_global_delay_delete_list; // eax

  if ( *(_DWORD *)(a2 + 628) )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      p_m_next_in_global_delay_delete_list = (volatile signed __int32 *)&vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(pinned_compressed_data)[-1].m_next_in_global_delay_delete_list;
      _InterlockedExchangeAdd(p_m_next_in_global_delay_delete_list + 11, 0xFFFFFFFF);
      if ( *((_DWORD *)p_m_next_in_global_delay_delete_list + 4) )
      {
        if ( !*((_DWORD *)p_m_next_in_global_delay_delete_list + 11) )
        {
          _InterlockedExchangeAdd(
            (volatile signed __int32 *)(*((_DWORD *)p_m_next_in_global_delay_delete_list + 4) + 40),
            1u);
          *((_DWORD *)p_m_next_in_global_delay_delete_list + 4) = 0;
        }
      }
    }
  }
}
