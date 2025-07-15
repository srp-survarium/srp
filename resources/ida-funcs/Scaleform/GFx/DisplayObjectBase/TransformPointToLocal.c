void __thiscall Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *p,
        const Scaleform::Render::Point<float> *pt,
        bool bPtInParentSpace,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  bool v6; // al
  Scaleform::Render::Matrix2x4<float> *v7; // eax
  Scaleform::Render::ScreenToWorld *p_ScreenToWorld; // edi
  _BYTE pmat[48]; // [esp+10h] [ebp-A0h] BYREF
  Scaleform::Render::Matrix3x4<float> v10; // [esp+40h] [ebp-70h] BYREF
  unsigned __int8 src[64]; // [esp+70h] [ebp-40h] BYREF

  if ( bPtInParentSpace )
    v6 = Scaleform::GFx::DisplayObjectBase::Has3D(this);
  else
    v6 = Scaleform::GFx::DisplayObjectBase::Is3D(this, 1);
  if ( v6 )
  {
    memset((int)pmat, 0, sizeof(pmat));
    *(float *)pmat = 1.0;
    *(float *)&pmat[20] = 1.0;
    *(float *)&pmat[40] = 1.0;
    memset((int)src, 0, sizeof(src));
    *(float *)src = 1.0;
    *(float *)&src[20] = 1.0;
    *(float *)&src[40] = 1.0;
    *(float *)&src[60] = 1.0;
    memset((int)&v10, 0, sizeof(v10));
    v10.M[0][0] = 1.0;
    v10.M[1][1] = 1.0;
    v10.M[2][2] = 1.0;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(this, &v10);
    p_ScreenToWorld = &this->pASRoot->pMovieImpl->ScreenToWorld;
    if ( this->GetProjectionMatrix3D(this, (Scaleform::Render::Matrix4x4<float> *)src, 1) )
      memcpy((int)&p_ScreenToWorld->MatProj, (const __m128i *)src, sizeof(p_ScreenToWorld->MatProj));
    if ( this->GetViewMatrix3D(this, (Scaleform::Render::Matrix3x4<float> *)pmat, 1) )
      memcpy((int)&p_ScreenToWorld->MatView, (const __m128i *)pmat, sizeof(p_ScreenToWorld->MatView));
    memcpy((int)&p_ScreenToWorld->MatWorld, (const __m128i *)&v10, sizeof(p_ScreenToWorld->MatWorld));
    Scaleform::Render::ScreenToWorld::GetWorldPoint(p_ScreenToWorld, p);
  }
  else if ( bPtInParentSpace )
  {
    if ( mat )
    {
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(mat, p, pt);
    }
    else
    {
      v7 = (Scaleform::Render::Matrix2x4<float> *)this->GetMatrix(this);
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(v7, p, pt);
    }
  }
  else
  {
    *(float *)pmat = 1.0;
    *(float *)&pmat[4] = 0.0;
    *(float *)&pmat[8] = 0.0;
    *(float *)&pmat[12] = 0.0;
    *(float *)&pmat[16] = 0.0;
    *(float *)&pmat[24] = 0.0;
    *(float *)&pmat[28] = 0.0;
    *(float *)&pmat[20] = 1.0;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, (Scaleform::Render::Matrix2x4<float> *)pmat);
    Scaleform::Render::Matrix2x4<float>::TransformByInverse((Scaleform::Render::Matrix2x4<float> *)pmat, p, pt);
  }
}
