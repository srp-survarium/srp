void __stdcall Scaleform::GFx::GFx_DefineFontLoader(
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *v2; // esi
  int v3; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::ResourceId v5; // ebp
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // edx
  bool v7; // bl
  Scaleform::GFx::TagType TagType; // eax
  Scaleform::GFx::FontDataCompactedGfx *v9; // eax
  Scaleform::GFx::FontDataCompactedGfx *v10; // eax
  Scaleform::GFx::Resource *v11; // esi
  Scaleform::GFx::FontDataCompactedSwf *v12; // eax
  Scaleform::GFx::FontDataCompactedSwf *v13; // eax
  Scaleform::GFx::FontData *v14; // eax
  Scaleform::GFx::FontData *v15; // eax
  Scaleform::GFx::ResourceHandle result; // [esp+10h] [ebp-8h] BYREF

  v2 = (Scaleform::GFx::SWFProcessInfo *)p[213].__vftable;
  if ( !v2 )
    v2 = (Scaleform::GFx::SWFProcessInfo *)&p[12];
  v3 = v2->Stream.DataSize - v2->Stream.Pos;
  v2->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&v2->Stream, 2);
  Pos = v2->Stream.Pos;
  v5.Id = *(unsigned __int16 *)&v2->Stream.pBuffer[Pos];
  v2->Stream.Pos = Pos + 2;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    (Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *)&p[5],
    "  Font: id = %d\n",
    v5.Id);
  v6 = (Scaleform::GFx::MovieDataDef::LoadTaskData *)p[8].__vftable;
  v7 = 0;
  if ( (v6->Header.mExporterInfo.SI.Format != File_Unopened ? (unsigned int)&v6->Header.mExporterInfo : 0) != 0 )
    v7 = (*(v6->Header.mExporterInfo.SI.Format != File_Unopened
          ? (_BYTE *)&v6->Header.mExporterInfo.SI.ExportFlags
          : (_BYTE *)16)
        & 0x10) != 0;
  TagType = tagInfo->TagType;
  if ( tagInfo->TagType == Tag_DefineCompactedFont )
  {
    v9 = (Scaleform::GFx::FontDataCompactedGfx *)v6->pHeap->Alloc(v6->pHeap, 108u, 0);
    if ( v9 )
    {
      Scaleform::GFx::FontDataCompactedGfx::FontDataCompactedGfx(v9);
      v11 = (Scaleform::GFx::Resource *)v10;
      Scaleform::GFx::FontDataCompactedGfx::Read(v10, p, tagInfo);
    }
    else
    {
      v11 = 0;
      Scaleform::GFx::FontDataCompactedGfx::Read(0, p, tagInfo);
    }
  }
  else if ( (TagType == Tag_DefineFont2 || TagType == Tag_DefineFont3)
         && !v7
         && *((_DWORD *)p[4].__vftable[1].~Scaleform::GFx::LogBase<Scaleform::GFx::Stream> + 8) )
  {
    v12 = (Scaleform::GFx::FontDataCompactedSwf *)v6->pHeap->Alloc(v6->pHeap, 120u, 0);
    if ( v12 )
    {
      Scaleform::GFx::FontDataCompactedSwf::FontDataCompactedSwf(v12);
      v11 = (Scaleform::GFx::Resource *)v13;
      Scaleform::GFx::FontDataCompactedSwf::Read(v13, (Scaleform::GFx::LoadProcess *)p, tagInfo);
    }
    else
    {
      v11 = 0;
      Scaleform::GFx::FontDataCompactedSwf::Read(0, (Scaleform::GFx::LoadProcess *)p, tagInfo);
    }
  }
  else
  {
    v14 = (Scaleform::GFx::FontData *)v6->pHeap->Alloc(v6->pHeap, 76u, 0);
    if ( v14 )
      Scaleform::GFx::FontData::FontData(v14);
    else
      v15 = 0;
    v11 = (Scaleform::GFx::Resource *)v15;
    Scaleform::GFx::FontData::Read(v15, (Scaleform::GFx::LoadProcess *)p, tagInfo);
  }
  Scaleform::GFx::LoadProcess::AddFontDataResource((Scaleform::GFx::LoadProcess *)p, &result, v5, v11);
  if ( result.HType == RH_Pointer && result.BindIndex )
    Scaleform::GFx::Resource::Release(result.pResource);
  if ( v11 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v11);
}
