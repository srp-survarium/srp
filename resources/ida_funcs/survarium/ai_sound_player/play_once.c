void __thiscall survarium::ai_sound_player::play_once(
        survarium::ai_sound_player *this,
        survarium::ai_sound_player_vtbl *sound_type,
        bool sound_is_positioned,
        const vostok::math::float3 *position)
{
  unsigned int m_sounds_count; // eax
  survarium::ai_sound_player *v6; // ecx
  survarium::ai_sound_player *v7; // eax
  survarium::ai_sound_player *v8; // edi

  m_sounds_count = this->m_sounds_count;
  v6 = this + 1;
  v7 = (survarium::ai_sound_player *)((char *)v6 + 16 * m_sounds_count);
  if ( v6 == v7 )
  {
LABEL_4:
    v8 = 0;
  }
  else
  {
    while ( v6->__vftable != sound_type )
    {
      v6 = (survarium::ai_sound_player *)((char *)v6 + 16);
      if ( v6 == v7 )
        goto LABEL_4;
    }
    v8 = v6;
  }
  vostok::sound::sound_emitter::emit_point_sound(
    (vostok::sound::sound_emitter *)v8->type,
    (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)&sound_type,
    this->m_scene,
    this->m_user);
  vostok::sound::sound_emitter::emit_and_play_once(
    (vostok::sound::sound_emitter *)v8->type,
    this->m_scene,
    this->m_user,
    position,
    this->m_sound_producer,
    this->m_ignorable_receiver,
    0);
  if ( sound_type )
  {
    if ( sound_type[9].log_string-- == (vostok::fixed_string<512> *(__thiscall *)(struct vostok::resources::resource_base *, vostok::fixed_string<512> *))1 )
      (*((void (__thiscall **)(survarium::ai_sound_player_vtbl *))sound_type->~vostok::resources::resource_base + 15))(sound_type);
  }
}
