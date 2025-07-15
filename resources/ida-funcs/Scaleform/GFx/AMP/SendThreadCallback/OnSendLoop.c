int __thiscall Scaleform::GFx::AMP::SendThreadCallback::OnSendLoop(Scaleform::GFx::AMP::SendThreadCallback *this)
{
  Scaleform::AmpServer *Instance; // eax

  Instance = Scaleform::AmpServer::GetInstance();
  return ((int (__thiscall *)(Scaleform::AmpServer *))Instance->HandleNextMessage)(Instance);
}
