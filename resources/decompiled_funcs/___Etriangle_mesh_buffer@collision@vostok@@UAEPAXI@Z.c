vostok::collision::triangle_mesh_buffer *__thiscall vostok::collision::triangle_mesh_buffer::`vector deleting destructor'(
        vostok::collision::triangle_mesh_buffer *this,
        char a2)
{
  vostok::collision::triangle_mesh_buffer::~triangle_mesh_buffer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
