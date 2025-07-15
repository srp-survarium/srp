void __thiscall survarium::damage_model::serialize(
        survarium::damage_model *this,
        int writer,
        vostok::network_core::buffer_writer *time_offset,
        survarium::damage_model *time_offseta)
{
  int v4; // ebx
  int v5; // eax
  vostok::network_core::buffer_writer *v6; // ecx
  int v7; // eax
  vostok::network_core::buffer_writer *v8; // ecx
  survarium::body_part_parameters *v9; // ebx
  survarium::body_part_parameters *v10; // ecx
  survarium::body_part_parameters *next; // esi

  v4 = writer;
  v5 = *(_DWORD *)(writer + 1648);
  if ( v5 == -1 )
  {
    writer = -1;
  }
  else
  {
    this = time_offseta;
    writer = (int)time_offseta + v5;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer,
    (vostok::network_core::buffer_writer *)this,
    time_offset,
    ".\\damage_model.cpp",
    (const char *)0x1FF,
    "survarium::damage_model::serialize",
    "m_last_tick_time_in_ms != u32(-1) ? m_last_tick_time_in_ms + time_offset : u32(-1)");
  v7 = *(_DWORD *)(v4 + 1652);
  if ( v7 == -1 )
  {
    writer = -1;
  }
  else
  {
    v6 = (vostok::network_core::buffer_writer *)time_offseta;
    writer = (int)time_offseta + v7;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&writer,
    v6,
    time_offset,
    ".\\damage_model.cpp",
    (const char *)0x200,
    "survarium::damage_model::serialize",
    "m_invulnerability_time_in_ms != u32(-1) ? m_invulnerability_time_in_ms + time_offset : u32(-1)");
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)(v4 + 1656),
    v8,
    time_offset,
    ".\\damage_model.cpp",
    (const char *)0x201,
    "survarium::damage_model::serialize",
    "m_invulnerability_attenuation");
  v9 = *(survarium::body_part_parameters **)(v4 + 272);
  if ( v9 )
  {
    v10 = v9;
    do
    {
      next = v10->next;
      survarium::body_part_parameters::serialize(v10, time_offset, (vostok::network_core::buffer_writer *)time_offseta);
      v10 = next;
    }
    while ( next );
  }
}
