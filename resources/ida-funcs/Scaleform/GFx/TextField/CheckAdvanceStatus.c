int __thiscall Scaleform::GFx::TextField::CheckAdvanceStatus(Scaleform::GFx::TextField *this, bool playingNow)
{
  int v3; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  Scaleform::Render::Text::EditorKitBase *pObject; // edi
  unsigned __int8 AvmObjOffset; // al
  int v8; // eax
  int v9; // eax
  int v10; // eax

  v3 = 0;
  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0xC) == 0
    && (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x40) == 0
    && (this->pDef.pObject->Flags & 0x1000) == 0
    && ((this->Flags & 0x4000) != 0
     || (this->Flags & 0x8000) != 0
     || (pMovieImpl = this->pASRoot->pMovieImpl,
         pObject = this->pDocument.pObject->pEditorKit.pObject,
         (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
        & 0x4000) != 0)
     && pObject
     && (!pObject->IsReadOnly(pObject) && Scaleform::GFx::MovieImpl::IsFocused(pMovieImpl, this)
      || ((int)pObject[16].__vftable & 0x20) != 0)) )
  {
    if ( !playingNow )
      return 1;
  }
  else if ( playingNow )
  {
    v3 = -1;
  }
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v8 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + AvmObjOffset)
                                       + 16))(
           (char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
         + 4 * AvmObjOffset);
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 92))(v8);
    if ( v9 )
    {
      v10 = *(_DWORD *)(v9 + 20);
      if ( v10 == 1 || v10 == 2 )
        return 1;
    }
  }
  return v3;
}
