void __thiscall survarium::artefact_base::deserialize(
        survarium::artefact_base *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader,
        unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // esi
  bool v7; // zf
  vostok::network_core::buffer_reader *readera; // [esp+14h] [ebp+8h]
  vostok::network_core::buffer_reader *readerb; // [esp+14h] [ebp+8h]
  unsigned __int8 reader_3; // [esp+17h] [ebp+Bh]
  unsigned __int8 time_offset_3; // [esp+1Fh] [ebp+13h]

  survarium::inventory_item::deserialize(this, reader, client_reader, time_offset);
  this->m_time_left_to_spawn = -1;
  this->m_time_left_to_cool = 0;
  this->m_container_id = -1;
  time_offset_3 = *reader->m_pointer++;
  this->m_state = time_offset_3;
  if ( time_offset_3 == 1 || time_offset_3 == 2 )
  {
    m_pointer = reader->m_pointer;
    reader_3 = *m_pointer;
    reader->m_pointer = m_pointer + 1;
    v7 = this->m_state == artefact_state_spawning;
    this->m_container_id = reader_3;
    if ( v7 )
    {
      readerb = *(vostok::network_core::buffer_reader **)reader->m_pointer;
      reader->m_pointer += 4;
      this->m_time_left_to_spawn = (unsigned int)readerb;
    }
  }
  else
  {
    readera = *(vostok::network_core::buffer_reader **)reader->m_pointer;
    reader->m_pointer += 4;
    this->m_time_left_to_cool = (unsigned int)readera;
  }
}
