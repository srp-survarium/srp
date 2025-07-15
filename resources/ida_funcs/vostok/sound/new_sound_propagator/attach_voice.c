vostok::sound::sound_voice *__thiscall vostok::sound::new_sound_propagator::attach_voice(
        vostok::sound::new_sound_propagator *this,
        unsigned int offset)
{
  const vostok::resources::resource_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base> *v2; // eax
  vostok::sound::sound_world *m_owner_world; // [esp+4h] [ebp-10h]
  vostok::sound::sound_scene *scene; // [esp+Ch] [ebp-8h]

  if ( offset <= 0xA )
    offset = 0;
  scene = this->m_proxy->m_scene;
  m_owner_world = this->m_proxy->m_user->m_owner_world;
  v2 = this->m_emitter->get_sound_spl(this->m_emitter);
  return vostok::sound::sound_world::create_sound_voice(
           m_owner_world,
           scene,
           offset,
           0,
           0,
           this->m_proxy,
           this->m_emitter,
           v2);
}
