void __thiscall survarium::artefact_lifebone_core::serialize(
        survarium::artefact_lifebone_core *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v5; // ecx

  survarium::artefact_base::serialize(this, writer, client_writer, time_offset);
  if ( this->m_state == artefact_state_picked_active )
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&this->m_time_left_to_deactivate,
      v5,
      writer,
      ".\\artefact_lifebone_core.cpp",
      (const char *)0x60,
      "survarium::artefact_lifebone_core::serialize",
      "m_time_left_to_deactivate");
}
