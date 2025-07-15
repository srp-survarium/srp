void __thiscall survarium::grenade_set::initialize(survarium::grenade_set *this)
{
  unsigned int i; // edx
  survarium::grenade_core *m_object; // eax

  for ( i = 0; i < this->m_amount; ++i )
  {
    m_object = this->m_grenades.m_begin[i].m_object;
    m_object[1].survarium::serializable_object::next = 0;
    *((_BYTE *)&m_object[1].vostok::collision::game_object + 4) = 0;
  }
}
