void __thiscall Scaleform::Render::SortKey::SortKey(
        Scaleform::Render::SortKey *this,
        Scaleform::Render::SortKeyTextType __formal,
        bool is3D)
{
  this->Data = 0;
  if ( is3D )
  {
    this->pImpl = &Scaleform::Render::SKI_TextPrimitive::Instance3D;
    Scaleform::Render::SKI_TextPrimitive::Instance3D.AddRef(&Scaleform::Render::SKI_TextPrimitive::Instance3D, 0);
  }
  else
  {
    this->pImpl = &Scaleform::Render::SKI_TextPrimitive::Instance;
    Scaleform::Render::SKI_TextPrimitive::Instance.AddRef(&Scaleform::Render::SKI_TextPrimitive::Instance, 0);
  }
}
