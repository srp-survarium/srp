void __thiscall Scaleform::GFx::MovieImpl::ResetViewportMatrix(Scaleform::GFx::MovieImpl *this)
{
  float v1; // [esp+8h] [ebp-28h]
  float v2; // [esp+8h] [ebp-28h]
  float v3; // [esp+8h] [ebp-28h]
  float v4; // [esp+Ch] [ebp-24h]
  float v5; // [esp+1Ch] [ebp-14h]
  float v6; // [esp+2Ch] [ebp-4h]

  v5 = -this->VisibleFrameRect.x1;
  v6 = -this->VisibleFrameRect.y1;
  this->ViewportMatrix.M[0][0] = 1.0;
  this->ViewportMatrix.M[0][1] = 0.0;
  this->ViewportMatrix.M[0][2] = 0.0;
  this->ViewportMatrix.M[0][3] = v5;
  this->ViewportMatrix.M[1][0] = 0.0;
  this->ViewportMatrix.M[1][2] = 0.0;
  this->ViewportMatrix.M[1][1] = 1.0;
  this->ViewportMatrix.M[1][3] = v6;
  v1 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
  v4 = (double)this->mViewport.Width / v1;
  v2 = this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1;
  v3 = (double)this->mViewport.Height / v2;
  this->ViewportMatrix.M[0][0] = this->ViewportMatrix.M[0][0] * v4;
  this->ViewportMatrix.M[0][1] = this->ViewportMatrix.M[0][1] * v4;
  this->ViewportMatrix.M[0][2] = this->ViewportMatrix.M[0][2] * v4;
  this->ViewportMatrix.M[0][3] = v4 * this->ViewportMatrix.M[0][3];
  this->ViewportMatrix.M[1][0] = this->ViewportMatrix.M[1][0] * v3;
  this->ViewportMatrix.M[1][1] = this->ViewportMatrix.M[1][1] * v3;
  this->ViewportMatrix.M[1][2] = v3 * this->ViewportMatrix.M[1][2];
  this->ViewportMatrix.M[1][3] = v3 * this->ViewportMatrix.M[1][3];
}
