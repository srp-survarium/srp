void __thiscall vostok::animation::animation_collection_cook::delete_resource(
        vostok::animation::animation_collection_cook *this,
        vostok::resources::resource_base *res)
{
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
  if ( res )
    vostok::memory::detail::free_helper_impl<vostok::memory::base_allocator,vostok::resources::resource_base>(
      &vostok::memory::g_resources_unmanaged_allocator,
      &res,
      res);
}
