void __thiscall vostok::physics::bt_collision_shape::~bt_collision_shape(vostok::physics::bt_collision_shape *this)
{
  unsigned __int16 *m_shapes_face_data; // eax

  this->__vftable = (vostok::physics::bt_collision_shape_vtbl *)&vostok::physics::bt_collision_shape::`vftable';
  m_shapes_face_data = this->m_shapes_face_data;
  if ( m_shapes_face_data )
  {
    vostok::physics::g_ph_allocator->call_free(vostok::physics::g_ph_allocator, m_shapes_face_data);
    this->m_shapes_face_data = 0;
  }
  if ( this->m_tri_face_data )
  {
    vostok::physics::g_ph_allocator->call_free(vostok::physics::g_ph_allocator, this->m_tri_face_data);
    this->m_tri_face_data = 0;
  }
  vostok::physics::destroy_bt_shape(this->m_bt_shape);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
