void __thiscall vostok::animation::legs_ik_solver::leg_params::serialize(
        vostok::animation::legs_ik_solver::leg_params *this,
        int writer,
        vostok::network_core::buffer_writer *time_offset,
        vostok::network_core::buffer_writer *a4)
{
  int v4; // ebx
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  int v8; // eax
  vostok::network_core::buffer_writer *v9; // ecx
  vostok::network_core::buffer_writer *v10; // ecx

  v4 = writer;
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)(writer + 20),
    (vostok::network_core::buffer_writer *)this,
    time_offset,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1E1,
    "vostok::animation::legs_ik_solver::leg_params::serialize",
    "heel_transition_time_in_ms");
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)(v4 + 24),
    v5,
    time_offset,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1E2,
    "vostok::animation::legs_ik_solver::leg_params::serialize",
    "toe_transition_time_in_ms");
  vostok::network_core::buffer_writer::w<vostok::math::float3>(
    (vostok::math::float3 *)(v4 + 28),
    v6,
    time_offset,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1E3,
    "vostok::animation::legs_ik_solver::leg_params::serialize",
    "rotation_axis");
  v8 = *(_DWORD *)(v4 + 40);
  if ( v8 == -1 )
  {
    writer = -1;
  }
  else
  {
    v7 = a4;
    writer = (int)a4 + v8;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer,
    v7,
    time_offset,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1E4,
    "vostok::animation::legs_ik_solver::leg_params::serialize",
    "m_last_stance_time_in_ms != u32( -1 ) ? m_last_stance_time_in_ms + time_offset : u32( -1 )");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)(v4 + 44),
    v9,
    time_offset,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1E5,
    "vostok::animation::legs_ik_solver::leg_params::serialize",
    "m_heel_on_ground");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)(v4 + 45),
    v10,
    time_offset,
    ".\\legs_ik_solver.cpp",
    (const char *)0x1E6,
    "vostok::animation::legs_ik_solver::leg_params::serialize",
    "m_toe_on_ground");
}
