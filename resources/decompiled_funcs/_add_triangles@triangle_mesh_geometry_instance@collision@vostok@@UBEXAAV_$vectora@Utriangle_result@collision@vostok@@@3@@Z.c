void __thiscall vostok::collision::triangle_mesh_geometry_instance::add_triangles(
        vostok::collision::triangle_mesh_geometry_instance *this,
        vostok::vectora<vostok::collision::triangle_result> *triangles)
{
  this->m_triangle_mesh->add_triangles((vostok::collision::geometry *)this->m_triangle_mesh, triangles);
}
