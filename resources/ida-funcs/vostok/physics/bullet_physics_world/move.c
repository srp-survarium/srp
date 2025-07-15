void __thiscall vostok::physics::bullet_physics_world::move(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_rigid_body_base *body,
        const vostok::math::float4x4 *new_transform)
{
  body->set_transform(body, new_transform);
}
