void __usercall survarium::object_sound::insert(
        survarium::object_sound *this@<ecx>,
        vostok::sound::sound_cone_type a2@<esi>)
{
  vostok::particle::particle_system_instance_impl *m_object; // edi
  survarium::base_game_scene *m_game_scene; // esi
  vostok::sound::world_user *v5; // eax
  vostok::sound::sound_scene *v6; // ecx
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *p_m_sound_instance; // esi
  bool v8; // zf
  survarium::base_game_scene *v9; // eax
  vostok::sound::world *m_sound_world; // ecx
  int v11; // eax
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v12; // edi
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> v14; // [esp+8h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // [esp+Ch] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> object; // [esp+10h] [ebp-4h] BYREF

  m_object = (vostok::particle::particle_system_instance_impl *)this->m_sound_emitter.m_object;
  if ( m_object )
  {
    if ( this->m_sound_emitter_type == 1 )
    {
      m_game_scene = this->m_game_scene;
      v14.m_object = (vostok::sound::sound_instance_proxy *)m_game_scene->m_game->m_sound_world->get_logic_world_user(m_game_scene->m_game->m_sound_world);
      object.m_object = (vostok::sound::sound_instance_proxy *)m_game_scene->m_sound_scene.m_object;
      vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
        &v15,
        m_object);
      v5 = (vostok::sound::world_user *)((int (__thiscall *)(vostok::particle::particle_system_instance_impl *, vostok::sound::sound_instance_proxy *))m_object->is_finished)(
                                          m_object,
                                          v14.m_object);
      vostok::sound::sound_scene::new_spot_sound_instance_proxy(
        v6,
        (vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)object.m_object,
        &object,
        &v15,
        v5,
        a2);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v15);
      p_m_sound_instance = &this->m_sound_instance;
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        &object,
        &this->m_sound_instance);
      if ( object.m_object )
      {
        v8 = object.m_object->m_reference_count-- == 1;
        if ( v8 )
          object.m_object->free_object(object.m_object);
      }
      p_m_sound_instance->m_object->set_position_and_direction(
        p_m_sound_instance->m_object,
        (const vostok::math::float3 *)&this->m_transform.lines[3],
        (const vostok::math::float3 *)&this->m_transform.lines[2]);
    }
    else
    {
      v9 = this->m_game_scene;
      m_sound_world = v9->m_game->m_sound_world;
      v15.m_object = (vostok::particle::particle_system_instance_impl *)&v9->m_sound_scene;
      p_m_sound_instance = &this->m_sound_instance;
      v11 = ((int (__thiscall *)(vostok::sound::world *, vostok::sound::sound_cone_type))m_sound_world->get_logic_world_user)(
              m_sound_world,
              a2);
      v12 = vostok::sound::sound_emitter::emit_point_sound(
              (vostok::sound::sound_emitter *)m_object,
              (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)v15.m_object,
              &v14,
              v11);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        v12,
        &this->m_sound_instance);
      if ( v14.m_object )
      {
        v8 = v14.m_object->m_reference_count-- == 1;
        if ( v8 )
          v14.m_object->free_object(v14.m_object);
      }
      p_m_sound_instance->m_object->set_position(
        p_m_sound_instance->m_object,
        (const vostok::math::float3 *)&this->m_transform.lines[3]);
    }
    ((void (__thiscall *)(vostok::sound::sound_instance_proxy *, int, _DWORD))p_m_sound_instance->m_object->play)(
      p_m_sound_instance->m_object,
      1,
      0);
  }
}
