void __thiscall survarium::bullet_manager::destroy_all_bullets(survarium::bullet_manager *this, const char *args)
{
  survarium::bullet **destroying_bullet_iterator; // [esp+8h] [ebp-4h] BYREF

  while ( this->m_bullets.m_begin != this->m_bullets.m_end )
  {
    destroying_bullet_iterator = this->m_bullets.m_begin;
    survarium::bullet_manager::destroy_bullet(this, &destroying_bullet_iterator);
  }
}
