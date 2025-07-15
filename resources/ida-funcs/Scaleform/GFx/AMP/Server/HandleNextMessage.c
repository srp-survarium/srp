bool __thiscall Scaleform::GFx::AMP::Server::HandleNextMessage(Scaleform::GFx::AMP::Server *this)
{
  return Scaleform::GFx::AMP::ThreadMgr::HandleNextReceivedMessage((Scaleform::GFx::AMP::ThreadMgr *)this->Port);
}
