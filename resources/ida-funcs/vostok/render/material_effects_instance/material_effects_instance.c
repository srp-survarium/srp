void __userpurge vostok::render::material_effects_instance::material_effects_instance(
        vostok::render::material_effects_instance *this@<ecx>,
        _DWORD *a2@<esi>,
        unsigned int num_effects)
{
  vostok::fs_new::virtual_path_string *v3; // ecx

  vostok::resources::unmanaged_resource::unmanaged_resource(this, a2, fs_iterator_class);
  *a2 = &vostok::render::material_effects_instance::`vftable';
  vostok::fs_new::virtual_path_string::virtual_path_string(v3, (int)(a2 + 66));
  a2[135] = 0;
  a2[136] = num_effects;
  if ( num_effects )
    a2[135] = vostok::memory::new_array_helper<vostok::render::material_effects>::call<vostok::memory::doug_lea_allocator>(
                vostok::render::g_allocator,
                num_effects);
}
