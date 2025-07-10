int __thiscall vostok::ai::ai_world::get_weapons_count(vostok::ai::ai_world *this, unsigned int weapons_type)
{
  int result; // eax

  switch ( weapons_type )
  {
    case 0u:
      result = this->m_melee_weapons.m_end - this->m_melee_weapons.m_begin;
      break;
    case 1u:
      result = this->m_sniper_weapons.m_end - this->m_sniper_weapons.m_begin;
      break;
    case 2u:
      result = this->m_heavy_weapons.m_end - this->m_heavy_weapons.m_begin;
      break;
    case 3u:
      result = this->m_energy_weapons.m_end - this->m_energy_weapons.m_begin;
      break;
    case 4u:
      result = this->m_light_weapons.m_end - this->m_light_weapons.m_begin;
      break;
  }
  return result;
}
