Scaleform::GFx::AMP::MessageFontData *__thiscall Scaleform::GFx::AMP::Server::GetImageData(
        Scaleform::GFx::AMP::Server *this,
        unsigned int imageId)
{
  Scaleform::GFx::AMP::MessageImageData *v3; // eax
  int v4; // ebp
  Scaleform::GFx::AMP::MessageFontData *v5; // eax
  Scaleform::GFx::AMP::AmpStream *v6; // eax
  Scaleform::RefCountVImpl *v7; // eax
  Scaleform::RefCountVImpl *v8; // ebx
  Scaleform::Lock *p_ImageLock; // esi
  Scaleform::GFx::ImageResource *v10; // esi
  int v11; // eax
  Scaleform::Render::ImageBase *pImage; // esi
  Scaleform::Render::Image *v13; // eax
  Scaleform::GFx::AMP::MessageFontData *v15; // [esp+18h] [ebp-10h]
  int v16; // [esp+20h] [ebp-8h] BYREF
  int v17; // [esp+24h] [ebp-4h] BYREF

  v16 = 580;
  v3 = (Scaleform::GFx::AMP::MessageImageData *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this,
                                                  36,
                                                  &v16);
  v4 = 0;
  if ( v3 )
  {
    Scaleform::GFx::AMP::MessageImageData::MessageImageData(v3, imageId);
    v15 = v5;
  }
  else
  {
    v15 = 0;
  }
  v17 = 2;
  v6 = (Scaleform::GFx::AMP::AmpStream *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           24,
                                           &v17);
  if ( v6 )
  {
    Scaleform::GFx::AMP::AmpStream::AmpStream(v6);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  p_ImageLock = &this->ImageLock;
  EnterCriticalSection(&this->ImageLock.cs);
  if ( !this->Images.Data.Size )
  {
LABEL_18:
    LeaveCriticalSection(&p_ImageLock->cs);
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
    return v15;
  }
  while ( 1 )
  {
    v10 = this->Images.Data.Data[v4];
    if ( v10->pImage )
      v11 = v10->pImage->GetImageId(v10->pImage);
    else
      v11 = 0;
    if ( v11 != imageId )
      goto LABEL_16;
    pImage = v10->pImage;
    if ( !pImage )
      goto LABEL_16;
    pImage->AddRef(pImage);
    if ( (pImage->GetFormat(pImage) & 0xFFFu) - 50 > 0xB )
    {
      Scaleform::GFx::AMP::AmpFileWriter::Instance.Version = this->SocketThreadMgr.pObject->MsgVersion.Value;
      v13 = pImage->GetAsImage(pImage);
      if ( Scaleform::Render::ImageFileWriter::writeImage(
             (Scaleform::File *)v8,
             &Scaleform::GFx::AMP::AmpFileWriter::Instance,
             v13,
             0) )
      {
        break;
      }
    }
    pImage->Release(pImage);
LABEL_16:
    if ( ++v4 >= this->Images.Data.Size )
    {
      p_ImageLock = &this->ImageLock;
      goto LABEL_18;
    }
  }
  if ( v8 )
  {
    Scaleform::GFx::AMP::MessageFontData::SetImageData(v15, (Scaleform::GFx::Resource *)v8);
    Scaleform::GFx::AMP::MessageImageData::SetPngFormat((Scaleform::GFx::AMP::MessageImageData *)v15, 0);
  }
  pImage->Release(pImage);
  LeaveCriticalSection(&this->ImageLock.cs);
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  return v15;
}
