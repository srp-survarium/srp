void __thiscall survarium::oxygen_tank::serialize(
        survarium::oxygen_tank *this,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v5; // ecx
  vostok::network_core::buffer_writer *v6; // ecx

  survarium::inventory_item::serialize(this, writer, client_writer, time_offset);
  vostok::network_core::buffer_writer::w<bool>(
    &this->m_active,
    v5,
    writer,
    ".\\oxygen_tank.cpp",
    (const char *)0xA0,
    "survarium::oxygen_tank::serialize",
    "m_active");
  vostok::network_core::buffer_writer::w<unsigned int>(
    (unsigned __int8 *)&this->m_amount_ms,
    v6,
    writer,
    ".\\oxygen_tank.cpp",
    (const char *)0xA1,
    "survarium::oxygen_tank::serialize",
    "m_amount_ms");
}
