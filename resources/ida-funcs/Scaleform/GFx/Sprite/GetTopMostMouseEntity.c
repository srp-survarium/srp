int __thiscall Scaleform::GFx::Sprite::GetTopMostMouseEntity(
        Scaleform::GFx::Sprite *this,
        const Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  int TopMostMouseEntity; // ebp
  Scaleform::GFx::Sprite *v5; // edi
  unsigned __int8 v6; // al
  int v7; // eax
  unsigned __int8 v8; // al
  int v9; // eax
  unsigned __int8 AvmObjOffset; // al
  int v11; // eax
  Scaleform::GFx::Sprite *v13; // eax
  Scaleform::GFx::Sprite *pParent; // ecx
  Scaleform::GFx::InteractiveObject *pResult; // ecx

  TopMostMouseEntity = Scaleform::GFx::DisplayObjContainer::GetTopMostMouseEntity(this, pt, pdescr);
  if ( TopMostMouseEntity == 3 && this->pDrawingAPI.pObject )
  {
    if ( (v5 = this->GetHitAreaHolder(this), (v6 = this->AvmObjOffset) != 0)
      && (v7 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                               + v6)
                                             + 4))(
                 (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
               + 4 * v6),
          (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 52))(v7))
      || v5
      && (pdescr->TestAll
       || (v8 = v5->AvmObjOffset) != 0
       && (v9 = (*(int (__thiscall **)(int))(*((_DWORD *)&v5->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + v8)
                                           + 4))((int)v5 + 4 * v8),
           (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 52))(v9))) )
    {
      if ( Scaleform::GFx::DrawingContext::DefPointTestLocal(
             this->pDrawingAPI.pObject,
             (int)pdescr,
             &pdescr->LocalPt,
             1,
             this) )
      {
        if ( v5 )
        {
          if ( pdescr->TestAll
            || (AvmObjOffset = v5->AvmObjOffset) != 0
            && (v11 = (*(int (__thiscall **)(int))(*((_DWORD *)&v5->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                   + AvmObjOffset)
                                                 + 4))((int)v5 + 4 * AvmObjOffset),
                (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 52))(v11)) )
          {
            pdescr->pResult = v5;
            pdescr->pHitArea = this;
            return 1;
          }
        }
        v13 = this->GetHitArea(this);
        if ( this->pASRoot->AVMVersion == 1 )
        {
          if ( v13 )
          {
            pParent = v13;
            while ( 1 )
            {
              pParent = (Scaleform::GFx::Sprite *)pParent->pParent;
              if ( !pParent )
                goto LABEL_21;
              if ( pParent == this )
                goto LABEL_26;
            }
          }
          goto LABEL_27;
        }
        if ( !v13 )
        {
LABEL_27:
          pdescr->pResult = this;
          return 1;
        }
        pResult = pdescr->pResult;
        if ( !pdescr->pResult
          || pResult == this
          || SLOBYTE(pResult->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >= 0 )
        {
LABEL_26:
          if ( v13 != pdescr->pHitArea )
          {
LABEL_21:
            pdescr->pResult = 0;
            return 2;
          }
          goto LABEL_27;
        }
      }
    }
  }
  return TopMostMouseEntity;
}
