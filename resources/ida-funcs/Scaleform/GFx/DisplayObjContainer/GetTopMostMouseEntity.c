int __thiscall Scaleform::GFx::DisplayObjContainer::GetTopMostMouseEntity(
        Scaleform::GFx::DisplayObjContainer *this,
        const Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::Sprite *v4; // edi
  unsigned int v5; // eax
  Scaleform::GFx::DisplayObject *Mask; // eax
  Scaleform::GFx::DisplayObject *v7; // ebx
  const Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  const Scaleform::Render::Matrix2x4<float> *v9; // eax
  Scaleform::Render::Point<float> *v10; // eax
  Scaleform::GFx::Sprite *(__thiscall *GetHitArea)(Scaleform::GFx::DisplayObjContainer *); // eax
  float v13; // ecx
  signed int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  unsigned __int8 AvmObjOffset; // al
  int v19; // eax
  Scaleform::GFx::InteractiveObject *v20; // eax
  unsigned __int8 v21; // al
  int v22; // eax
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  unsigned __int8 v24; // al
  int v25; // eax
  float v26; // eax
  Scaleform::GFx::InteractiveObject *v27; // eax
  Scaleform::GFx::InteractiveObject *pResult; // eax
  char v29; // [esp+17h] [ebp-D1h]
  Scaleform::Render::ScreenToWorld *p_ScreenToWorld; // [esp+18h] [ebp-D0h]
  int v31; // [esp+18h] [ebp-D0h]
  Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> v32; // [esp+1Ch] [ebp-CCh] BYREF
  float y; // [esp+28h] [ebp-C0h]
  Scaleform::GFx::InteractiveObject *v34; // [esp+2Ch] [ebp-BCh]
  Scaleform::Render::Point<float> ptOut; // [esp+30h] [ebp-B8h] BYREF
  Scaleform::Render::Point<float> p; // [esp+38h] [ebp-B0h] BYREF
  Scaleform::Render::Point<float> v37; // [esp+40h] [ebp-A8h] BYREF
  Scaleform::Render::Matrix3x4<float> v38; // [esp+48h] [ebp-A0h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [esp+78h] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> v40; // [esp+A8h] [ebp-40h] BYREF

  v4 = this->GetHitAreaHolder(this);
  v5 = this->Scaleform::GFx::InteractiveObject::Flags >> 11;
  v34 = v4;
  if ( (v5 & 1) != 0 || !this->GetVisible(this) && !v4 || this->IsUsedAsMask(this) )
  {
    pdescr->pResult = 0;
    return 2;
  }
  if ( pdescr->pIgnoreMC == this || !this->IsFocusAllowed(this, this->pASRoot->pMovieImpl, pdescr->ControllerIdx) )
  {
LABEL_19:
    pdescr->pResult = 0;
    return 2;
  }
  if ( !Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(this, &p, pt, 1, 0) )
    return 2;
  Mask = Scaleform::GFx::DisplayObject::GetMask(this);
  v7 = Mask;
  if ( Mask && Mask->IsUsedAsMask(Mask) && (v7->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
  {
    if ( Scaleform::GFx::DisplayObjectBase::Has3D(v7) )
    {
      Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(&result);
      Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(&v40);
      Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v7, &v38);
      p_ScreenToWorld = &this->pASRoot->pMovieImpl->ScreenToWorld;
      if ( v7->GetProjectionMatrix3D(v7, &v40, 0) )
        memcpy((int)&p_ScreenToWorld->MatProj, (const __m128i *)&v40, sizeof(p_ScreenToWorld->MatProj));
      if ( v7->GetViewMatrix3D(v7, &result, 0) )
        memcpy((int)&p_ScreenToWorld->MatView, (const __m128i *)&result, sizeof(p_ScreenToWorld->MatView));
      memcpy((int)&p_ScreenToWorld->MatWorld, (const __m128i *)&v38, sizeof(p_ScreenToWorld->MatWorld));
      Scaleform::Render::ScreenToWorld::GetWorldPoint(p_ScreenToWorld, &ptOut);
    }
    else
    {
      Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>((Scaleform::Render::Matrix2x4<float> *)&v38);
      WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
                      v7,
                      (Scaleform::Render::Matrix2x4<float> *)&result);
      Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&v38, WorldMatrix);
      v9 = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, (Scaleform::Render::Matrix2x4<float> *)&result);
      Scaleform::Render::Matrix2x4<float>::Prepend((Scaleform::Render::Matrix2x4<float> *)&v38, v9);
      v10 = Scaleform::Render::Matrix2x4<float>::Transform((Scaleform::Render::Matrix2x4<float> *)&v38, &v37, &p);
      y = v10->y;
      ptOut.x = v10->x;
      ptOut.y = y;
    }
    if ( !v7->PointTestLocal(v7, &ptOut, 1u) )
      goto LABEL_19;
  }
  memset(&v32, 0, sizeof(v32));
  Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(this, &v32.Data, &p, 1);
  GetHitArea = this->GetHitArea;
  memset(&v38.M[0][3], 0, 13);
  v31 = 2;
  v29 = 0;
  v13 = COERCE_FLOAT((int)GetHitArea(this));
  v14 = this->mDisplayList.DisplayObjectArray.Data.Size - 1;
  y = v13;
  LODWORD(v37.x) = v14;
  if ( v14 < 0 )
  {
LABEL_71:
    if ( v13 == 0.0
      || (pResult = pdescr->pResult) != 0
      && pResult != this
      && SLOBYTE(pResult->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
    {
      if ( v31 == 1 )
      {
        Scaleform::GFx::DisplayObjectBase::TopMostDescr::operator=(
          pdescr,
          (const Scaleform::GFx::DisplayObjectBase::TopMostDescr *)&v38);
        Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>(&v32);
        return 1;
      }
      pdescr->LocalPt = p;
      if ( !v29 )
      {
        pdescr->pResult = 0;
        Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>(&v32);
        return 3;
      }
    }
    else if ( (const Scaleform::GFx::DisplayObject *)LODWORD(v13) != pdescr->pHitArea )
    {
      goto LABEL_48;
    }
LABEL_76:
    pdescr->pResult = this;
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>(&v32);
    return 1;
  }
  LODWORD(ptOut.x) = 12 * v14;
  while ( 1 )
  {
    v15 = *(int *)((char *)&this->mDisplayList.DisplayObjectArray.Data.Data->pCharacter + LODWORD(ptOut.x));
    if ( v32.Data.Size && (!v32.Data.Data[LODWORD(v37.x)] || *(_WORD *)(v15 + 60)) || (*(_BYTE *)(v15 + 62) & 2) != 0 )
      goto LABEL_69;
    v16 = (*(int (__thiscall **)(int, Scaleform::Render::Point<float> *, Scaleform::GFx::DisplayObjectBase::TopMostDescr *))(*(_DWORD *)v15 + 248))(
            v15,
            &p,
            pdescr);
    v17 = v16;
    if ( v16 == 1 )
    {
      if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x2000) != 0 )
        pdescr->pResult = this;
      if ( pdescr->pResult && (pdescr->pResult->Flags & 0x1000) != 0 )
      {
        pdescr->pResult = this;
        v29 = 1;
        goto LABEL_69;
      }
      if ( pdescr->TestAll )
        v17 = 1;
    }
    else if ( v16 == 3 && pdescr->pResult )
    {
      v31 = 1;
      Scaleform::GFx::DisplayObjectBase::TopMostDescr::operator=(
        (Scaleform::GFx::DisplayObjectBase::TopMostDescr *)&v38,
        pdescr);
    }
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v19 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                            + AvmObjOffset)
                                          + 4))(
              (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + 4 * AvmObjOffset);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v19 + 52))(v19) )
        break;
    }
    v20 = v34;
    if ( v34 )
    {
      if ( pdescr->TestAll )
        goto LABEL_50;
      v21 = v34->AvmObjOffset;
      if ( v21 )
      {
        v22 = (*(int (__thiscall **)(int))(*((_DWORD *)&v34->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v21)
                                         + 4))((int)v34 + 4 * v21);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v22 + 52))(v22) )
          break;
      }
    }
    if ( v17 == 1 )
    {
      if ( pdescr->TestAll )
        goto LABEL_78;
      if ( pdescr->pResult != this )
      {
        pParent = pdescr->pResult->pParent;
        if ( !pParent || !pParent->GetVisible(pParent) )
          goto LABEL_48;
LABEL_78:
        Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>(&v32);
        return 1;
      }
    }
LABEL_69:
    LODWORD(ptOut.x) -= 12;
    --LODWORD(v37.x);
    if ( v37.x < 0.0 )
    {
      v13 = y;
      goto LABEL_71;
    }
  }
  v20 = v34;
LABEL_50:
  if ( v17 != 1 && v31 != 1 )
  {
LABEL_67:
    if ( v17 == 1 && pdescr->TestAll )
      goto LABEL_78;
    goto LABEL_69;
  }
  if ( v20 )
  {
    if ( pdescr->TestAll
      || (v24 = v20->AvmObjOffset) != 0
      && (v25 = (*(int (__thiscall **)(int))(*((_DWORD *)&v34->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + v24)
                                           + 4))((int)v34 + 4 * v24),
          (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v25 + 52))(v25)) )
    {
      pdescr->pResult = v34;
      pdescr->pHitArea = this;
      goto LABEL_78;
    }
  }
  if ( this->pASRoot->AVMVersion != 1 )
  {
    if ( y != 0.0 )
    {
      v27 = pdescr->pResult;
      if ( !pdescr->pResult
        || v27 == this
        || SLOBYTE(v27->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >= 0 )
      {
LABEL_61:
        if ( (const Scaleform::GFx::DisplayObject *)LODWORD(y) == pdescr->pHitArea )
          goto LABEL_76;
        pdescr->pResult = 0;
        v31 = 2;
        goto LABEL_69;
      }
    }
    goto LABEL_67;
  }
  if ( y == 0.0 )
    goto LABEL_76;
  v26 = y;
  while ( 1 )
  {
    v26 = *(float *)(LODWORD(v26) + 32);
    if ( v26 == 0.0 )
      break;
    if ( (Scaleform::GFx::DisplayObjContainer *)LODWORD(v26) == this )
      goto LABEL_61;
  }
LABEL_48:
  pdescr->pResult = 0;
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>(&v32);
  return 2;
}
