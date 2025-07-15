void __userpurge survarium::shared_statistics::deserialize(
        survarium::shared_statistics *this@<ecx>,
        int a2@<edi>,
        vostok::network_core::buffer_reader *reader,
        unsigned int time_offset)
{
  unsigned __int8 v4; // bl
  int v5; // esi
  unsigned __int16 v6; // ax
  unsigned __int16 *v7; // ecx
  survarium::victory_item_event_manager *v8; // ecx
  unsigned __int16 *v9; // [esp+4h] [ebp-4h]

  v4 = 0;
  if ( *(_BYTE *)(a2 + 6152) )
  {
    do
    {
      v5 = a2 + 212 * v4;
      v9 = (unsigned __int16 *)v5;
      do
      {
        v6 = vostok::network_core::buffer_reader::r<unsigned short>(reader);
        v7 = v9++;
        *v7 = v6;
      }
      while ( v9 != (unsigned __int16 *)(v5 + 42) );
      survarium::intermediate_shared_statistics::deserialize(
        (int)v7,
        reader,
        (survarium::intermediate_shared_statistics *)(v5 + 44),
        time_offset);
      ++v4;
    }
    while ( v4 != *(_BYTE *)(a2 + 6152) );
  }
  survarium::teammate_cure_event_manager::deserialize(
    (survarium::teammate_cure_event_manager *)this,
    (vostok::network_core::buffer_reader *)(a2 + 4240),
    reader,
    time_offset);
  if ( *(_DWORD *)(a2 + 6096) )
    survarium::victory_item_event_manager::deserialize(v8, (vostok::network_core::buffer_reader *)(a2 + 5080), reader);
}
