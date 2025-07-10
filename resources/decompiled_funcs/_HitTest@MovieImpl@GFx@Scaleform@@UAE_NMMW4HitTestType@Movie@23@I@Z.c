char __thiscall Scaleform::GFx::MovieImpl::HitTest(
        Scaleform::GFx::MovieImpl *this,
        float x,
        float y,
        Scaleform::GFx::Movie::HitTestType testCond,
        float controllerIdx)
{
  double v6; // st7
  double v7; // st6
  unsigned int Size; // eax
  double v9; // st7
  double v10; // st6
  Scaleform::GFx::InteractiveObject *pObject; // esi
  Scaleform::GFx::InteractiveObject_vtbl *v12; // eax
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // eax
  bool v14; // al
  Scaleform::GFx::ASMovieRootBase *v15; // ecx
  Scaleform::GFx::DisplayObjectBase::TopMostResult (__thiscall *GetTopMostMouseEntity)(Scaleform::GFx::DisplayObjectBase *, const Scaleform::Render::Point<float> *, Scaleform::GFx::DisplayObjectBase::TopMostDescr *); // eax
  float v18; // esi
  unsigned __int8 v19; // al
  int v20; // eax
  float v21; // [esp+10Ch] [ebp-44h]
  float v22; // [esp+10Ch] [ebp-44h]
  float v23; // [esp+10Ch] [ebp-44h]
  float v24; // [esp+10Ch] [ebp-44h]
  unsigned int v25; // [esp+10Ch] [ebp-44h]
  Scaleform::Render::Point<float> p; // [esp+110h] [ebp-40h] BYREF
  Scaleform::Render::Point<float> result; // [esp+118h] [ebp-38h] BYREF
  float v28[4]; // [esp+120h] [ebp-30h] BYREF
  float v29; // [esp+130h] [ebp-20h] BYREF
  float v30; // [esp+134h] [ebp-1Ch]
  float v31; // [esp+138h] [ebp-18h]
  float v32; // [esp+13Ch] [ebp-14h]
  float v33; // [esp+140h] [ebp-10h]
  float v34; // [esp+144h] [ebp-Ch]
  float v35; // [esp+148h] [ebp-8h]
  float v36; // [esp+14Ch] [ebp-4h]

  p.x = x;
  p.y = y;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
  v21 = this->ViewOffsetY * 20.0;
  v6 = result.y - v21;
  v22 = this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1;
  p.x = v6 / v22 * 2.0 - 1.0;
  v23 = 20.0 * this->ViewOffsetX;
  v7 = result.x - v23;
  v24 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
  this->ScreenToWorld.Sx = v7 / v24 * 2.0 - 1.0;
  this->ScreenToWorld.Sy = -p.x;
  Size = this->MovieLevels.Data.Size;
  v25 = Size;
  if ( !Size )
    return 0;
  v9 = 1.0;
  v10 = 0.0;
  while ( 2 )
  {
    pObject = this->MovieLevels.Data.Data[Size - 1].pSprite.pObject;
    v29 = v9;
    v12 = pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    v34 = v29;
    GetBounds = v12->GetBounds;
    v30 = v10;
    v31 = v30;
    v32 = v30;
    v33 = v30;
    v35 = v30;
    v36 = v30;
    GetBounds(pObject, (Scaleform::Render::Rect<float> *)v28, (const Scaleform::Render::Matrix2x4<float> *)&v29);
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(pObject, &p, &result, 0, 0);
    if ( (v28[2] < (double)p.x || v28[0] > (double)p.x || v28[3] < (double)p.y || v28[1] > (double)p.y)
      && !pObject->Has3D(pObject) )
    {
      goto LABEL_23;
    }
    switch ( testCond )
    {
      case HitTest_Bounds:
        v14 = pObject->PointTestLocal(pObject, &p, 0);
        goto LABEL_22;
      case HitTest_Shapes:
        v14 = pObject->PointTestLocal(pObject, &p, 1u);
        goto LABEL_22;
      case HitTest_ButtonEvents:
        v15 = this->pASMovieRoot.pObject;
        v32 = 0.0;
        v33 = 0.0;
        LOBYTE(v35) = 0;
        v34 = controllerIdx;
        if ( v15->AVMVersion == 1 )
        {
          if ( pObject->GetTopMostMouseEntity(pObject, &p, (Scaleform::GFx::DisplayObjectBase::TopMostDescr *)&v29) == TopMost_Found )
            return 1;
LABEL_23:
          if ( !--v25 )
            return 0;
          Size = v25;
          v10 = 0.0;
          v9 = 1.0;
          continue;
        }
        GetTopMostMouseEntity = pObject->GetTopMostMouseEntity;
        LOBYTE(v35) = 1;
        if ( GetTopMostMouseEntity(pObject, &p, (Scaleform::GFx::DisplayObjectBase::TopMostDescr *)&v29) != TopMost_Found )
          goto LABEL_23;
        v18 = v29;
        if ( v29 == 0.0 )
          goto LABEL_23;
        while ( 1 )
        {
          v19 = *(_BYTE *)(LODWORD(v18) + 65);
          if ( v19 )
          {
            v20 = (*(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(v18) + 4 * v19) + 4))(LODWORD(v18) + 4 * v19);
            if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v20 + 52))(v20) )
              return 1;
          }
          v18 = *(float *)(LODWORD(v18) + 32);
          if ( v18 == 0.0 )
            goto LABEL_23;
        }
      case HitTest_ShapesNoInvisible:
        v14 = pObject->PointTestLocal(pObject, &p, 3u);
LABEL_22:
        if ( !v14 )
          goto LABEL_23;
        return 1;
      default:
        goto LABEL_23;
    }
  }
}
