void __thiscall survarium::player_logic_sprint_state::on_stamina_depleted(survarium::player_logic_sprint_state *this)
{
  survarium::base_player::force_animation_selection((survarium::base_player *)this, (int)this->m_user);
}
