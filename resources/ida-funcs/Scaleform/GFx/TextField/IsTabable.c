bool __thiscall Scaleform::GFx::TextField::IsTabable(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // ecx
  unsigned int v4; // ecx
  unsigned __int8 AvmObjOffset; // al
  int v6; // eax

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 || !this->GetVisible(this) )
    return 0;
  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject ? pObject->IsReadOnly(pObject) : (this->pDef.pObject->Flags & 8) != 0 )
    return 0;
  v4 = this->Scaleform::GFx::InteractiveObject::Flags & 0x60;
  if ( v4 )
    return !v4 || v4 == 96;
  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return !v4 || v4 == 96;
  v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + AvmObjOffset)
                                     + 16))(
         (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + 4 * AvmObjOffset);
  return (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 88))(v6);
}
