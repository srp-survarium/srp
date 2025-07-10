void __thiscall vostok::ai::ai_world::get_colliding_objects(
        vostok::ai::ai_world *this,
        const vostok::math::aabb *query_aabb,
        vostok::vectora<vostok::ai::game_object const *> *results)
{
  this->m_engine->get_colliding_objects(this->m_engine, query_aabb, results);
}
