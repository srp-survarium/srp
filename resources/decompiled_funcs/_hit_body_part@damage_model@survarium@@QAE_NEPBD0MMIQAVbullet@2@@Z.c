char __thiscall survarium::damage_model::hit_body_part(
        survarium::damage_model *this,
        unsigned __int8 initiator,
        const char *part_name,
        const char *damage_type,
        float amount,
        float armor_piercing,
        unsigned int time_in_ms,
        survarium::bullet *const bullet)
{
  survarium::game_camera *m_damage_group; // ecx
  survarium::game_camera **v10; // [esp+14h] [ebp-64h]
  survarium::find_by_damage_type_predicate destination; // [esp+57h] [ebp-21h] BYREF
  char v13; // [esp+67h] [ebp-11h]
  survarium::damage_protector *prot; // [esp+68h] [ebp-10h]
  survarium::body_part_parameters *last_hitted_body_part; // [esp+6Ch] [ebp-Ch]
  survarium::body_part_parameters *part; // [esp+70h] [ebp-8h]
  const char *hit_type; // [esp+74h] [ebp-4h]

  if ( bullet )
    v10 = vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::find(
            &this->m_body_parts,
            (survarium::game_camera **)bullet->m_last_hitted_body_part);
  else
    v10 = 0;
  last_hitted_body_part = (survarium::body_part_parameters *)v10;
  part = (survarium::body_part_parameters *)survarium::damage_model::get_body_part(this, part_name);
  if ( v10 )
  {
    if ( last_hitted_body_part == part )
      return 0;
    LOBYTE(m_damage_group) = last_hitted_body_part->m_damage_group;
    if ( (unsigned __int8)m_damage_group != 255 )
    {
      m_damage_group = (survarium::game_camera *)last_hitted_body_part->m_damage_group;
      if ( m_damage_group == (survarium::game_camera *)part->m_damage_group )
        return 0;
    }
  }
  v13 = 0;
  survarium::weapon_user_dead_state::finalize(m_damage_group);
  hit_type = damage_type;
  this->m_last_hit_initiator = initiator;
  vostok::strings::copy(destination.m_damage_type, 0x10u, damage_type);
  prot = vostok::intrusive_list<survarium::booster_damage_protector,survarium::booster_damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::find_if<survarium::find_by_damage_type_predicate>(
           &this->m_damage_protectors,
           &destination);
  survarium::body_part_parameters::hit_by_type(part, (char *)hit_type, time_in_ms, amount, armor_piercing, 1, prot);
  if ( bullet )
    bullet->m_last_hitted_body_part = part;
  return 1;
}
