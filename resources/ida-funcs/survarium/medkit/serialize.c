void __thiscall survarium::medkit::serialize(
        survarium::medkit *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx
  vostok::network_core::buffer_writer *v7; // ecx
  unsigned __int8 i; // [esp+Fh] [ebp-1h]

  survarium::inventory_item::serialize(&this->survarium::inventory_item, writer, client_writer, time_offset);
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_active,
    v5,
    writer,
    ".\\medkit.cpp",
    (const char *)0x11F,
    "survarium::medkit::serialize",
    "m_active");
  if ( this->m_active )
  {
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&this->m_activity_time_ms,
      v6,
      writer,
      ".\\medkit.cpp",
      (const char *)0x123,
      "survarium::medkit::serialize",
      "m_activity_time_ms");
    vostok::network_core::buffer_writer::w<unsigned int>(
      (unsigned __int8 *)&this->m_delay_ms,
      v7,
      writer,
      ".\\medkit.cpp",
      (const char *)0x124,
      "survarium::medkit::serialize",
      "m_delay_ms");
    for ( i = 0; i < this->m_influences_count; ++i )
      vostok::network_core::buffer_writer::w<float>(
        &this->m_applied_influence[i],
        (vostok::network_core::buffer_writer *)this->m_applied_influence,
        writer,
        ".\\medkit.cpp",
        (const char *)0x127,
        "survarium::medkit::serialize",
        "m_applied_influence[i]");
  }
}
