void __thiscall survarium::oxygen_tank::~oxygen_tank(survarium::oxygen_tank *this)
{
  unsigned int v2; // esi
  bool v3; // zf
  int v4; // ebx
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+4h] [ebp-8h]
  unsigned int v7; // [esp+8h] [ebp-4h]

  v2 = 0;
  v3 = this->m_influences_count == 0;
  this->survarium::inventory_item::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::oxygen_tank_vtbl *)&survarium::oxygen_tank::`vftable'{for `survarium::inventory_item'};
  this->survarium::tickable_object::__vftable = (survarium::tickable_object_vtbl *)&survarium::oxygen_tank::`vftable'{for `survarium::tickable_object'};
  if ( !v3 )
  {
    v4 = 0;
    do
    {
      ((void (__thiscall *)(survarium::oxygen_tank::item_influence *, _DWORD))this->m_influences[v4].protector.~survarium::damage_protector)(
        &this->m_influences[v4],
        0);
      ++v2;
      ++v4;
    }
    while ( v2 < this->m_influences_count );
  }
  if ( this->m_influences )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)this->m_influences,
      v5,
      v6,
      v7);
    this->m_influences = 0;
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
