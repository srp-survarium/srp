void __thiscall vostok::render::effect_cook::destroy_resource(
        vostok::render::effect_cook *this,
        vostok::render::res_effect *resource_to_destroy)
{
  vostok::render::effect_manager::remove_effect((vostok::render::effect_manager *)this, resource_to_destroy);
  ((void (__thiscall *)(vostok::render::res_effect *, _DWORD))resource_to_destroy->~vostok::resources::resource_base)(
    resource_to_destroy,
    0);
}
