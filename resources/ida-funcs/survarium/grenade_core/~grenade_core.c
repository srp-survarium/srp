void __thiscall survarium::grenade_core::~grenade_core(survarium::grenade_core *this)
{
  vostok::physics::bt_dynamic_rigid_body *m_rigid_body; // edi
  vostok::resources::unmanaged_resource *v2; // ebx
  vostok::memory::base_allocator *v3; // esi
  _BYTE *v4; // ebp

  m_rigid_body = this->m_rigid_body;
  v2 = &this->vostok::resources::unmanaged_resource;
  this->survarium::tickable_object::__vftable = (survarium::grenade_core_vtbl *)&survarium::grenade_core::`vftable'{for `survarium::tickable_object'};
  this->survarium::serializable_object::__vftable = (survarium::serializable_object_vtbl *)&survarium::grenade_core::`vftable'{for `survarium::serializable_object'};
  this->vostok::collision::game_object::__vftable = (vostok::collision::game_object_vtbl *)&survarium::grenade_core::`vftable'{for `vostok::collision::game_object'};
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::grenade_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  vostok::physics::destroy_shape(m_rigid_body->m_shape);
  v3 = vostok::physics::g_allocator;
  v4 = __RTCastToVoid((void **)&m_rigid_body->__vftable);
  ((void (__thiscall *)(vostok::physics::bt_dynamic_rigid_body *, _DWORD))m_rigid_body->~vostok::physics::bt_rigid_body_base)(
    m_rigid_body,
    0);
  v3->call_free(v3, v4, "vostok::physics::destroy_dynamic_rigid_body", ".\\dynamic_rigid_body.cpp", 78u);
  vostok::resources::unmanaged_resource::~unmanaged_resource(v2);
}
