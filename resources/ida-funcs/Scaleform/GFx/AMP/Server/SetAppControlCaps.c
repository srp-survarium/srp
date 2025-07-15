void __thiscall Scaleform::GFx::AMP::Server::SetAppControlCaps(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::Render::RawImage *caps)
{
  Scaleform::GFx::AMP::MessageAppControl *v3; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AMP::SendThreadCallback *v5; // eax
  Scaleform::GFx::AMP::SendThreadCallback *v6; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  const Scaleform::GFx::AS2::Environment *ASEnvironment; // eax
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = 580;
  v3 = (Scaleform::GFx::AMP::MessageAppControl *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   &this[-1].RecordingStateLock.cs.LockSemaphore,
                                                   36,
                                                   &v9);
  if ( v3 )
  {
    Flags = Scaleform::GFx::AMP::MessageAppControl::GetFlags(caps);
    Scaleform::GFx::AMP::MessageAppControl::MessageAppControl(v3, Flags);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->SendCallback.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->SendCallback.pObject = v6;
  ASEnvironment = Scaleform::GFx::AS2::AvmSprite::GetASEnvironment((Scaleform::GFx::AS2::AvmSprite *)caps);
  Scaleform::GFx::AMP::MessageAppControl::SetLoadMovieFile(
    (Scaleform::GFx::AMP::MessageAppControl *)this->SendCallback.pObject,
    (char *)(((int)ASEnvironment->__vftable & 0xFFFFFFFC) + 8));
}
