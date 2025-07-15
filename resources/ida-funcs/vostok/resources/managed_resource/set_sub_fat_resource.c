void __userpurge vostok::resources::managed_resource::set_sub_fat_resource(
        vostok::resources::managed_resource *this@<ecx>,
        vostok::resources::resource_base *a2@<edi>,
        vostok::resources::vfs_sub_fat_resource *sub_fat)
{
  int *v3; // esi
  vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v4; // ecx
  vostok::resources::resource_children *v5; // ecx
  vostok::resources::resource_base *v6; // eax

  v3 = (int *)&a2[1].m_reconstruction_info_actuality_tick + 1;
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed(
    (vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)this,
    (_DWORD *)&a2[1].m_reconstruction_info_actuality_tick + 1);
  if ( sub_fat )
  {
    vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
      v4,
      v3,
      sub_fat);
    v6 = (vostok::resources::resource_base *)*v3;
    a2[1].m_reconstruction_size = (unsigned int)a2;
    if ( v6 )
    {
      vostok::resources::resource_children::link_parent_resource(
        v5,
        v6,
        a2,
        (vostok::threading::simple_lock *)0xFFFFFFFF);
      a2->link_child_resource(a2, (vostok::resources::resource_base *)*v3, -1u);
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
