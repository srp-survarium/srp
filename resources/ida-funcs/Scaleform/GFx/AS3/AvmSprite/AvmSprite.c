void __thiscall Scaleform::GFx::AS3::AvmSprite::AvmSprite(
        Scaleform::GFx::AS3::AvmSprite *this,
        Scaleform::GFx::Sprite *psprite)
{
  Scaleform::GFx::Sprite *v2; // edi
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax
  Scaleform::GFx::DisplayObject *v8; // eax

  v2 = psprite;
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(this, psprite);
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmInteractiveObjBase_vtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable';
  this->MouseOverCnt = 0;
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Flags = 0;
  v2->TabIndex = -1;
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmDisplayObjContainerBase_vtbl *)&Scaleform::GFx::AvmDisplayObjContainerBase::`vftable';
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmSpriteBase_vtbl *)&Scaleform::GFx::AvmSpriteBase::`vftable';
  pDispObj = this->pDispObj;
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS3::AvmSprite_vtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmInteractiveObjBase_vtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AS3::AvmDisplayObjContainer::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmDisplayObjContainerBase_vtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObjContainer'};
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmSpriteBase_vtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable'{for `Scaleform::GFx::AvmSpriteBase'};
  v5 = (*(int (__thiscall **)(Scaleform::GFx::CharacterHandle *))(pDispObj[1].pNameHandle.pObject->RefCount + 40))(pDispObj[1].pNameHandle.pObject);
  this->InitActionsExecuted.BitsCount = v5;
  v6 = (v5 + 7) >> 3;
  psprite = (Scaleform::GFx::Sprite *)323;
  v7 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                            Scaleform::Memory::pGlobalHeap,
                            &this->InitActionsExecuted,
                            v6,
                            &psprite);
  this->InitActionsExecuted.pData = v7;
  memset((int)v7, 0, v6);
  v8 = this->pDispObj;
  this->Flags = 0;
  LOBYTE(v8[2].Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable) &= ~0x20u;
}
