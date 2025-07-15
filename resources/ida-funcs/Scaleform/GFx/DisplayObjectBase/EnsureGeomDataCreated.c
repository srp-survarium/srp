void __thiscall Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(Scaleform::GFx::DisplayObjectBase *this)
{
  const Scaleform::GFx::DisplayObjectBase::GeomDataType *v2; // eax
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [esp+70h] [ebp-60h] BYREF

  if ( !this->pGeomData )
  {
    geomData.Y = 0;
    geomData.OrigMatrix.M[0][0] = 1.0;
    geomData.X = 0;
    geomData.OrigMatrix.M[0][1] = 0.0;
    geomData.OrigMatrix.M[0][2] = 0.0;
    geomData.OrigMatrix.M[0][3] = 0.0;
    geomData.OrigMatrix.M[1][0] = 0.0;
    geomData.OrigMatrix.M[1][2] = 0.0;
    geomData.OrigMatrix.M[1][3] = 0.0;
    geomData.OrigMatrix.M[1][1] = 1.0;
    geomData.Rotation = 0.0;
    geomData.YScale = 100.0;
    geomData.XScale = 100.0;
    geomData.ZScale = 100.0;
    geomData.YRotation = 0.0;
    geomData.XRotation = 0.0;
    geomData.Z = 0.0;
    v2 = Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData);
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, v2);
  }
}
