void __thiscall survarium::artefact_base::serialize(
        survarium::artefact_base *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  survarium::artefact_state_enum v7; // eax
  vostok::network_core::buffer_writer *v8; // ecx
  unsigned __int8 m_state; // [esp+Fh] [ebp-1h] BYREF

  survarium::inventory_item::serialize(this, writer, client_writer, time_offset);
  m_state = this->m_state;
  vostok::network_core::buffer_writer::w<unsigned char>(
    &m_state,
    v5,
    writer,
    ".\\artefact_base.cpp",
    (const char *)0xB0,
    "survarium::artefact_base::serialize",
    "static_cast< u8 >( m_state )");
  v7 = this->m_state;
  if ( v7 == artefact_state_spawning || v7 == artefact_state_spawned )
  {
    vostok::network_core::buffer_writer::w<unsigned char>(
      &this->m_container_id,
      v6,
      writer,
      ".\\artefact_base.cpp",
      (const char *)0xB3,
      "survarium::artefact_base::serialize",
      "m_container_id");
    if ( this->m_state == artefact_state_spawning )
      vostok::network_core::buffer_writer::w<unsigned int>(
        (unsigned __int8 *)&this->m_time_left_to_spawn,
        v8,
        writer,
        ".\\artefact_base.cpp",
        (const char *)0xB5,
        "survarium::artefact_base::serialize",
        "m_time_left_to_spawn");
  }
  else
  {
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&this->m_time_left_to_cool,
      v6,
      writer,
      ".\\artefact_base.cpp",
      (const char *)0xB8,
      "survarium::artefact_base::serialize",
      "m_time_left_to_cool");
  }
}
