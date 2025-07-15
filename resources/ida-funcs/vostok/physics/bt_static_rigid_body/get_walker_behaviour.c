vostok::physics::bt_rigid_body_base::walker_props_enum __thiscall vostok::physics::bt_static_rigid_body::get_walker_behaviour(
        vostok::physics::bt_static_rigid_body *this,
        const int triangle_id,
        const bool is_shape_index)
{
  vostok::physics::bt_collision_shape *m_object; // eax
  unsigned __int16 *m_tri_face_data; // ecx
  unsigned __int16 v5; // ax
  vostok::physics::bt_rigid_body_base::walker_props_enum result; // eax

  m_object = this->m_shape.m_object;
  if ( is_shape_index || (m_tri_face_data = m_object->m_tri_face_data) == 0 )
    v5 = m_object->m_shapes_face_data[triangle_id];
  else
    v5 = m_tri_face_data[triangle_id];
  if ( v5 == 0xFFFF )
    LOBYTE(result) = 0;
  else
    LOWORD(result) = v5 >> 14;
  return (unsigned __int8)result;
}
