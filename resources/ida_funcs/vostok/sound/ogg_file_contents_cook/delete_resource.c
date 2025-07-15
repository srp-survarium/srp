void __thiscall vostok::sound::ogg_file_contents_cook::delete_resource(
        vostok::sound::ogg_file_contents_cook *this,
        vostok::resources::resource_base *res)
{
  vostok::memory::base_allocator *allocator; // [esp+10h] [ebp-4h]

  allocator = vostok::resources::unmanaged_allocator();
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(allocator, &res);
}
