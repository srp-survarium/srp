void __thiscall vostok::engine::engine_world::create_physical_path(
        vostok::engine::engine_world *this,
        char (*result)[260],
        char *resources_path,
        char *inside_resources_path)
{
  vostok::strings::detail::tuples *v4; // ecx
  vostok::strings::detail::tuples v5; // [esp+4h] [ebp-34h] BYREF

  vostok::strings::detail::tuples::tuples(
    (vostok::strings::detail::tuples *)this,
    &v5,
    resources_path,
    inside_resources_path);
  vostok::strings::detail::tuples::concat(v4, (int)&v5, (char *)result);
}
