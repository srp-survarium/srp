void __thiscall Scaleform::GFx::AMP::ImageRequestMsgHandler::Handle(
        Scaleform::GFx::AMP::ImageRequestMsgHandler *this,
        Scaleform::Render::RawImage *message)
{
  Scaleform::GFx::AMP::Server *AmpSrv; // esi
  unsigned int Flags; // eax
  Scaleform::RefCountVImpl *ImageData; // edi

  AmpSrv = this->AmpSrv;
  Flags = Scaleform::GFx::AMP::MessageAppControl::GetFlags(message);
  ImageData = (Scaleform::RefCountVImpl *)Scaleform::GFx::AMP::Server::GetImageData(AmpSrv, Flags);
  if ( Scaleform::GFx::AS2::MovieRoot::GetMemoryContext((Scaleform::GFx::AS3::XMLSupportImpl *)ImageData)
    || AmpSrv->SocketThreadMgr.pObject->MsgVersion.Value >= 0x17 )
  {
    Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage(AmpSrv->SocketThreadMgr.pObject, ImageData);
  }
}
