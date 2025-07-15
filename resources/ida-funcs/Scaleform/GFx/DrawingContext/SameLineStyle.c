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
  float v13[5]; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::RefCountVImpl *v14; // [esp+1Ch] [ebp-8h]
  Scaleform::RefCountVImpl *v15; // [esp+20h] [ebp-4h]
  bool v16; // [esp+30h] [ebp+Ch]

  if ( !this->Shapes.pObject->GetStrokeStyleCount(this->Shapes.pObject) )
    return 0;
  StrokeStyle = this->StrokeStyle;
  if ( !StrokeStyle )
    return 0;
  pObject = this->Shapes.pObject;
  v14 = 0;
  v15 = 0;
  pObject->GetStrokeStyle(pObject, StrokeStyle, (Scaleform::Render::StrokeStyleType *)v13);
  v11 = v14;
  if ( v14 )
  {
    if ( v15 )
    {
      Scaleform::RefCountImpl::Release(v15);
      v11 = v14;
    }
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    return 0;
  }
  v16 = LODWORD(v13[4]) == rgba
     && (int)(v13[0] * 20.0) == (int)(lineWidth * 20.0)
     && LODWORD(v13[2]) == (joins | caps | scaling | hinting)
     && (int)(v13[3] * 20.0) == (int)(20.0 * miterLimit);
  if ( v15 )
  {
    Scaleform::RefCountImpl::Release(v15);
    if ( v14 )
      Scaleform::RefCountImpl::Release(v14);
  }
  return v16;
}
