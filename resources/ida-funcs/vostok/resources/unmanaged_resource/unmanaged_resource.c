void __userpurge vostok::resources::unmanaged_resource::unmanaged_resource(
        vostok::resources::unmanaged_resource *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::resources::class_id_enum quality_levels_count)
{
  vostok::resources::unmanaged_resource *v4; // ecx
  unsigned int v5; // [esp+0h] [ebp-8h]

  vostok::resources::resource_base::resource_base(
    (vostok::resources::resource_base *)4,
    (int)a2,
    unknown_data_class,
    quality_levels_count,
    v5);
  a2[52] = 0;
  a2[53] = 0;
  *a2 = &vostok::resources::unmanaged_resource::`vftable';
  a2[54] = 0;
  a2[55] = 0;
  a2[57] = 0;
  a2[64] = 0;
  vostok::resources::unmanaged_resource::constructor_impl(v4, (int)a2);
}
