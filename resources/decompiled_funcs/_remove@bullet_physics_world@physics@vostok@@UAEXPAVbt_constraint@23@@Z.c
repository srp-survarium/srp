void __thiscall vostok::physics::bullet_physics_world::remove(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_constraint *constraint)
{
  this->m_dynamicsWorld->removeConstraint(this->m_dynamicsWorld, constraint->m_bt_typed_constraint);
}
