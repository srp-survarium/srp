void __thiscall survarium::bullet_manager::tick_bullets(
        survarium::bullet_manager *this,
        unsigned int start_index,
        survarium::bullet *end_index,
        unsigned int current_time_in_ms)
{
  survarium::bullet **m_begin; // eax
  survarium::bullet **v5; // esi
  survarium::bullet *v6; // ecx
  const char *i; // edi

  m_begin = this->m_bullets.m_begin;
  v5 = &m_begin[start_index];
  v6 = end_index;
  for ( i = (const char *)&m_begin[(_DWORD)end_index];
        v5 != (survarium::bullet **)i;
        survarium::bullet::tick(current_time_in_ms, v6, i, *v5++) )
  {
    ;
  }
}
