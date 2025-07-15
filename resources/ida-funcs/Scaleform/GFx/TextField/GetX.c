double __thiscall Scaleform::GFx::TextField::GetX(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [esp+60h] [ebp-60h] BYREF

  pgeomData.OrigMatrix.M[0][0] = 1.0;
  pgeomData.Y = 0;
  pgeomData.OrigMatrix.M[0][1] = 0.0;
  pgeomData.X = 0;
  pgeomData.OrigMatrix.M[0][2] = 0.0;
  pgeomData.OrigMatrix.M[0][3] = 0.0;
  pgeomData.OrigMatrix.M[1][0] = 0.0;
  pgeomData.OrigMatrix.M[1][2] = 0.0;
  pgeomData.OrigMatrix.M[1][3] = 0.0;
  pgeomData.OrigMatrix.M[1][1] = 1.0;
  pgeomData.Rotation = 0.0;
  pgeomData.YScale = 100.0;
  pgeomData.XScale = 100.0;
  pgeomData.ZScale = 100.0;
  pgeomData.YRotation = 0.0;
  pgeomData.XRotation = 0.0;
  pgeomData.Z = 0.0;
  Scaleform::GFx::TextField::UpdateAndGetGeomData(this, &pgeomData, 0);
  return (double)pgeomData.X * 0.05;
}
