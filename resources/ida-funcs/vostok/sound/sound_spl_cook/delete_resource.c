void __thiscall vostok::sound::sound_spl_cook::delete_resource(
        vostok::sound::sound_spl_cook *this,
        vostok::resources::resource_base *res)
{
  vostok::memory::base_allocator *allocator; // [esp+10h] [ebp-4h]

  allocator = vostok::resources::unmanaged_allocator();
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(allocator, &res);
}
