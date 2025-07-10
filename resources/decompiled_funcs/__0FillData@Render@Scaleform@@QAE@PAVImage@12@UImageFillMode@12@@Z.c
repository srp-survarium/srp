void __thiscall Scaleform::Render::FillData::FillData(
        Scaleform::Render::FillData *this,
        Scaleform::Render::Image *p,
        Scaleform::Render::ImageFillMode fm)
{
  this->Type = Fill_Image;
  this->Color = (unsigned int)p;
  this->PrimFill = PrimFill_Texture_EAlpha;
  this->FillMode = fm;
  this->pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
}
