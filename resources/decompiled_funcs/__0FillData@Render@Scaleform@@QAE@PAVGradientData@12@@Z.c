void __thiscall Scaleform::Render::FillData::FillData(
        Scaleform::Render::FillData *this,
        Scaleform::Render::GradientData *p)
{
  this->Type = Fill_Gradient;
  this->Color = (unsigned int)p;
  this->PrimFill = PrimFill_Texture_EAlpha;
  this->FillMode.Fill = 3;
  this->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
}
