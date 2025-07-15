void __thiscall Scaleform::GFx::Sprite::ExecuteFrameTags(Scaleform::GFx::Sprite *this, unsigned int frame)
{
  int (*GetLoadingFrame)(void); // eax
  unsigned int i; // edi
  unsigned __int8 AvmObjOffset; // al
  int v6; // eax
  int v7; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v8; // [esp+10h] [ebp-4h]

  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x800) != 0
    || !frame )
  {
    GetLoadingFrame = (int (*)(void))this->GetLoadingFrame;
    ++this->RefCount;
    if ( frame < GetLoadingFrame() )
    {
      this->pDef.pObject->GetPlaylist(this->pDef.pObject, (const Scaleform::GFx::TimelineDef::Frame *)&v7, frame);
      for ( i = 0; i < v8; ++i )
        (*(void (__thiscall **)(_DWORD, Scaleform::GFx::Sprite *, int))(**(_DWORD **)(v7 + 4 * i) + 8))(
          *(_DWORD *)(v7 + 4 * i),
          this,
          4);
      AvmObjOffset = this->AvmObjOffset;
      if ( AvmObjOffset )
      {
        v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                             + AvmObjOffset)
                                           + 8))(
               (char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
             + 4 * AvmObjOffset);
        (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v6 + 108))(v6, frame);
      }
    }
    Scaleform::RefCountNTSImpl::Release(this);
  }
}
