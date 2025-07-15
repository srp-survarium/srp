void __thiscall Scaleform::GFx::AMP::SwdRequestMsgHandler::Handle(
        Scaleform::GFx::AMP::SwdRequestMsgHandler *this,
        Scaleform::GFx::AMP::Message *message)
{
  Scaleform::GFx::AMP::Server::HandleSwdRequest(this->AmpSrv, (Scaleform::String)message);
}
