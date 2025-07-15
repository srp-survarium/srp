void __userpurge Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::hitTestPoint(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        bool *result,
        long double x,
        long double y,
        bool shapeFlag)
{
  Scaleform::GFx::DisplayObject *pObject; // ecx
  Scaleform::GFx::DisplayObject *v9; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  double v11; // st7
  double v12; // st6
  Scaleform::GFx::DisplayObject *v13; // ecx
  const __m128i *WorldMatrix3D; // eax
  Scaleform::GFx::DisplayObject *v15; // ecx
  Scaleform::GFx::DisplayObject *v16; // ebx
  float v18; // [esp+4ACh] [ebp-C8h]
  float v19; // [esp+4ACh] [ebp-C8h]
  float v20; // [esp+4ACh] [ebp-C8h]
  float v21; // [esp+4ACh] [ebp-C8h]
  float v22; // [esp+4ACh] [ebp-C8h]
  float v23; // [esp+4ACh] [ebp-C8h]
  bool v24; // [esp+4B0h] [ebp-C4h]
  Scaleform::Render::Point<float> p; // [esp+4B4h] [ebp-C0h] BYREF
  Scaleform::Render::Point<float> ptOut; // [esp+4BCh] [ebp-B8h] BYREF
  _BYTE pmat[56]; // [esp+4C4h] [ebp-B0h] BYREF
  float v28; // [esp+4FCh] [ebp-78h]
  float v29; // [esp+500h] [ebp-74h]
  _BYTE v30[72]; // [esp+504h] [ebp-70h] BYREF
  int v31; // [esp+54Ch] [ebp-28h] BYREF

  *(float *)pmat = 1.0;
  *(float *)&pmat[4] = 0.0;
  *(float *)&pmat[8] = 0.0;
  *(float *)&pmat[12] = 0.0;
  *result = 0;
  pObject = this->pDispObj.pObject;
  *(float *)&pmat[16] = 0.0;
  *(float *)&pmat[24] = 0.0;
  *(float *)&pmat[28] = 0.0;
  *(float *)&pmat[20] = 1.0;
  pObject->GetBounds(
    pObject,
    (Scaleform::Render::Rect<float> *)&pmat[48],
    (const Scaleform::Render::Matrix2x4<float> *)pmat);
  if ( *(float *)&pmat[48] != v28 || *(float *)&pmat[52] != v29 )
  {
    v18 = x;
    p.x = v18 * 20.0;
    v19 = y;
    p.y = 20.0 * v19;
    v9 = this->pDispObj.pObject;
    pMovieImpl = v9->pASRoot->pMovieImpl;
    if ( pMovieImpl && Scaleform::GFx::DisplayObjectBase::Is3D(v9, 1) )
    {
      v20 = pMovieImpl->ViewOffsetY * 20.0;
      v11 = p.y - v20;
      v21 = pMovieImpl->VisibleFrameRect.y2 - pMovieImpl->VisibleFrameRect.y1;
      ptOut.x = v11 / v21 * 2.0 - 1.0;
      v22 = 20.0 * pMovieImpl->ViewOffsetX;
      v12 = p.x - v22;
      v23 = pMovieImpl->VisibleFrameRect.x2 - pMovieImpl->VisibleFrameRect.x1;
      pMovieImpl->ScreenToWorld.Sx = v12 / v23 * 2.0 - 1.0;
      pMovieImpl->ScreenToWorld.Sy = -ptOut.x;
      memset((int)pmat, 0, 48);
      *(float *)pmat = 1.0;
      *(float *)&pmat[20] = 1.0;
      *(float *)&pmat[40] = 1.0;
      memset((int)v30, 0, 64);
      v13 = this->pDispObj.pObject;
      *(float *)v30 = 1.0;
      *(float *)&v30[20] = 1.0;
      *(float *)&v30[40] = 1.0;
      *(float *)&v30[60] = 1.0;
      if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::DisplayObject *, _BYTE *, _DWORD, int, int))v13->GetProjectionMatrix3D)(
             v13,
             v30,
             0,
             a2,
             a3) )
      {
        memcpy(
          (int)&pMovieImpl->ScreenToWorld.MatProj,
          (const __m128i *)&v30[8],
          sizeof(pMovieImpl->ScreenToWorld.MatProj));
      }
      if ( this->pDispObj.pObject->GetViewMatrix3D(
             this->pDispObj.pObject,
             (Scaleform::Render::Matrix3x4<float> *)&pmat[8],
             0) )
      {
        memcpy(
          (int)&pMovieImpl->ScreenToWorld.MatView,
          (const __m128i *)&pmat[8],
          sizeof(pMovieImpl->ScreenToWorld.MatView));
      }
      WorldMatrix3D = (const __m128i *)Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(
                                         this->pDispObj.pObject,
                                         (Scaleform::Render::Matrix3x4<float> *)&v31);
      memcpy((int)&pMovieImpl->ScreenToWorld.MatWorld, WorldMatrix3D, sizeof(pMovieImpl->ScreenToWorld.MatWorld));
      Scaleform::Render::ScreenToWorld::GetWorldPoint(&pMovieImpl->ScreenToWorld, &ptOut);
      *result = this->pDispObj.pObject->PointTestLocal(this->pDispObj.pObject, &ptOut, LODWORD(p.y));
    }
    else
    {
      v15 = this->pDispObj.pObject;
      *(float *)pmat = 1.0;
      *(float *)&pmat[4] = 0.0;
      *(float *)&pmat[8] = 0.0;
      *(float *)&pmat[12] = 0.0;
      *(float *)&pmat[16] = 0.0;
      *(float *)&pmat[24] = 0.0;
      *(float *)&pmat[28] = 0.0;
      *(float *)&pmat[20] = 1.0;
      Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v15, (Scaleform::Render::Matrix2x4<float> *)pmat);
      Scaleform::Render::Matrix2x4<float>::TransformByInverse((Scaleform::Render::Matrix2x4<float> *)pmat, &ptOut, &p);
      v16 = this->pDispObj.pObject;
      if ( (v16->Scaleform::GFx::DisplayObjectBase::Flags & 1) != 0 )
        goto LABEL_14;
      if ( !Scaleform::Render::Rect<float>::Contains((Scaleform::Render::Rect<float> *)&pmat[48], &ptOut) )
        return;
      if ( shapeFlag )
      {
LABEL_14:
        v24 = shapeFlag;
        *result = v16->PointTestLocal(v16, &ptOut, v24);
      }
      else
      {
        *result = 1;
      }
    }
  }
}
