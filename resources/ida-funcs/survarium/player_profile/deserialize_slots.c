void __userpurge survarium::player_profile::deserialize_slots(
        survarium::player_profile *this@<ecx>,
        vostok::network_core::buffer_reader *a2@<eax>,
        vostok::network_core::buffer_reader *reader)
{
  const unsigned __int8 *m_pointer; // esi
  vostok::network_core::buffer_reader *v5; // edi
  int *v6; // esi
  int v7; // [esp+Ch] [ebp-8h]
  vostok::network_core::buffer_reader *v8; // [esp+10h] [ebp-4h]
  int v9; // [esp+10h] [ebp-4h]
  survarium::inventory_item_descr *v10; // [esp+1Ch] [ebp+8h]

  v8 = a2 + 6;
  memset((int)&a2[6], 0, 0x170u);
  m_pointer = reader->m_pointer;
  v7 = *(_DWORD *)m_pointer;
  v5 = v8;
  v10 = 0;
  reader->m_pointer = m_pointer + 4;
  v6 = (int *)slot_serialize_mode;
  v9 = 23;
  do
  {
    if ( ((1 << (char)v10) & v7) != 0 )
      survarium::inventory_item_descr::deserialize(v10, v5, reader, *v6);
    v10 = (survarium::inventory_item_descr *)((char *)v10 + 1);
    ++v6;
    v5 = (vostok::network_core::buffer_reader *)((char *)v5 + 16);
    --v9;
  }
  while ( v9 );
}
