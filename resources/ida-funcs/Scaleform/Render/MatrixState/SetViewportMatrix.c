void __thiscall Scaleform::Render::MatrixState::SetViewportMatrix(
        Scaleform::Render::MatrixState *this,
        const Scaleform::Render::Matrix2x4<float> *vp)
{
  Scaleform::Render::Matrix2x4<float> *p_View2D; // edi
  const Scaleform::Render::Matrix2x4<float> *v4; // eax
  Scaleform::Render::Matrix2x4<float> result; // [esp+10h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v6; // [esp+30h] [ebp-20h] BYREF

  this->View2D = *vp;
  p_View2D = &this->View2D;
  v4 = Scaleform::Render::operator*(&result, &this->User, &this->Orient2D);
  this->UserView = *Scaleform::Render::operator*(&v6, p_View2D, v4);
}
