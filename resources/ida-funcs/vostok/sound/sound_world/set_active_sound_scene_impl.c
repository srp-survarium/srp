void __thiscall vostok::sound::sound_world::set_active_sound_scene_impl(
        vostok::sound::sound_world *this,
        vostok::sound::sound_scene *scene,
        unsigned int fade_in_time,
        unsigned int fade_out_time)
{
  if ( this->m_current_scene )
    vostok::sound::sound_scene::fade_out(this->m_current_scene, fade_out_time);
  this->m_current_scene = scene;
  if ( this->m_current_scene )
    vostok::sound::sound_scene::fade_in(this->m_current_scene, this, fade_in_time);
}
