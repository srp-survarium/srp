unsigned int __thiscall survarium::game_state_history_item::hash(
        survarium::game_state_history_item *this,
        const survarium::fixed_history<survarium::players_mask_history_item,40> *players_masks_history,
        boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> a3)
{
  void *v4; // esp
  _DWORD *v5; // eax
  unsigned int v6; // edi
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::mutable_buffer *v8; // ecx
  int v9; // [esp-8000h] [ebp-8038h] BYREF
  vostok::network_core::buffer_writer v10; // [esp+10h] [ebp-28h] BYREF
  int v11; // [esp+28h] [ebp-10h] BYREF
  char *v12; // [esp+2Ch] [ebp-Ch]
  int v13; // [esp+30h] [ebp-8h]
  int v14; // [esp+34h] [ebp-4h]

  if ( *((_BYTE *)&players_masks_history->m_items.m_size + (_DWORD)&loc_B993F + 1) )
    return *(_DWORD *)((char *)&loc_B993C + (_DWORD)players_masks_history);
  *((_BYTE *)&players_masks_history->m_items.m_size + (_DWORD)&loc_B993F + 1) = 1;
  v4 = alloca(0x8000);
  v12 = (char *)&v9;
  v10.m_buffer = (vostok::network_core::mutable_buffer *)&v11;
  v5 = *(_DWORD **)(a3.rem_ + 8);
  v11 = 0;
  v13 = 0x8000;
  v14 = 0;
  v10.serialization_operations_descriptors.m_size = 0;
  v10.serialization_operations_descriptors.m_first = 0;
  v10.serialization_operations_descriptors.m_last = 0;
  v10.player_id = -1;
  if ( v5 )
  {
    this = *(survarium::game_state_history_item **)((char *)&players_masks_history->m_items.m_size
                                                  + (_DWORD)&loc_B9937
                                                  + 1);
    while ( v5[3] > (unsigned int)this )
    {
      v5 = (_DWORD *)v5[1];
      if ( !v5 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v5 = 0;
  }
  survarium::game_state_history_item::serialize(this, (int)players_masks_history, &v10, v5[2]);
  a3.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(&a3, v12, &v12[v14]);
  v6 = ~a3.rem_;
  *(_DWORD *)((char *)&loc_B993C + (_DWORD)players_masks_history) = ~a3.rem_;
  vostok::network_core::buffer_writer::~buffer_writer(v7, &v10.serialization_operations_descriptors);
  vostok::network_core::mutable_buffer::~mutable_buffer(v8, &v11);
  return v6;
}
