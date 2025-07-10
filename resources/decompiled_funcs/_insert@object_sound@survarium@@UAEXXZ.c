void __thiscall survarium::object_sound::insert(survarium::object_sound *this)
{
  survarium::base_game_scene *m_game_scene; // eax
  vostok::sound::sound_emitter *m_object; // ebp
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_sound_scene; // ebx
  int (*get_logic_world_user)(void); // eax
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *p_m_sound_instance; // edi
  vostok::sound::world_user *v7; // eax
  const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v8; // eax
  bool v9; // zf
  vostok::sound::world_user *v10; // eax
  const vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v11; // eax
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> result; // [esp+10h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> v13; // [esp+14h] [ebp-4h] BYREF

  m_game_scene = this->m_game_scene;
  m_object = this->m_sound_emitter.m_object;
  p_m_sound_scene = &m_game_scene->m_sound_scene;
  get_logic_world_user = (int (*)(void))m_game_scene->m_game->m_sound_world->get_logic_world_user;
  p_m_sound_instance = &this->m_sound_instance;
  if ( this->m_sound_emitter_type == 1 )
  {
    v7 = (vostok::sound::world_user *)get_logic_world_user();
    v8 = vostok::sound::sound_emitter::emit_spot_sound(m_object, &result, p_m_sound_scene, v7, human);
    vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
      &this->m_sound_instance,
      v8);
    if ( result.m_object )
    {
      v9 = result.m_object->m_reference_count-- == 1;
      if ( v9 )
        result.m_object->free_object(result.m_object);
    }
    p_m_sound_instance->m_object->set_position_and_direction(
      p_m_sound_instance->m_object,
      (const vostok::math::float3 *)&this->m_transform.lines[3],
      (const vostok::math::float3 *)&this->m_transform.lines[2]);
  }
  else
  {
    v10 = (vostok::sound::world_user *)get_logic_world_user();
    v11 = vostok::sound::sound_emitter::emit_point_sound(m_object, &v13, p_m_sound_scene, v10);
    vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
      &this->m_sound_instance,
      v11);
    if ( v13.m_object )
    {
      v9 = v13.m_object->m_reference_count-- == 1;
      if ( v9 )
        v13.m_object->free_object(v13.m_object);
    }
    p_m_sound_instance->m_object->set_position(
      p_m_sound_instance->m_object,
      (const vostok::math::float3 *)&this->m_transform.lines[3]);
  }
  p_m_sound_instance->m_object->play(p_m_sound_instance->m_object, looped, 0, 0);
}
