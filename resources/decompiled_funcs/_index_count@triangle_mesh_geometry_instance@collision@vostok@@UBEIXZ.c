unsigned int __thiscall vostok::collision::triangle_mesh_geometry_instance::index_count(
        vostok::collision::triangle_mesh_geometry_instance *this)
{
  return this->m_triangle_mesh->index_count((vostok::collision::geometry *)this->m_triangle_mesh);
}
