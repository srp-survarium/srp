void __thiscall vostok::physics::bullet_physics_world::on_before_reuse(vostok::physics::bullet_physics_world *this)
{
  *(_QWORD *)&this->m_last_frame_time = 0;
}
