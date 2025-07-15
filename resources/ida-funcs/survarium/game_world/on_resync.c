void __thiscall survarium::game_world::on_resync(survarium::game_world *this, unsigned int __formal)
{
  Scaleform::GFx::Movie::Invoke(
    this->game_ui.m_game_hud_ui.m_object->movie->m_movie,
    "root.show_warning_indicator",
    0,
    0,
    0);
}
