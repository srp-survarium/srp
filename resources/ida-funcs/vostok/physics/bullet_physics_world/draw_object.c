void __thiscall vostok::physics::bullet_physics_world::draw_object(
        vostok::physics::bullet_physics_world *this,
        btCollisionShape *const shape,
        const btTransform *transform,
        const btVector3 *color)
{
  this->m_dynamicsWorld->debugDrawObject(this->m_dynamicsWorld, transform, shape, color);
}
