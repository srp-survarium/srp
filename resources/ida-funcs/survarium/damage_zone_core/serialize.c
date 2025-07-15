void __thiscall survarium::damage_zone_core::serialize(
        survarium::damage_zone_core *this,
        vostok::network_core::buffer_writer *writer,
        survarium::damage_zone_core *time_offset)
{
  survarium::damage_zone_core *v3; // ebx
  vostok::resources::class_id_enum m_class_id; // eax
  vostok::network_core::buffer_writer *v5; // ecx
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v3 = this;
  m_class_id = this->m_class_id;
  if ( m_class_id == -1 )
  {
    v6 = -1;
  }
  else
  {
    this = time_offset;
    v6 = (int)time_offset + m_class_id;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v6,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\damage_zone_core.cpp",
    (const char *)0x2B,
    "survarium::damage_zone_core::serialize",
    "(m_last_hit_time_ms!=u32(-1)) ? m_last_hit_time_ms+time_offset : m_last_hit_time_ms");
  vostok::network_core::buffer_writer::w<bool>(
    (const bool *)&v3->grm_satisfaction_tree_hook.parent_ + 1,
    v5,
    writer,
    ".\\damage_zone_core.cpp",
    (const char *)0x2C,
    "survarium::damage_zone_core::serialize",
    "m_hitting");
}
