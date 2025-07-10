Scaleform::GFx::DisplayObjectBase::GeomDataType *__thiscall Scaleform::GFx::DisplayObjectBase::GetGeomData(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::DisplayObjectBase::GeomDataType *geomData)
{
  float *v3; // edi
  float *v4; // eax
  double v5; // st7
  Scaleform::GFx::DisplayObjectBase::GeomDataType *result; // eax

  if ( this->pGeomData )
  {
    Scaleform::GFx::DisplayObjectBase::GeomDataType::GeomDataType(geomData, this->pGeomData);
    return geomData;
  }
  else
  {
    v3 = (float *)this->GetMatrix(this);
    geomData->X = (int)v3[3];
    geomData->Y = (int)v3[7];
    geomData->XScale = sqrt(v3[4] * v3[4] + *v3 * *v3) * 100.0;
    geomData->YScale = sqrt(v3[5] * v3[5] + v3[1] * v3[1]) * 100.0;
    geomData->Rotation = atan2(v3[4], *v3) * 180.0 / 3.141592653589793;
    v4 = (float *)this->GetMatrix(this);
    geomData->OrigMatrix.M[0][0] = *v4;
    geomData->OrigMatrix.M[0][1] = v4[1];
    geomData->OrigMatrix.M[0][2] = v4[2];
    geomData->OrigMatrix.M[0][3] = v4[3];
    geomData->OrigMatrix.M[1][0] = v4[4];
    geomData->OrigMatrix.M[1][1] = v4[5];
    geomData->OrigMatrix.M[1][2] = v4[6];
    v5 = v4[7];
    result = geomData;
    geomData->OrigMatrix.M[1][3] = v5;
  }
  return result;
}
