void __userpurge vostok::resources::unmanaged_resource::set_sub_fat_resource(
        vostok::resources::unmanaged_resource *this@<ecx>,
        int a2@<edi>,
        vostok::resources::vfs_sub_fat_resource *sub_fat)
{
  int *v3; // esi
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v4; // ecx
  vostok::resources::resource_children *v5; // ecx
  vostok::resources::resource_base *v6; // eax

  v3 = (int *)(a2 + 216);
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed(
    (vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)this,
    (_DWORD *)(a2 + 216));
  if ( sub_fat )
  {
    vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v4,
      v3,
      sub_fat);
    v6 = (vostok::resources::resource_base *)*v3;
    *(_DWORD *)(a2 + 220) = a2;
    if ( v6 )
    {
      vostok::resources::resource_children::link_parent_resource(
        v5,
        v6,
        (vostok::resources::resource_base *)a2,
        (vostok::threading::simple_lock *)0xFFFFFFFF);
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 8))(a2, *v3, -1);
    }
  }
  else
  {
    vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v4,
      v3,
      0);
  }
}
