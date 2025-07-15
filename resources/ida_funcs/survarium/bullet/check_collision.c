// local variable allocation has failed, the output may be wrong!
survarium::collision_result __thiscall survarium::bullet::check_collision(
        survarium::bullet *this,
        __int128 start_position,
        float current_time)
{
  survarium::game_camera *v3; // ecx
  vostok::math::float3_pod *v4; // ecx
  vostok::math::float3 *v6; // eax
  vostok::math::float3_pod *v7; // ecx
  long double v8; // st7
  vostok::math::float3_pod *v9; // ecx
  vostok::math::float3 *v10; // eax
  vostok::math::float3 *v11; // eax
  bool v12; // [esp+2Fh] [ebp-BDh]
  vostok::math::float3 v14; // [esp+44h] [ebp-A8h] BYREF
  vostok::math::float3 v15; // [esp+50h] [ebp-9Ch] BYREF
  vostok::math::float3 v16; // [esp+5Ch] [ebp-90h] BYREF
  float value; // [esp+68h] [ebp-84h] BYREF
  vostok::math::float3 v18; // [esp+6Ch] [ebp-80h] BYREF
  char v19; // [esp+7Ah] [ebp-72h]
  bool ignorable_object_was_hit; // [esp+7Bh] [ebp-71h]
  vostok::math::float3 triangle_normal; // [esp+7Ch] [ebp-70h] BYREF
  vostok::physics::closest_ray_result ray_result; // [esp+88h] [ebp-64h] BYREF
  float cos_alpha; // [esp+B0h] [ebp-3Ch]
  survarium::triangle_orientation orientation; // [esp+B4h] [ebp-38h]
  const vostok::math::float3 *target_position; // [esp+B8h] [ebp-34h]
  survarium::collision_result result; // [esp+BCh] [ebp-30h]
  vostok::physics::world *p_world; // [esp+C0h] [ebp-2Ch]
  float distance; // [esp+C4h] [ebp-28h] BYREF
  vostok::math::float3 new_start_position; // [esp+C8h] [ebp-24h] BYREF
  vostok::math::float3 v30; // [esp+D4h] [ebp-18h] BYREF
  vostok::math::float3 direction; // [esp+E0h] [ebp-Ch] BYREF

  result = collision_result_no_collision;
  survarium::bullet::compute_trajectory_position(this, &v30, current_time, &this->m_bullet_manager->m_gravity);
  target_position = &v30;
  v19 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::math::operator-((const vostok::math::float3_pod *)&start_position, &v30, &direction);
  distance = vostok::math::float3_pod::length(v4, &direction.x);
  if ( vostok::math::is_zero<float>(&distance, &epsilon_5_84) )
    return result;
  vostok::math::float3_pod::operator*=(&direction.x, *(float *)&clear_value / distance);
  p_world = this->m_bullet_manager->m_physics_world;
  for ( new_start_position = (vostok::math::float3)start_position;
        ;
        new_start_position = *vostok::math::operator+(v11, &ray_result.hit_point_world, &v14) )
  {
    ((void (__thiscall *)(vostok::physics::world *, vostok::physics::closest_ray_result *, vostok::math::float3 *, vostok::math::float3 *, _DWORD, int, int))p_world->ray_test)(
      p_world,
      &ray_result,
      &new_start_position,
      &direction,
      LODWORD(distance),
      16,
      8);
    if ( !ray_result.object )
      return result;
    triangle_normal = ray_result.hit_normal_world;
    cos_alpha = vostok::math::operator|(&triangle_normal, &direction);
    orientation = cos_alpha >= 0.0;
    v12 = this->m_ignorable_object
       && ray_result.object->user_data
       && ray_result.object->user_data->cast_to_hit_receiver(ray_result.object->user_data) == this->m_ignorable_object;
    ignorable_object_was_hit = v12;
    if ( !v12 && orientation != triangle_orientation_back_face )
      break;
    v6 = vostok::math::operator-(&new_start_position, &ray_result.hit_point_world, &v18);
    v8 = vostok::math::float3_pod::length(v7, &v6->x);
    distance = distance - v8;
    value = vostok::math::float3_pod::length(v9, &new_start_position.x);
    v10 = vostok::math::operator*(&direction, &v16, (float *)&epsilon_5_84);
    v11 = vostok::math::operator*(v10, &v15, &value);
  }
  return survarium::bullet::process_ray_query(
           this,
           &ray_result,
           distance,
           (vostok::math::float3 *)&start_position,
           &direction,
           (float *)&start_position + 3,
           &current_time);
}
