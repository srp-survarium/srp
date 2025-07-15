void __thiscall Scaleform::GFx::AMP::Server::SendAppControlCaps(Scaleform::GFx::AMP::Server *this)
{
  Scaleform::GFx::AMP::MessageAppControl *v2; // edi
  unsigned int Flags; // eax
  Scaleform::RefCountVImpl *v4; // eax
  int v5; // [esp+8h] [ebp-4h] BYREF

  v5 = 580;
  v2 = (Scaleform::GFx::AMP::MessageAppControl *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   &this[-1].RecordingStateLock.cs.LockSemaphore,
                                                   36,
                                                   &v5);
  if ( v2 )
  {
    Flags = Scaleform::GFx::AMP::MessageAppControl::GetFlags((Scaleform::Render::RawImage *)this->SendCallback.pObject);
    Scaleform::GFx::AMP::MessageAppControl::MessageAppControl(v2, Flags);
    Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage((Scaleform::GFx::AMP::ThreadMgr *)this->Port, v4);
  }
  else
  {
    Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage((Scaleform::GFx::AMP::ThreadMgr *)this->Port, 0);
  }
}
