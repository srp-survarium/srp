char *__thiscall vostok::ai::ai_world::get_weapon_name_by_id(
        vostok::ai::ai_world *this,
        unsigned int weapon_type,
        unsigned int id)
{
  char *result; // eax

  switch ( weapon_type )
  {
    case 0u:
      result = vostok::ai::get_name_by_id(&this->m_melee_weapons, id);
      break;
    case 1u:
      result = vostok::ai::get_name_by_id(&this->m_sniper_weapons, id);
      break;
    case 2u:
      result = vostok::ai::get_name_by_id(&this->m_heavy_weapons, id);
      break;
    case 3u:
      result = vostok::ai::get_name_by_id(&this->m_energy_weapons, id);
      break;
    case 4u:
      result = vostok::ai::get_name_by_id(&this->m_light_weapons, id);
      break;
  }
  return result;
}
