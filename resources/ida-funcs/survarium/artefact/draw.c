void __usercall survarium::artefact<survarium::artefact_lifebone_core>::draw(
        survarium::artefact<survarium::artefact_lifebone_core> *this@<ecx>,
        float a2@<xmm0>)
{
  char *m_reconstruction_info_actuality_tick; // eax
  survarium::simple_game_project *m_object; // ecx
  int v5; // eax
  survarium::artefact_base *v6; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // eax
  vostok::render::scene_renderer *v8; // ecx
  char *m_max_end; // eax
  survarium::simple_game_project *v10; // ecx
  int v11; // eax
  survarium::pure_game_effect_emitter_base *v12; // ecx
  survarium::simple_game_project *v13; // ecx
  int v14; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v15; // eax
  bool v16; // zf
  int v17; // ecx
  vostok::math::float4x4 *v18; // edx
  int v19; // ecx
  int v20; // eax
  survarium::base_network_client *v21; // ecx
  int v22; // edx
  survarium::game_world_ui *v23; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v24; // [esp-14h] [ebp-B4h] BYREF
  vostok::math::float4x4 *v25; // [esp-10h] [ebp-B0h]
  vostok::math::float4x4 *v26; // [esp-Ch] [ebp-ACh]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v27; // [esp-8h] [ebp-A8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v28; // [esp-4h] [ebp-A4h]
  unsigned __int8 v29; // [esp+0h] [ebp-A0h]
  unsigned int v30; // [esp+4h] [ebp-9Ch]
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v31; // [esp+Ch] [ebp-94h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v32; // [esp+10h] [ebp-90h] BYREF
  vostok::math::float3 scale; // [esp+14h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v34; // [esp+20h] [ebp-80h] BYREF
  vostok::math::float4x4 v35; // [esp+60h] [ebp-40h] BYREF

  m_reconstruction_info_actuality_tick = (char *)this->m_reconstruction_info_actuality_tick;
  if ( m_reconstruction_info_actuality_tick == this[-1].m_pickup_hint.m_max_end )
  {
    if ( m_reconstruction_info_actuality_tick == (char *)1 )
    {
      m_object = survarium::game_world::get_project(
                   *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
                   &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v5 = (int)m_object->artefact_container(m_object, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v5 + 40))(v5, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      survarium::artefact_base::spawn_progress(
        v6,
        (int)&this[-1].vostok::uid_object<vostok::resources::resource_children>);
      scale.x = a2;
      scale.y = a2;
      scale.z = a2;
      vostok::math::float4x4::set_scale(&v34, &scale);
      vostok::render::scene_renderer::update_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        &v34,
        &v34);
    }
  }
  else
  {
    if ( m_reconstruction_info_actuality_tick == (char *)2 )
    {
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4));
      v7 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)*((_DWORD *)&this->vostok::resources::resource_flags + 3);
      v8 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + v7[40].m_object->m_fat_it.m_type);
      vostok::render::scene_renderer::remove_particle_system_instance(
        v8,
        (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v8,
        v7 + 1,
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_size);
    }
    else if ( m_reconstruction_info_actuality_tick == (char *)1 )
    {
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4));
    }
    m_max_end = this[-1].m_pickup_hint.m_max_end;
    if ( m_max_end == (char *)1 )
    {
      v10 = survarium::game_world::get_project(
              *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
              &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v11 = (int)v10->artefact_container(v10, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v11 + 40))(v11, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      qmemcpy(&v35, &v34, sizeof(v35));
      scale.x = epsilon_3_4;
      scale.y = epsilon_3_4;
      scale.z = epsilon_3_4;
      vostok::math::float4x4::set_scale(&v35, &scale);
      vostok::render::scene_renderer::add_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        &v35,
        &v35);
      v32.m_object = 0;
      v31.m_object = 0;
      v28 = &v32;
      v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31;
      v26 = &v34;
      v25 = &v34;
      v24.m_object = v12;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v24,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_size);
      vostok::render::scene_renderer::play_particle_system(
        (vostok::render::scene_renderer *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        (const vostok::math::float4x4 *)v24.m_object,
        v25,
        v26,
        v27,
        v28);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v32);
      (*(void (__thiscall **)(_DWORD, unsigned int *, vostok::math::float4_pod *))(**((_DWORD **)&this->vostok::resources::resource_flags
                                                                                    + 3)
                                                                                 + 20))(
        *((_DWORD *)&this->vostok::resources::resource_flags + 3),
        &this->m_reconstruction_size + 1,
        &v34.c);
    }
    else if ( m_max_end == (char *)2 )
    {
      v13 = survarium::game_world::get_project(
              *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
              &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v14 = (int)v13->artefact_container(v13, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v14 + 40))(v14, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      v15 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264);
      v16 = BYTE1(v15->m_object->m_lods[0].m_emitter_instance_list.m_size) == 0;
      v17 = *((_DWORD *)&this->vostok::resources::resource_flags + 3);
      v28 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34;
      v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34;
      v18 = (vostok::math::float4x4 *)(v17 + 4);
      v19 = *(_DWORD *)(*(_DWORD *)(v17 + 160) + 172);
      v26 = v18;
      v25 = *(vostok::math::float4x4 **)((char *)&dword_200060 + v19);
      if ( v16 )
        vostok::render::scene_renderer::add_model(
          v15,
          (vostok::render::scene_renderer *)v25,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v26,
          (const vostok::math::float4x4 *)v27,
          (const vostok::math::float4x4 *)v28);
      else
        vostok::render::scene_renderer::update_model(
          v15,
          (vostok::render::scene_renderer *)v25,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v26,
          (const vostok::math::float4x4 *)v27,
          (const vostok::math::float4x4 *)v28);
    }
    else if ( m_max_end == (char *)4 )
    {
      v20 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this[-1].m_container_id + 376) + 12))(*(_DWORD *)(*(_DWORD *)&this[-1].m_container_id + 376));
      if ( survarium::base_network_client::is_player_current(
             v21,
             *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 160) + 13912),
             *(_BYTE *)(v20 + 304)) )
      {
        survarium::game_world_ui::show_parametrized_message(
          v23,
          (const char *)(v22 + 516),
          *(char **)&this[-1].m_activation_hint.m_buffer[20],
          v29,
          v30);
      }
    }
    LODWORD(this->m_reconstruction_info_actuality_tick) = this[-1].m_pickup_hint.m_max_end;
  }
}


void __usercall survarium::artefact<survarium::artefact_onyx_core>::draw(
        survarium::artefact<survarium::artefact_onyx_core> *this@<ecx>,
        float a2@<xmm0>)
{
  char *m_reconstruction_info_actuality_tick; // eax
  survarium::simple_game_project *m_object; // ecx
  int v5; // eax
  survarium::artefact_base *v6; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // eax
  vostok::render::scene_renderer *v8; // ecx
  char *m_max_end; // eax
  survarium::simple_game_project *v10; // ecx
  int v11; // eax
  survarium::pure_game_effect_emitter_base *v12; // ecx
  survarium::simple_game_project *v13; // ecx
  int v14; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v15; // eax
  bool v16; // zf
  int v17; // ecx
  vostok::math::float4x4 *v18; // edx
  int v19; // ecx
  int v20; // eax
  survarium::base_network_client *v21; // ecx
  int v22; // edx
  survarium::game_world_ui *v23; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v24; // [esp-14h] [ebp-B4h] BYREF
  vostok::math::float4x4 *v25; // [esp-10h] [ebp-B0h]
  vostok::math::float4x4 *v26; // [esp-Ch] [ebp-ACh]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v27; // [esp-8h] [ebp-A8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v28; // [esp-4h] [ebp-A4h]
  unsigned __int8 v29; // [esp+0h] [ebp-A0h]
  unsigned int v30; // [esp+4h] [ebp-9Ch]
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v31; // [esp+Ch] [ebp-94h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v32; // [esp+10h] [ebp-90h] BYREF
  vostok::math::float3 scale; // [esp+14h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v34; // [esp+20h] [ebp-80h] BYREF
  vostok::math::float4x4 v35; // [esp+60h] [ebp-40h] BYREF

  m_reconstruction_info_actuality_tick = (char *)this->m_reconstruction_info_actuality_tick;
  if ( m_reconstruction_info_actuality_tick == this[-1].m_pickup_hint.m_max_end )
  {
    if ( m_reconstruction_info_actuality_tick == (char *)1 )
    {
      m_object = survarium::game_world::get_project(
                   *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
                   &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v5 = (int)m_object->artefact_container(m_object, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v5 + 40))(v5, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      survarium::artefact_base::spawn_progress(
        v6,
        (int)&this[-1].vostok::uid_object<vostok::resources::resource_children>);
      scale.x = a2;
      scale.y = a2;
      scale.z = a2;
      vostok::math::float4x4::set_scale(&v34, &scale);
      vostok::render::scene_renderer::update_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        &v34,
        &v34);
    }
  }
  else
  {
    if ( m_reconstruction_info_actuality_tick == (char *)2 )
    {
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4));
      v7 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)*((_DWORD *)&this->vostok::resources::resource_flags + 3);
      v8 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + v7[40].m_object->m_fat_it.m_type);
      vostok::render::scene_renderer::remove_particle_system_instance(
        v8,
        (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v8,
        v7 + 1,
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_size);
    }
    else if ( m_reconstruction_info_actuality_tick == (char *)1 )
    {
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4));
    }
    m_max_end = this[-1].m_pickup_hint.m_max_end;
    if ( m_max_end == (char *)1 )
    {
      v10 = survarium::game_world::get_project(
              *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
              &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v11 = (int)v10->artefact_container(v10, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v11 + 40))(v11, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      qmemcpy(&v35, &v34, sizeof(v35));
      scale.x = epsilon_3_4;
      scale.y = epsilon_3_4;
      scale.z = epsilon_3_4;
      vostok::math::float4x4::set_scale(&v35, &scale);
      vostok::render::scene_renderer::add_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        &v35,
        &v35);
      v32.m_object = 0;
      v31.m_object = 0;
      v28 = &v32;
      v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31;
      v26 = &v34;
      v25 = &v34;
      v24.m_object = v12;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v24,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_size);
      vostok::render::scene_renderer::play_particle_system(
        (vostok::render::scene_renderer *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        (const vostok::math::float4x4 *)v24.m_object,
        v25,
        v26,
        v27,
        v28);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v32);
      (*(void (__thiscall **)(_DWORD, unsigned int *, vostok::math::float4_pod *))(**((_DWORD **)&this->vostok::resources::resource_flags
                                                                                    + 3)
                                                                                 + 20))(
        *((_DWORD *)&this->vostok::resources::resource_flags + 3),
        &this->m_reconstruction_size + 1,
        &v34.c);
    }
    else if ( m_max_end == (char *)2 )
    {
      v13 = survarium::game_world::get_project(
              *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
              &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v14 = (int)v13->artefact_container(v13, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v14 + 40))(v14, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      v15 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264);
      v16 = BYTE1(v15->m_object->m_lods[0].m_emitter_instance_list.m_size) == 0;
      v17 = *((_DWORD *)&this->vostok::resources::resource_flags + 3);
      v28 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34;
      v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34;
      v18 = (vostok::math::float4x4 *)(v17 + 4);
      v19 = *(_DWORD *)(*(_DWORD *)(v17 + 160) + 172);
      v26 = v18;
      v25 = *(vostok::math::float4x4 **)((char *)&dword_200060 + v19);
      if ( v16 )
        vostok::render::scene_renderer::add_model(
          v15,
          (vostok::render::scene_renderer *)v25,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v26,
          (const vostok::math::float4x4 *)v27,
          (const vostok::math::float4x4 *)v28);
      else
        vostok::render::scene_renderer::update_model(
          v15,
          (vostok::render::scene_renderer *)v25,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v26,
          (const vostok::math::float4x4 *)v27,
          (const vostok::math::float4x4 *)v28);
    }
    else if ( m_max_end == (char *)4 )
    {
      v20 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this[-1].m_container_id + 376) + 12))(*(_DWORD *)(*(_DWORD *)&this[-1].m_container_id + 376));
      if ( survarium::base_network_client::is_player_current(
             v21,
             *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 160) + 13912),
             *(_BYTE *)(v20 + 304)) )
      {
        survarium::game_world_ui::show_parametrized_message(
          v23,
          (const char *)(v22 + 516),
          *(char **)&this[-1].m_activation_hint.m_buffer[20],
          v29,
          v30);
      }
    }
    LODWORD(this->m_reconstruction_info_actuality_tick) = this[-1].m_pickup_hint.m_max_end;
  }
}


void __usercall survarium::artefact<survarium::artefact_rattle_core>::draw(
        survarium::artefact<survarium::artefact_rattle_core> *this@<ecx>,
        float a2@<xmm0>)
{
  char *m_reconstruction_info_actuality_tick; // eax
  survarium::simple_game_project *m_object; // ecx
  int v5; // eax
  survarium::artefact_base *v6; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // eax
  vostok::render::scene_renderer *v8; // ecx
  char *m_max_end; // eax
  survarium::simple_game_project *v10; // ecx
  int v11; // eax
  survarium::pure_game_effect_emitter_base *v12; // ecx
  survarium::simple_game_project *v13; // ecx
  int v14; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v15; // eax
  bool v16; // zf
  int v17; // ecx
  vostok::math::float4x4 *v18; // edx
  int v19; // ecx
  int v20; // eax
  survarium::base_network_client *v21; // ecx
  int v22; // edx
  survarium::game_world_ui *v23; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v24; // [esp-14h] [ebp-B4h] BYREF
  vostok::math::float4x4 *v25; // [esp-10h] [ebp-B0h]
  vostok::math::float4x4 *v26; // [esp-Ch] [ebp-ACh]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v27; // [esp-8h] [ebp-A8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v28; // [esp-4h] [ebp-A4h]
  unsigned __int8 v29; // [esp+0h] [ebp-A0h]
  unsigned int v30; // [esp+4h] [ebp-9Ch]
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v31; // [esp+Ch] [ebp-94h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v32; // [esp+10h] [ebp-90h] BYREF
  vostok::math::float3 scale; // [esp+14h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v34; // [esp+20h] [ebp-80h] BYREF
  vostok::math::float4x4 v35; // [esp+60h] [ebp-40h] BYREF

  m_reconstruction_info_actuality_tick = (char *)this->m_reconstruction_info_actuality_tick;
  if ( m_reconstruction_info_actuality_tick == this[-1].m_pickup_hint.m_max_end )
  {
    if ( m_reconstruction_info_actuality_tick == (char *)1 )
    {
      m_object = survarium::game_world::get_project(
                   *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
                   &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v5 = (int)m_object->artefact_container(m_object, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v5 + 40))(v5, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      survarium::artefact_base::spawn_progress(
        v6,
        (int)&this[-1].vostok::uid_object<vostok::resources::resource_children>);
      scale.x = a2;
      scale.y = a2;
      scale.z = a2;
      vostok::math::float4x4::set_scale(&v34, &scale);
      vostok::render::scene_renderer::update_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        &v34,
        &v34);
    }
  }
  else
  {
    if ( m_reconstruction_info_actuality_tick == (char *)2 )
    {
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4));
      v7 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)*((_DWORD *)&this->vostok::resources::resource_flags + 3);
      v8 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + v7[40].m_object->m_fat_it.m_type);
      vostok::render::scene_renderer::remove_particle_system_instance(
        v8,
        (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v8,
        v7 + 1,
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_size);
    }
    else if ( m_reconstruction_info_actuality_tick == (char *)1 )
    {
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4));
    }
    m_max_end = this[-1].m_pickup_hint.m_max_end;
    if ( m_max_end == (char *)1 )
    {
      v10 = survarium::game_world::get_project(
              *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
              &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v11 = (int)v10->artefact_container(v10, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v11 + 40))(v11, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      qmemcpy(&v35, &v34, sizeof(v35));
      scale.x = epsilon_3_4;
      scale.y = epsilon_3_4;
      scale.z = epsilon_3_4;
      vostok::math::float4x4::set_scale(&v35, &scale);
      vostok::render::scene_renderer::add_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        &v35,
        &v35);
      v32.m_object = 0;
      v31.m_object = 0;
      v28 = &v32;
      v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31;
      v26 = &v34;
      v25 = &v34;
      v24.m_object = v12;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v24,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_size);
      vostok::render::scene_renderer::play_particle_system(
        (vostok::render::scene_renderer *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        (const vostok::math::float4x4 *)v24.m_object,
        v25,
        v26,
        v27,
        v28);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v32);
      (*(void (__thiscall **)(_DWORD, unsigned int *, vostok::math::float4_pod *))(**((_DWORD **)&this->vostok::resources::resource_flags
                                                                                    + 3)
                                                                                 + 20))(
        *((_DWORD *)&this->vostok::resources::resource_flags + 3),
        &this->m_reconstruction_size + 1,
        &v34.c);
    }
    else if ( m_max_end == (char *)2 )
    {
      v13 = survarium::game_world::get_project(
              *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
              &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v14 = (int)v13->artefact_container(v13, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v14 + 40))(v14, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      v15 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264);
      v16 = BYTE1(v15->m_object->m_lods[0].m_emitter_instance_list.m_size) == 0;
      v17 = *((_DWORD *)&this->vostok::resources::resource_flags + 3);
      v28 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34;
      v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34;
      v18 = (vostok::math::float4x4 *)(v17 + 4);
      v19 = *(_DWORD *)(*(_DWORD *)(v17 + 160) + 172);
      v26 = v18;
      v25 = *(vostok::math::float4x4 **)((char *)&dword_200060 + v19);
      if ( v16 )
        vostok::render::scene_renderer::add_model(
          v15,
          (vostok::render::scene_renderer *)v25,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v26,
          (const vostok::math::float4x4 *)v27,
          (const vostok::math::float4x4 *)v28);
      else
        vostok::render::scene_renderer::update_model(
          v15,
          (vostok::render::scene_renderer *)v25,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v26,
          (const vostok::math::float4x4 *)v27,
          (const vostok::math::float4x4 *)v28);
    }
    else if ( m_max_end == (char *)4 )
    {
      v20 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this[-1].m_container_id + 376) + 12))(*(_DWORD *)(*(_DWORD *)&this[-1].m_container_id + 376));
      if ( survarium::base_network_client::is_player_current(
             v21,
             *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 160) + 13912),
             *(_BYTE *)(v20 + 304)) )
      {
        survarium::game_world_ui::show_parametrized_message(
          v23,
          (const char *)(v22 + 516),
          *(char **)&this[-1].m_activation_hint.m_buffer[20],
          v29,
          v30);
      }
    }
    LODWORD(this->m_reconstruction_info_actuality_tick) = this[-1].m_pickup_hint.m_max_end;
  }
}


void __usercall survarium::artefact<survarium::artefact_spring_core>::draw(
        survarium::artefact<survarium::artefact_spring_core> *this@<ecx>,
        float a2@<xmm0>)
{
  char *m_reconstruction_info_actuality_tick; // eax
  survarium::simple_game_project *m_object; // ecx
  int v5; // eax
  survarium::artefact_base *v6; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // eax
  vostok::render::scene_renderer *v8; // ecx
  char *m_max_end; // eax
  survarium::simple_game_project *v10; // ecx
  int v11; // eax
  survarium::pure_game_effect_emitter_base *v12; // ecx
  survarium::simple_game_project *v13; // ecx
  int v14; // eax
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v15; // eax
  bool v16; // zf
  int v17; // ecx
  vostok::math::float4x4 *v18; // edx
  int v19; // ecx
  int v20; // eax
  survarium::base_network_client *v21; // ecx
  int v22; // edx
  survarium::game_world_ui *v23; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v24; // [esp-14h] [ebp-B4h] BYREF
  vostok::math::float4x4 *v25; // [esp-10h] [ebp-B0h]
  vostok::math::float4x4 *v26; // [esp-Ch] [ebp-ACh]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v27; // [esp-8h] [ebp-A8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v28; // [esp-4h] [ebp-A4h]
  unsigned __int8 v29; // [esp+0h] [ebp-A0h]
  unsigned int v30; // [esp+4h] [ebp-9Ch]
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v31; // [esp+Ch] [ebp-94h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v32; // [esp+10h] [ebp-90h] BYREF
  vostok::math::float3 scale; // [esp+14h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v34; // [esp+20h] [ebp-80h] BYREF
  vostok::math::float4x4 v35; // [esp+60h] [ebp-40h] BYREF

  m_reconstruction_info_actuality_tick = (char *)this->m_reconstruction_info_actuality_tick;
  if ( m_reconstruction_info_actuality_tick == this[-1].m_pickup_hint.m_max_end )
  {
    if ( m_reconstruction_info_actuality_tick == (char *)1 )
    {
      m_object = survarium::game_world::get_project(
                   *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
                   &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v5 = (int)m_object->artefact_container(m_object, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v5 + 40))(v5, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      survarium::artefact_base::spawn_progress(
        v6,
        (int)&this[-1].vostok::uid_object<vostok::resources::resource_children>);
      scale.x = a2;
      scale.y = a2;
      scale.z = a2;
      vostok::math::float4x4::set_scale(&v34, &scale);
      vostok::render::scene_renderer::update_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        &v34,
        &v34);
    }
  }
  else
  {
    if ( m_reconstruction_info_actuality_tick == (char *)2 )
    {
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4));
      v7 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)*((_DWORD *)&this->vostok::resources::resource_flags + 3);
      v8 = *(vostok::render::scene_renderer **)((char *)&dword_200060 + v7[40].m_object->m_fat_it.m_type);
      vostok::render::scene_renderer::remove_particle_system_instance(
        v8,
        (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v8,
        v7 + 1,
        (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_size);
    }
    else if ( m_reconstruction_info_actuality_tick == (char *)1 )
    {
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4));
    }
    m_max_end = this[-1].m_pickup_hint.m_max_end;
    if ( m_max_end == (char *)1 )
    {
      v10 = survarium::game_world::get_project(
              *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
              &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v11 = (int)v10->artefact_container(v10, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v11 + 40))(v11, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      qmemcpy(&v35, &v34, sizeof(v35));
      scale.x = epsilon_3_4;
      scale.y = epsilon_3_4;
      scale.z = epsilon_3_4;
      vostok::math::float4x4::set_scale(&v35, &scale);
      vostok::render::scene_renderer::add_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264),
        *(vostok::render::scene_renderer **)((char *)&dword_200060
                                           + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags
                                                                     + 3)
                                                                   + 160)
                                                       + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        &v35,
        &v35);
      v32.m_object = 0;
      v31.m_object = 0;
      v28 = &v32;
      v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31;
      v26 = &v34;
      v25 = &v34;
      v24.m_object = v12;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v24,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_size);
      vostok::render::scene_renderer::play_particle_system(
        (vostok::render::scene_renderer *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 160) + 172)),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 4),
        (const vostok::math::float4x4 *)v24.m_object,
        v25,
        v26,
        v27,
        v28);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v31);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v32);
      (*(void (__thiscall **)(_DWORD, unsigned int *, vostok::math::float4_pod *))(**((_DWORD **)&this->vostok::resources::resource_flags
                                                                                    + 3)
                                                                                 + 20))(
        *((_DWORD *)&this->vostok::resources::resource_flags + 3),
        &this->m_reconstruction_size + 1,
        &v34.c);
    }
    else if ( m_max_end == (char *)2 )
    {
      v13 = survarium::game_world::get_project(
              *((survarium::game_world **)&this->vostok::resources::resource_flags + 3),
              &v31)->m_object;
      LOBYTE(v32.m_object) = this[-1].m_pickup_hint.m_buffer[0];
      v14 = (int)v13->artefact_container(v13, (unsigned __int8)v32.m_object);
      (*(void (__thiscall **)(int, vostok::math::float4x4 *))(*(_DWORD *)v14 + 40))(v14, &v34);
      vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v31);
      v15 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(HIDWORD(this->m_reconstruction_info_actuality_tick) + 264);
      v16 = BYTE1(v15->m_object->m_lods[0].m_emitter_instance_list.m_size) == 0;
      v17 = *((_DWORD *)&this->vostok::resources::resource_flags + 3);
      v28 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34;
      v27 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v34;
      v18 = (vostok::math::float4x4 *)(v17 + 4);
      v19 = *(_DWORD *)(*(_DWORD *)(v17 + 160) + 172);
      v26 = v18;
      v25 = *(vostok::math::float4x4 **)((char *)&dword_200060 + v19);
      if ( v16 )
        vostok::render::scene_renderer::add_model(
          v15,
          (vostok::render::scene_renderer *)v25,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v26,
          (const vostok::math::float4x4 *)v27,
          (const vostok::math::float4x4 *)v28);
      else
        vostok::render::scene_renderer::update_model(
          v15,
          (vostok::render::scene_renderer *)v25,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v26,
          (const vostok::math::float4x4 *)v27,
          (const vostok::math::float4x4 *)v28);
    }
    else if ( m_max_end == (char *)4 )
    {
      v20 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)&this[-1].m_container_id + 376) + 12))(*(_DWORD *)(*(_DWORD *)&this[-1].m_container_id + 376));
      if ( survarium::base_network_client::is_player_current(
             v21,
             *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&this->vostok::resources::resource_flags + 3) + 160) + 13912),
             *(_BYTE *)(v20 + 304)) )
      {
        survarium::game_world_ui::show_parametrized_message(
          v23,
          (const char *)(v22 + 516),
          *(char **)&this[-1].m_activation_hint.m_buffer[20],
          v29,
          v30);
      }
    }
    LODWORD(this->m_reconstruction_info_actuality_tick) = this[-1].m_pickup_hint.m_max_end;
  }
}
