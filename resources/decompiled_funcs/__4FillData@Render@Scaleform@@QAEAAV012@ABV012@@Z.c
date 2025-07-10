Scaleform::Render::FillData *__thiscall Scaleform::Render::FillData::operator=(
        Scaleform::Render::FillData *this,
        const Scaleform::Render::FillData *__that)
{
  Scaleform::Render::FillData *result; // eax

  result = this;
  this->Type = __that->Type;
  this->Color = __that->Color;
  this->Color = __that->Color;
  this->Color = __that->Color;
  this->PrimFill = __that->PrimFill;
  this->FillMode.Fill = __that->FillMode.Fill;
  this->pVFormat = __that->pVFormat;
  return result;
}
