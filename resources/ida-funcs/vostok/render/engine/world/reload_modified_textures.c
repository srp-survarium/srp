void __thiscall vostok::render::engine::world::reload_modified_textures(vostok::render::engine::world *this)
{
  vostok::render::resource_manager::reload_modified_textures(
    (vostok::render::resource_manager *)this,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
}
