void __thiscall Scaleform::GFx::Sprite::ExecuteFrameTags(Scaleform::GFx::Sprite *this, unsigned int frame)
{
  int (*GetLoadingFrame)(void); // eax
  unsigned int i; // edi
  unsigned __int8 AvmObjOffset; // al
  int v6; // eax
  Scaleform::GFx::TimelineDef::Frame playlist; // [esp+Ch] [ebp-8h] BYREF

  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x800) != 0
    || !frame )
  {
    GetLoadingFrame = (int (*)(void))this->GetLoadingFrame;
    ++this->RefCount;
    if ( frame < GetLoadingFrame() )
    {
      this->pDef.pObject->GetPlaylist(this->pDef.pObject, &playlist, frame);
      for ( i = 0; i < playlist.TagCount; ++i )
        playlist.pTagPtrList[i]->ExecuteWithPriority(playlist.pTagPtrList[i], this, AP_Frame);
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
