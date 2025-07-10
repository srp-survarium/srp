void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::PrimitiveFill *fill,
        bool is3D)
{
  this->Data = fill;
  if ( is3D )
  {
    this->pImpl = &Scaleform::Render::SKI_Primitive::Instance3D;
    Scaleform::Render::SKI_Primitive::Instance3D.AddRef(&Scaleform::Render::SKI_Primitive::Instance3D, fill);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_Primitive::Instance;
    Scaleform::Render::SKI_Primitive::Instance.AddRef(&Scaleform::Render::SKI_Primitive::Instance, fill);
  }
}
