unsigned int __thiscall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::Render::StrokeStyleType *stroke)
{
  Scaleform::ArrayLH<Scaleform::Render::StrokeStyleType,2,Scaleform::ArrayDefaultPolicy> *p_StrokeStyles; // esi
  unsigned int Size; // eax

  p_StrokeStyles = &this->StrokeStyles;
  Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->StrokeStyles.Data,
    &this->StrokeStyles,
    this->StrokeStyles.Data.Size + 1);
  Size = p_StrokeStyles->Data.Size;
  if ( &p_StrokeStyles->Data.Data[Size] != (Scaleform::Render::StrokeStyleType *)28 )
    Scaleform::Render::StrokeStyleType::StrokeStyleType(&p_StrokeStyles->Data.Data[Size - 1], stroke);
  return this->StrokeStyles.Data.Size;
}
