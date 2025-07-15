BOOL __thiscall Scaleform::Render::TextMeshProvider::NeedsUpdate(
        Scaleform::Render::TextMeshProvider *this,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        Scaleform::Render::Matrix4x4<float> *m4,
        const Scaleform::Render::Viewport *vp,
        const Scaleform::Render::TextFieldParam *param)
{
  double v6; // st6
  BOOL result; // eax
  float v8; // [esp+Ch] [ebp+8h]
  float v9; // [esp+10h] [ebp+Ch]
  float v10; // [esp+10h] [ebp+Ch]
  float v11; // [esp+10h] [ebp+Ch]

  v8 = Scaleform::Render::TextMeshProvider::calcHeightRatio(m, m4, vp);
  v9 = 0.85000002;
  if ( (param->TextParam.Flags & 1) != 0 )
    v9 = 0.99000001;
  v6 = v9;
  v10 = this->HeightRatio * v9;
  result = 1;
  if ( v10 <= (double)v8 )
  {
    v11 = this->HeightRatio / v6;
    if ( v11 >= (double)v8 )
      return 0;
  }
  return result;
}
