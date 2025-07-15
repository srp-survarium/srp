btTriangleIndexVertexArray *__thiscall btTriangleIndexVertexArray::`scalar deleting destructor'(
        btTriangleIndexVertexArray *this,
        char a2)
{
  btTriangleIndexVertexArray::~btTriangleIndexVertexArray(this);
  if ( (a2 & 1) != 0 )
    btAlignedFreeInternal(this);
  return this;
}
