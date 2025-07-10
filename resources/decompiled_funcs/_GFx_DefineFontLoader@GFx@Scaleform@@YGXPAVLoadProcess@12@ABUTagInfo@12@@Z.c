void __stdcall Scaleform::GFx::GFx_DefineFontLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // ecx
  Scaleform::GFx::ResourceId v6; // ebp
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // edx
  bool v8; // bl
  Scaleform::GFx::TagType TagType; // eax
  Scaleform::GFx::FontDataCompactedGfx *v10; // eax
  Scaleform::GFx::FontDataCompactedGfx *v11; // eax
  Scaleform::Render::Font *v12; // esi
  Scaleform::GFx::FontDataCompactedSwf *v13; // eax
  Scaleform::GFx::FontDataCompactedSwf *v14; // eax
  Scaleform::GFx::FontData *v15; // eax
  Scaleform::GFx::FontData *v16; // eax
  Scaleform::GFx::ResourceHandle result; // [esp+10h] [ebp-8h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos];
  v6.Id = (unsigned __int16)v5;
  pAltStream->Stream.Pos = Pos + 2;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v5);
  pObject = p->pLoadData.pObject;
  v8 = 0;
  if ( (pObject->Header.mExporterInfo.SI.Format != File_Unopened ? (unsigned int)&pObject->Header.mExporterInfo : 0) != 0 )
    v8 = (*(pObject->Header.mExporterInfo.SI.Format != File_Unopened
          ? (_BYTE *)&pObject->Header.mExporterInfo.SI.ExportFlags
          : (_BYTE *)16)
        & 0x10) != 0;
  TagType = tagInfo->TagType;
  if ( tagInfo->TagType == Tag_DefineCompactedFont )
  {
    v10 = (Scaleform::GFx::FontDataCompactedGfx *)pObject->pHeap->Alloc(pObject->pHeap, 108u, 0);
    if ( v10 )
    {
      Scaleform::GFx::FontDataCompactedGfx::FontDataCompactedGfx(v10);
      v12 = v11;
      Scaleform::GFx::FontDataCompactedGfx::Read(v11, p, tagInfo);
    }
    else
    {
      v12 = 0;
      Scaleform::GFx::FontDataCompactedGfx::Read(0, p, tagInfo);
    }
  }
  else if ( (TagType == Tag_DefineFont2 || TagType == Tag_DefineFont3)
         && !v8
         && p->pLoadStates.pObject->pBindStates.pObject->pFontCompactorParams.pObject )
  {
    v13 = (Scaleform::GFx::FontDataCompactedSwf *)pObject->pHeap->Alloc(pObject->pHeap, 120u, 0);
    if ( v13 )
    {
      Scaleform::GFx::FontDataCompactedSwf::FontDataCompactedSwf(v13);
      v12 = v14;
      Scaleform::GFx::FontDataCompactedSwf::Read(v14, p, tagInfo);
    }
    else
    {
      v12 = 0;
      Scaleform::GFx::FontDataCompactedSwf::Read(0, p, tagInfo);
    }
  }
  else
  {
    v15 = (Scaleform::GFx::FontData *)pObject->pHeap->Alloc(pObject->pHeap, 76u, 0);
    if ( v15 )
      Scaleform::GFx::FontData::FontData(v15);
    else
      v16 = 0;
    v12 = v16;
    Scaleform::GFx::FontData::Read(v16, p, tagInfo);
  }
  Scaleform::GFx::LoadProcess::AddFontDataResource(p, &result, v6, v12);
  if ( result.HType == RH_Pointer && result.BindIndex )
    Scaleform::GFx::Resource::Release(result.pResource);
  if ( v12 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
}
