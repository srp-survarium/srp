void __thiscall vostok::sound::receiver_collision::delete_position(
        vostok::sound::receiver_collision *this,
        vostok::sound::sound_scene *scene)
{
  vostok::sound::sound_scene::delete_receiver_position(scene, this->m_position);
  this->m_position = 0;
}
