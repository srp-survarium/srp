void __thiscall vostok::collision::truncated_sphere_geometry_instance::aabb_query(
        vostok::collision::truncated_sphere_geometry_instance *this,
        const vostok::collision::object *object,
        survarium::game_camera *aabb,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  survarium::weapon_user_dead_state::finalize(aabb);
  JUMPOUT(0x6D87F7);
}
