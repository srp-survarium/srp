void __thiscall survarium::dispersion_calculator::deserialize(
        survarium::dispersion_calculator *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *time_offset,
        unsigned int a4)
{
  const unsigned __int8 *m_pointer; // eax
  const unsigned __int8 *v5; // xmm0_4

  survarium::transition_helper::deserialize((survarium::transition_helper *)&reader[1], time_offset, a4);
  survarium::transition_helper::deserialize((survarium::transition_helper *)&reader[2].m_buffer_size, time_offset, a4);
  m_pointer = time_offset->m_pointer;
  v5 = *(const unsigned __int8 **)m_pointer;
  time_offset->m_pointer = m_pointer + 4;
  reader[4].m_pointer = v5;
}
