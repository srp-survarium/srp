survarium::game *__thiscall survarium::game_module_proxy::create_world(
        survarium::game_module_proxy *this,
        vostok::engine_user::engine *engine,
        vostok::render::world *render_world,
        vostok::sound::world *sound,
        vostok::network::world *network)
{
  return survarium::game_module::create_world(engine, render_world, sound, network);
}
