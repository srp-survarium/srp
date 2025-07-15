Scaleform::GFx::DisplayObjectBase::TopMostResult __thiscall Scaleform::GFx::TextField::GetTopMostMouseEntity(
        Scaleform::GFx::TextField *this,
        const Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // ebx
  Scaleform::GFx::TextField *pParent; // esi
  Scaleform::GFx::DisplayObject *Mask; // eax
  Scaleform::GFx::DisplayObject *v6; // edi
  const Scaleform::Render::Matrix2x4<float> *WorldMatrix; // eax
  const Scaleform::Render::Matrix2x4<float> *v8; // eax
  Scaleform::Render::Point<float> *v9; // eax
  Scaleform::Render::ScreenToWorld *p_ScreenToWorld; // ebx
  Scaleform::GFx::DisplayObjectBase::TopMostResult v11; // eax
  Scaleform::Render::Text::DocView *pObject; // ecx
  unsigned __int8 AvmObjOffset; // al
  int v14; // eax
  Scaleform::GFx::TextField *pIgnoreMC; // eax
  Scaleform::Render::Point<float> p; // [esp+28h] [ebp-BCh] BYREF
  float y; // [esp+30h] [ebp-B4h]
  Scaleform::Render::Point<float> ptOut; // [esp+34h] [ebp-B0h] BYREF
  Scaleform::Render::Point<float> v19; // [esp+3Ch] [ebp-A8h] BYREF
  Scaleform::Render::Matrix3x4<float> v20; // [esp+44h] [ebp-A0h] BYREF
  Scaleform::Render::Matrix3x4<float> result; // [esp+74h] [ebp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> v22; // [esp+A4h] [ebp-40h] BYREF

  v3 = pdescr;
  pParent = this;
  pdescr->pResult = 0;
  if ( (this->pDef.pObject->Flags & 0x1000) != 0
    || (this->Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0
    || !this->GetVisible(this)
    || pdescr->pIgnoreMC == pParent )
  {
    return 2;
  }
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(pParent, &p, pt, 1, 0);
  Mask = Scaleform::GFx::DisplayObject::GetMask(pParent);
  v6 = Mask;
  if ( Mask && Mask->IsUsedAsMask(Mask) && (v6->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
  {
    if ( Scaleform::GFx::DisplayObjectBase::Has3D(v6) )
    {
      Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(&result);
      Scaleform::Render::Matrix4x4<float>::Matrix4x4<float>(&v22);
      Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v6, &v20);
      p_ScreenToWorld = &pParent->pASRoot->pMovieImpl->ScreenToWorld;
      if ( v6->GetProjectionMatrix3D(v6, &v22, 0) )
        memcpy((int)&p_ScreenToWorld->MatProj, (const __m128i *)&v22, sizeof(p_ScreenToWorld->MatProj));
      if ( v6->GetViewMatrix3D(v6, &result, 0) )
        memcpy((int)&p_ScreenToWorld->MatView, (const __m128i *)&result, sizeof(p_ScreenToWorld->MatView));
      memcpy((int)&p_ScreenToWorld->MatWorld, (const __m128i *)&v20, sizeof(p_ScreenToWorld->MatWorld));
      Scaleform::Render::ScreenToWorld::GetWorldPoint(p_ScreenToWorld, &ptOut);
      v3 = pdescr;
    }
    else
    {
      Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>((Scaleform::Render::Matrix2x4<float> *)&v20);
      WorldMatrix = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
                      v6,
                      (Scaleform::Render::Matrix2x4<float> *)&result);
      Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&v20, WorldMatrix);
      v8 = Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, (Scaleform::Render::Matrix2x4<float> *)&result);
      Scaleform::Render::Matrix2x4<float>::Prepend((Scaleform::Render::Matrix2x4<float> *)&v20, v8);
      v9 = Scaleform::Render::Matrix2x4<float>::Transform((Scaleform::Render::Matrix2x4<float> *)&v20, &v19, &p);
      y = v9->y;
      ptOut.x = v9->x;
      ptOut.y = y;
    }
    if ( !v6->PointTestLocal(v6, &ptOut, 1u) )
    {
      v3->pResult = 0;
      return 2;
    }
  }
  if ( pParent->ClipDepth || !pParent->PointTestLocal(pParent, &p, 1u) )
    goto LABEL_34;
  if ( !v3->TestAll && !Scaleform::GFx::TextField::IsSelectable(pParent) )
  {
    if ( Scaleform::GFx::TextField::IsSelectable(pParent)
      || (pParent->Flags & 2) == 0
      || (pObject = pParent->pDocument.pObject, (pObject->pDocument.pObject->RTFlags & 1) == 0)
      || !Scaleform::Render::Text::DocView::IsUrlAtPoint(pObject, p.x, p.y, 0) )
    {
      pParent = (Scaleform::GFx::TextField *)pParent->pParent;
      if ( pParent )
      {
        while ( (pParent->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
               & 0x400) != 0 )
        {
          if ( v3->TestAll
            || (AvmObjOffset = pParent->AvmObjOffset) != 0
            && (v14 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                   + AvmObjOffset)
                                                 + 4))((int)pParent + 4 * AvmObjOffset),
                (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v14 + 52))(v14)) )
          {
            pIgnoreMC = (Scaleform::GFx::TextField *)v3->pIgnoreMC;
            if ( !pIgnoreMC || pParent != pIgnoreMC )
              goto LABEL_35;
          }
          pParent = (Scaleform::GFx::TextField *)pParent->pParent;
          if ( !pParent )
            break;
        }
      }
LABEL_34:
      v11 = TopMost_Continue;
      v3->LocalPt = p;
      v3->pResult = 0;
      return v11;
    }
  }
LABEL_35:
  v3->pResult = pParent;
  return 1;
}
