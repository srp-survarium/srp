void __thiscall Scaleform::GFx::AMP::FontRequestMsgHandler::Handle(
        Scaleform::GFx::AMP::FontRequestMsgHandler *this,
        Scaleform::Render::RawImage *message)
{
  Scaleform::GFx::AMP::Server::HandleFontRequest(this->AmpSrv, message);
}
