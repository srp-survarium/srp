void __usercall vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed(
        vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // ecx

  v2 = a2[1];
  if ( v2 )
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 12))(v2, *a2);
    vostok::resources::resource_children::unlink_parent_resource(
      (vostok::resources::resource_children *)*a2,
      (vostok::resources::resource_base *)a2[1]);
    a2[1] = 0;
  }
}
