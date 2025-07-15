void __thiscall vostok::physics::bt_static_rigid_body::~bt_static_rigid_body(
        vostok::physics::bt_static_rigid_body *this)
{
  btRigidBody *m_bt_body; // ecx
  vostok::physics::loose_ptr_base *v3; // ecx

  m_bt_body = this->m_bt_body;
  this->__vftable = (vostok::physics::bt_static_rigid_body_vtbl *)&vostok::physics::bt_static_rigid_body::`vftable';
  if ( m_bt_body )
    ((void (__thiscall *)(btRigidBody *, int))m_bt_body->~btRigidBody)(m_bt_body, 1);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_shape);
  this->__vftable = (vostok::physics::bt_static_rigid_body_vtbl *)&vostok::physics::bt_rigid_body_base::`vftable';
  vostok::physics::loose_ptr_base::~loose_ptr_base(v3, &this->vostok::physics::loose_ptr_base_a);
}
