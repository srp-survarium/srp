void __userpurge Scaleform::GFx::AS3::MovieRoot::ActionEntry::Execute(
        Scaleform::GFx::AS3::MovieRoot::ActionEntry *this@<ecx>,
        int a2@<ebp>,
        Scaleform::GFx::AS3::MovieRoot *proot)
{
  Scaleform::GFx::DisplayObject *pObject; // eax
  __int32 v5; // ecx
  __int32 v6; // ecx
  void (__cdecl *CFunction)(const Scaleform::GFx::AS3::MovieRoot::ActionEntry *); // eax
  int AvmObjOffset; // edx
  Scaleform::GFx::AS3::Object *v9; // ecx
  Scaleform::GFx::DisplayObject_vtbl **v10; // eax
  Scaleform::GFx::AS3::Object *v11; // eax
  Scaleform::GFx::AS3::ASVM *v12; // ecx
  Scaleform::GFx::AS3::ASVM *v13; // ecx
  Scaleform::GFx::AS3::Value result; // [esp+4h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value _this; // [esp+14h] [ebp-10h] BYREF

  pObject = this->pCharacter.pObject;
  if ( pObject && (pObject->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
  {
    v5 = this->Type - 1;
    if ( this->Type == Entry_Buffer )
    {
      Scaleform::GFx::AS3::AvmDisplayObj::FireEvent(
        (Scaleform::GFx::AS3::AvmDisplayObj *)(&pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + pObject->AvmObjOffset),
        a2,
        &this->mEventId);
    }
    else
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 == 1 )
        {
          CFunction = this->CFunction;
          if ( CFunction )
            CFunction(this);
        }
      }
      else
      {
        AvmObjOffset = pObject->AvmObjOffset;
        v9 = (Scaleform::GFx::AS3::Object *)*((_DWORD *)&pObject->pWeakProxy + AvmObjOffset);
        v10 = &pObject->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + AvmObjOffset;
        if ( v9 )
          v11 = v9;
        else
          v11 = (Scaleform::GFx::AS3::Object *)v10[1];
        if ( ((unsigned __int8)v11 & 1) != 0 )
          v11 = (Scaleform::GFx::AS3::Object *)((char *)v11 - 1);
        Scaleform::GFx::AS3::Value::Value(&_this, v11);
        v12 = proot->pAVM.pObject;
        result.Flags = 0;
        result.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v12, &this->Function, &_this, &result, 0, 0, 0);
        v13 = proot->pAVM.pObject;
        if ( v13->HandleException )
        {
          Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v13);
          this->pCharacter.pObject->Flags |= 0x20u;
        }
        Scaleform::GFx::AS3::Value::~Value(&result);
        Scaleform::GFx::AS3::Value::~Value(&_this);
      }
    }
  }
}
