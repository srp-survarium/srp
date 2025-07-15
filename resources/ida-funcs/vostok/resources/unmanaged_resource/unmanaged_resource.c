void __thiscall vostok::resources::unmanaged_resource::unmanaged_resource(
        vostok::resources::unmanaged_resource *this,
        vostok::resources::resource_flags_enum flags,
        unsigned int quality_levels_count)
{
  vostok::resources::unmanaged_resource *v4; // ecx
  unsigned int v5; // [esp+0h] [ebp-8h]

  vostok::resources::resource_base::resource_base(
    (vostok::resources::resource_base *)(flags | 4),
    (int)this,
    unknown_data_class,
    quality_levels_count,
    v5);
  this->m_reference_count = 0;
  this->vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags = 0;
  this->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::resources::unmanaged_resource::`vftable';
  this->m_sub_fat.m_object = 0;
  this->m_sub_fat.m_parent = 0;
  this->m_raw_resource_ptr.m_object = 0;
  this->m_flags.m_flags = 0;
  vostok::resources::unmanaged_resource::constructor_impl(v4, (int)this);
}


void __thiscall vostok::resources::unmanaged_resource::unmanaged_resource(
        vostok::resources::unmanaged_resource *this,
        unsigned int quality_levels_count)
{
  vostok::resources::unmanaged_resource *v3; // ecx
  unsigned int v4; // [esp+0h] [ebp-8h]

  vostok::resources::resource_base::resource_base(
    (vostok::resources::resource_base *)4,
    (int)this,
    unknown_data_class,
    quality_levels_count,
    v4);
  this->m_reference_count = 0;
  this->vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags = 0;
  this->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::resources::unmanaged_resource::`vftable';
  this->m_sub_fat.m_object = 0;
  this->m_sub_fat.m_parent = 0;
  this->m_raw_resource_ptr.m_object = 0;
  this->m_flags.m_flags = 0;
  vostok::resources::unmanaged_resource::constructor_impl(v3, (int)this);
}
