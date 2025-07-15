void __thiscall survarium::transition_helper::serialize(
        survarium::transition_helper *this,
        int writer,
        vostok::network_core::buffer_writer *time_offset,
        int a4)
{
  int v4; // ebx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  int v9; // ebx

  v4 = writer;
  vostok::network_core::buffer_writer::w<float>(
    (float *)writer,
    (vostok::network_core::buffer_writer *)this,
    time_offset,
    ".\\transition_helper.cpp",
    (const char *)0x3A,
    "survarium::transition_helper::serialize",
    "m_current_value");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(v4 + 4),
    v5,
    time_offset,
    ".\\transition_helper.cpp",
    (const char *)0x3B,
    "survarium::transition_helper::serialize",
    "m_start_value");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(v4 + 8),
    v6,
    time_offset,
    ".\\transition_helper.cpp",
    (const char *)0x3C,
    "survarium::transition_helper::serialize",
    "m_target_value");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(v4 + 12),
    v7,
    time_offset,
    ".\\transition_helper.cpp",
    (const char *)0x3D,
    "survarium::transition_helper::serialize",
    "m_transition_time");
  v9 = *(_DWORD *)(v4 + 16);
  if ( v9 == -1 )
    writer = -1;
  else
    writer = a4 + v9;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer,
    v8,
    time_offset,
    ".\\transition_helper.cpp",
    (const char *)0x3E,
    "survarium::transition_helper::serialize",
    "m_start_transition_time_in_ms == u32( -1 ) ? u32( -1 ) : m_start_transition_time_in_ms + time_offset");
}
