void __thiscall vostok::physics::bullet_physics_world::set_renderer(
        vostok::physics::bullet_physics_world *this,
        btIDebugDraw *const renderer)
{
  this->m_dynamicsWorld->setDebugDrawer(this->m_dynamicsWorld, renderer);
}
