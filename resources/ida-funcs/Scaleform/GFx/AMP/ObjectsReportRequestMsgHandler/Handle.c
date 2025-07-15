void __thiscall Scaleform::GFx::AMP::ObjectsReportRequestMsgHandler::Handle(
        Scaleform::GFx::AMP::ObjectsReportRequestMsgHandler *this,
        Scaleform::Render::RawImage *message)
{
  Scaleform::GFx::AMP::Server::HandleObjectsReportRequest(this->AmpSrv, message);
}
