int __userpurge survarium::bullet::check_collision@<eax>(
        survarium::bullet *this@<ecx>,
        float a2@<xmm0>,
        survarium::bullet *time,
        __int128 a4,
        float *a5,
        float *a6)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  survarium::bullet_manager *m_bullet_manager; // eax
  int v13; // esi
  vostok::physics::world *m_physics_world; // ecx
  vostok::physics::world_vtbl *v15; // eax
  survarium::bullet *v16; // ecx
  vostok::physics::base_physics_object *object; // eax
  bool v18; // zf
  int v19; // edi
  unsigned __int16 v20; // ax
  survarium::game_material_manager *v21; // ecx
  const survarium::game_material *material; // eax
  survarium::bullet *v23; // ecx
  const vostok::math::float3 *p_m_gravity; // [esp+30h] [ebp-68h]
  survarium::triangle_orientation v25; // [esp+30h] [ebp-68h]
  vostok::physics::closest_ray_result ray_result; // [esp+44h] [ebp-54h] BYREF
  vostok::math::float3 v27; // [esp+6Ch] [ebp-2Ch] BYREF
  vostok::math::float3 direction; // [esp+78h] [ebp-20h] BYREF
  vostok::physics::world *v29; // [esp+84h] [ebp-14h]
  float gravity; // [esp+88h] [ebp-10h]
  survarium::triangle_orientation orientation; // [esp+8Ch] [ebp-Ch]
  float v32; // [esp+90h] [ebp-8h]
  survarium::hit_receiver *timea; // [esp+A0h] [ebp+8h]

  survarium::bullet::compute_trajectory_position(time, this, &v27, a2, *a5);
  v7 = v27.y - *((float *)&a4 + 1);
  v8 = v27.z - *((float *)&a4 + 2);
  v9 = v27.x - *(float *)&a4;
  v10 = fsqrt((float)((float)(v8 * v8) + (float)(v7 * v7)) + (float)(v9 * v9));
  v32 = v10;
  if ( COERCE_FLOAT(LODWORD(v10) & 0x7FFFFFFF) < 0.0000099999997 )
    return 0;
  m_bullet_manager = time->m_bullet_manager;
  v13 = 1;
  direction.x = (float)(s_bm_current_air_resistance / v10) * v9;
  direction.y = v7 * (float)(s_bm_current_air_resistance / v10);
  direction.z = v8 * (float)(s_bm_current_air_resistance / v10);
  m_physics_world = m_bullet_manager->m_physics_world;
  v15 = m_physics_world->__vftable;
  v29 = m_physics_world;
  ((void (__stdcall *)(vostok::physics::closest_ray_result *, __int128 *, vostok::math::float3 *, float, int, int, survarium::bullet *, int))v15->ray_test)(
    &ray_result,
    &a4,
    &direction,
    COERCE_FLOAT(LODWORD(v32)),
    16,
    72,
    time,
    1);
  object = ray_result.object;
  if ( !ray_result.object )
    return 0;
  while ( 1 )
  {
    orientation = (float)((float)((float)(ray_result.hit_normal_world.z * direction.z)
                                + (float)(ray_result.hit_normal_world.y * direction.y))
                        + (float)(ray_result.hit_normal_world.x * direction.x)) >= 0.0;
    v18 = object->user_data == 0;
    gravity = fsqrt(
                (float)((float)((float)(ray_result.hit_point_world.z - *((float *)&a4 + 2))
                              * (float)(ray_result.hit_point_world.z - *((float *)&a4 + 2)))
                      + (float)((float)(ray_result.hit_point_world.y - *((float *)&a4 + 1))
                              * (float)(ray_result.hit_point_world.y - *((float *)&a4 + 1))))
              + (float)((float)(ray_result.hit_point_world.x - *(float *)&a4)
                      * (float)(ray_result.hit_point_world.x - *(float *)&a4)));
    v19 = (int)object;
    timea = v18 ? 0 : object->user_data->cast_to_hit_receiver(object->user_data);
    if ( orientation != triangle_orientation_back_face || timea )
      break;
    survarium::bullet::process_back_face_piercing(v16, (int)time, &ray_result, &direction, 0);
    v27.x = (float)(direction.x * 0.001) + ray_result.hit_point_world.x;
    v27.y = (float)(direction.y * 0.001) + ray_result.hit_point_world.y;
    v27.z = (float)(direction.z * 0.001) + ray_result.hit_point_world.z;
    *(vostok::math::float3 *)&a4 = v27;
    v32 = v32 - (float)(gravity + 0.001);
    if ( v32 <= 0.0 )
      return 0;
    ((void (__stdcall *)(vostok::physics::closest_ray_result *, __int128 *, vostok::math::float3 *, float, int, int, survarium::bullet *, int))v29->ray_test)(
      &ray_result,
      &a4,
      &direction,
      COERCE_FLOAT(LODWORD(v32)),
      16,
      72,
      time,
      1);
    object = ray_result.object;
    if ( !ray_result.object )
      return 0;
    v13 = 1;
  }
  p_m_gravity = &time->m_bullet_manager->m_gravity;
  gravity = (float)((float)((float)(*a5 - *(float *)HIDWORD(a4)) / v32) * gravity) + *(float *)HIDWORD(a4);
  if ( survarium::bullet::update_bullet_position(
         v16,
         (int)time,
         v19,
         1,
         gravity,
         time,
         (const vostok::math::float3 *)LODWORD(gravity),
         *(float *)&p_m_gravity) )
  {
    v20 = (*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v19 + 16))(
            v19,
            ray_result.triangle_index,
            *(_DWORD *)&ray_result.is_shape_index);
    material = survarium::game_material_manager::get_material(
                 v21,
                 (int)time->m_bullet_manager->m_game_material_manager,
                 v20);
    v25 = orientation;
    time->m_collided_material = material;
    if ( survarium::bullet::try_pierce(timea, *(float *)&v19, time, &ray_result, &direction, v25) )
    {
      v13 = 2;
    }
    else
    {
      if ( orientation )
        goto LABEL_24;
      if ( survarium::bullet::try_reflect(v23, time, (const vostok::math::float3 *)&ray_result, &direction.x) )
      {
        v13 = 3;
        survarium::bullet::process_reflection(v23, (int)time, &ray_result, &direction, timea);
LABEL_26:
        *(_DWORD *)HIDWORD(a4) = 0;
        *a5 = 0.0;
        *a6 = *a6 - gravity;
        return v13;
      }
    }
    if ( orientation == triangle_orientation_front_face )
    {
      if ( v13 == 2 )
        survarium::bullet::process_front_face_piercing(v23, (int)time, &ray_result, &direction, timea);
      else
        survarium::bullet::process_collision(v23, (int)time, &ray_result, &direction, timea);
      goto LABEL_26;
    }
LABEL_24:
    if ( v13 == 2 )
      survarium::bullet::process_back_face_piercing(v23, (int)time, &ray_result, &direction, timea);
    goto LABEL_26;
  }
  return v13;
}
