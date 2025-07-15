const char *__thiscall vostok::engine::engine_world::get_resources_path(vostok::engine::engine_world *this)
{
  return "../../resources";
}


const char *__thiscall vostok::engine::engine_world::get_resources_path(char *this)
{
  return vostok::engine::engine_world::get_resources_path((vostok::engine::engine_world *)(this - 4));
}


const char *__thiscall vostok::engine::engine_world::get_resources_path(char *this)
{
  return vostok::engine::engine_world::get_resources_path((vostok::engine::engine_world *)(this - 8));
}
