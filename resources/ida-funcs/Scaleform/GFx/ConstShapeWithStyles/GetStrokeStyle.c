void __thiscall Scaleform::GFx::ConstShapeWithStyles::GetStrokeStyle(
        Scaleform::GFx::ConstShapeWithStyles *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *p)
{
  Scaleform::Render::StrokeStyleType::operator=(
    p,
    (const Scaleform::Render::StrokeStyleType *)&this->Styles[28 * idx - 28 + 8 * this->FillStylesNum]);
}
