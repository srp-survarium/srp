void __thiscall survarium::bullet_manager::tick_bullets(
        survarium::bullet_manager *this,
        unsigned int start_index,
        unsigned int end_index,
        unsigned int current_time_in_ms)
{
  survarium::bullet **m_begin; // [esp+4h] [ebp-10h]
  survarium::bullet **current; // [esp+10h] [ebp-4h]

  current = &this->m_bullets.m_begin[start_index];
  m_begin = this->m_bullets.m_begin;
  while ( current != &m_begin[end_index] )
    survarium::bullet::tick(*current++, current_time_in_ms);
}
