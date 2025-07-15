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


void __thiscall survarium::ai_sound_player::play(
        survarium::ai_sound_player *this,
        survarium::ai_sound_player_vtbl *sound_type,
        bool sound_is_positioned,
        const vostok::math::float3 *position)
{
  unsigned int m_sounds_count; // eax
  survarium::ai_sound_player *v6; // ecx
  survarium::ai_sound_player *v7; // eax
  vostok::sound::sound_emitter *type; // ecx
  char v9; // bl
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v10; // eax
  vostok::sound::sound_instance_proxy *m_object; // eax
  vostok::sound::sound_instance_proxy *v12; // ecx
  vostok::sound::sound_instance_proxy *v13; // eax
  bool v14; // zf
  void (__cdecl *v15)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<enum vostok::sound::command_result_enum,boost::_mfi::mf0<enum vostok::sound::command_result_enum,survarium::ai_sound_player>,boost::_bi::list1<boost::_bi::value<survarium::ai_sound_player *> > > v16; // [esp-10h] [ebp-58h]
  int v17; // [esp+0h] [ebp-48h]
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> v18; // [esp+Ch] [ebp-3Ch] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> result; // [esp+10h] [ebp-38h] BYREF
  vostok::sound::command_result_enum (__thiscall *v20)(survarium::ai_sound_player *); // [esp+18h] [ebp-30h]
  int v21; // [esp+1Ch] [ebp-2Ch]
  __int64 v22; // [esp+20h] [ebp-28h]
  boost::function<void __cdecl(void)> f; // [esp+28h] [ebp-20h] BYREF

  result.m_object = 0;
  m_sounds_count = this->m_sounds_count;
  v6 = this + 1;
  v7 = (survarium::ai_sound_player *)((char *)v6 + 16 * m_sounds_count);
  if ( v6 == v7 )
  {
LABEL_4:
    v6 = 0;
  }
  else
  {
    while ( v6->__vftable != sound_type )
    {
      v6 = (survarium::ai_sound_player *)((char *)v6 + 16);
      if ( v6 == v7 )
        goto LABEL_4;
    }
  }
  type = (vostok::sound::sound_emitter *)v6->type;
  if ( sound_is_positioned )
  {
    v9 = 1;
    v10 = vostok::sound::sound_emitter::emit_point_sound(type, &result, this->m_scene, this->m_user);
  }
  else
  {
    v9 = 2;
    v10 = vostok::sound::sound_emitter::emit_hud_sound(type, &v18, this->m_scene, this->m_user);
  }
  m_object = v10->m_object;
  v12 = 0;
  if ( m_object )
  {
    v12 = m_object;
    ++m_object->m_reference_count;
  }
  v13 = this->m_active_sound.m_object;
  this->m_active_sound.m_object = v12;
  if ( v13 )
  {
    v14 = v13->m_reference_count-- == 1;
    if ( v14 )
      v13->free_object(v13);
  }
  if ( (v9 & 2) != 0 )
  {
    v9 &= ~2u;
    if ( v18.m_object )
    {
      v14 = v18.m_object->m_reference_count-- == 1;
      if ( v14 )
        v18.m_object->free_object(v18.m_object);
    }
  }
  if ( (v9 & 1) != 0 )
  {
    if ( result.m_object )
    {
      v14 = result.m_object->m_reference_count-- == 1;
      if ( v14 )
        result.m_object->free_object(result.m_object);
    }
  }
  v20 = survarium::ai_sound_player::on_finish_playing;
  v21 = 0;
  v16.f_.f_ = (vostok::sound::command_result_enum (__thiscall *__ptr64)(survarium::ai_sound_player *))(unsigned int)survarium::ai_sound_player::on_finish_playing;
  LODWORD(v22) = this;
  *(_QWORD *)&v16.l_.a1_.t_ = v22;
  boost::function0<void>::function0<void>(0, (int)&f, (int)this, v16, v17);
  boost::function<void __cdecl (void)>::operator=(&this->m_active_sound.m_object->m_callback, &f);
  if ( f.vtable )
  {
    if ( ((int)f.vtable & 1) == 0 )
    {
      v15 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)f.vtable & 0xFFFFFFFE);
      if ( v15 )
        v15(&f.functor, &f.functor, 2);
    }
  }
  if ( sound_is_positioned )
    this->m_active_sound.m_object->set_position(this->m_active_sound.m_object, position);
  this->m_active_sound.m_object->play(
    this->m_active_sound.m_object,
    once,
    this->m_sound_producer,
    this->m_ignorable_receiver);
}
