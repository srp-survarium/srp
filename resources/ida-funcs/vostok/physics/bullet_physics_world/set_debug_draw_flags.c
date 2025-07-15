void __thiscall vostok::physics::bullet_physics_world::set_debug_draw_flags(
        vostok::physics::bullet_physics_world *this,
        bool draw_hittable,
        bool draw_walkable,
        bool draw_sensor,
        bool draw_trimesh)
{
  this->m_debug_draw_walkable = draw_walkable;
  this->m_debug_draw_hittable = draw_hittable;
  this->m_debug_draw_sensor = draw_sensor;
  this->m_debug_draw_trimesh = draw_trimesh;
}
