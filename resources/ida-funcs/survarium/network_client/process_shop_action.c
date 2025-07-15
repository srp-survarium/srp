void __thiscall survarium::network_client::process_shop_action(
        survarium::network_client *this,
        vostok::network_core::buffer_reader *packet,
        vostok::network_core::buffer_reader *a3)
{
  vostok::network_core::buffer_reader *v3; // ecx
  const unsigned __int8 *v5; // eax
  const vostok::network_core::tcp_packet *v6; // eax
  survarium::lobby_client *v7; // ecx
  const unsigned __int8 *v8; // esi
  const unsigned __int8 *v9; // eax
  const unsigned __int8 *v10; // esi
  int v11; // esi
  int v12; // eax
  survarium::lobby_menu *v13; // ecx
  bool v14; // zf
  int v15; // edi
  unsigned __int8 *v16; // eax
  int v17; // edi
  const vostok::network_core::tcp_packet *v18; // eax
  survarium::lobby_client *v19; // ecx
  const unsigned __int8 *v20; // esi
  const vostok::network_core::tcp_packet *v21; // eax
  survarium::lobby_client *v22; // ecx
  unsigned __int16 v23; // ax
  const unsigned __int8 *m_pointer; // esi
  vostok::memory::base_allocator *v25; // edi
  const unsigned __int8 *m_buffer; // eax
  _DWORD *v27; // esi
  _DWORD *v28; // eax
  const unsigned __int8 *v29; // eax
  int v30; // eax
  survarium::inventory_item_descr *v31; // edi
  unsigned int v32; // eax
  unsigned int *p_amount_in_inventory; // edi
  const vostok::network_core::tcp_packet *v34; // eax
  survarium::lobby_client *v35; // ecx
  unsigned __int8 v36; // [esp-4h] [ebp-3Ch]
  unsigned __int8 v37; // [esp-4h] [ebp-3Ch]
  stlp_std::priv::_Impl_vector<survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr> > v38; // [esp+10h] [ebp-28h] BYREF
  stlp_std::priv::_Impl_vector<survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr> > v39; // [esp+20h] [ebp-18h]
  vostok::memory::base_allocator *v40; // [esp+30h] [ebp-8h]
  unsigned int v41; // [esp+34h] [ebp-4h]
  survarium::lobby_menu *v42; // [esp+40h] [ebp+8h]
  survarium::inventory_item_descr *v43; // [esp+40h] [ebp+8h]
  unsigned __int8 v44; // [esp+43h] [ebp+Bh]
  unsigned __int8 i; // [esp+43h] [ebp+Bh]
  unsigned __int8 v46; // [esp+43h] [ebp+Bh]

  v3 = a3;
  v44 = *a3->m_pointer;
  v5 = a3->m_pointer + 1;
  a3->m_pointer = v5;
  if ( !v44 )
  {
    v46 = *v5;
    v14 = *v5 == 0;
    a3->m_pointer = v5 + 1;
    if ( !v14 )
    {
      v41 = v46;
      while ( 2 )
      {
        v39._M_finish = 0;
        v23 = vostok::network_core::buffer_reader::r<unsigned short>(v3);
        m_pointer = a3->m_pointer;
        v40 = *(vostok::memory::base_allocator **)m_pointer;
        a3->m_pointer = m_pointer + 4;
        v43 = (survarium::inventory_item_descr *)*((_DWORD *)m_pointer + 1);
        v25 = v40;
        LOWORD(v39._M_end_of_storage._M_data) = v23;
        a3->m_pointer = m_pointer + 8;
        v39._M_start = v43;
        m_buffer = packet->m_buffer;
        v39._M_end_of_storage.m_allocator = v25;
        v27 = *(_DWORD **)((*((int (__thiscall **)(vostok::network_core::buffer_reader *))m_buffer + 15))(packet) + 12712);
        v28 = *(_DWORD **)((*((int (__thiscall **)(vostok::network_core::buffer_reader *))packet->m_buffer + 15))(packet)
                         + 12716);
        while ( v27 != v28 )
        {
          if ( (vostok::memory::base_allocator *)v27[2] == v25 )
          {
            *v27 += v43;
            goto LABEL_32;
          }
          v27 += 4;
        }
        v29 = packet->m_buffer;
        v38 = v39;
        v30 = (*((int (__thiscall **)(vostok::network_core::buffer_reader *))v29 + 15))(packet);
        v31 = *(survarium::inventory_item_descr **)(v30 + 12716);
        v32 = v30 + 12712;
        if ( v31 == *(survarium::inventory_item_descr **)(v32 + 12) )
        {
          stlp_std::priv::_Impl_vector<survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr>>::_M_insert_overflow(
            &v38,
            v32,
            v31,
            (const stlp_std::__true_type *)&v38,
            1u,
            1);
        }
        else
        {
          if ( v31 )
          {
            v31->condition_or_stack = (unsigned int)v39._M_start;
            p_amount_in_inventory = &v31->amount_in_inventory;
            *p_amount_in_inventory = (unsigned int)v39._M_finish;
            *(stlp_std::priv::_STLP_alloc_proxy<survarium::inventory_item_descr *,survarium::inventory_item_descr,vostok::vectora_allocator<survarium::inventory_item_descr> > *)(p_amount_in_inventory + 1) = v39._M_end_of_storage;
          }
          *(_DWORD *)(v32 + 4) += 16;
        }
LABEL_32:
        if ( --v41 )
        {
          v3 = a3;
          continue;
        }
        break;
      }
    }
    survarium::lobby_menu::fill_inventory_contents((survarium::lobby_menu *)v3, *((_DWORD *)packet[2].m_buffer + 3460));
    v36 = 5;
LABEL_34:
    v34 = (const vostok::network_core::tcp_packet *)(*((int (__thiscall **)(vostok::network_core::buffer_reader *))packet->m_buffer
                                                     + 15))(packet);
    survarium::lobby_client::query_client_status(v35, v34, v36);
    return;
  }
  if ( v44 != 1 )
  {
    if ( v44 != 2 )
      return;
    v6 = (const vostok::network_core::tcp_packet *)(*((int (__thiscall **)(vostok::network_core::buffer_reader *))packet->m_buffer
                                                    + 15))(packet);
    survarium::lobby_client::query_client_status(v7, v6, 5u);
    v36 = 16;
    goto LABEL_34;
  }
  v8 = v5;
  v9 = v5 + 4;
  v42 = *(survarium::lobby_menu **)v8;
  a3->m_pointer = v9;
  v10 = v9;
  v9 += 4;
  v40 = *(vostok::memory::base_allocator **)v10;
  a3->m_pointer = v9;
  v41 = *(_DWORD *)v9;
  a3->m_pointer = v9 + 4;
  v11 = *(_DWORD *)((*((int (__thiscall **)(vostok::network_core::buffer_reader *))packet->m_buffer + 15))(packet)
                  + 12712);
  v12 = *(_DWORD *)((*((int (__thiscall **)(vostok::network_core::buffer_reader *))packet->m_buffer + 15))(packet)
                  + 12716);
  while ( v11 != v12 )
  {
    v13 = *(survarium::lobby_menu **)(v11 + 8);
    if ( v13 == v42 )
    {
      if ( !survarium::items_dictionary::item_by_id(
              *((survarium::items_dictionary **)packet[2].m_buffer + 3477),
              (survarium::items_dictionary_vtbl *)*(unsigned __int16 *)(v11 + 12))->is_stack
        || (v14 = *(_DWORD *)v11 == (_DWORD)v40, *(_DWORD *)v11 -= v40, v14) )
      {
        v15 = (*((int (__thiscall **)(vostok::network_core::buffer_reader *))packet->m_buffer + 15))(packet);
        v16 = *(unsigned __int8 **)(v15 + 12716);
        v17 = v15 + 12712;
        v13 = (survarium::lobby_menu *)(v11 + 16);
        if ( (unsigned __int8 *)(v11 + 16) != v16 )
          stlp_std::priv::__copy_trivial((unsigned __int8 *)(v11 + 16), v16, (unsigned __int8 *)v11);
        *(_DWORD *)(v17 + 4) -= 16;
      }
      break;
    }
    v11 += 16;
  }
  survarium::lobby_menu::fill_inventory_contents(v13, *((_DWORD *)packet[2].m_buffer + 3460));
  v18 = (const vostok::network_core::tcp_packet *)(*((int (__thiscall **)(vostok::network_core::buffer_reader *))packet->m_buffer
                                                   + 15))(packet);
  survarium::lobby_client::query_client_status(v19, v18, 5u);
  if ( v41 )
  {
    for ( i = 0; i < v41; ++i )
    {
      v20 = a3->m_pointer;
      v40 = *(vostok::memory::base_allocator **)v20;
      v37 = (unsigned __int8)v40;
      a3->m_pointer = v20 + 4;
      v21 = (const vostok::network_core::tcp_packet *)(*((int (__thiscall **)(vostok::network_core::buffer_reader *))packet->m_buffer
                                                       + 15))(packet);
      survarium::lobby_client::query_profile_contents(v22, v21, v37);
    }
  }
}
