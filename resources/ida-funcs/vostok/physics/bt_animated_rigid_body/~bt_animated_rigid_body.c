void __thiscall vostok::physics::bt_animated_rigid_body::~bt_animated_rigid_body(
        vostok::physics::bt_animated_rigid_body *this)
{
  btRigidBody *m_bt_body; // ecx
  vostok::physics::loose_ptr_base *v3; // ecx

  m_bt_body = this->m_bt_body;
  this->__vftable = (vostok::physics::bt_animated_rigid_body_vtbl *)&vostok::physics::bt_animated_rigid_body::`vftable';
  if ( m_bt_body )
    ((void (__thiscall *)(btRigidBody *, int))m_bt_body->~btRigidBody)(m_bt_body, 1);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)m_bt_body,
    (int *)&this->m_recompute_bones_callback);
  this->__vftable = (vostok::physics::bt_animated_rigid_body_vtbl *)&vostok::physics::bt_rigid_body_base::`vftable';
  vostok::physics::loose_ptr_base::~loose_ptr_base(v3, &this->vostok::physics::loose_ptr_base_a);
}
