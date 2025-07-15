void __thiscall Scaleform::GFx::AS3::SoundObject::Stop(Scaleform::GFx::AS3::SoundObject *this)
{
  Scaleform::GFx::InteractiveObject *v2; // eax
  Scaleform::GFx::InteractiveObject_vtbl *v3; // edx

  v2 = Scaleform::GFx::CharacterHandle::ResolveCharacter(this->pTargetHandle.pObject, this->pMovieRoot);
  if ( v2
    && ((v2->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? (unsigned int)v2 : 0) != 0 )
  {
    v3 = ((v2->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 ? v2 : 0)->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
    if ( this->pResource.pObject )
      ((void (__stdcall *)(Scaleform::GFx::SoundResource *))v3->StopActiveSounds)(this->pResource.pObject);
    else
      ((void (__stdcall *)(Scaleform::GFx::ASSoundIntf *))v3->StopActiveSounds)(&this->Scaleform::GFx::ASSoundIntf);
  }
}
