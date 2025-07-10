void __thiscall Scaleform::Render::ScreenToWorld::ScreenToWorld(Scaleform::Render::ScreenToWorld *this)
{
  float *p_MatProj; // edi

  this->Sx = 3.4028235e38;
  this->Sy = 3.4028235e38;
  p_MatProj = (float *)&this->MatProj;
  this->LastX = 3.4028235e38;
  this->LastY = 3.4028235e38;
  memset((int)&this->MatProj, 0, sizeof(this->MatProj));
  *p_MatProj = 1.0;
  p_MatProj[5] = 1.0;
  p_MatProj[10] = 1.0;
  p_MatProj[15] = 1.0;
  memset((int)&this->MatView, 0, sizeof(this->MatView));
  this->MatView.M[0][0] = 1.0;
  this->MatView.M[1][1] = 1.0;
  this->MatView.M[2][2] = 1.0;
  memset((int)&this->MatWorld, 0, sizeof(this->MatWorld));
  this->MatWorld.M[0][0] = 1.0;
  this->MatWorld.M[1][1] = 1.0;
  this->MatWorld.M[2][2] = 1.0;
  memset((int)&this->MatInvProj, 0, sizeof(this->MatInvProj));
  this->MatInvProj.M[0][0] = 1.0;
  this->MatInvProj.M[1][1] = 1.0;
  this->MatInvProj.M[2][2] = 1.0;
  this->MatInvProj.M[3][3] = 1.0;
}
