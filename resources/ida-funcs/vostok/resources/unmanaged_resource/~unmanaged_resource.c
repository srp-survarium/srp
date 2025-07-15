void __thiscall vostok::resources::unmanaged_resource::~unmanaged_resource(vostok::resources::unmanaged_resource *this)
{
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *v2; // ecx

  this->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::resources::unmanaged_resource::`vftable';
  vostok::resources::resource_children::unlink_from_children(this, this);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_raw_resource_ptr);
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed(
    v2,
    &this->m_sub_fat.m_object);
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_sub_fat);
  vostok::resources::resource_base::~resource_base(this);
}
