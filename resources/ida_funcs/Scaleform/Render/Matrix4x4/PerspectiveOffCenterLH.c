void __thiscall Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterLH(
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

  memset((int)this, 0, sizeof(Scaleform::Render::Matrix4x4<float>));
  v9 = focalLength + focalLength;
  this->M[0][0] = v9 / (viewMaxX - viewMinX);
  this->M[1][1] = v9 / (viewMaxY - viewMinY);
  this->M[2][2] = fFarZ / (fFarZ - fNearZ);
  this->M[3][2] = 1.0;
  this->M[2][3] = fNearZ * fFarZ / (fNearZ - fFarZ);
  this->M[0][2] = (viewMinX + viewMaxX) / (viewMinX - viewMaxX);
  this->M[1][2] = (viewMinY + viewMaxY) / (viewMinY - viewMaxY);
}
