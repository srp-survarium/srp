void __thiscall vostok::collision::composite_geometry_instance::get_surface_area(
        vostok::collision::composite_geometry_instance *this)
{
  this->m_geometry->get_surface_area((vostok::collision::geometry *)this->m_geometry);
}
