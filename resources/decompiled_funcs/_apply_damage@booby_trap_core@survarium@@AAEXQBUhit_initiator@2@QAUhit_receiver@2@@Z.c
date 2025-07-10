void __thiscall survarium::booby_trap_core::apply_damage(
        survarium::booby_trap_core *this,
        const survarium::hit_initiator *const initiator,
        survarium::hit_receiver *const receiver)
{
  survarium::booby_trap_set_core *m_owner; // ecx
  vostok::collision::bone_collision_data bcd; // [esp+24h] [ebp-80h] BYREF
  const vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage> *damage_parameters; // [esp+98h] [ebp-Ch]
  const survarium::booby_trap_set_core::apply_damage *end; // [esp+9Ch] [ebp-8h]
  const survarium::booby_trap_set_core::apply_damage *it; // [esp+A0h] [ebp-4h]

  m_owner = this->m_owner;
  damage_parameters = &m_owner->m_damage_parameters;
  it = m_owner->m_damage_parameters.m_begin;
  end = m_owner->m_damage_parameters.m_end;
  while ( it != end )
  {
    vostok::collision::bone_collision_data::bone_collision_data(&bcd, (const char *)&buf, 0, it->body_part);
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))receiver->hit)(
      receiver,
      initiator,
      &bcd,
      it->hit_type,
      it->amount,
      it->armor_piercing,
      0);
    ++it;
  }
}
