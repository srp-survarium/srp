void __thiscall survarium::victory_item_event_manager::serialize(
        survarium::victory_item_event_manager *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *time_offset)
{
  const vostok::network_core::buffer_writer *v3; // eax
  vostok::network_core::buffer_writer::serialization_operation_descriptor **i; // ebx
  vostok::network_core::buffer_writer::serialization_operation_descriptor *m_last; // eax
  unsigned int function_low; // eax
  unsigned int v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  vostok::network_core::buffer_writer *v11; // ecx
  char v12; // [esp+13h] [ebp-Dh] BYREF
  unsigned int v13; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v14; // [esp+18h] [ebp-8h]
  unsigned int v15; // [esp+1Ch] [ebp-4h]

  v3 = writer;
  if ( writer[42].serialization_operations_descriptors.m_first )
  {
    v15 = 0;
    for ( i = &writer[1].serialization_operations_descriptors.m_first; ; i += 24 )
    {
      m_last = v3[42].serialization_operations_descriptors.m_last;
      if ( v15 >= HIBYTE(m_last[930].line) )
        break;
      function_low = LOBYTE(m_last[930].function);
      v7 = 0;
      v13 = 0;
      v14 = function_low;
      while ( v7 < v14 )
      {
        if ( *(float *)&i[v7] > 0.0 )
          v13 |= 1 << v7;
        ++v7;
      }
      vostok::network_core::buffer_writer::w<unsigned int>(
        (unsigned __int8 *)&v13,
        (vostok::network_core::buffer_writer *)v7,
        time_offset,
        ".\\victory_item_event_manager.cpp",
        (const char *)0xA4,
        "survarium::victory_item_event_manager::serialize",
        "players_mask");
      v14 = 0;
      v13 = (unsigned int)i;
      while ( v14 < LOBYTE(writer[42].serialization_operations_descriptors.m_last[930].function) )
      {
        if ( *(float *)v13 > 0.0 )
          vostok::network_core::buffer_writer::w<float>(
            (float *)v13,
            v8,
            time_offset,
            ".\\victory_item_event_manager.cpp",
            (const char *)0xA7,
            "survarium::victory_item_event_manager::serialize",
            "item_status.carried_distances[ j ]");
        ++v14;
        v13 += 4;
      }
      vostok::network_core::buffer_writer::w<float>(
        (float *)i + 20,
        v8,
        time_offset,
        ".\\victory_item_event_manager.cpp",
        (const char *)0xA8,
        "survarium::victory_item_event_manager::serialize",
        "item_status.nearest_positions[ team_1 ]");
      vostok::network_core::buffer_writer::w<float>(
        (float *)i + 21,
        v9,
        time_offset,
        ".\\victory_item_event_manager.cpp",
        (const char *)0xA9,
        "survarium::victory_item_event_manager::serialize",
        "item_status.nearest_positions[ team_2 ]");
      v12 = *((_BYTE *)i + 88);
      vostok::network_core::buffer_writer::w<unsigned char>(
        (unsigned __int8 *)&v12,
        v10,
        time_offset,
        ".\\victory_item_event_manager.cpp",
        (const char *)0xAA,
        "survarium::victory_item_event_manager::serialize",
        "static_cast< u8 >( item_status.owner_team )");
      vostok::network_core::buffer_writer::w<bool>(
        (const bool *)i + 92,
        v11,
        time_offset,
        ".\\victory_item_event_manager.cpp",
        (const char *)0xAB,
        "survarium::victory_item_event_manager::serialize",
        "item_status.already_found_once");
      ++v15;
      v3 = writer;
    }
  }
}
