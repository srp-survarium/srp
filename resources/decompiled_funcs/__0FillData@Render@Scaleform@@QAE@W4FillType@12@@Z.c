void __thiscall Scaleform::Render::FillData::FillData(
        Scaleform::Render::FillData *this,
        Scaleform::Render::FillType type)
{
  this->Type = type;
  this->Color = 0;
  this->PrimFill = PrimFill_VColor_EAlpha;
  this->FillMode.Fill = 0;
  this->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
  if ( type == Fill_Mask )
  {
    this->PrimFill = PrimFill_Mask;
    this->pVFormat = &Scaleform::Render::VertexXY16i::Format;
  }
}
