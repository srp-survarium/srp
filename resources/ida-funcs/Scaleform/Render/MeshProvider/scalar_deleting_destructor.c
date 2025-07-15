Scaleform::Render::MeshProvider *__thiscall Scaleform::Render::MeshProvider::`scalar deleting destructor'(
        Scaleform::Render::MeshProvider *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::MeshProvider_vtbl *)&Scaleform::Render::MeshProvider::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
