void __thiscall Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(
        Scaleform::GFx::DisplayObjectBase::GeomDataType *this,
        const Scaleform::GFx::DisplayObjectBase::GeomDataType *__that)
{
  *this = *__that;
}


void __thiscall Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(
        Scaleform::GFx::DisplayObjectBase::GeomDataType *this)
{
  this->OrigMatrix.M[0][0] = 1.0;
  this->OrigMatrix.M[0][1] = 0.0;
  this->OrigMatrix.M[0][2] = 0.0;
  this->OrigMatrix.M[0][3] = 0.0;
  this->OrigMatrix.M[1][0] = 0.0;
  this->OrigMatrix.M[1][2] = 0.0;
  this->OrigMatrix.M[1][3] = 0.0;
  this->OrigMatrix.M[1][1] = 1.0;
  this->Y = 0;
  this->X = 0;
  this->Rotation = 0.0;
  this->YScale = 100.0;
  this->XScale = 100.0;
  this->ZScale = 100.0;
  this->YRotation = 0.0;
  this->XRotation = 0.0;
  this->Z = 0.0;
}
