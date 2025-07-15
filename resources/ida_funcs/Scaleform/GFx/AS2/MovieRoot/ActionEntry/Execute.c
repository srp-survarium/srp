void __thiscall Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(
        Scaleform::GFx::AS2::MovieRoot::ActionEntry *this,
        Scaleform::GFx::AS2::MovieRoot *proot)
{
  Scaleform::GFx::InteractiveObject *pObject; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax

  pObject = this->pCharacter.pObject;
  if ( pObject && (pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
  {
    switch ( this->Type )
    {
      case Entry_Buffer:
        v4 = &pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + pObject->AvmObjOffset;
        v5 = ((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v4)->CreateRenderNode)(v4);
        (*(void (__thiscall **)(int, Scaleform::GFx::AS2::ActionBuffer *))(*(_DWORD *)v5 + 148))(
          v5,
          this->pActionBuffer.pObject);
        break;
      case Entry_Event:
        v6 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pObject->AvmObjOffset)
                                        + 4))((int)pObject + 4 * pObject->AvmObjOffset);
        (*(void (__thiscall **)(int, Scaleform::GFx::EventId *))(*(_DWORD *)v6 + 152))(v6, &this->mEventId);
        break;
      case Entry_Function:
        v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pObject->AvmObjOffset)
                                        + 4))((int)pObject + 4 * pObject->AvmObjOffset);
        (*(void (__thiscall **)(int, Scaleform::GFx::AS2::FunctionRef *, Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *))(*(_DWORD *)v7 + 156))(
          v7,
          &this->Function,
          &this->FunctionParams);
        break;
      case Entry_CFunction:
        v8 = (*(int (__thiscall **)(int))(*((_DWORD *)&pObject->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pObject->AvmObjOffset)
                                        + 4))((int)pObject + 4 * pObject->AvmObjOffset);
        (*(void (__thiscall **)(int, void (__cdecl *)(const Scaleform::GFx::AS2::FnCall *), Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *))(*(_DWORD *)v8 + 160))(
          v8,
          this->CFunction,
          &this->FunctionParams);
        break;
      default:
        return;
    }
  }
}
