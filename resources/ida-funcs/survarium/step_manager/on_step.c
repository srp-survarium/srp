void __thiscall survarium::step_manager::on_step(
        survarium::step_manager *this,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        int foot_material,
        unsigned __int16 third_person_view,
        char a6)
{
  int v6; // ecx
  float z; // xmm0_4
  unsigned __int16 v8; // si
  int v9; // eax
  survarium::game_material_manager *v10; // ecx
  const survarium::material_pair *pair; // eax
  vostok::particle::particle_system_instance_impl *m_object; // edi
  survarium::material_pair *v13; // ecx
  float y; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v15; // esi
  vostok::sound::sound_instance_proxy *v16; // eax
  const survarium::material_pair *v17; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_collision_decal; // edi
  float v19; // eax
  int v20; // edi
  const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v21; // eax
  float v22; // [esp+38h] [ebp-6Ch]
  const vostok::sound::sound_receiver *v23; // [esp+4Ch] [ebp-58h]
  bool v24; // [esp+50h] [ebp-54h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v25; // [esp+5Ch] [ebp-48h] BYREF
  const survarium::material_pair *v26; // [esp+60h] [ebp-44h]
  float v27; // [esp+64h] [ebp-40h] BYREF
  float v28; // [esp+68h] [ebp-3Ch]
  int v29; // [esp+6Ch] [ebp-38h]
  float x; // [esp+70h] [ebp-34h] BYREF
  float v31; // [esp+74h] [ebp-30h]
  float v32; // [esp+78h] [ebp-2Ch]
  int v33; // [esp+7Ch] [ebp-28h] BYREF
  vostok::math::float3 v34; // [esp+80h] [ebp-24h] BYREF
  char v35[12]; // [esp+8Ch] [ebp-18h] BYREF
  int v36; // [esp+98h] [ebp-Ch]
  int v37; // [esp+9Ch] [ebp-8h]

  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v25,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(LODWORD(position->y) + 13604));
  v6 = *(_DWORD *)&v25.m_object->m_lods[1].m_emitter_instance_list.gap4;
  v27 = 0.0;
  v29 = 0;
  x = direction->x;
  v31 = direction->y + s_bm_current_air_resistance;
  z = direction->z;
  v28 = FLOAT_N1_0;
  v32 = z;
  (*(void (__thiscall **)(int, int *, float *, float *, _DWORD, int, int, _DWORD, int))(*(_DWORD *)v6 + 64))(
    v6,
    &v33,
    &x,
    &v27,
    2.0,
    48,
    8,
    0,
    1);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v25);
  if ( v33 )
  {
    v8 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v33 + 16))(v33, v36, v37);
    v9 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(position->y) + 28))(LODWORD(position->y));
    pair = survarium::game_material_manager::get_pair(v10, v9, third_person_view, v8);
    m_object = (vostok::particle::particle_system_instance_impl *)pair->m_collision_sound.m_object;
    v26 = pair;
    vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
      &v25,
      m_object);
    if ( v25.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      y = position->y;
      v15 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(y) + 148);
      v16 = (vostok::sound::sound_instance_proxy *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(LODWORD(y) + 160)
                                                                                               + 156)
                                                                                 + 8))(*(_DWORD *)(*(_DWORD *)(LODWORD(y) + 160)
                                                                                                 + 156));
      vostok::sound::sound_emitter::emit_and_play_once(
        (vostok::sound::sound_emitter *)v25.m_object,
        v15,
        v16,
        &v34,
        (const vostok::sound::sound_producer *)(a6 == 0),
        v23,
        v24);
    }
    v17 = v26;
    p_m_collision_decal = &v26->m_collision_decal;
    if ( v26->m_collision_decal.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v22 = survarium::material_pair::collision_decal_size(v13, (int)v26);
      (*(void (__thiscall **)(_DWORD, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *, int, _DWORD, _DWORD, _DWORD, vostok::math::float3 *, int, char *))(*(_DWORD *)LODWORD(position->y) + 24))(
        LODWORD(position->y),
        p_m_collision_decal,
        LODWORD(position->x) + 11000,
        LODWORD(v22),
        LODWORD(v22),
        0.1,
        &v34,
        foot_material,
        v35);
      LODWORD(position->x) = ((unsigned __int8)LODWORD(position->x) + 1) & 0x1F;
    }
    if ( v17->m_collision_particles._M_impl._M_start != v17->m_collision_particles._M_impl._M_finish )
    {
      v19 = position->y;
      x = 0.0;
      v31 = s_bm_current_air_resistance;
      v32 = 0.0;
      v27 = s_bm_current_air_resistance;
      v28 = 0.0;
      v29 = 0;
      v20 = *(_DWORD *)(LODWORD(v19) + 240);
      v21 = survarium::material_pair::collision_particle(v13, v17);
      (*(void (__thiscall **)(int, const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *, vostok::math::float3 *, float *, float *, _DWORD))(v20 + 12))(
        LODWORD(position->y) + 240,
        v21,
        &v34,
        &v27,
        &x,
        0);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v25);
  }
}
