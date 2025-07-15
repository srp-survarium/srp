void __thiscall Scaleform::GFx::LoadProcess::LoadProcess(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::MovieDataDef *pdataDef,
        Scaleform::GFx::Resource *pstates,
        unsigned int loadFlags)
{
  Scaleform::GFx::ParseControl *Value; // eax
  unsigned int ParseFlags; // eax
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v8; // ecx

  Scaleform::GFx::LoaderTask::LoaderTask(this, pstates, Id_MovieDataLoad);
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  this->Scaleform::GFx::LoaderTask::Scaleform::GFx::Task::Scaleform::RefCountBase<Scaleform::GFx::Task,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::LoadProcess_vtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LoaderTask'};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>_vtbl *)&Scaleform::GFx::LoadProcess::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>'};
  this->pBindProcess.pObject = 0;
  this->pLoadData.pObject = 0;
  Scaleform::GFx::Stream::Stream(&this->ProcessInfo.Stream, 0, pdataDef->pData.pObject->pHeap, 0, 0);
  Scaleform::GFx::MovieHeaderData::MovieHeaderData(&this->ProcessInfo.Header);
  this->ProcessInfo.FileAttributes = 0;
  this->pJpegTables.pObject = 0;
  this->FrameTags[0].Data.Data = 0;
  this->FrameTags[0].Data.Size = 0;
  this->FrameTags[0].Data.Policy.Capacity = 0;
  this->FrameTags[1].Data.Data = 0;
  this->FrameTags[1].Data.Size = 0;
  this->FrameTags[1].Data.Policy.Capacity = 0;
  this->InitActionTags.Data.Data = 0;
  this->InitActionTags.Data.Size = 0;
  this->InitActionTags.Data.Policy.Capacity = 0;
  Value = (Scaleform::GFx::ParseControl *)pstates[1].RefCount.Value;
  if ( Value )
    ParseFlags = Value->ParseFlags;
  else
    ParseFlags = 0;
  this->ParseFlags = ParseFlags;
  pObject = (Scaleform::GFx::Resource *)pdataDef->pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v8 = (Scaleform::RefCountVImpl *)this->pLoadData.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  this->pLoadData.pObject = pdataDef->pData.pObject;
  this->pTimelineDef = 0;
  this->LoadState = LS_LoadingRoot;
  this->ImportIndex = 0;
  this->ImportDataCount = 0;
  this->ResourceDataCount = 0;
  this->FontDataCount = 0;
  this->pImportDataLast = 0;
  this->pImportData = 0;
  this->pResourceDataLast = 0;
  this->pResourceData = 0;
  this->pFontDataLast = 0;
  this->pFontData = 0;
  this->pAltStream = 0;
  this->pTempBindData = 0;
  this->ASInitActionTagsNum = 0;
  this->LoadFlags = loadFlags;
  this->pDataDef_Unsafe = pdataDef;
}
