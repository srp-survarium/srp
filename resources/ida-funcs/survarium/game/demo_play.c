void __thiscall survarium::game::demo_play(survarium::game *this, const char *track_name)
{
  if ( this->m_active_scene )
    this->m_active_scene->demo_play(this->m_active_scene, track_name);
}
