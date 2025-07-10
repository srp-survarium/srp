void __thiscall vostok::engine::engine_world::sound_tick(
        vostok::engine::engine_world *this,
        vostok::engine::engine_world *thisa)
{
  vostok::resources::dispatch_callbacks((vostok::resources::resources_manager *)this);
  thisa->m_sound_world->tick(thisa->m_sound_world);
}
