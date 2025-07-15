void __thiscall Scaleform::GFx::AMP::SourceRequestMsgHandler::Handle(
        Scaleform::GFx::AMP::SourceRequestMsgHandler *this,
        Scaleform::GFx::AMP::Message *message)
{
  Scaleform::GFx::AMP::Server::HandleSourceRequest(this->AmpSrv, (int)message);
}
