void __thiscall vostok::physics::collision_shape_cook::delete_resource(
        vostok::physics::collision_shape_cook *this,
        vostok::physics::bt_collision_shape *resource)
{
  vostok::physics::destroy_shape(resource);
}
