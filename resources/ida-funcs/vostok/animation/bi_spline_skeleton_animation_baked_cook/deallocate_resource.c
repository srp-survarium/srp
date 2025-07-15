void __thiscall vostok::animation::bi_spline_skeleton_animation_baked_cook::deallocate_resource(
        vostok::animation::bi_spline_skeleton_animation_baked_cook *this,
        void *buffer)
{
  if ( buffer )
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      buffer,
      "vostok::animation::bi_spline_skeleton_animation_baked_cook::deallocate_resource",
      ".\\bi_spline_skeleton_animation_baked_cook.cpp",
      48u);
}
