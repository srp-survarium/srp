bool __thiscall vostok::sound::sound_voice::is_same_voice(
        vostok::sound::sound_voice *this,
        unsigned int first_portal_id,
        unsigned int second_portal_id)
{
  if ( first_portal_id == this->m_first_portal_id && second_portal_id == this->m_second_portal_id )
    return 1;
  return first_portal_id == this->m_second_portal_id || second_portal_id == this->m_first_portal_id;
}
