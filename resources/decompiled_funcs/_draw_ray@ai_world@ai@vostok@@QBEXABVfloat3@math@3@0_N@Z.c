void __thiscall vostok::ai::ai_world::draw_ray(
        vostok::ai::ai_world *this,
        const vostok::math::float3 *start_point,
        const vostok::math::float3 *end_point,
        bool sees_something)
{
  this->m_engine->draw_ray(this->m_engine, start_point, end_point, sees_something);
}
