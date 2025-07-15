void __thiscall survarium::weapon::deserialize(
        survarium::weapon *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  bool m_aimed; // al

  survarium::weapon_core::deserialize(this, reader, client_reader, time_offset);
  m_aimed = 0;
  if ( client_reader )
  {
    m_aimed = vostok::network_core::buffer_reader::r<bool>(client_reader);
  }
  else if ( this->m_rifle_scope.m_object )
  {
    m_aimed = this->m_aimed;
  }
  this->m_is_scope_aimed = m_aimed;
}


void __thiscall survarium::weapon::deserialize(
        char *this,
        vostok::network_core::buffer_reader *a2,
        vostok::network_core::buffer_reader *a3,
        unsigned int a4)
{
  survarium::weapon::deserialize((survarium::weapon *)(this - 16), a2, a3, a4);
}
