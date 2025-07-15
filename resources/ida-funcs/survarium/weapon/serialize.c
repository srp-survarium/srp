void __thiscall survarium::weapon::serialize(
        survarium::weapon *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer,
        unsigned int time_offset)
{
  vostok::network_core::buffer_writer *v5; // ecx

  survarium::weapon_core::serialize(this, writer, client_writer, time_offset);
  vostok::network_core::buffer_writer::w<bool>(&this->m_is_scope_aimed, v5, client_writer);
}


void __thiscall survarium::weapon::serialize(
        char *this,
        vostok::network_core::buffer_writer *a2,
        vostok::network_core::buffer_writer *a3,
        unsigned int a4)
{
  survarium::weapon::serialize((survarium::weapon *)(this - 16), a2, a3, a4);
}
