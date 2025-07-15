void __stdcall Scaleform::GFx::GFx_DefineBitsJpeg3Loader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // edi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int16 v6; // bp
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v7; // edi
  Scaleform::GFx::ImageFileHandlerRegistry *pObject; // ebx
  Scaleform::Render::ImageSource *v9; // ebp
  Scaleform::Render::JPEG::AbstractReader *Reader; // ebx
  Scaleform::MemoryHeap *pHeap; // ebp
  Scaleform::GFx::SWFProcessInfo *v12; // edi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  Scaleform::File *v14; // edi
  Scaleform::MemoryHeap *v15; // ecx
  Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *v16; // ebp
  Scaleform::Render::ImageUpdateSync *UpdateSync; // eax
  Scaleform::Render::Image *v18; // eax
  Scaleform::Render::Image *v19; // edi
  Scaleform::GFx::ResourceId v20; // [esp+10h] [ebp-30h]
  int jpegSize; // [esp+14h] [ebp-2Ch]
  Scaleform::GFx::ZlibSupportBase *pzlib; // [esp+18h] [ebp-28h]
  unsigned int sz; // [esp+1Ch] [ebp-24h]
  Scaleform::Render::Size<unsigned long> size; // [esp+24h] [ebp-1Ch] BYREF
  Scaleform::Render::ImageCreateArgs args; // [esp+2Ch] [ebp-14h] BYREF
  Scaleform::GFx::LoadProcess *pa; // [esp+44h] [ebp+4h]

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
  jpegSize = Scaleform::GFx::LoadProcess::ReadU32(p);
  if ( tagInfo->TagType == Tag_DefineBitsJpeg4 )
    Scaleform::GFx::LoadProcess::ReadU16(p);
  v7 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
  v20.Id = v6;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v6);
  pObject = p->pLoadStates.pObject->pImageFileHandlerRegistry.pObject;
  v9 = 0;
  pa = (Scaleform::GFx::LoadProcess *)pObject;
  if ( pObject )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
    pzlib = p->pLoadStates.pObject->pZlibSupport.pObject;
    if ( pzlib )
    {
      Reader = (Scaleform::Render::JPEG::AbstractReader *)Scaleform::Render::ImageFileHandlerRegistry::GetReader(
                                                            &pObject->Scaleform::Render::ImageFileHandlerRegistry,
                                                            ImageFile_JPEG);
      if ( Reader )
      {
        pHeap = p->pLoadData.pObject->pHeap;
        v12 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        args.Use = 0;
        memset(&args.pManager, 0, 12);
        args.pHeap = pHeap;
        p_ProcessInfo = &p->ProcessInfo;
        if ( v12 )
          p_ProcessInfo = v12;
        sz = tagInfo->TagLength
           + tagInfo->TagDataOffset
           - (p_ProcessInfo->Stream.Pos
            + p_ProcessInfo->Stream.FilePos
            - p_ProcessInfo->Stream.DataSize);
        if ( !v12 )
          v12 = &p->ProcessInfo;
        Scaleform::GFx::Stream::SyncFileStream(&v12->Stream);
        v12->Stream.ResyncFile = 1;
        v14 = v12->Stream.pInput.pObject;
        v15 = pHeap;
        if ( !pHeap )
          v15 = Scaleform::Memory::pGlobalHeap;
        v16 = (Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas *)v15->Alloc(v15, 40u, 0);
        if ( v16 )
        {
          UpdateSync = Scaleform::Render::ImageCreateArgs::GetUpdateSync(&args);
          Scaleform::GFx::MemoryBufferJpegImageWithZlibAlphas::MemoryBufferJpegImageWithZlibAlphas(
            v16,
            pzlib,
            Reader,
            jpegSize,
            Image_R8G8B8A8,
            &size,
            0,
            UpdateSync,
            v14,
            sz);
          v19 = v18;
        }
        else
        {
          v19 = 0;
        }
        v9 = Reader->CreateWrapperImageSource(Reader, v19);
        if ( v19 )
          v19->Release(v19);
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
          v7,
          "Jpeg System is not installed - can't load jpeg image data");
      }
      pObject = (Scaleform::GFx::ImageFileHandlerRegistry *)pa;
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        v7,
        "ZlibState is not set - can't load zipped image data");
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      v7,
      "Image file handler registry is not installed - can't load jpeg image data");
  }
  Scaleform::GFx::LoadProcess::AddImageResource(p, v20, v9);
  if ( v9 )
    v9->Release(v9);
}
