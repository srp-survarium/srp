void __stdcall Scaleform::GFx::GFx_JpegTablesLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadStates *pObject; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v3; // ebp
  Scaleform::Render::JPEG::TablesHeader *v4; // eax
  int v5; // eax
  int v6; // edi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ecx

  pObject = p->pLoadStates.pObject;
  v3 = pObject->pImageFileHandlerRegistry.pObject;
  if ( v3 )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject->pImageFileHandlerRegistry.pObject);
    if ( Scaleform::Render::ImageFileHandlerRegistry::GetReader(
           &v3->Scaleform::Render::ImageFileHandlerRegistry,
           ImageFile_JPEG) )
    {
      if ( tagInfo->TagLength > 0 )
      {
        v4 = (Scaleform::Render::JPEG::TablesHeader *)p->pLoadData.pObject->pHeap->Alloc(
                                                        p->pLoadData.pObject->pHeap,
                                                        16,
                                                        0);
        if ( v4 )
        {
          Scaleform::Render::JPEG::TablesHeader::TablesHeader(v4, p->pLoadData.pObject->pHeap, tagInfo->TagLength);
          v6 = v5;
        }
        else
        {
          v6 = 0;
        }
        pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
        if ( !pAltStream )
          pAltStream = &p->ProcessInfo;
        Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, *(unsigned __int8 **)(v6 + 8), tagInfo->TagLength);
        Scaleform::GFx::LoadProcess::SetJpegHeader(p, (Scaleform::GFx::Resource *)v6);
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
      }
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
    }
    else
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "Jpeg System is not installed - can't load jpeg image data");
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
    }
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "Image file handler registry is not installed - can't load jpeg image data");
  }
}
