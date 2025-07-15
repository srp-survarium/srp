void __thiscall Scaleform::Render::MatrixState::SetUserMatrix(
        Scaleform::Render::MatrixState *this,
        const Scaleform::Render::Matrix2x4<float> *user)
{
  Scaleform::Render::Matrix2x4<float> *p_User; // edi
  Scaleform::Render::Matrix2x4<float> *p_View2D; // ebx
  const Scaleform::Render::Matrix2x4<float> *v5; // eax
  Scaleform::Render::Matrix2x4<float> result; // [esp+10h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v7; // [esp+30h] [ebp-20h] BYREF

  this->UVPOChanged = 1;
  this->User = *user;
  p_User = &this->User;
  p_View2D = &this->View2D;
  v5 = Scaleform::Render::operator*(&result, &this->User, &this->Orient2D);
  this->UserView = *Scaleform::Render::operator*(&v7, &this->View2D, v5);
  this->User3D = *p_User;
  this->User3D.M[0][3] = p_View2D->M[0][0] / p_User->M[0][0] * this->User3D.M[0][3];
  this->User3D.M[1][3] = this->View2D.M[1][1] / this->User.M[1][1] * this->User3D.M[1][3];
}
