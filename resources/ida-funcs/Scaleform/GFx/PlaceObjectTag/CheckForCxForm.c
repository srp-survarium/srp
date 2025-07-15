void __thiscall Scaleform::GFx::PlaceObjectTag::CheckForCxForm(
        Scaleform::GFx::PlaceObjectTag *this,
        unsigned int dataSz)
{
  Scaleform::GFx::StreamContext v3; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> pm; // [esp+20h] [ebp-20h] BYREF

  pm.M[0][0] = 1.0;
  pm.M[0][1] = 0.0;
  pm.M[0][2] = 0.0;
  pm.M[0][3] = 0.0;
  pm.M[1][0] = 0.0;
  v3.pData = this->pData;
  pm.M[1][2] = 0.0;
  v3.DataSize = -1;
  pm.M[1][3] = 0.0;
  v3.CurBitIndex = 0;
  v3.CurByteIndex = 4;
  pm.M[1][1] = 1.0;
  Scaleform::GFx::StreamContext::ReadMatrix(&v3, &pm);
  this->HasCxForm = v3.CurByteIndex < dataSz - 1;
}
