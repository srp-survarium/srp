void __thiscall Scaleform::GFx::DrawingContext::SetLineStyle(
        Scaleform::GFx::DrawingContext *this,
        float lineWidth,
        unsigned int rgba,
        bool hinting,
        unsigned int scaling,
        unsigned int caps,
        unsigned int joins,
        float miterLimit)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // ebp
  Scaleform::Render::StrokeStyleType *p_mLineStyle; // ebx
  unsigned int Size; // eax
  Scaleform::Render::StrokeStyleType *Data; // edx
  unsigned int v13; // eax

  pObject = this->Shapes.pObject;
  this->mLineStyle.Width = lineWidth;
  this->mLineStyle.Miter = miterLimit;
  p_mLineStyle = &this->mLineStyle;
  this->mLineStyle.Units = 0.050000001;
  this->mLineStyle.Color = rgba;
  this->mLineStyle.Flags = joins | caps | scaling | hinting;
  Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pObject->StrokeStyles.Data,
    &pObject->StrokeStyles,
    pObject->StrokeStyles.Data.Size + 1);
  Size = pObject->StrokeStyles.Data.Size;
  Data = pObject->StrokeStyles.Data.Data;
  if ( &Data[Size] != (Scaleform::Render::StrokeStyleType *)28 )
    Scaleform::Render::StrokeStyleType::StrokeStyleType(&Data[Size - 1], p_mLineStyle);
  v13 = pObject->StrokeStyles.Data.Size;
  this->States |= 2u;
  this->StrokeStyle = v13;
}
