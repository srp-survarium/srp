void __userpurge survarium::lobby_camera::process_collision(
        survarium::lobby_camera *this@<eax>,
        const vostok::math::float3 *target_point@<esi>,
        float *distance_to_focus_point@<edi>,
        const vostok::math::float3 *direction)
{
  vostok::physics::closest_ray_result result; // [esp+1Ch] [ebp-28h] BYREF

  ((void (__stdcall *)(vostok::physics::closest_ray_result *, const vostok::math::float3 *, const vostok::math::float3 *, _DWORD, int, int))this->m_game_scene->m_physics_world->ray_test)(
    &result,
    target_point,
    direction,
    *distance_to_focus_point,
    16,
    8);
  if ( result.object )
    *distance_to_focus_point = sqrtf(
                                 (float)((float)((float)(result.hit_point_world.z - target_point->z)
                                               * (float)(result.hit_point_world.z - target_point->z))
                                       + (float)((float)(result.hit_point_world.y - target_point->y)
                                               * (float)(result.hit_point_world.y - target_point->y)))
                               + (float)((float)(result.hit_point_world.x - target_point->x)
                                       * (float)(result.hit_point_world.x - target_point->x)));
}
