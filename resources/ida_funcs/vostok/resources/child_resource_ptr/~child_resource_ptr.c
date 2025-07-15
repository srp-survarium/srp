void __usercall vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::~child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::unmanaged_intrusive_base **a2@<eax>)
{
  vostok::resources::unmanaged_intrusive_base *v3; // ecx

  v3 = a2[1];
  if ( v3 )
  {
    (*(void (__thiscall **)(vostok::resources::unmanaged_intrusive_base *, vostok::resources::unmanaged_intrusive_base *))(v3->m_reference_count + 12))(
      v3,
      *a2);
    vostok::resources::resource_children::unlink_parent_resource(
      (vostok::resources::resource_children *)*a2,
      (vostok::resources::resource_base *)a2[1]);
    a2[1] = 0;
  }
  if ( *a2 )
  {
    if ( !_InterlockedExchangeAdd(&(*a2)[26].m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(*a2 + 26, (vostok::resources::unmanaged_resource *)*a2);
  }
}
