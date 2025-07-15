void __thiscall vostok::engine::engine_world::enable_game(
        vostok::engine::engine_world *this,
        boost::function<void __cdecl(void)> *value)
{
  vostok::engine::engine_world::enable_game_impl(
    (vostok::engine::engine_world *)((char *)this - 8),
    (vostok::engine::engine_world *)((char *)this - 8),
    value);
}
