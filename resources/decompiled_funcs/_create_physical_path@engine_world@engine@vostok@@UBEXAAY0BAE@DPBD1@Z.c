void __thiscall vostok::engine::engine_world::create_physical_path(
        vostok::engine::engine_world *this,
        char (*result)[260],
        const char *resources_path,
        const char *inside_resources_path)
{
  vostok::strings::detail::tuples v4; // [esp+8h] [ebp-34h] BYREF

  vostok::strings::detail::tuples::tuples(&v4, resources_path, inside_resources_path);
  vostok::strings::detail::tuples::concat(&v4, (const char *)result);
}
