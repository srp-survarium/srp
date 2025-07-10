void __thiscall vostok::sound::panning_lut_cook::delete_resource(
        vostok::sound::panning_lut_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::base_allocator *allocator; // [esp+10h] [ebp-4h]

  allocator = vostok::resources::unmanaged_allocator();
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(allocator, &resource);
}
