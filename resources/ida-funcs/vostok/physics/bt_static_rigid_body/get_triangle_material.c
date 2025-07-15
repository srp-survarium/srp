int __thiscall vostok::physics::bt_static_rigid_body::get_triangle_material(
        vostok::physics::bt_dynamic_rigid_body *this,
        const int triangle_id,
        const bool is_shape_index)
{
  vostok::physics::bt_collision_shape *m_shape; // eax
  unsigned __int16 *m_tri_face_data; // ecx
  unsigned __int16 v5; // ax

  m_shape = this->m_shape;
  if ( is_shape_index || (m_tri_face_data = m_shape->m_tri_face_data) == 0 )
    v5 = m_shape->m_shapes_face_data[triangle_id];
  else
    v5 = m_tri_face_data[triangle_id];
  return v5 & 0x3FFF;
}
