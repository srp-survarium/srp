const Scaleform::Render::Matrix4x4<float> *__thiscall Scaleform::Render::TransformArgs::GetViewProj(
        Scaleform::Render::TransformArgs *this)
{
  const Scaleform::Render::ViewMatrix3DState *viewState; // eax
  const Scaleform::Render::ProjectionMatrix3DState *projState; // edi
  Scaleform::Render::Matrix4x4<float> *p_ViewProj; // edi
  Scaleform::Render::Matrix3x4<float> dst; // [esp+10h] [ebp-B0h] BYREF
  Scaleform::Render::Matrix4x4<float> m1; // [esp+40h] [ebp-80h] BYREF
  Scaleform::Render::Matrix4x4<float> v8; // [esp+80h] [ebp-40h] BYREF

  if ( this->bRecomputeViewProj )
  {
    viewState = this->viewState;
    if ( viewState )
    {
      projState = this->projState;
      if ( projState )
      {
        memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)(viewState->DataValue + 16), sizeof(dst));
        memcpy((unsigned __int8 *)&m1, (unsigned __int8 *)(projState->DataValue + 16), sizeof(m1));
        Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v8, &m1, &dst);
        memcpy((unsigned __int8 *)&this->ViewProj, (unsigned __int8 *)&v8, sizeof(this->ViewProj));
        this->bRecomputeViewProj = 0;
        return &this->ViewProj;
      }
    }
    p_ViewProj = &this->ViewProj;
    memset((int)&this->ViewProj, 0, sizeof(this->ViewProj));
    p_ViewProj->M[0][0] = 1.0;
    this->ViewProj.M[1][1] = 1.0;
    this->ViewProj.M[2][2] = 1.0;
    this->ViewProj.M[3][3] = 1.0;
    this->bRecomputeViewProj = 0;
  }
  return &this->ViewProj;
}
