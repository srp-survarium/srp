void __thiscall Scaleform::GFx::AS3::AvmSprite::CreateChildren(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::Sprite *pDispObj; // esi
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  Scaleform::GFx::AS3::AvmInteractiveObj *AvmParent; // eax
  unsigned __int8 AvmObjOffset; // al
  int v6; // eax

  if ( (this->Flags & 4) == 0 )
  {
    pDispObj = (Scaleform::GFx::Sprite *)this->pDispObj;
    if ( !Scaleform::GFx::InteractiveObject::IsInPlayList(pDispObj) )
    {
      pParent = pDispObj->pParent;
      if ( pParent )
      {
        if ( Scaleform::GFx::InteractiveObject::IsInPlayList(pParent) )
        {
          if ( pDispObj->pParent )
          {
            AvmParent = Scaleform::GFx::AS3::AvmDisplayObj::GetAvmParent(this);
            Scaleform::GFx::AS3::AvmInteractiveObj::InsertChildToPlayList(AvmParent, pDispObj);
          }
          else
          {
            Scaleform::GFx::InteractiveObject::AddToPlayList(pDispObj);
          }
          Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(pDispObj);
        }
      }
    }
    if ( (pDispObj->Flags & 8) == 0 )
      Scaleform::GFx::Sprite::DefaultOnEventLoad(pDispObj);
    AvmObjOffset = pDispObj->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v6 = (*(int (__thiscall **)(int))(*((_DWORD *)&pDispObj->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                        + AvmObjOffset)
                                      + 8))((int)pDispObj + 4 * AvmObjOffset);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 112))(v6, 0);
    }
    this->Flags |= 4u;
  }
}
