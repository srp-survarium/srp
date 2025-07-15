void __thiscall Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // edi
  double x2; // st7
  const Scaleform::Render::Rect<float> *p_VisibleFrameRect; // ebx
  bool v6; // zf
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // eax
  long double v8; // st6
  long double v9; // st7
  float focalLength; // [esp+1Ch] [ebp-80h]
  float y; // [esp+20h] [ebp-7Ch]
  float fieldOfView; // [esp+20h] [ebp-7Ch]
  Scaleform::Render::Point<float> projCenter; // [esp+24h] [ebp-78h] BYREF
  Scaleform::Render::Matrix3x4<float> matView; // [esp+2Ch] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> matPersp; // [esp+5Ch] [ebp-40h] BYREF

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
        memset((int)&matView, 0, sizeof(matView));
        matView.M[0][0] = 1.0;
        matView.M[1][1] = 1.0;
        matView.M[2][2] = 1.0;
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
          v8 = 55.0;
        else
          v8 = pPerspectiveData->FieldOfView;
        if ( 0.0 == pPerspectiveData->FocalLength )
          v9 = 0.0;
        else
          v9 = pPerspectiveData->FocalLength;
        focalLength = v9;
        fieldOfView = v8;
        Scaleform::GFx::MovieImpl::MakeViewAndPersp3D(
          &matView,
          &matPersp,
          p_VisibleFrameRect,
          &projCenter,
          fieldOfView,
          focalLength,
          0);
        this->SetViewMatrix3D(this, &matView);
        this->SetProjectionMatrix3D(this, &matPersp);
      }
    }
  }
}
