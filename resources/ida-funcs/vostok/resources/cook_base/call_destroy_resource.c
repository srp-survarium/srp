void __usercall vostok::resources::cook_base::call_destroy_resource(
        vostok::resources::cook_base *this@<eax>,
        vostok::resources::managed_resource *resource@<edx>)
{
  vostok::resources::inplace_managed_cook *v3; // eax
  vostok::resources::managed_resource *v4; // edx
  unsigned int m_flags; // eax
  vostok::resources::cook_base *v6; // ecx
  vostok::resources::cook_base *v7; // ecx

  _InterlockedExchangeAdd(&resource->m_reference_count, 1u);
  _InterlockedOr(
    &resource->vostok::resources::managed_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::managed_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags,
    8u);
  v3 = vostok::resources::cook_base::cast_inplace_managed_cook(
         (vostok::resources::cook_base *)8,
         (vostok::resources::inplace_managed_cook *)this);
  if ( v3 )
  {
    v3->destroy_resource(v3, v4);
  }
  else
  {
    m_flags = this->m_flags.m_flags;
    if ( (m_flags & 0x20) == 0 || (m_flags & 0x18) != 0 )
      v6 = 0;
    else
      v6 = this;
    if ( v6 )
    {
      ((void (__thiscall *)(vostok::resources::cook_base *, vostok::resources::managed_resource *))v6->__vftable[1].cache_by_game_resources_manager)(
        v6,
        v4);
    }
    else
    {
      v7 = (unsigned __int8)((m_flags & 8) - 8) == 0 ? this : 0;
      v7->__vftable[1].calculate_quality_levels_count(v7, (const vostok::resources::query_result_for_cook *)v4);
    }
  }
}


void __usercall vostok::resources::cook_base::call_destroy_resource(
        vostok::resources::cook_base *this@<esi>,
        vostok::resources::unmanaged_resource *resource@<eax>)
{
  vostok::resources::unmanaged_resource *v3; // ecx
  vostok::resources::cook_base *v4; // ecx
  vostok::resources::inplace_unmanaged_cook *v5; // eax
  unsigned int m_flags; // eax
  vostok::resources::cook_base *v7; // ecx
  vostok::resources::cook_base *v8; // ecx
  vostok::resources::vfs_sub_fat_resource *m_object; // [esp-4h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+4h] [ebp-4h] BYREF

  _InterlockedExchangeAdd(&resource->m_reference_count, 1u);
  _InterlockedOr(
    &resource->vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags,
    8u);
  m_object = resource->m_sub_fat.m_object;
  v10.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v10,
    m_object);
  vostok::resources::unmanaged_resource::set_sub_fat_resource(v3, (int)resource, 0);
  v5 = vostok::resources::cook_base::cast_inplace_unmanaged_cook(v4, (vostok::resources::inplace_unmanaged_cook *)this);
  if ( v5 )
  {
    v5->destroy_resource(v5, resource);
  }
  else
  {
    m_flags = this->m_flags.m_flags;
    if ( (m_flags & 0x38) != 0 )
      v7 = 0;
    else
      v7 = this;
    if ( v7 )
    {
      ((void (__thiscall *)(vostok::resources::cook_base *, vostok::resources::unmanaged_resource *))v7->__vftable[1].cache_by_game_resources_manager)(
        v7,
        resource);
    }
    else
    {
      v8 = (unsigned __int8)((m_flags & 8) - 8) == 0 ? this : 0;
      v8->__vftable[1].calculate_quality_levels_count(v8, (const vostok::resources::query_result_for_cook *)resource);
    }
  }
  vostok::intrusive_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
}
