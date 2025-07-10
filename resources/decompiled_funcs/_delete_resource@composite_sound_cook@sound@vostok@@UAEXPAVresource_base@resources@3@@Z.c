void __thiscall vostok::sound::composite_sound_cook::delete_resource(
        vostok::sound::composite_sound_cook *this,
        vostok::resources::resource_base *res)
{
  vostok::memory::base_allocator *v2; // [esp+8h] [ebp-4h]

  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
  v2 = vostok::resources::unmanaged_allocator();
  if ( res )
    vostok::memory::base_allocator::free_impl(v2, res);
}
