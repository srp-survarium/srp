void __usercall survarium::player_input::deserialize(
        survarium::player_input *this@<ecx>,
        vostok::network_core::buffer_reader *reader@<eax>)
{
  const unsigned __int8 *m_pointer; // esi
  vostok::math::float2 v3; // [esp+8h] [ebp-8h]

  m_pointer = reader->m_pointer;
  v3 = *(vostok::math::float2 *)m_pointer;
  reader->m_pointer = m_pointer + 8;
  this->rotation_delta = v3;
  v3.y = *(float *)reader->m_pointer;
  reader->m_pointer += 4;
  this->actions_mask = LODWORD(v3.y);
}
