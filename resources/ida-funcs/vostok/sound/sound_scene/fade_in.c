void __usercall vostok::sound::sound_scene::fade_in(
        vostok::sound::sound_scene *this@<edi>,
        vostok::sound::sound_world *world@<edx>)
{
  if ( !this->m_is_active )
  {
    vostok::sound::sound_world::add_scene_to_active((vostok::sound::sound_world *)this, (int)world);
    this->m_is_active = 1;
  }
  this->m_fade_state = overall;
}
