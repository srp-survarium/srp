void __thiscall vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage>::push_back(
        vostok::buffer_vector<survarium::booby_trap_set_core::apply_damage> *this,
        const survarium::booby_trap_set_core::apply_damage *value)
{
  survarium::booby_trap_set_core::apply_damage *v3; // [esp+14h] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v3 = (survarium::booby_trap_set_core::apply_damage *)operator new(0x28u, this->m_end);
  if ( v3 )
    qmemcpy(v3, value, sizeof(survarium::booby_trap_set_core::apply_damage));
  ++this->m_end;
}
