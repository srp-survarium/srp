void __thiscall Scaleform::Render::Matrix4x4<float>::OrthoOffCenterRH(
        Scaleform::Render::Matrix4x4<float> *this,
        float viewMinX,
        float viewMaxX,
        float viewMinY,
        float viewMaxY,
        float fNearZ,
        float fFarZ)
{
  double v8; // st7
  float dz; // [esp+18h] [ebp+14h]

  memset((int)this, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  v8 = fNearZ;
  dz = fNearZ - fFarZ;
  this->M[0][0] = 2.0 / (viewMaxX - viewMinX);
  this->M[1][1] = 2.0 / (viewMaxY - viewMinY);
  this->M[2][2] = 1.0 / dz;
  this->M[2][3] = v8 / dz;
  this->M[3][3] = 1.0;
  this->M[0][3] = (viewMinX + viewMaxX) / (viewMinX - viewMaxX);
  this->M[1][3] = (viewMinY + viewMaxY) / (viewMinY - viewMaxY);
}
