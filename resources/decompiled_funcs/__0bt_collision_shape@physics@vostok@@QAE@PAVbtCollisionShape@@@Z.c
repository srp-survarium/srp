void __usercall vostok::physics::bt_collision_shape::bt_collision_shape(
        vostok::physics::bt_collision_shape *this@<esi>,
        btCollisionShape *sh@<edi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->m_tri_face_data = 0;
  this->m_shapes_face_data = 0;
  this->__vftable = (vostok::physics::bt_collision_shape_vtbl *)&vostok::physics::bt_collision_shape::`vftable';
  this->m_bt_shape = sh;
  sh->m_userPointer = this;
}
