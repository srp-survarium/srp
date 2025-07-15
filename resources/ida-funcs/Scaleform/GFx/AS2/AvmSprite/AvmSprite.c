void __thiscall Scaleform::GFx::AS2::AvmSprite::AvmSprite(
        Scaleform::GFx::AS2::AvmSprite *this,
        Scaleform::GFx::Sprite *psprite)
{
  unsigned int v3; // eax
  unsigned int v4; // ebp
  Scaleform::GFx::AS2::Object *ActualPrototype; // eax
  Scaleform::GFx::AS2::Object *v6; // edi
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax

  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  this->pUserDataHolder = 0;
  this->pProto.pObject = 0;
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmSprite_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pDispObj = psprite;
  this->EventHandlers.mHash.pTable = 0;
  Scaleform::GFx::DisplayObjectBase::BindAvmObj(psprite, this);
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmSpriteBase_vtbl *)&Scaleform::GFx::AvmSpriteBase::`vftable';
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS2::AvmSprite_vtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AvmSpriteBase::Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AvmSpriteBase_vtbl *)&Scaleform::GFx::AS2::AvmSprite::`vftable';
  Scaleform::GFx::AS2::Environment::Environment(&this->ASEnvironment);
  this->Level = -1;
  this->ASMovieClipObj.pObject = 0;
  this->InitActionsExecuted.Data.Data = 0;
  this->InitActionsExecuted.Data.Size = 0;
  this->InitActionsExecuted.Data.Policy.Capacity = 0;
  this->TabChildren.Value = 0;
  Scaleform::GFx::AS2::Environment::SetTargetOnConstruct(&this->ASEnvironment, psprite);
  LOBYTE(this->pDispObj[1].pIndXFormData) &= ~0x20u;
  this->pDispObj->Flags |= 0x800u;
  v3 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)this->pDispObj[1].CreateFrame + 40))(this->pDispObj[1].CreateFrame);
  v4 = v3;
  if ( v3 >= this->InitActionsExecuted.Data.Size )
  {
    if ( v3 >= this->InitActionsExecuted.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &this->InitActionsExecuted.Data,
        &this->InitActionsExecuted,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->InitActionsExecuted.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->InitActionsExecuted.Data,
      &this->InitActionsExecuted,
      v3);
  }
  this->InitActionsExecuted.Data.Size = v4;
  memset((int)this->InitActionsExecuted.Data.Data, 0, v4);
  ActualPrototype = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
                      (Scaleform::GFx::AS2::GlobalContext *)this->pDispObj->pASRoot[2].RefCount,
                      &this->ASEnvironment,
                      ASBuiltin_MovieClip);
  v6 = ActualPrototype;
  if ( ActualPrototype )
    ActualPrototype->RefCount = (ActualPrototype->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = v6;
}
