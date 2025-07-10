void __thiscall vostok::collision::capsule_geometry_instance::get_random_surface_point(
        vostok::collision::capsule_geometry_instance *this,
        vostok::math::float3 *result,
        vostok::math::random32 *randomizer)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)randomizer->m_seed);
  JUMPOUT(0x6DB38F);
}
