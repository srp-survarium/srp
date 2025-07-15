void __thiscall Scaleform::GFx::AMP::AppControlMsgHandler::Handle(
        Scaleform::GFx::AMP::AppControlMsgHandler *this,
        const Scaleform::GFx::AMP::MessageAppControl *message)
{
  Scaleform::GFx::AMP::Server::HandleAppControl(this->AmpSrv, message);
}
