void __thiscall survarium::collision_geometry::get_shapes_centers(
        survarium::collision_geometry *this,
        vostok::physics::bt_ghost_object *centers_results)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::physics::bt_ghost_object::non_compound_shapes_centers(
    centers_results,
    (vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_ghost_object,
    (vostok::vectora<vostok::math::float3> *)centers_results);
}
