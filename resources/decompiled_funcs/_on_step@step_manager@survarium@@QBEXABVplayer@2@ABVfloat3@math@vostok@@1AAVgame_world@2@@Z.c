void __userpurge survarium::step_manager::on_step(
        const vostok::math::float3 *position@<eax>,
        survarium::game_world *world@<ecx>,
        int a3@<ebx>,
        int a4@<edi>,
        int a5@<esi>,
        survarium::step_manager *this,
        const survarium::player *a,
        const vostok::math::float3 *direction)
{
  vostok::physics::world *m_physics_world; // ecx
  float z; // xmm0_4
  survarium::player *m_object; // eax
  unsigned __int8 v12; // bl
  unsigned __int16 v13; // ax
  survarium::material_pair *pair; // edi
  vostok::sound::sound_emitter *v15; // ebx
  vostok::sound::world_user *v16; // eax
  unsigned int v17; // eax
  void (__thiscall *play_particle)(survarium::bullet_manager_engine *, const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *, const vostok::math::float3 *, const vostok::math::float3 *, const vostok::math::float3 *); // edx
  const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v19; // eax
  vostok::configs::binary_config *v21; // [esp+40h] [ebp-50h]
  bool v22; // [esp+40h] [ebp-50h]
  int v23; // [esp+50h] [ebp-40h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v24; // [esp+54h] [ebp-3Ch] BYREF
  survarium::input_mode_type_enum m_input_mode; // [esp+58h] [ebp-38h]
  float x; // [esp+5Ch] [ebp-34h] BYREF
  float v27; // [esp+60h] [ebp-30h]
  float v28; // [esp+64h] [ebp-2Ch]
  vostok::physics::closest_ray_result ray_result; // [esp+68h] [ebp-28h] BYREF
  int vars0; // [esp+90h] [ebp+0h]
  void *retaddr; // [esp+94h] [ebp+4h]

  v23 = 0;
  m_input_mode = first_person_mode;
  m_physics_world = world->m_physics_world;
  x = position->x;
  v27 = position->y + *(float *)&clear_value;
  z = position->z;
  v24.m_object = (vostok::configs::binary_config *)-1082130432;
  v28 = z;
  ((void (__thiscall *)(vostok::physics::world *, vostok::physics::closest_ray_result *, float *, int *, _DWORD, int, int, int, int, int))m_physics_world->ray_test)(
    m_physics_world,
    &ray_result,
    &x,
    &v23,
    2.0,
    48,
    8,
    a4,
    a5,
    a3);
  if ( LODWORD(ray_result.hit_point_world.z) )
  {
    m_object = world->m_game->m_network_client->m_current_player.m_object;
    if ( m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
      && m_object->id == a->id )
    {
      m_input_mode = world->m_input_mode;
    }
    else
    {
      m_input_mode = third_person_mode;
    }
    if ( m_input_mode )
      v12 = byte_10F30[(_DWORD)a];
    else
      v12 = byte_10F31[(_DWORD)a];
    v13 = (*(int (__stdcall **)(int, void *))(*(_DWORD *)LODWORD(ray_result.hit_point_world.z) + 16))(vars0, retaddr);
    pair = (survarium::material_pair *)survarium::game_material_manager::get_pair(
                                         world->m_game_material_manager.m_object,
                                         v12,
                                         v13);
    v21 = (vostok::configs::binary_config *)pair->m_sound_emitter.m_object;
    v24.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v24,
      v21);
    v15 = (vostok::sound::sound_emitter *)v24.m_object;
    if ( v24.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v22 = m_input_mode == first_person_mode;
      v16 = world->m_game->m_sound_world->get_logic_world_user(world->m_game->m_sound_world);
      vostok::sound::sound_emitter::emit_and_play_once(
        v15,
        &world->m_sound_scene,
        v16,
        &ray_result.hit_normal_world,
        0,
        0,
        v22);
    }
    if ( pair->m_decal1.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v17 = this->m_decal_id++;
        ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))world->add_decal)(
          &world->survarium::bullet_manager_engine,
          &pair->m_decal1,
          v17,
          pair->m_decal1_size,
          0.1,
          &ray_result.hit_normal_world,
          direction,
          &ray_result.triangle_index,
          1);
        v15 = (vostok::sound::sound_emitter *)v24.m_object;
        if ( this->m_decal_id == 32 )
          this->m_decal_id = 0;
      }
    }
    if ( pair->m_particles._M_impl._M_start != pair->m_particles._M_impl._M_finish )
    {
      survarium::material_pair::particle(pair);
      play_particle = world->play_particle;
      ray_result.object = 0;
      *(_QWORD *)&ray_result.hit_point_world.x = (unsigned int)clear_value;
      x = *(float *)&clear_value;
      v27 = 0.0;
      v28 = 0.0;
      play_particle(
        &world->survarium::bullet_manager_engine,
        v19,
        &ray_result.hit_normal_world,
        (const vostok::math::float3 *)&x,
        (const vostok::math::float3 *)&ray_result);
    }
    if ( v15 )
    {
      if ( !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v15->vostok::resources::unmanaged_intrusive_base, v15);
    }
  }
}
