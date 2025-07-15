void __thiscall Scaleform::GFx::AMP::InitStateMsgHandler::Handle(
        Scaleform::GFx::AMP::InitStateMsgHandler *this,
        Scaleform::Render::RawImage *message)
{
  Scaleform::GFx::AMP::Server *AmpSrv; // esi

  AmpSrv = this->AmpSrv;
  EnterCriticalSection(&AmpSrv->ToggleStateLock.cs);
  AmpSrv->ForceState = Scaleform::GFx::AMP::MessageAppControl::GetFlags(message);
  AmpSrv->PendingForceState = 1;
  AmpSrv->PendingProfileLevel = (int)Scaleform::GFx::AS2::MovieRoot::GetMemoryContext((Scaleform::GFx::AS3::XMLSupportImpl *)message);
  LeaveCriticalSection(&AmpSrv->ToggleStateLock.cs);
}
