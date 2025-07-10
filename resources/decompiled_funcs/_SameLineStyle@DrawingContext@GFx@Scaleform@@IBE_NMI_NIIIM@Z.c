bool __thiscall Scaleform::GFx::DrawingContext::SameLineStyle(
        Scaleform::GFx::DrawingContext *this,
        float lineWidth,
        unsigned int rgba,
        bool hinting,
        unsigned int scaling,
        unsigned int caps,
        unsigned int joins,
        float miterLimit)
{
  unsigned int StrokeStyle; // eax
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // ecx
  Scaleform::RefCountVImpl *v11; // eax
  Scaleform::Render::StrokeStyleType ls; // [esp+8h] [ebp-1Ch] BYREF
  bool hintinga; // [esp+30h] [ebp+Ch]

  if ( !this->Shapes.pObject->GetStrokeStyleCount(this->Shapes.pObject) )
    return 0;
  StrokeStyle = this->StrokeStyle;
  if ( !StrokeStyle )
    return 0;
  pObject = this->Shapes.pObject;
  ls.pFill.pObject = 0;
  ls.pDashes.pObject = 0;
  pObject->GetStrokeStyle(pObject, StrokeStyle, &ls);
  v11 = (Scaleform::RefCountVImpl *)ls.pFill.pObject;
  if ( ls.pFill.pObject )
  {
    if ( ls.pDashes.pObject )
    {
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)ls.pDashes.pObject);
      v11 = (Scaleform::RefCountVImpl *)ls.pFill.pObject;
    }
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    return 0;
  }
  hintinga = ls.Color == rgba
          && (int)(ls.Width * 20.0) == (int)(lineWidth * 20.0)
          && ls.Flags == (joins | caps | scaling | hinting)
          && (int)(ls.Miter * 20.0) == (int)(20.0 * miterLimit);
  if ( ls.pDashes.pObject )
  {
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)ls.pDashes.pObject);
    if ( ls.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)ls.pFill.pObject);
  }
  return hintinga;
}
