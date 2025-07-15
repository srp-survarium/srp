void __thiscall survarium::booby_trap_set::holder_assigned(survarium::booby_trap_set *this)
{
  survarium::base_player *v2; // eax

  v2 = this->m_inventory->m_holder->cast_to_base_player(this->m_inventory->m_holder);
  survarium::base_player::subscribe_on_player_death(v2, (survarium::game_camera *)&this->m_player_death_subscriber);
}
