void __usercall vostok::resources::managed_resource::set_sub_fat_resource(
        vostok::resources::managed_resource *this@<ecx>,
        vostok::resources::resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *sub_fat@<eax>)
{
  vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base>::initialize_and_set_parent<vostok::resources::unmanaged_resource>(
    &this->m_sub_fat,
    this,
    (vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)this,
    sub_fat);
}
