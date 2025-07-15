void __thiscall survarium::weapon_recoil_calculator::serialize(
        survarium::weapon_recoil_calculator *this,
        unsigned int writer,
        vostok::network_core::buffer_writer *time_offset,
        int a4)
{
  unsigned int v4; // ebx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx
  int v11; // eax
  vostok::network_core::buffer_writer *v12; // ecx
  int v13; // eax
  vostok::network_core::buffer_writer *v14; // ecx
  int v15; // eax
  vostok::network_core::buffer_writer *v16; // ecx

  v4 = writer;
  writer = *(_DWORD *)writer;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer,
    (vostok::network_core::buffer_writer *)this,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0x98,
    "survarium::weapon_recoil_calculator::serialize",
    "m_random.seed( )");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(v4 + 16),
    v5,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0x9A,
    "survarium::weapon_recoil_calculator::serialize",
    "m_vertical_target");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(v4 + 20),
    v6,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0x9B,
    "survarium::weapon_recoil_calculator::serialize",
    "m_horizontal_target");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(v4 + 24),
    v7,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0x9C,
    "survarium::weapon_recoil_calculator::serialize",
    "m_back_target");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(v4 + 28),
    v8,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0x9D,
    "survarium::weapon_recoil_calculator::serialize",
    "m_vertical_value_at_last_shoot");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(v4 + 32),
    v9,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0x9E,
    "survarium::weapon_recoil_calculator::serialize",
    "m_horizontal_value_at_last_shoot");
  v11 = *(_DWORD *)(v4 + 36);
  if ( v11 == -1 )
  {
    writer = -1;
  }
  else
  {
    v10 = (vostok::network_core::buffer_writer *)a4;
    writer = a4 + v11;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer,
    v10,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0xA0,
    "survarium::weapon_recoil_calculator::serialize",
    "m_time_to_start_side_compensation != u32( -1 ) ? ( m_time_to_start_side_compensation + time_offset ) : u32( -1 )");
  v13 = *(_DWORD *)(v4 + 40);
  if ( v13 == -1 )
  {
    writer = -1;
  }
  else
  {
    v12 = (vostok::network_core::buffer_writer *)a4;
    writer = a4 + v13;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer,
    v12,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0xA1,
    "survarium::weapon_recoil_calculator::serialize",
    "m_time_to_start_back_compensation != u32( -1 ) ? ( m_time_to_start_back_compensation + time_offset ) : u32( -1 )");
  v15 = *(_DWORD *)(v4 + 44);
  if ( v15 == -1 )
  {
    a4 = -1;
  }
  else
  {
    v14 = (vostok::network_core::buffer_writer *)a4;
    a4 += v15;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&a4,
    v14,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0xA2,
    "survarium::weapon_recoil_calculator::serialize",
    "m_time_of_last_shoot != u32( -1 ) ? ( m_time_of_last_shoot + time_offset ) : u32( -1 )");
  vostok::network_core::buffer_writer::w<float>(
    (float *)(v4 + 12),
    v16,
    time_offset,
    ".\\weapon_recoil_calculator.cpp",
    (const char *)0xA3,
    "survarium::weapon_recoil_calculator::serialize",
    "m_player_recoil_multiplier");
}
