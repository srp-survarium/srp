void __thiscall vostok::collision::truncated_sphere_geometry_instance::cuboid_query(
        vostok::collision::truncated_sphere_geometry_instance *this,
        const vostok::collision::object *object,
        survarium::game_camera *cuboid,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  survarium::weapon_user_dead_state::finalize(cuboid);
  JUMPOUT(0x6D87C7);
}
