vostok::resources::managed_resource *__thiscall vostok::resources::managed_resource::`vector deleting destructor'(
        vostok::resources::managed_resource *this,
        char a2)
{
  vostok::memory::managed_node_owner *v3; // ebx
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v4; // ecx

  v3 = &this->vostok::memory::managed_node_owner;
  this->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::managed_resource_vtbl *)&vostok::resources::managed_resource::`vftable'{for `vostok::resources::resource_base'};
  this->vostok::memory::managed_node_owner::__vftable = (vostok::memory::managed_node_owner_vtbl *)&vostok::resources::managed_resource::`vftable'{for `vostok::memory::managed_node_owner'};
  vostok::resources::resource_children::unlink_from_children(this, this);
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed(
    v4,
    &this->m_sub_fat.m_object);
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_sub_fat);
  v3->__vftable = (vostok::memory::managed_node_owner_vtbl *)&vostok::memory::managed_node_owner::`vftable';
  vostok::resources::resource_base::~resource_base(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


vostok::resources::managed_resource *__thiscall vostok::resources::managed_resource::`vector deleting destructor'(
        char *this,
        char a2)
{
  return vostok::resources::managed_resource::`vector deleting destructor'(
           (vostok::resources::managed_resource *)(this - 208),
           a2);
}
