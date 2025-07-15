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
  Scaleform::GFx::InteractiveObject_vtbl *v12; // edx
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // edx
  Scaleform::AmpStats *v14; // edi
  void (__thiscall **v15)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v16; // rax
  bool v18; // al
  Scaleform::GFx::ASMovieRootBase *v19; // ecx
  Scaleform::GFx::DisplayObjectBase::TopMostResult (__thiscall *GetTopMostMouseEntity)(Scaleform::GFx::DisplayObjectBase *, const Scaleform::Render::Point<float> *, Scaleform::GFx::DisplayObjectBase::TopMostDescr *); // eax
  float v21; // esi
  unsigned __int8 v22; // al
  int v23; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpStats *v27; // edi
  void (__thiscall **v28)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v29; // rax
  float v30; // [esp+10h] [ebp-54h]
  float v31; // [esp+10h] [ebp-54h]
  float v32; // [esp+10h] [ebp-54h]
  float v33; // [esp+10h] [ebp-54h]
  unsigned int v34; // [esp+10h] [ebp-54h]
  Scaleform::Render::Point<float> p; // [esp+14h] [ebp-50h] BYREF
  Scaleform::Render::Point<float> result; // [esp+1Ch] [ebp-48h] BYREF
  Scaleform::AmpFunctionTimer v37; // [esp+24h] [ebp-40h] BYREF
  float v38[4]; // [esp+34h] [ebp-30h] BYREF
  float v39; // [esp+44h] [ebp-20h] BYREF
  float v40; // [esp+48h] [ebp-1Ch]
  float v41; // [esp+4Ch] [ebp-18h]
  float v42; // [esp+50h] [ebp-14h]
  float v43; // [esp+54h] [ebp-10h]
  float v44; // [esp+58h] [ebp-Ch]
  float v45; // [esp+5Ch] [ebp-8h]
  float v46; // [esp+60h] [ebp-4h]

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v37,
    this->AdvanceStats.pObject,
    "MovieImpl::HitTest",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  p.x = x;
  p.y = y;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(&this->ViewportMatrix, &result, &p);
  v30 = this->ViewOffsetY * 20.0;
  v6 = result.y - v30;
  v31 = this->VisibleFrameRect.y2 - this->VisibleFrameRect.y1;
  p.x = v6 / v31 * 2.0 - 1.0;
  v32 = 20.0 * this->ViewOffsetX;
  v7 = result.x - v32;
  v33 = this->VisibleFrameRect.x2 - this->VisibleFrameRect.x1;
  this->ScreenToWorld.Sx = v7 / v33 * 2.0 - 1.0;
  this->ScreenToWorld.Sy = -p.x;
  Size = this->MovieLevels.Data.Size;
  v34 = Size;
  if ( !Size )
  {
LABEL_27:
    Stats = v37.Stats;
    if ( v37.Stats )
    {
      p_NativePopCallstack = &v37.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v37.StartTicks),
        (ProfileTicks - v37.StartTicks) >> 32);
    }
    return 0;
  }
  v9 = 1.0;
  v10 = 0.0;
  while ( 2 )
  {
    pObject = this->MovieLevels.Data.Data[Size - 1].pSprite.pObject;
    v39 = v9;
    v12 = pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    v44 = v39;
    GetBounds = v12->GetBounds;
    v40 = v10;
    v41 = v40;
    v42 = v40;
    v43 = v40;
    v45 = v40;
    v46 = v40;
    GetBounds(pObject, (Scaleform::Render::Rect<float> *)v38, (const Scaleform::Render::Matrix2x4<float> *)&v39);
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(pObject, &p, &result, 0, 0);
    if ( (v38[2] < (double)p.x || v38[0] > (double)p.x || v38[3] < (double)p.y || v38[1] > (double)p.y)
      && !pObject->Has3D(pObject) )
    {
      goto LABEL_26;
    }
    switch ( testCond )
    {
      case HitTest_Bounds:
        if ( !pObject->PointTestLocal(pObject, &p, 0) )
          goto LABEL_26;
        goto LABEL_11;
      case HitTest_Shapes:
        v18 = pObject->PointTestLocal(pObject, &p, 1u);
        goto LABEL_25;
      case HitTest_ButtonEvents:
        v19 = this->pASMovieRoot.pObject;
        v42 = 0.0;
        v43 = 0.0;
        LOBYTE(v45) = 0;
        v44 = controllerIdx;
        if ( v19->AVMVersion == 1 )
        {
          if ( pObject->GetTopMostMouseEntity(pObject, &p, (Scaleform::GFx::DisplayObjectBase::TopMostDescr *)&v39) == TopMost_Found )
          {
            Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v37);
            return 1;
          }
LABEL_26:
          if ( !--v34 )
            goto LABEL_27;
          Size = v34;
          v10 = 0.0;
          v9 = 1.0;
          continue;
        }
        GetTopMostMouseEntity = pObject->GetTopMostMouseEntity;
        LOBYTE(v45) = 1;
        if ( GetTopMostMouseEntity(pObject, &p, (Scaleform::GFx::DisplayObjectBase::TopMostDescr *)&v39) != TopMost_Found )
          goto LABEL_26;
        v21 = v39;
        if ( v39 == 0.0 )
          goto LABEL_26;
        while ( 1 )
        {
          v22 = *(_BYTE *)(LODWORD(v21) + 65);
          if ( v22 )
          {
            v23 = (*(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(v21) + 4 * v22) + 4))(LODWORD(v21) + 4 * v22);
            if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v23 + 52))(v23) )
              break;
          }
          v21 = *(float *)(LODWORD(v21) + 32);
          if ( v21 == 0.0 )
            goto LABEL_26;
        }
LABEL_11:
        v14 = v37.Stats;
        if ( v37.Stats )
        {
          v15 = &v37.Stats->NativePopCallstack;
          v16 = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v15)(
            v14,
            v16 - LODWORD(v37.StartTicks),
            (v16 - v37.StartTicks) >> 32);
        }
        return 1;
      case HitTest_ShapesNoInvisible:
        v18 = pObject->PointTestLocal(pObject, &p, 3u);
LABEL_25:
        if ( !v18 )
          goto LABEL_26;
        v27 = v37.Stats;
        if ( v37.Stats )
        {
          v28 = &v37.Stats->NativePopCallstack;
          v29 = Scaleform::Timer::GetProfileTicks();
          ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v28)(
            v27,
            v29 - LODWORD(v37.StartTicks),
            (v29 - v37.StartTicks) >> 32);
        }
        return 1;
      default:
        goto LABEL_26;
    }
  }
}
