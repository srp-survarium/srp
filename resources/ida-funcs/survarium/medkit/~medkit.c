void __thiscall survarium::medkit::~medkit(survarium::medkit *this)
{
  float **p_m_applied_influence; // ebx
  const char *v3; // [esp+0h] [ebp-Ch]
  const char *v4; // [esp+4h] [ebp-8h]
  unsigned int v5; // [esp+8h] [ebp-4h]

  p_m_applied_influence = &this->m_applied_influence;
  this->survarium::inventory_item::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::medkit_vtbl *)&survarium::medkit::`vftable'{for `survarium::inventory_item'};
  this->survarium::tickable_object::__vftable = (survarium::tickable_object_vtbl *)&survarium::medkit::`vftable'{for `survarium::tickable_object'};
  if ( this->m_applied_influence )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)this->m_applied_influence,
      v3,
      v4,
      v5);
    *p_m_applied_influence = 0;
  }
  if ( this->m_influences )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      this->m_influences->body_part_name,
      v3,
      v4,
      v5);
    this->m_influences = 0;
  }
  if ( this->m_affects )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      this->m_affects->body_part_name,
      v3,
      v4,
      v5);
    this->m_affects = 0;
  }
  if ( this->m_damage_protect )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)this->m_damage_protect,
      v3,
      v4,
      v5);
    this->m_damage_protect = 0;
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(&this->survarium::inventory_item);
}
