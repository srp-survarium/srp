void __thiscall survarium::ai_sound_player::play(
        survarium::ai_sound_player *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> sound_to_be_played,
        const boost::function<void __cdecl(void)> *finish_callback,
        const vostok::math::float3 *position)
{
  vostok::sound::sound_instance_proxy *m_object; // eax
  vostok::sound::sound_instance_proxy *v6; // ecx
  vostok::sound::sound_instance_proxy *v7; // eax
  bool v8; // zf
  vostok::sound::sound_emitter *v9; // eax
  vostok::resources::unmanaged_intrusive_base *v10; // ecx
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> sound; // [esp+10h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> result; // [esp+14h] [ebp-8h] BYREF

  sound.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&sound,
    (vostok::configs::binary_config *)sound_to_be_played.m_object);
  m_object = vostok::sound::sound_emitter::emit_point_sound(sound.m_object, &result, this->m_scene, this->m_user)->m_object;
  v6 = 0;
  if ( m_object )
  {
    v6 = m_object;
    ++m_object->m_reference_count;
  }
  v7 = this->m_active_sound.m_object;
  this->m_active_sound.m_object = v6;
  if ( v7 )
  {
    v8 = v7->m_reference_count-- == 1;
    if ( v8 )
      v7->free_object(v7);
  }
  if ( result.m_object )
  {
    v8 = result.m_object->m_reference_count-- == 1;
    if ( v8 )
      result.m_object->free_object(result.m_object);
  }
  boost::function<void __cdecl (void)>::operator=(&this->m_active_sound.m_object->m_callback, finish_callback);
  this->m_active_sound.m_object->set_position(this->m_active_sound.m_object, position);
  this->m_active_sound.m_object->play(
    this->m_active_sound.m_object,
    once,
    this->m_sound_producer,
    this->m_ignorable_receiver);
  v9 = sound.m_object;
  if ( sound.m_object )
  {
    v10 = &sound.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&sound.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v10, v9);
  }
  if ( sound_to_be_played.m_object )
  {
    if ( !_InterlockedExchangeAdd(&sound_to_be_played.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &sound_to_be_played.m_object->vostok::resources::unmanaged_intrusive_base,
        sound_to_be_played.m_object);
  }
}
