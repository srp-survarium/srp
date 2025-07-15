void __thiscall survarium::timelimit_rule_core::serialize(
        survarium::timelimit_rule_core *this,
        vostok::network_core::buffer_writer *writer,
        survarium::timelimit_rule_core *time_offset)
{
  survarium::timelimit_rule_core *v3; // ebx
  unsigned int m_state_start_time_ms; // eax
  vostok::network_core::buffer_writer *v5; // ecx
  unsigned int m_current_time_in_ms; // eax
  vostok::network_core::buffer_writer *v7; // ecx
  vostok::network_core::buffer_writer *v8; // ecx
  unsigned __int8 m_current_state; // [esp+13h] [ebp-5h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  v3 = this;
  m_state_start_time_ms = this->m_state_start_time_ms;
  if ( m_state_start_time_ms == -1 )
  {
    v10 = -1;
  }
  else
  {
    this = time_offset;
    v10 = (int)time_offset + m_state_start_time_ms;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v10,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\timelimit_rule_core.cpp",
    (const char *)0x2C,
    "survarium::timelimit_rule_core::serialize",
    "(m_state_start_time_ms==u32(-1)) ? m_state_start_time_ms : m_state_start_time_ms+time_offset");
  m_current_time_in_ms = v3->m_current_time_in_ms;
  if ( m_current_time_in_ms == -1 )
  {
    v10 = -1;
  }
  else
  {
    v5 = (vostok::network_core::buffer_writer *)time_offset;
    v10 = (int)time_offset + m_current_time_in_ms;
  }
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v10,
    v5,
    writer,
    ".\\timelimit_rule_core.cpp",
    (const char *)0x2D,
    "survarium::timelimit_rule_core::serialize",
    "(m_current_time_in_ms==u32(-1)) ? m_current_time_in_ms : m_current_time_in_ms+time_offset");
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&v3->m_players_mask,
    v7,
    writer,
    ".\\timelimit_rule_core.cpp",
    (const char *)0x2E,
    "survarium::timelimit_rule_core::serialize",
    "m_players_mask");
  m_current_state = v3->m_current_state;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &m_current_state,
    v8,
    writer,
    ".\\timelimit_rule_core.cpp",
    (const char *)0x2F,
    "survarium::timelimit_rule_core::serialize",
    "(u8)m_current_state");
}
