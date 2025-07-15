void __thiscall survarium::teammate_cure_event_manager::serialize(
        survarium::teammate_cure_event_manager *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset,
        vostok::network_core::buffer_writer *a4)
{
  vostok::network_core::buffer_writer *v4; // ecx
  char *v5; // esi
  int v6; // eax
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  unsigned __int8 i; // [esp+13h] [ebp-5h]
  char *v10; // [esp+14h] [ebp-4h] BYREF

  for ( i = 0; i != *(_BYTE *)(*(_DWORD *)&writer[34].player_id + 29772); ++i )
  {
    v4 = (vostok::network_core::buffer_writer *)(40 * i);
    v5 = (char *)&writer[1].serialization_operations_descriptors.m_first + (_DWORD)v4;
    v6 = *(_DWORD *)(&writer[2].player_id + (_DWORD)v4);
    if ( v6 )
    {
      v4 = a4;
      v10 = (char *)a4 + v6;
    }
    else
    {
      v10 = 0;
    }
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&v10,
      v4,
      time_offset,
      ".\\curing_event_status.cpp",
      (const char *)0x55,
      "survarium::curing_event_status::serialize",
      "last_canceled_affect_time");
    vostok::network_core::buffer_writer::w<unsigned short>(
      (unsigned __int8 *)v5 + 36,
      v7,
      time_offset,
      ".\\curing_event_status.cpp",
      (const char *)0x56,
      "survarium::curing_event_status::serialize",
      "m_medkits_active");
    vostok::network_core::buffer_writer::w<bool>(
      (const bool *)v5 + 38,
      v8,
      time_offset,
      ".\\curing_event_status.cpp",
      (const char *)0x57,
      "survarium::curing_event_status::serialize",
      "m_event_conditions_are_met");
  }
}
