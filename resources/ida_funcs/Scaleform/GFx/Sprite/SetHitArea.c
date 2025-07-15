void __thiscall Scaleform::GFx::Sprite::SetHitArea(Scaleform::GFx::Sprite *this, Scaleform::GFx::Sprite *phitArea)
{
  Scaleform::GFx::Sprite *v3; // eax
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::CharacterHandle *v5; // ebp
  Scaleform::GFx::CharacterHandle *v6; // esi
  Scaleform::GFx::CharacterHandle *v7; // esi
  unsigned __int8 AvmObjOffset; // al
  int v9; // eax

  v3 = this->GetHitArea(this);
  if ( v3 )
    v3->pHitAreaHolder = 0;
  if ( phitArea )
  {
    pObject = phitArea->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(phitArea);
    v5 = pObject;
    if ( pObject )
      ++pObject->RefCount;
    v6 = this->pHitAreaHandle.pObject;
    if ( v6 )
    {
      if ( --v6->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v6);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
      }
    }
    this->pHitAreaHandle.pObject = v5;
    phitArea->pHitAreaHolder = this;
  }
  else
  {
    v7 = this->pHitAreaHandle.pObject;
    if ( v7 )
    {
      if ( --v7->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v7);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
      }
    }
    this->pHitAreaHandle.pObject = 0;
  }
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v9 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 8))(
           (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    (*(void (__thiscall **)(int, Scaleform::GFx::Sprite *))(*(_DWORD *)v9 + 132))(v9, phitArea);
  }
}
