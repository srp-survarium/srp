const Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::Matrix2x4<float>::operator=(
        Scaleform::Render::Matrix2x4<float> *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::Matrix2x4<float>::SetMatrix(this, m);
  return this;
}


const Scaleform::Render::Matrix2x4<double> *__thiscall Scaleform::Render::Matrix2x4<double>::operator=(
        Scaleform::Render::Matrix2x4<double> *this,
        const Scaleform::Render::Matrix2x4<double> *m)
{
  const Scaleform::Render::Matrix2x4<double> *result; // eax

  result = this;
  *this = *m;
  return result;
}
