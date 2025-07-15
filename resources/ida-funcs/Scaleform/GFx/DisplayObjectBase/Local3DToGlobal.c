Scaleform::Render::Point<float> *__thiscall Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *result,
        const Scaleform::Render::Point3<float> *ptIn)
{
  Scaleform::GFx::DisplayObjectBase_vtbl *v4; // edx
  bool (__thiscall *GetViewMatrix3D)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix3x4<float> *, bool); // edx
  Scaleform::GFx::DisplayObjectBase_vtbl *v6; // edx
  bool (__thiscall *GetProjectionMatrix3D)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix4x4<float> *, bool); // edx
  Scaleform::GFx::ASMovieRootBase *pASRoot; // edx
  Scaleform::GFx::ASMovieRootBase *v9; // esi
  float *pMovieImpl; // esi
  Scaleform::Render::Point<float> *v11; // eax
  float v12; // [esp+14h] [ebp-174h]
  float v13; // [esp+14h] [ebp-174h]
  float x; // [esp+14h] [ebp-174h]
  float y; // [esp+18h] [ebp-170h]
  Scaleform::Render::Point3<float> resulta; // [esp+1Ch] [ebp-16Ch] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [esp+28h] [ebp-160h] BYREF
  _DWORD v18[4]; // [esp+64h] [ebp-124h] BYREF
  int v19; // [esp+74h] [ebp-114h]
  int v20; // [esp+78h] [ebp-110h]
  int v21; // [esp+7Ch] [ebp-10Ch]
  float v22; // [esp+80h] [ebp-108h]
  float v23; // [esp+84h] [ebp-104h]
  float v24; // [esp+88h] [ebp-100h]
  int v25; // [esp+8Ch] [ebp-FCh]
  float v26; // [esp+90h] [ebp-F8h]
  float v27; // [esp+94h] [ebp-F4h]
  Scaleform::Render::Matrix3x4<float> pmat; // [esp+98h] [ebp-F0h] BYREF
  Scaleform::Render::Matrix4x4<float> m1; // [esp+C8h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix4x4<float> v30; // [esp+108h] [ebp-80h] BYREF
  Scaleform::Render::Matrix4x4<float> v31; // [esp+148h] [ebp-40h] BYREF

  if ( Scaleform::GFx::DisplayObjectBase::Is3D(this, 1) )
  {
    memset((int)&m2, 0, sizeof(m2));
    v4 = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    m2.M[0][0] = 1.0;
    GetViewMatrix3D = v4->GetViewMatrix3D;
    m2.M[1][1] = 1.0;
    m2.M[2][2] = 1.0;
    GetViewMatrix3D(this, &m2, 1);
    memset((int)&m1, 0, sizeof(m1));
    v6 = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    m1.M[0][0] = 1.0;
    GetProjectionMatrix3D = v6->GetProjectionMatrix3D;
    m1.M[1][1] = 1.0;
    m1.M[2][2] = 1.0;
    m1.M[3][3] = 1.0;
    GetProjectionMatrix3D(this, &m1, 1);
    memset((int)&pmat, 0, sizeof(pmat));
    pmat.M[0][0] = 1.0;
    pmat.M[1][1] = 1.0;
    pmat.M[2][2] = 1.0;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(this, &pmat);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v30, &m1, &m2);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v31, &v30, &pmat);
    Scaleform::Render::Matrix4x4<float>::TransformHomogeneous(&v31, &resulta, ptIn);
    v27 = 1.0;
    memset(v18, 0, sizeof(v18));
    v20 = 1;
    v19 = 1;
    v24 = 0.0;
    v23 = 0.0;
    v22 = 0.0;
    v21 = 0;
    v25 = 0;
    pASRoot = this->pASRoot;
    v26 = 1.0;
    pASRoot->pMovieImpl->GetViewport(pASRoot->pMovieImpl, (Scaleform::GFx::Viewport *)v18);
    v9 = this->pASRoot;
    resulta.x = (resulta.x + 1.0) * (double)v19 * 0.5;
    resulta.y = 0.5 * ((1.0 - resulta.y) * (double)v20);
    if ( v9 )
      pMovieImpl = (float *)v9->pMovieImpl;
    else
      pMovieImpl = 0;
    if ( pMovieImpl )
    {
      v12 = pMovieImpl[34] * resulta.x + pMovieImpl[36];
      resulta.x = v12 * 20.0;
      v13 = pMovieImpl[35] * resulta.y + pMovieImpl[37];
      resulta.y = 20.0 * v13;
    }
    v11 = result;
    result->x = resulta.x;
    result->y = resulta.y;
  }
  else
  {
    x = ptIn->x;
    y = ptIn->y;
    m2.M[0][0] = 1.0;
    m2.M[0][1] = 0.0;
    m2.M[0][2] = 0.0;
    m2.M[0][3] = 0.0;
    m2.M[1][0] = 0.0;
    m2.M[1][2] = 0.0;
    m2.M[1][3] = 0.0;
    m2.M[1][1] = 1.0;
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, (Scaleform::Render::Matrix2x4<float> *)&m2);
    v11 = result;
    result->x = m2.M[0][0] * x + m2.M[0][1] * y + m2.M[0][3];
    result->y = x * m2.M[1][0] + y * m2.M[1][1] + m2.M[1][3];
  }
  return v11;
}
