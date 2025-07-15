void __thiscall vostok::ai::brain_unit_cook::delete_resource(
        vostok::ai::brain_unit_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::memory::writer>(
    vostok::ai::g_allocator,
    (vostok::memory::writer **)&resource);
}
