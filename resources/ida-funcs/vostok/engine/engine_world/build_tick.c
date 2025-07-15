// attributes: thunk
void __thiscall vostok::engine::engine_world::build_tick(vostok::engine::engine_world *this)
{
  vostok::resources::dispatch_callbacks((vostok::resources::resources_manager *)this);
}
