BOOL __thiscall Scaleform::Render::Cxform::operator==(
        Scaleform::Render::Cxform *this,
        const Scaleform::Render::Cxform *x)
{
  return x->M[0][0] == this->M[0][0]
      && x->M[0][1] == this->M[0][1]
      && x->M[0][2] == this->M[0][2]
      && x->M[0][3] == this->M[0][3]
      && x->M[1][0] == this->M[1][0]
      && x->M[1][1] == this->M[1][1]
      && x->M[1][2] == this->M[1][2]
      && x->M[1][3] == this->M[1][3];
}
