void __userpurge survarium::shared_statistics::serialize(
        survarium::shared_statistics *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset)
{
  unsigned __int8 v5; // bl
  unsigned __int16 *v6; // esi
  survarium::victory_item_event_manager *v7; // ecx
  unsigned __int16 *v8; // [esp+10h] [ebp-8h]
  unsigned __int16 value[2]; // [esp+14h] [ebp-4h] BYREF

  v5 = 0;
  if ( *(_BYTE *)(a2 + 6152) )
  {
    do
    {
      v6 = (unsigned __int16 *)(a2 + 212 * v5);
      v8 = v6;
      do
      {
        *(_DWORD *)value = *v8;
        vostok::network_core::buffer_writer::w<unsigned short>(
          (unsigned __int8 *)value,
          (vostok::network_core::buffer_writer *)this,
          writer,
          ".\\player_shared_statistics.cpp",
          (const char *)0x70,
          "survarium::player_shared_statistics::serialize",
          "event_count");
        ++v8;
      }
      while ( v8 != v6 + 21 );
      survarium::intermediate_shared_statistics::serialize(
        (survarium::intermediate_shared_statistics *)this,
        (const vostok::network_core::buffer_writer *)(v6 + 22),
        writer,
        time_offset);
      ++v5;
    }
    while ( v5 != *(_BYTE *)(a2 + 6152) );
  }
  survarium::teammate_cure_event_manager::serialize(
    (survarium::teammate_cure_event_manager *)this,
    (const vostok::network_core::buffer_writer *)(a2 + 4240),
    writer,
    time_offset);
  survarium::victory_item_event_manager::serialize(v7, (const vostok::network_core::buffer_writer *)(a2 + 5080), writer);
}
