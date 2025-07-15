void __thiscall vostok::physics::bt_dynamic_rigid_body::~bt_dynamic_rigid_body(
        vostok::physics::bt_dynamic_rigid_body *this)
{
  vostok::physics::loose_ptr_base *m_bt_body; // ecx

  m_bt_body = (vostok::physics::loose_ptr_base *)this->m_bt_body;
  this->__vftable = (vostok::physics::bt_dynamic_rigid_body_vtbl *)&vostok::physics::bt_dynamic_rigid_body::`vftable';
  if ( m_bt_body )
    ((void (__thiscall *)(vostok::physics::loose_ptr_base *, int))m_bt_body->m_pointer->m_reference_count)(m_bt_body, 1);
  this->__vftable = (vostok::physics::bt_dynamic_rigid_body_vtbl *)&vostok::physics::bt_rigid_body_base::`vftable';
  vostok::physics::loose_ptr_base::~loose_ptr_base(m_bt_body, &this->vostok::physics::loose_ptr_base_a);
}
