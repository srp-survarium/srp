void __thiscall vostok::collision::triangle_mesh_geometry::~triangle_mesh_geometry(
        vostok::collision::triangle_mesh_geometry *this)
{
  this->__vftable = (vostok::collision::triangle_mesh_geometry_vtbl *)&vostok::collision::triangle_mesh_geometry::`vftable';
  stlp_std::priv::_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int>>::~_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int>>(
    (stlp_std::priv::_Vector_base<unsigned int,vostok::vectora_allocator<unsigned int> > *)this,
    (int)&this->m_triangle_data);
  this->__vftable = (vostok::collision::triangle_mesh_geometry_vtbl *)&vostok::collision::geometry::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
