void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::MeshProvider *fill,
        bool is3D)
{
  this->Data = fill;
  if ( is3D )
  {
    this->pImpl = &Scaleform::Render::SKI_ComplexPrimitive::Instance3D;
    Scaleform::Render::SKI_ComplexPrimitive::Instance3D.AddRef(
      &Scaleform::Render::SKI_ComplexPrimitive::Instance3D,
      fill);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_ComplexPrimitive::Instance;
    Scaleform::Render::SKI_ComplexPrimitive::Instance.AddRef(&Scaleform::Render::SKI_ComplexPrimitive::Instance, fill);
  }
}
