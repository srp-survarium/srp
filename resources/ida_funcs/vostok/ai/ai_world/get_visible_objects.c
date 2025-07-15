void __thiscall vostok::ai::ai_world::get_visible_objects(
        vostok::ai::ai_world *this,
        const vostok::math::cuboid *cuboid,
        const boost::function<void __cdecl(vostok::ai::game_object const &)> *update_callback)
{
  this->m_engine->get_visible_objects(this->m_engine, cuboid, update_callback);
}
