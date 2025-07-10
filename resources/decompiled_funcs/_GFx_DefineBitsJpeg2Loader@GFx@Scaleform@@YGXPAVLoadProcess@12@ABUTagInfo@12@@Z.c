void __stdcall Scaleform::GFx::GFx_DefineBitsJpeg2Loader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v7; // dx
  Scaleform::GFx::ImageFileHandlerRegistry *pObject; // ebp
  Scaleform::Render::ImageSource *v9; // esi
  Scaleform::Render::ImageFileReader *Reader; // ebp
  Scaleform::GFx::MovieDataDef::LoadTaskData *v11; // ecx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  Scaleform::GFx::ResourceId v13; // [esp+18h] [ebp-18h]
  Scaleform::Render::ImageCreateArgs args; // [esp+1Ch] [ebp-14h] BYREF
  Scaleform::RefCountVImpl *pa; // [esp+34h] [ebp+4h]

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v4 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  pBuffer = pAltStream->Stream.pBuffer;
  v7 = pBuffer[Pos + 1];
  LOWORD(pBuffer) = pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v13.Id = (unsigned __int16)((unsigned __int16)pBuffer | (v7 << 8));
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v13.Id);
  pObject = p->pLoadStates.pObject->pImageFileHandlerRegistry.pObject;
  v9 = 0;
  pa = (Scaleform::RefCountVImpl *)pObject;
  if ( pObject )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
    Reader = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
               &pObject->Scaleform::Render::ImageFileHandlerRegistry,
               ImageFile_JPEG);
    if ( Reader )
    {
      v11 = p->pLoadData.pObject;
      p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      memset(&args.pHeap, 0, 16);
      args.Use = 0;
      args.pHeap = v11->pHeap;
      if ( !p_ProcessInfo )
        p_ProcessInfo = &p->ProcessInfo;
      Scaleform::GFx::Stream::SyncFileStream(&p_ProcessInfo->Stream);
      p_ProcessInfo->Stream.ResyncFile = 1;
      v9 = (Scaleform::Render::ImageSource *)((int (__thiscall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, Scaleform::Render::ImageCreateArgs *, _DWORD, int, int, int))Reader->__vftable[1].~Scaleform::Render::ImageFileReader)(
                                               Reader,
                                               p_ProcessInfo->Stream.pInput.pObject,
                                               &args,
                                               0,
                                               tagInfo->TagLength - 2,
                                               (tagInfo->TagLength - 2) >> 31,
                                               1);
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "Jpeg System is not installed - can't load jpeg image data");
    }
    Scaleform::RefCountImpl::Release(pa);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Image file handler registry is not installed - can't load jpeg image data");
  }
  Scaleform::GFx::LoadProcess::AddImageResource(p, v13, v9);
  if ( v9 )
    v9->Release(v9);
}
