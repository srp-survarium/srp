void __usercall survarium::ladder::~ladder(survarium::ladder *this@<ecx>, const char *a2@<ebp>)
{
  vostok::memory::doug_lea_allocator *v2; // esi
  survarium::usable_object *v4; // ebx
  survarium::ladder::ladder_occluder *m_occluder; // eax
  char *v6; // ebp
  vostok::memory::doug_lea_allocator *v7; // ecx
  const char *v9; // [esp+0h] [ebp-Ch]
  unsigned int v10; // [esp+4h] [ebp-8h]

  v2 = survarium::g_allocator;
  v4 = &this->survarium::usable_object;
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::ladder_vtbl *)&survarium::ladder::`vftable';
  this->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::ladder::`vftable'{for `survarium::collision_geometry_subscriber'};
  this->survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::ladder::`vftable'{for `survarium::link_resolver'};
  m_occluder = this->m_occluder;
  if ( m_occluder )
  {
    v6 = __RTCastToVoid((void **)&m_occluder->survarium::usable_object::survarium::collision_geometry_subscriber::__vftable);
    ((void (__thiscall *)(survarium::ladder::ladder_occluder *, _DWORD))this->m_occluder->~survarium::ladder::ladder_occluder)(
      this->m_occluder,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v7, (int)v2, v6, a2, v9, v10);
    this->m_occluder = 0;
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_main_animation);
  survarium::usable_object::~usable_object(v4);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
