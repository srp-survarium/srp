unsigned __int16 __thiscall vostok::physics::bt_collision_shape::get_triangle_material(
        vostok::physics::bt_collision_shape *this,
        int triangle_id,
        bool is_shape_index)
{
  if ( is_shape_index )
    return this->m_shapes_face_data[triangle_id];
  else
    return this->m_tri_face_data[triangle_id];
}
