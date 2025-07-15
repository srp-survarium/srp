Scaleform::Render::Matrix2x4<double> *__thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::GetMatrix(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        Scaleform::Render::Matrix2x4<double> *result)
{
  Scaleform::Render::Matrix2x4<double> *v2; // eax

  v2 = result;
  result->M[0][2] = 0.0;
  result->M[1][2] = 0.0;
  result->M[0][0] = this->a;
  result->M[1][0] = this->b;
  result->M[0][1] = this->c;
  result->M[1][1] = this->d;
  result->M[0][3] = this->tx;
  result->M[1][3] = this->ty;
  return v2;
}
