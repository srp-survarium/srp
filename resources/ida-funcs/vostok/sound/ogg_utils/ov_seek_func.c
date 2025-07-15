int __cdecl vostok::sound::ogg_utils::ov_seek_func(
        const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *datasource,
        __int64 offset_bytes,
        vostok::resources::pinned_ptr_const<unsigned char> *whence)
{
  vostok::resources::managed_resource *v3; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v4; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v5; // ecx
  char *v6; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v8; // [esp-4h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+8h] [ebp-Ch] BYREF
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v8.m_object = v3;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v8,
    datasource);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v4,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
    v8);
  v5 = whence;
  v6 = (char *)datasource[1].m_object + v10;
  if ( whence )
  {
    v5 = (vostok::resources::pinned_ptr_const<unsigned char> *)((char *)whence - 1);
    if ( whence == (vostok::resources::pinned_ptr_const<unsigned char> *)1 )
    {
      v6 += offset_bytes;
    }
    else
    {
      v5 = (vostok::resources::pinned_ptr_const<unsigned char> *)((char *)whence - 2);
      if ( whence == (vostok::resources::pinned_ptr_const<unsigned char> *)2 )
        v6 = (char *)(v11 + v10 + offset_bytes);
    }
  }
  else
  {
    v6 = (char *)(v10 + offset_bytes);
  }
  datasource[1].m_object = (vostok::resources::managed_resource *)&v6[-v10];
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v5);
  return 0;
}
