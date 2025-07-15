void __stdcall Scaleform::GFx::GFx_DefineBitsJpeg3Loader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // edi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int16 v6; // bp
  unsigned __int16 U16; // dx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v9; // edi
  Scaleform::GFx::SWFProcessInfo *v10; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *pObject; // ebx
  Scaleform::Render::ImageSource *v12; // ebp
  Scaleform::Render::JPEG::AbstractReader *Reader; // ebx
  Scaleform::MemoryHeap *pHeap; // ebp
  Scaleform::GFx::SWFProcessInfo *v15; // edi
  Scaleform::GFx::SWFProcessInfo *v16; // eax
  Scaleform::File *v17; // edi
  Scaleform::MemoryHeap *v18; // ecx
  Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *v19; // ebp
  Scaleform::Render::ImageUpdateSync *UpdateSync; // eax
  Scaleform::Render::Image *v21; // eax
  Scaleform::Render::Image *v22; // edi
  Scaleform::GFx::ResourceId v23; // [esp+10h] [ebp-30h]
  int alphaPos; // [esp+14h] [ebp-2Ch]
  Scaleform::GFx::ZlibSupportBase *zlib; // [esp+18h] [ebp-28h]
  unsigned int length; // [esp+1Ch] [ebp-24h]
  Scaleform::Render::Size<unsigned long> size; // [esp+24h] [ebp-1Ch] BYREF
  Scaleform::Render::ImageCreateArgs v28; // [esp+2Ch] [ebp-14h] BYREF
  Scaleform::GFx::LoadProcess *v29; // [esp+44h] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v4 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  alphaPos = Scaleform::GFx::LoadProcess::ReadU32(p);
  if ( tagInfo->TagType == Tag_DefineBitsJpeg4 )
  {
    U16 = Scaleform::GFx::LoadProcess::ReadU16(p);
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    v9 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
    v23.Id = v6;
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  GFx_DefineBitsJpeg4Loader: charid = %d pos = %d deblocking = %d\n",
      v6,
      p_ProcessInfo->Stream.Pos + p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.DataSize,
      U16);
  }
  else
  {
    v10 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v10 )
      v10 = &p->ProcessInfo;
    v9 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
    v23.Id = v6;
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  GFx_DefineBitsJpeg3Loader: charid = %d pos = %d\n",
      v6,
      v10->Stream.Pos + v10->Stream.FilePos - v10->Stream.DataSize);
  }
  pObject = p->pLoadStates.pObject->pImageFileHandlerRegistry.pObject;
  v12 = 0;
  v29 = (Scaleform::GFx::LoadProcess *)pObject;
  if ( pObject )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
    zlib = p->pLoadStates.pObject->pZlibSupport.pObject;
    if ( zlib )
    {
      Reader = (Scaleform::Render::JPEG::AbstractReader *)Scaleform::Render::ImageFileHandlerRegistry::GetReader(
                                                            &pObject->Scaleform::Render::ImageFileHandlerRegistry,
                                                            ImageFile_JPEG);
      if ( Reader )
      {
        pHeap = p->pLoadData.pObject->pHeap;
        v15 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        v28.Use = 0;
        memset(&v28.pManager, 0, 12);
        v28.pHeap = pHeap;
        v16 = &p->ProcessInfo;
        if ( v15 )
          v16 = v15;
        length = tagInfo->TagLength
               + tagInfo->TagDataOffset
               - (v16->Stream.Pos
                + v16->Stream.FilePos
                - v16->Stream.DataSize);
        if ( !v15 )
          v15 = &p->ProcessInfo;
        Scaleform::GFx::Stream::SyncFileStream(&v15->Stream);
        v15->Stream.ResyncFile = 1;
        v17 = v15->Stream.pInput.pObject;
        v18 = pHeap;
        if ( !pHeap )
          v18 = Scaleform::Memory::pGlobalHeap;
        v19 = (Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *)v18->Alloc(v18, 40u, 0);
        if ( v19 )
        {
          UpdateSync = Scaleform::Render::ImageCreateArgs::GetUpdateSync(&v28);
          Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas::MemoryBufferJpegImageWithZlibAlphas(
            v19,
            (Scaleform::GFx::Resource *)zlib,
            Reader,
            alphaPos,
            Image_R8G8B8A8,
            &size,
            0,
            UpdateSync,
            v17,
            length);
          v22 = v21;
        }
        else
        {
          v22 = 0;
        }
        v12 = Reader->CreateWrapperImageSource(Reader, v22);
        if ( v22 )
          v22->Release(v22);
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
          v9,
          "Jpeg System is not installed - can't load jpeg image data");
      }
      pObject = (Scaleform::GFx::ImageFileHandlerRegistry *)v29;
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        v9,
        "ZlibState is not set - can't load zipped image data");
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      v9,
      "Image file handler registry is not installed - can't load jpeg image data");
  }
  Scaleform::GFx::LoadProcess::AddImageResource(p, v23, v12);
  if ( v12 )
    v12->Release(v12);
}
