Scaleform::Render::VertexPath *__thiscall Scaleform::Render::VertexPath::`scalar deleting destructor'(
        Scaleform::Render::VertexPath *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::VertexPath_vtbl *)&Scaleform::Render::TessBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
