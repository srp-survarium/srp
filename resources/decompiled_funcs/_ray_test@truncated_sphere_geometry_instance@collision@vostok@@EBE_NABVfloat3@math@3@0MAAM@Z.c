void __thiscall vostok::collision::truncated_sphere_geometry_instance::ray_test(
        vostok::collision::truncated_sphere_geometry_instance *this,
        survarium::game_camera *origin,
        const vostok::math::float3 *direction,
        float max_distance,
        float *distance)
{
  survarium::weapon_user_dead_state::finalize(origin);
  JUMPOUT(0x6D8756);
}
