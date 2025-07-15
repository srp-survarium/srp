char __usercall vostok::resources::resource_base::try_unregister_from_fat_or_from_name_registry@<al>(
        vostok::resources::resource_base *this@<eax>,
        vostok::vfs::vfs_hashset *count_that_allows_unregister@<esi>)
{
  vostok::resources::unmanaged_resource *v3; // ecx

  if ( (this->m_flags.m_flags & 1) != 0 && this )
  {
    if ( (this->m_flags.m_flags & 1) != 0 )
    {
      return vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
               (vostok::resources::unmanaged_resource *const)this,
               (vostok::resources::base_of_intrusive_base *)(&this[1].vostok::resources::resource_flags + 1),
               count_that_allows_unregister);
    }
    else if ( (this->m_flags.m_flags & 4) != 0 )
    {
      return vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
               (vostok::resources::unmanaged_resource *const)this,
               (vostok::resources::base_of_intrusive_base *)&this[1],
               count_that_allows_unregister);
    }
    else
    {
      return vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
               (vostok::resources::unmanaged_resource *const)this,
               0,
               count_that_allows_unregister);
    }
  }
  else
  {
    v3 = (this->m_flags.m_flags & 4) != 4 ? 0 : (vostok::resources::unmanaged_resource *)this;
    if ( (this->m_flags.m_flags & 1) != 0 && this )
    {
      return vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
               v3,
               (vostok::resources::base_of_intrusive_base *)(&this[1].vostok::resources::resource_flags + 1),
               count_that_allows_unregister);
    }
    else if ( (this->m_flags.m_flags & 4) != 0 && this )
    {
      return vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
               v3,
               (vostok::resources::base_of_intrusive_base *)&this[1],
               count_that_allows_unregister);
    }
    else
    {
      return vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
               v3,
               0,
               count_that_allows_unregister);
    }
  }
}
