void __userpurge survarium::bullet::bullet(
        survarium::bullet *this@<ecx>,
        survarium::bullet *bullet_manager,
        unsigned int current_time_in_ms,
        const vostok::math::float3 *air_resistance,
        const survarium::weapon_ammunition *gravity,
        vostok::network_core::buffer_reader *reader,
        const unsigned int time_offset)
{
  const survarium::weapon_ammunition *v7; // ebx
  const survarium::weapon_ammunition **type; // esi
  vostok::math::float3 *v9; // ecx
  vostok::math::float3 *v10; // ecx
  const survarium::weapon_ammunition **v11; // esi
  vostok::math::float3 *v12; // xmm0_4
  const survarium::weapon_ammunition **v13; // esi
  vostok::math::float3 *v14; // xmm0_4
  const survarium::weapon_ammunition **v15; // esi
  const survarium::weapon_ammunition *v16; // edx
  const survarium::weapon_ammunition **v17; // esi
  vostok::math::float3 *v18; // xmm0_4
  const survarium::weapon_ammunition **v19; // esi
  const survarium::weapon_ammunition **v20; // esi
  const survarium::weapon_ammunition **v21; // esi
  _BYTE *v22; // esi
  _BYTE *v23; // esi
  _BYTE *v24; // esi
  _BYTE *v25; // esi
  const survarium::weapon_ammunition **v26; // esi
  vostok::math::float3 *v27; // xmm0_4
  _BYTE *v28; // esi
  _BYTE *v29; // esi
  survarium::base_player *v30; // eax
  const survarium::hit_initiator *v31; // eax
  _BYTE *v32; // esi
  survarium::base_player *v33; // eax
  survarium::hit_receiver *v34; // eax
  survarium::bullet *v35; // ecx
  _BYTE *v36; // esi
  survarium::inventory_item *m_object; // eax
  const survarium::weapon_core *p_m_inventory; // eax
  _BYTE *v39; // esi
  bool v40; // zf
  _BYTE *v41; // eax
  const survarium::game_material *material; // eax
  _BYTE *v43; // esi
  unsigned __int8 v44; // al
  const survarium::weapon_ammunition *m_weapon_ammunition; // eax
  const survarium::game_material *v46; // eax
  survarium::bullet *v48; // ecx
  survarium::bullet *v49; // ecx
  const survarium::weapon_ammunition *time; // [esp+8h] [ebp-20h]
  const survarium::weapon_ammunition *timea; // [esp+8h] [ebp-20h]
  vostok::math::float3 v52; // [esp+1Ch] [ebp-Ch] BYREF
  float m_life_time; // [esp+30h] [ebp+8h]
  survarium::base_player *v54; // [esp+34h] [ebp+Ch]

  bullet_manager->m_id = -1;
  bullet_manager->m_collided_material = 0;
  bullet_manager->m_bullet_manager = (survarium::bullet_manager *)this;
  bullet_manager->m_current_time_in_ms = current_time_in_ms;
  v7 = gravity;
  bullet_manager->m_tracer_idx = -1;
  type = (const survarium::weapon_ammunition **)v7->type;
  gravity = *type;
  v7->type = (unsigned int)(type + 1);
  bullet_manager->m_id = (unsigned int)gravity;
  v9 = (vostok::math::float3 *)v7->type;
  v52 = *v9;
  v7->type = (unsigned int)&v9[1];
  bullet_manager->m_start_position = v52;
  v10 = (vostok::math::float3 *)v7->type;
  v52 = *v10;
  v7->type = (unsigned int)&v10[1];
  bullet_manager->m_start_velocity = v52;
  v11 = (const survarium::weapon_ammunition **)v7->type;
  gravity = *v11;
  v12 = (vostok::math::float3 *)gravity;
  v7->type = (unsigned int)(v11 + 1);
  LODWORD(bullet_manager->m_max_damage_speed) = v12;
  v13 = (const survarium::weapon_ammunition **)v7->type;
  gravity = *v13;
  v14 = (vostok::math::float3 *)gravity;
  v7->type = (unsigned int)(v13 + 1);
  LODWORD(bullet_manager->m_min_damage_speed) = v14;
  v15 = (const survarium::weapon_ammunition **)v7->type;
  gravity = *v15;
  v16 = gravity;
  v7->type = (unsigned int)(v15 + 1);
  bullet_manager->m_born_time_in_ms = (unsigned int)v16 + (_DWORD)reader;
  v17 = (const survarium::weapon_ammunition **)v7->type;
  gravity = *v17;
  v18 = (vostok::math::float3 *)gravity;
  v7->type = (unsigned int)(v17 + 1);
  LODWORD(bullet_manager->m_life_time) = v18;
  v19 = (const survarium::weapon_ammunition **)v7->type;
  gravity = *v19;
  v7->type = (unsigned int)(v19 + 1);
  LODWORD(bullet_manager->m_flown_distance) = gravity;
  v20 = (const survarium::weapon_ammunition **)v7->type;
  gravity = *v20;
  v7->type = (unsigned int)(v20 + 1);
  LODWORD(bullet_manager->m_damage) = gravity;
  v21 = (const survarium::weapon_ammunition **)v7->type;
  gravity = *v21;
  v7->type = (unsigned int)(v21 + 1);
  LODWORD(bullet_manager->m_pierce) = gravity;
  v22 = (_BYTE *)v7->type;
  HIBYTE(gravity) = *v22;
  v7->type = (unsigned int)(v22 + 1);
  bullet_manager->m_ricochet_count = HIBYTE(gravity);
  v23 = (_BYTE *)v7->type;
  HIBYTE(gravity) = *v23;
  v7->type = (unsigned int)(v23 + 1);
  bullet_manager->m_change_trajectory_count = HIBYTE(gravity);
  v24 = (_BYTE *)v7->type;
  HIBYTE(gravity) = *v24;
  v7->type = (unsigned int)(v24 + 1);
  bullet_manager->m_last_hitted_player = HIBYTE(gravity);
  v25 = (_BYTE *)v7->type;
  HIBYTE(gravity) = *v25;
  v7->type = (unsigned int)(v25 + 1);
  bullet_manager->m_last_hitted_body_part = HIBYTE(gravity);
  v26 = (const survarium::weapon_ammunition **)v7->type;
  gravity = *v26;
  v27 = (vostok::math::float3 *)gravity;
  v7->type = (unsigned int)(v26 + 1);
  LODWORD(bullet_manager->m_max_damage_dealt) = v27;
  v28 = (_BYTE *)v7->type;
  HIBYTE(gravity) = *v28;
  v7->type = (unsigned int)(v28 + 1);
  bullet_manager->m_initiator_stance = SHIBYTE(gravity);
  v29 = (_BYTE *)v7->type;
  LOBYTE(gravity) = *v29;
  time = gravity;
  v7->type = (unsigned int)(v29 + 1);
  v30 = bullet_manager->m_bullet_manager->m_engine->get_player(bullet_manager->m_bullet_manager->m_engine, time);
  v54 = v30;
  if ( v30 )
    v31 = &v30->survarium::hit_initiator;
  else
    v31 = 0;
  bullet_manager->m_initiator = v31;
  v32 = (_BYTE *)v7->type;
  LOBYTE(gravity) = *v32;
  timea = gravity;
  v7->type = (unsigned int)(v32 + 1);
  v33 = bullet_manager->m_bullet_manager->m_engine->get_player(bullet_manager->m_bullet_manager->m_engine, timea);
  if ( v33 )
    v34 = &v33->survarium::hit_receiver;
  else
    v34 = 0;
  v35 = bullet_manager;
  bullet_manager->m_ignorable_object = v34;
  v36 = (_BYTE *)v7->type;
  HIBYTE(gravity) = *v36;
  v7->type = (unsigned int)(v36 + 1);
  m_object = v54->m_inventory.m_object->m_slots.elems[HIBYTE(gravity)].m_object;
  if ( m_object )
    p_m_inventory = (const survarium::weapon_core *)&m_object[-1].m_inventory;
  else
    p_m_inventory = 0;
  bullet_manager->m_weapon = p_m_inventory;
  v39 = (_BYTE *)v7->type;
  HIBYTE(gravity) = *v39;
  v40 = HIBYTE(gravity) == 0xFF;
  v7->type = (unsigned int)(v39 + 1);
  bullet_manager->m_is_melee = v40;
  if ( v40 )
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&gravity,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&bullet_manager->m_weapon->m_melee_ammunition);
    bullet_manager->m_weapon_ammunition = gravity;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&gravity);
    v35 = bullet_manager;
  }
  else
  {
    bullet_manager->m_weapon_ammunition = (const survarium::weapon_ammunition *)v54->m_inventory.m_object->m_slots.elems[HIBYTE(gravity)].m_object;
  }
  v41 = (_BYTE *)v7->type;
  HIBYTE(gravity) = *v41;
  v40 = HIBYTE(gravity) == 0;
  v7->type = (unsigned int)(v41 + 1);
  if ( v40 )
  {
    material = 0;
  }
  else
  {
    material = survarium::game_material_manager::get_material(
                 (survarium::game_material_manager *)v35,
                 (int)v35->m_bullet_manager->m_game_material_manager,
                 HIBYTE(gravity));
    v35 = bullet_manager;
  }
  v35->m_collided_material = material;
  if ( v35->m_weapon_ammunition->m_buck_shot <= 1u )
  {
    v44 = 0;
  }
  else
  {
    v43 = (_BYTE *)v7->type;
    HIBYTE(gravity) = *v43;
    v7->type = (unsigned int)(v43 + 1);
    v44 = HIBYTE(gravity);
  }
  v35->m_buck_shot = v44;
  m_weapon_ammunition = v35->m_weapon_ammunition;
  v35->m_air_resistance = m_weapon_ammunition->m_air_resistance;
  v46 = survarium::game_material_manager::get_material(
          (survarium::game_material_manager *)v35,
          (int)v35->m_bullet_manager->m_game_material_manager,
          m_weapon_ammunition->m_game_material_id);
  m_life_time = bullet_manager->m_life_time;
  bullet_manager->m_bullet_material = v46;
  bullet_manager->m_position = *survarium::bullet::compute_trajectory_position(
                                  bullet_manager,
                                  v48,
                                  &v52,
                                  *(float *)&v27,
                                  m_life_time);
  bullet_manager->m_velocity = *survarium::bullet::compute_trajectory_velocity(
                                  bullet_manager,
                                  v49,
                                  &v52,
                                  *(float *)&v27,
                                  m_life_time);
}
