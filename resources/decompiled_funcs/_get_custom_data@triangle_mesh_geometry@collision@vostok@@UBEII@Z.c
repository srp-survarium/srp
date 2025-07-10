unsigned int __thiscall vostok::collision::triangle_mesh_geometry::get_custom_data(
        vostok::collision::triangle_mesh_geometry *this,
        unsigned int triangle_id)
{
  return this->m_triangle_data._M_impl._M_start[triangle_id];
}
