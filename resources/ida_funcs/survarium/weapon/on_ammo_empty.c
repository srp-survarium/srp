void __thiscall survarium::weapon::on_ammo_empty(survarium::weapon *this)
{
  if ( this->m_game_ui )
    survarium::game_world_ui::show_screen_message(this->m_game_ui, "st_empty_ammo_message");
}
