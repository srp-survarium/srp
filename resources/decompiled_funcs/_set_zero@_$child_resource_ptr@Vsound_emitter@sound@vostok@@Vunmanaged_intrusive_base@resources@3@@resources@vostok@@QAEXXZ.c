void __usercall vostok::resources::child_resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>::set_zero(
        vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<eax>)
{
  vostok::resources::unmanaged_resource *v3; // ecx
  vostok::resources::unmanaged_resource *v4; // eax

  v3 = a2[1];
  if ( v3 )
  {
    v3->unlink_child_resource(v3, *a2);
    vostok::resources::resource_children::unlink_parent_resource(*a2, a2[1]);
    a2[1] = 0;
  }
  v4 = *a2;
  *a2 = 0;
  if ( v4 )
  {
    if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
  }
}
