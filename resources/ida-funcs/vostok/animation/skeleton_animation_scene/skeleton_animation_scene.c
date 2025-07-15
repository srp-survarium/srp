void __usercall vostok::animation::skeleton_animation_scene::skeleton_animation_scene(
        vostok::animation::skeleton_animation_scene *this@<ecx>,
        _DWORD *a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, a2, fs_iterator_class);
  *a2 = &vostok::animation::skeleton_animation_scene::`vftable';
  a2[66] = 0;
  a2[67] = 0;
  a2[69] = 0;
  a2[68] = &vostok::memory::g_resources_unmanaged_allocator;
  a2[70] = 0;
  a2[71] = 0;
  a2[72] = &vostok::memory::g_resources_unmanaged_allocator;
  a2[73] = 0;
}
