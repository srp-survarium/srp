long double __thiscall Scaleform::Render::Matrix4x4<double>::GetDeterminant(Scaleform::Render::Matrix4x4<double> *this)
{
  long double v3; // [esp+4h] [ebp-8h]
  long double v4; // [esp+4h] [ebp-8h]
  long double v5; // [esp+4h] [ebp-8h]

  v3 = Scaleform::Render::Matrix4x4<double>::GetMinor(this, this, 1u, 2u, 3u, 1u, 2u, 3u) * this->M[0][0];
  v4 = v3 - Scaleform::Render::Matrix4x4<double>::GetMinor(this, this, 1u, 2u, 3u, 0, 2u, 3u) * this->M[0][1];
  v5 = Scaleform::Render::Matrix4x4<double>::GetMinor(this, this, 1u, 2u, 3u, 0, 1u, 3u) * this->M[0][2] + v4;
  return v5 - Scaleform::Render::Matrix4x4<double>::GetMinor(this, this, 1u, 2u, 3u, 0, 1u, 2u) * this->M[0][3];
}
