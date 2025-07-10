char __thiscall survarium::booby_trap_set_core::get_visible_place_transform(
        survarium::booby_trap_set_core *this,
        vostok::math::float4x4 *result)
{
  survarium::inventory *inventory; // eax
  survarium::inventory *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::inventory_item *v5; // ecx
  survarium::inventory *v6; // eax
  survarium::inventory *v7; // ecx
  survarium::game_camera *v8; // ecx
  vostok::math::float3 *v9; // eax
  vostok::math::float3 *v10; // eax
  survarium::game_camera *v11; // ecx
  const vostok::math::float3 *v12; // eax
  vostok::math::float3 *v13; // eax
  vostok::math::float3 *v14; // eax
  survarium::booby_trap_set_core *v16; // ecx
  const survarium::booby_trap_set_core::config_params *v17; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v18; // ecx
  survarium::game_material_manager *v19; // eax
  survarium::booby_trap_set_core *v20; // ecx
  survarium::booby_trap_set_core *v21; // ecx
  vostok::math::float3 *v22; // eax
  vostok::math::float3 *v23; // eax
  const vostok::math::float4x4 *v24; // eax
  vostok::math::float3_pod *v25; // ecx
  const vostok::math::float4x4 *v26; // eax
  survarium::game_camera *v27; // ecx
  survarium::booby_trap_set_core *v28; // ecx
  survarium::game_camera *v29; // ecx
  survarium::game_camera *v30; // ecx
  const vostok::variant<32> **v31; // eax
  const vostok::math::float3 *v32; // [esp+1Ch] [ebp-37Ch]
  int v33; // [esp+1Ch] [ebp-37Ch]
  unsigned __int16 length; // [esp+20h] [ebp-378h]
  int lengtha; // [esp+20h] [ebp-378h]
  survarium::inventory_holder *v36; // [esp+2Ch] [ebp-36Ch]
  survarium::inventory_holder *v37; // [esp+30h] [ebp-368h]
  vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **v39; // [esp+48h] [ebp-350h]
  vostok::math::float4x4 v40; // [esp+164h] [ebp-234h] BYREF
  vostok::math::float4x4 v41; // [esp+1A4h] [ebp-1F4h] BYREF
  vostok::math::float3 v42; // [esp+1E4h] [ebp-1B4h] BYREF
  vostok::math::float3 v43; // [esp+1F0h] [ebp-1A8h] BYREF
  vostok::math::float3 v44; // [esp+1FCh] [ebp-19Ch] BYREF
  vostok::math::float3 v45; // [esp+240h] [ebp-158h] BYREF
  vostok::math::float3 v46; // [esp+24Ch] [ebp-14Ch] BYREF
  char v47; // [esp+25Ah] [ebp-13Eh]
  char v48; // [esp+25Bh] [ebp-13Dh]
  vostok::math::float3 dir_to_head; // [esp+25Ch] [ebp-13Ch] BYREF
  vostok::math::float3 ray_dir; // [esp+268h] [ebp-130h] BYREF
  const survarium::game_material *material; // [esp+274h] [ebp-124h]
  vostok::math::float4x4 matrix_b; // [esp+278h] [ebp-120h] BYREF
  vostok::physics::bt_ghost_object *ghost; // [esp+2B8h] [ebp-E0h]
  float slope_cos; // [esp+2BCh] [ebp-DCh]
  vostok::physics::bt_rigid_body_base *body; // [esp+2C0h] [ebp-D8h]
  vostok::physics::closest_ray_result ray_result; // [esp+2C4h] [ebp-D4h] BYREF
  vostok::math::float3 ray_from; // [esp+2ECh] [ebp-ACh] BYREF
  vostok::math::float4x4 looking_point_matrix; // [esp+2F8h] [ebp-A0h] BYREF
  vostok::math::float4x4 matrix_a; // [esp+338h] [ebp-60h] BYREF
  vostok::physics::world *world; // [esp+378h] [ebp-20h]
  float ray_length; // [esp+37Ch] [ebp-1Ch] BYREF
  unsigned __int16 group; // [esp+380h] [ebp-18h]
  unsigned __int16 mask; // [esp+384h] [ebp-14h]
  const vostok::math::float4x4 *head_transform; // [esp+388h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> arbitrary_trap; // [esp+38Ch] [ebp-Ch] BYREF
  survarium::base_player *player; // [esp+390h] [ebp-8h]
  unsigned __int16 game_material_id; // [esp+394h] [ebp-4h]

  inventory = survarium::inventory_item::get_inventory(this, (int)this);
  v37 = survarium::inventory::holder(v3, (int)inventory);
  world = v37->get_physics_world(v37);
  v48 = 0;
  survarium::weapon_user_dead_state::finalize(v4);
  v6 = survarium::inventory_item::get_inventory(v5, (int)this);
  v36 = survarium::inventory::holder(v7, (int)v6);
  player = v36->cast_to_base_player(v36);
  v47 = 0;
  survarium::weapon_user_dead_state::finalize(v8);
  head_transform = &player->m_character_head_transform;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&player->m_character_head_transform);
  ray_from = *v9;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)LODWORD(ray_from.y));
  ray_dir = *v10;
  ray_length = survarium::booby_trap_set_core::config((survarium::booby_trap_set_core *)LODWORD(ray_dir.x), (int)this)->max_distance;
  group = 1028;
  mask = 514;
  ((void (__thiscall *)(vostok::physics::world *, vostok::physics::closest_ray_result *, vostok::math::float3 *, vostok::math::float3 *, _DWORD, int, int))world->ray_test)(
    world,
    &ray_result,
    &ray_from,
    &ray_dir,
    LODWORD(ray_length),
    1028,
    514);
  if ( ray_result.object )
  {
    survarium::create_place_matrix_for_looking_point(
      &looking_point_matrix,
      &ray_result.hit_point_world,
      &ray_result.hit_normal_world);
    slope_cos = ray_result.hit_normal_world.y;
    v17 = survarium::booby_trap_set_core::config(v16, (int)this);
    if ( v17->max_slope_cos > slope_cos
      || (((int (__thiscall *)(vostok::physics::base_physics_object *))ray_result.object->get_collision_group)(ray_result.object)
        & 0x200) != 0
      || (body = (vostok::physics::bt_rigid_body_base *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                                          v18,
                                                          (int)&ray_result),
          length = ray_result.is_shape_index,
          game_material_id = ((int (__thiscall *)(vostok::physics::bt_rigid_body_base *, int))body->get_triangle_material)(
                               body,
                               ray_result.triangle_index),
          v19 = (survarium::game_material_manager *)((int (__thiscall *)(survarium::booby_trap_set_core *, _DWORD))this->get_game_material_manager)(
                                                      this,
                                                      game_material_id),
          material = survarium::game_material_manager::get_material(v19, length),
          survarium::booby_trap_set_core::config(v20, (int)this)->material_can_place_test)
      && (v21 = (survarium::booby_trap_set_core *)material, !material->m_mine_can_place)
      || survarium::booby_trap_set_core::config(v21, (int)this)->material_can_stick_test && !material->m_mine_can_stick )
    {
      qmemcpy((void *)result, &looking_point_matrix, sizeof(vostok::math::float4x4));
      return 0;
    }
    else
    {
      v44.x = 0.0049999999;
      v22 = vostok::math::float3_pod::operator-(&ray_dir, &v43);
      v23 = vostok::math::operator*(v22, &v42, &v44.x);
      v24 = vostok::math::create_translation(&v41, v23);
      vostok::math::operator*(&matrix_a, &looking_point_matrix, v24);
      vostok::math::float3_pod::operator-(&ray_dir, &dir_to_head);
      vostok::math::float3_pod::set_length(v25, &dir_to_head.x, 0.5);
      v26 = vostok::math::create_translation(&v40, &dir_to_head);
      vostok::math::operator*(&matrix_b, &looking_point_matrix, v26);
      survarium::weapon_user_dead_state::finalize(v27);
      v39 = (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)survarium::booby_trap_set_core::traps(v28, (int)this);
      survarium::weapon_user_dead_state::finalize(v29);
      vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
        *v39,
        (survarium::inventory **)&arbitrary_trap);
      survarium::weapon_user_dead_state::finalize(v30);
      ghost = survarium::collision_sensor::get_collision_geometry(
                &arbitrary_trap.m_object->survarium::collision_sensor,
                0)->m_ghost_object;
      lengtha = mask;
      v33 = group;
      v31 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)group,
              (int)&ghost->m_shape);
      if ( world->recover_from_penetrations(
             world,
             (vostok::physics::bt_collision_shape *const)v31,
             &matrix_a,
             result,
             v33,
             lengtha) )
      {
        vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&arbitrary_trap);
        return 1;
      }
      else
      {
        qmemcpy((void *)result, &looking_point_matrix, sizeof(vostok::math::float4x4));
        vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&arbitrary_trap);
        return 0;
      }
    }
  }
  else
  {
    survarium::weapon_user_dead_state::finalize(v11);
    v32 = v12;
    v13 = vostok::math::operator*(&ray_dir, &v46, &ray_length);
    v14 = vostok::math::operator+(v13, &ray_from, &v45);
    qmemcpy(
      (void *)result,
      survarium::create_place_matrix_for_looking_point((vostok::math::float4x4 *)&v44.elements[1], v14, v32),
      sizeof(vostok::math::float4x4));
    return 0;
  }
}
