void __thiscall vostok::physics::bt_static_rigid_body::~bt_static_rigid_body(
        vostok::physics::bt_static_rigid_body *this)
{
  btRigidBody *m_bt_body; // eax
  vostok::memory::base_allocator *v3; // edi
  _BYTE *v4; // ebp
  vostok::physics::bt_collision_shape *m_object; // eax
  vostok::loose_ptr_data *m_pointer; // eax

  this->__vftable = (vostok::physics::bt_static_rigid_body_vtbl *)&vostok::physics::bt_static_rigid_body::`vftable';
  m_bt_body = this->m_bt_body;
  v3 = vostok::physics::g_ph_allocator;
  if ( m_bt_body )
  {
    v4 = __RTCastToVoid((void **)&m_bt_body->__vftable);
    ((void (__thiscall *)(btRigidBody *, _DWORD))this->m_bt_body->~btRigidBody)(this->m_bt_body, 0);
    v3->call_free(v3, v4);
    this->m_bt_body = 0;
  }
  m_object = this->m_shape.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_shape.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_shape.m_object);
  this->__vftable = (vostok::physics::bt_static_rigid_body_vtbl *)&vostok::physics::bt_rigid_body_base::`vftable';
  if ( --this->m_pointer->m_reference_count )
  {
    this->m_pointer->m_pointer = 0;
  }
  else
  {
    m_pointer = this->m_pointer;
    if ( m_pointer )
    {
      pt3free(m_pointer);
      this->m_pointer = 0;
    }
  }
}
