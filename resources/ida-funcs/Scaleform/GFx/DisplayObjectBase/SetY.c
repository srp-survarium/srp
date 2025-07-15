void __thiscall Scaleform::GFx::DisplayObjectBase::SetY(Scaleform::GFx::DisplayObjectBase *this, double y)
{
  float *v3; // eax
  double v4; // [esp+14h] [ebp-28h]
  Scaleform::Render::Matrix2x4<float> v5; // [esp+1Ch] [ebp-20h] BYREF

  v4 = y;
  if ( (HIDWORD(v4) & 0x7FF00000) != 0x7FF00000 || !(HIDWORD(v4) & 0xFFFFF | LODWORD(v4)) )
  {
    if ( y == -INFINITY || y == INFINITY )
      y = 0.0;
    this->SetAcceptAnimMoves(this, 0);
    v3 = (float *)this->GetMatrix(this);
    v5.M[0][0] = *v3;
    v5.M[0][1] = v3[1];
    v5.M[0][2] = v3[2];
    v5.M[0][3] = v3[3];
    v5.M[1][0] = v3[4];
    v5.M[1][1] = v3[5];
    v5.M[1][2] = v3[6];
    v5.M[1][3] = v3[7];
    this->pGeomData->Y = (int)floor(y * 20.0);
    v5.M[1][3] = (float)this->pGeomData->Y;
    if ( Scaleform::Render::Matrix2x4<float>::IsValid(&v5) )
      this->SetMatrix(this, &v5);
  }
}
