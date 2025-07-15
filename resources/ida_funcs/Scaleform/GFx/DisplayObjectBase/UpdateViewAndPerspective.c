void __thiscall Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // edi
  double x2; // st7
  const Scaleform::Render::Rect<float> *p_VisibleFrameRect; // ebx
  bool v6; // zf
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // eax
  long double FieldOfView; // st6
  long double FocalLength; // st7
  float v10; // [esp+234h] [ebp-80h]
  float y; // [esp+238h] [ebp-7Ch]
  float v12; // [esp+238h] [ebp-7Ch]
  Scaleform::Render::Point<float> projCenter; // [esp+23Ch] [ebp-78h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+244h] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> matPersp; // [esp+274h] [ebp-40h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( pMovieImpl )
  {
    pPerspectiveData = this->pPerspectiveData;
    if ( pPerspectiveData )
    {
      x2 = pMovieImpl->VisibleFrameRect.x2;
      p_VisibleFrameRect = &pMovieImpl->VisibleFrameRect;
      if ( p_VisibleFrameRect->x1 != x2 || p_VisibleFrameRect->y1 != p_VisibleFrameRect->y2 )
      {
        memset((int)&dst, 0, sizeof(dst));
        dst.M[0][0] = 1.0;
        dst.M[1][1] = 1.0;
        dst.M[2][2] = 1.0;
        memset((int)&matPersp, 0, sizeof(matPersp));
        matPersp.M[0][0] = 1.0;
        matPersp.M[1][1] = 1.0;
        matPersp.M[2][2] = 1.0;
        matPersp.M[3][3] = 1.0;
        if ( Scaleform::GFx::NumberUtil::IsNaN(pPerspectiveData->ProjectionCenter.x)
          || Scaleform::GFx::NumberUtil::IsNaN(pPerspectiveData->ProjectionCenter.y) )
        {
          projCenter.x = (p_VisibleFrameRect->x1 + p_VisibleFrameRect->x2) * 0.5;
          projCenter.y = 0.5 * (p_VisibleFrameRect->y2 + p_VisibleFrameRect->y1);
        }
        else
        {
          v6 = this->pGeomData == 0;
          y = pPerspectiveData->ProjectionCenter.y;
          projCenter.x = pPerspectiveData->ProjectionCenter.x;
          projCenter.y = y;
          if ( !v6 )
          {
            pGeomData = this->pGeomData;
            projCenter.x = (double)pGeomData->X + projCenter.x;
            projCenter.y = y + (double)pGeomData->Y;
          }
        }
        if ( 0.0 == pPerspectiveData->FieldOfView )
          FieldOfView = 55.0;
        else
          FieldOfView = pPerspectiveData->FieldOfView;
        if ( 0.0 == pPerspectiveData->FocalLength )
          FocalLength = 0.0;
        else
          FocalLength = pPerspectiveData->FocalLength;
        v10 = FocalLength;
        v12 = FieldOfView;
        Scaleform::GFx::MovieImpl::MakeViewAndPersp3D(&dst, &matPersp, p_VisibleFrameRect, &projCenter, v12, v10, 0);
        this->SetViewMatrix3D(this, &dst);
        this->SetProjectionMatrix3D(this, &matPersp);
      }
    }
  }
}
