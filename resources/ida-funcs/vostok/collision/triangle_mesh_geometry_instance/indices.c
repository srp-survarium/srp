const unsigned int *__thiscall vostok::collision::triangle_mesh_geometry_instance::indices(
        vostok::collision::triangle_mesh_geometry_instance *this,
        unsigned int triangle_id)
{
  return this->m_triangle_mesh->indices(this->m_triangle_mesh, triangle_id);
}


const unsigned int *__thiscall vostok::collision::triangle_mesh_geometry_instance::indices(
        vostok::collision::triangle_mesh_geometry_instance *this)
{
  return this->m_triangle_mesh->indices(this->m_triangle_mesh);
}
