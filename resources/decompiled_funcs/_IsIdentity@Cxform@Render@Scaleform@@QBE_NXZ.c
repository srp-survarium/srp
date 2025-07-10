BOOL __thiscall Scaleform::Render::Cxform::IsIdentity(Scaleform::Render::Cxform *this)
{
  return 1.0 == this->M[0][0]
      && 1.0 == this->M[0][1]
      && 1.0 == this->M[0][2]
      && 1.0 == this->M[0][3]
      && 0.0 == this->M[1][0]
      && 0.0 == this->M[1][1]
      && 0.0 == this->M[1][2]
      && 0.0 == this->M[1][3];
}
