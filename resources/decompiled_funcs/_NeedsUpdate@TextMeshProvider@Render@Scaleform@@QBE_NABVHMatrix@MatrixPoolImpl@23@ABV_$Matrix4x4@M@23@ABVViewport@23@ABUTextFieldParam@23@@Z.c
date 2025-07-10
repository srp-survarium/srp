BOOL __thiscall Scaleform::Render::TextMeshProvider::NeedsUpdate(
        Scaleform::Render::TextMeshProvider *this,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        Scaleform::Render::Matrix4x4<float> *m4,
        const Scaleform::Render::Viewport *vp,
        const Scaleform::Render::TextFieldParam *param)
{
  double v6; // st6
  BOOL result; // eax
  float heightRatio; // [esp+Ch] [ebp+8h]
  float vpa; // [esp+10h] [ebp+Ch]
  float vpb; // [esp+10h] [ebp+Ch]
  float vpc; // [esp+10h] [ebp+Ch]

  heightRatio = Scaleform::Render::TextMeshProvider::calcHeightRatio(m, m4, vp);
  vpa = 0.85000002;
  if ( (param->TextParam.Flags & 1) != 0 )
    vpa = 0.99000001;
  v6 = vpa;
  vpb = this->HeightRatio * vpa;
  result = 1;
  if ( vpb <= (double)heightRatio )
  {
    vpc = this->HeightRatio / v6;
    if ( vpc >= (double)heightRatio )
      return 0;
  }
  return result;
}
