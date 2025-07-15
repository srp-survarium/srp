int __thiscall survarium::bullet::process_ray_query(
        survarium::bullet *this,
        const vostok::physics::closest_ray_result *ray_result,
        float distance,
        vostok::math::float3 *start_position,
        vostok::math::float3 *fly_direction,
        float *start_time,
        float *current_time)
{
  vostok::math::float3 *v7; // eax
  vostok::math::float3_pod *v8; // ecx
  vostok::math::float3 *v9; // eax
  float v10; // xmm0_4
  survarium::game_camera *v12; // ecx
  __int128 v13; // [esp-8h] [ebp-B4h]
  vostok::math::float3 result; // [esp+4Ch] [ebp-60h] BYREF
  char v16; // [esp+5Bh] [ebp-51h]
  vostok::math::float3 v17; // [esp+5Ch] [ebp-50h] BYREF
  vostok::math::float3 v18; // [esp+68h] [ebp-44h] BYREF
  vostok::math::float3 collide_point; // [esp+74h] [ebp-38h] BYREF
  vostok::math::float3 triangle_normal; // [esp+80h] [ebp-2Ch] BYREF
  vostok::physics::bt_rigid_body_base *body; // [esp+8Ch] [ebp-20h]
  float cos_alpha; // [esp+90h] [ebp-1Ch] BYREF
  float speed; // [esp+94h] [ebp-18h]
  float distance_to_hit_point; // [esp+98h] [ebp-14h] BYREF
  float angle_alpha; // [esp+9Ch] [ebp-10h]
  float collision_time; // [esp+A0h] [ebp-Ch] BYREF
  survarium::triangle_orientation orientation; // [esp+A4h] [ebp-8h]
  unsigned __int16 game_material_id; // [esp+A8h] [ebp-4h]

  triangle_normal = ray_result->hit_normal_world;
  v7 = vostok::math::operator-(&ray_result->hit_point_world, start_position, &v18);
  distance_to_hit_point = vostok::math::float3_pod::length(v8, &v7->x);
  v9 = vostok::math::operator*(fly_direction, &v17, &distance_to_hit_point);
  vostok::math::operator+(v9, start_position, &collide_point);
  collision_time = (float)((float)(distance_to_hit_point / distance) * (float)(*current_time - *start_time))
                 + *start_time;
  cos_alpha = vostok::math::operator|(&triangle_normal, fly_direction);
  v10 = *(float *)&FLOAT_0_0;
  orientation = cos_alpha >= 0.0;
  if ( orientation == triangle_orientation_back_face )
    return 0;
  if ( vostok::math::is_zero<float>(&cos_alpha, &epsilon_5_84) )
    return 0;
  body = (vostok::physics::bt_rigid_body_base *)ray_result->object;
  game_material_id = body->get_triangle_material(body, ray_result->triangle_index, ray_result->is_shape_index);
  this->m_collided_material = survarium::game_material_manager::get_material(
                                this->m_bullet_manager->m_game_material_manager,
                                game_material_id);
  v16 = 0;
  survarium::weapon_user_dead_state::finalize(v12);
  survarium::bullet::fix_collision_point_and_time(
    this,
    &collide_point,
    &collision_time,
    *start_time,
    *current_time,
    orientation,
    &triangle_normal,
    &this->m_bullet_manager->m_gravity);
  *fly_direction = *survarium::bullet::compute_trajectory_velocity(
                      this,
                      &result,
                      collision_time,
                      &this->m_bullet_manager->m_gravity);
  speed = vostok::math::float3_pod::length(fly_direction, &fly_direction->x);
  vostok::math::float3_pod::operator/=(fly_direction, speed);
  angle_alpha = vostok::math::acos(cos_alpha);
  if ( this->m_ricochet_count >= 2u )
    return survarium::bullet::collide_front_face(
             this,
             v10,
             (survarium::material_pair *)&collide_point,
             fly_direction,
             &triangle_normal,
             speed,
             collision_time,
             start_position,
             start_time,
             current_time,
             ray_result);
  v10 = angle_alpha - 1.5707964;
  if ( (float)(this->m_collided_material->m_ricochet_koef * this->m_ricochet_angle) < (float)(angle_alpha - 1.5707964) )
    return survarium::bullet::collide_front_face(
             this,
             v10,
             (survarium::material_pair *)&collide_point,
             fly_direction,
             &triangle_normal,
             speed,
             collision_time,
             start_position,
             start_time,
             current_time,
             ray_result);
  HIDWORD(v13) = &triangle_normal;
  *(vostok::math::float3 *)&v13 = *fly_direction;
  return survarium::bullet::try_reflect(
           this,
           &collide_point,
           v13,
           speed,
           collision_time,
           start_position,
           start_time,
           current_time,
           cos_alpha);
}
