void __stdcall Scaleform::GFx::GFx_DefineBitsJpegLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v7; // dx
  Scaleform::GFx::ImageFileHandlerRegistry *pObject; // ebx
  Scaleform::Render::ImageSource *v9; // esi
  Scaleform::Render::ImageFileReader *Reader; // ebp
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ecx
  Scaleform::Render::JPEG::TablesHeader *v12; // ebx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v13; // ecx
  Scaleform::GFx::SWFProcessInfo *v14; // esi
  int v15; // eax
  unsigned __int16 v16; // [esp+18h] [ebp-2Ch]
  Scaleform::Render::ImageCreateArgs args; // [esp+1Ch] [ebp-28h] BYREF
  int v18; // [esp+30h] [ebp-14h] BYREF
  Scaleform::MemoryHeap *pHeap; // [esp+34h] [ebp-10h]
  int v20; // [esp+38h] [ebp-Ch]
  int v21; // [esp+3Ch] [ebp-8h]
  int v22; // [esp+40h] [ebp-4h]
  Scaleform::GFx::LoadProcess *pa; // [esp+48h] [ebp+4h]

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
  pObject = p->pLoadStates.pObject->pImageFileHandlerRegistry.pObject;
  v9 = 0;
  v16 = (unsigned __int16)pBuffer | (v7 << 8);
  pa = (Scaleform::GFx::LoadProcess *)pObject;
  if ( pObject )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
    Reader = Scaleform::Render::ImageFileHandlerRegistry::GetReader(
               &pObject->Scaleform::Render::ImageFileHandlerRegistry,
               ImageFile_JPEG);
    if ( Reader )
    {
      p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !p_ProcessInfo )
        p_ProcessInfo = &p->ProcessInfo;
      Scaleform::GFx::Stream::SyncFileStream(&p_ProcessInfo->Stream);
      v12 = p->pJpegTables.pObject;
      v13 = p->pLoadData.pObject;
      v14 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( v12 )
      {
        memset(&args.pHeap, 0, 16);
        args.Use = 0;
        args.pHeap = v13->pHeap;
        if ( !v14 )
          v14 = &p->ProcessInfo;
        Scaleform::GFx::Stream::SyncFileStream(&v14->Stream);
        v14->Stream.ResyncFile = 1;
        v15 = ((int (__thiscall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, Scaleform::Render::ImageCreateArgs *, Scaleform::Render::JPEG::TablesHeader *, int, int, _DWORD))Reader->__vftable[1].~Scaleform::Render::ImageFileReader)(
                Reader,
                v14->Stream.pInput.pObject,
                &args,
                v12,
                tagInfo->TagLength - 2,
                (tagInfo->TagLength - 2) >> 31,
                0);
      }
      else
      {
        pHeap = 0;
        v18 = 0;
        v20 = 0;
        v21 = 0;
        v22 = 0;
        pHeap = v13->pHeap;
        if ( !v14 )
          v14 = &p->ProcessInfo;
        Scaleform::GFx::Stream::SyncFileStream(&v14->Stream);
        v14->Stream.ResyncFile = 1;
        v15 = ((int (__thiscall *)(Scaleform::Render::ImageFileReader *, Scaleform::File *, int *, _DWORD, int, int, _DWORD))Reader->__vftable[1].~Scaleform::Render::ImageFileReader)(
                Reader,
                v14->Stream.pInput.pObject,
                &v18,
                0,
                tagInfo->TagLength - 2,
                (tagInfo->TagLength - 2) >> 31,
                0);
      }
      pObject = (Scaleform::GFx::ImageFileHandlerRegistry *)pa;
      v9 = (Scaleform::Render::ImageSource *)v15;
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "Jpeg System is not installed - can't load jpeg image data");
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Image file handler registry is not installed - can't load jpeg image data");
  }
  Scaleform::GFx::LoadProcess::AddImageResource(p, (Scaleform::GFx::ResourceId)v16, v9);
  if ( v9 )
    v9->Release(v9);
}
