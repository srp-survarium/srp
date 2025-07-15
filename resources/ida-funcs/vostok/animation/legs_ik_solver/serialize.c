void __userpurge vostok::animation::legs_ik_solver::serialize(
        vostok::animation::legs_ik_solver *this@<ecx>,
        int a2@<esi>,
        vostok::network_core::buffer_writer *writer,
        vostok::animation::legs_ik_solver *time_offset)
{
  int v4; // eax
  vostok::animation::legs_ik_solver::leg_params *v5; // ecx
  vostok::animation::legs_ik_solver::leg_params *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  int v8; // eax
  vostok::network_core::buffer_writer *v9; // ecx
  int v10; // eax
  vostok::network_core::buffer_writer *v11; // ecx
  vostok::network_core::buffer_writer *v12; // ecx
  int v13; // [esp+Ch] [ebp-4h] BYREF

  v4 = *(_DWORD *)(a2 + 4);
  if ( v4 == -1 )
  {
    v13 = -1;
  }
  else
  {
    this = time_offset;
    v13 = (int)time_offset + v4;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v13,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1F6,
    "vostok::animation::legs_ik_solver::serialize",
    "(m_current_time_in_ms != u32( -1 )) ? m_current_time_in_ms + time_offset : u32( -1 )");
  vostok::animation::legs_ik_solver::leg_params::serialize(
    v5,
    a2 + 16,
    writer,
    (vostok::network_core::buffer_writer *)time_offset);
  vostok::animation::legs_ik_solver::leg_params::serialize(
    v6,
    a2 + 64,
    writer,
    (vostok::network_core::buffer_writer *)time_offset);
  v8 = *(_DWORD *)(a2 + 112);
  if ( v8 == -1 )
  {
    v13 = -1;
  }
  else
  {
    v7 = (vostok::network_core::buffer_writer *)time_offset;
    v13 = (int)time_offset + v8;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v13,
    v7,
    writer,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1FB,
    "vostok::animation::legs_ik_solver::serialize",
    "m_last_time_heel_was_on_the_ground_in_ms != u32( -1 ) ? m_last_time_heel_was_on_the_ground_in_ms + time_offset : u32( -1 )");
  v10 = *(_DWORD *)(a2 + 116);
  if ( v10 == -1 )
  {
    v13 = -1;
  }
  else
  {
    v9 = (vostok::network_core::buffer_writer *)time_offset;
    v13 = (int)time_offset + v10;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v13,
    v9,
    writer,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1FC,
    "vostok::animation::legs_ik_solver::serialize",
    "m_last_time_toe_was_on_the_ground_in_ms != u32( -1 ) ? m_last_time_toe_was_on_the_ground_in_ms + time_offset : u32( -1 )");
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)(a2 + 124),
    v11,
    writer,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1FD,
    "vostok::animation::legs_ik_solver::serialize",
    "m_heel_transition_time_in_ms");
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)(a2 + 128),
    v12,
    writer,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1FE,
    "vostok::animation::legs_ik_solver::serialize",
    "m_toe_transition_time_in_ms");
}
