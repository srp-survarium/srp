void __thiscall vostok::collision::triangle_mesh_geometry_instance::get_surface_area(
        vostok::collision::triangle_mesh_geometry_instance *this)
{
  this->m_triangle_mesh->get_surface_area((vostok::collision::geometry *)this->m_triangle_mesh);
}
