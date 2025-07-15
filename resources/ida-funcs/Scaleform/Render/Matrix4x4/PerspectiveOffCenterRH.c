void __thiscall Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterRH(
        Scaleform::Render::Matrix4x4<float> *this,
        float focalLength,
        float viewMinX,
        float viewMaxX,
        float viewMinY,
        float viewMaxY,
        float fNearZ,
        float fFarZ)
{
  double v9; // st7
  double v10; // st5
  double v11; // st3
  float v12; // [esp+1Ch] [ebp+18h]

  memset((int)this, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  v9 = fNearZ;
  v12 = fNearZ - fFarZ;
  v10 = focalLength + focalLength;
  v11 = viewMaxX - viewMinX;
  this->M[0][0] = v10 / v11;
  this->M[1][1] = v10 / (viewMaxY - viewMinY);
  this->M[2][2] = fFarZ / v12;
  this->M[3][2] = -1.0;
  this->M[2][3] = fFarZ * v9 / v12;
  this->M[0][2] = (viewMinX + viewMaxX) / v11;
  this->M[1][2] = (viewMinY + viewMaxY) / (viewMaxY - viewMinY);
}
