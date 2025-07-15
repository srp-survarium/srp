char __thiscall Scaleform::GFx::AMP::Server::HandleFontRequest(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::Render::RawImage *msg)
{
  Scaleform::GFx::AMP::MessageFontData *v3; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AMP::MessageFontData *v5; // eax
  Scaleform::GFx::AMP::MessageFontData *v6; // ebx
  Scaleform::GFx::AMP::AmpStream *v7; // eax
  Scaleform::GFx::Resource *v8; // eax
  Scaleform::GFx::Resource *v9; // edi
  int v11; // [esp+Ch] [ebp-4h] BYREF

  v11 = 580;
  v3 = (Scaleform::GFx::AMP::MessageFontData *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 32,
                                                 &v11);
  if ( v3 )
  {
    Flags = Scaleform::GFx::AMP::MessageAppControl::GetFlags(msg);
    Scaleform::GFx::AMP::MessageFontData::MessageFontData(v3, Flags);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  msg = (Scaleform::Render::RawImage *)2;
  v7 = (Scaleform::GFx::AMP::AmpStream *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           24,
                                           &msg);
  if ( v7 )
  {
    Scaleform::GFx::AMP::AmpStream::AmpStream(v7);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  if ( Scaleform::Render::GlyphCache::GetTextureData(
         this->CurrentRenderer->pImpl->pGlyphCache.pObject,
         (Scaleform::File *)v9,
         this->SocketThreadMgr.pObject->MsgVersion.Value) > 0 )
    Scaleform::GFx::AMP::MessageFontData::SetImageData(v6, v9);
  Scaleform::GFx::AMP::ThreadMgr::SendAmpMessage(this->SocketThreadMgr.pObject, (Scaleform::RefCountVImpl *)v6);
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
  return 1;
}
