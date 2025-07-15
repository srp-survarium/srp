vostok::collision::triangle_mesh_geometry *__thiscall vostok::collision::triangle_mesh_geometry::`vector deleting destructor'(
        vostok::collision::triangle_mesh_geometry *this,
        char a2)
{
  vostok::collision::triangle_mesh_geometry::~triangle_mesh_geometry(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
