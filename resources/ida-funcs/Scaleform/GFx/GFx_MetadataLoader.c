void __stdcall Scaleform::GFx::GFx_MetadataLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // esi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ecx
  int TagEndPosition; // eax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ecx
  signed int v6; // edi
  unsigned __int8 *v7; // ebx
  signed int i; // ebp
  Scaleform::GFx::Stream *p_Stream; // esi
  int v10; // ecx
  unsigned int Pos; // eax
  unsigned __int8 v12; // cl
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // ecx

  v2 = p;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  TagEndPosition = Scaleform::GFx::Stream::GetTagEndPosition(&pAltStream->Stream);
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v6 = TagEndPosition + p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.Pos;
  v7 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, v6 + 1, 0);
  if ( v7 )
  {
    for ( i = 0; i < v6; ++i )
    {
      if ( v2->pAltStream )
        p_Stream = v2->pAltStream;
      else
        p_Stream = &v2->ProcessInfo.Stream;
      v10 = p_Stream->DataSize - p_Stream->Pos;
      p_Stream->UnusedBits = 0;
      if ( v10 < 1 )
        Scaleform::GFx::Stream::PopulateBuffer1(p_Stream);
      Pos = p_Stream->Pos;
      v12 = p_Stream->pBuffer[Pos];
      p_Stream->Pos = Pos + 1;
      v2 = p;
      v7[i] = v12;
    }
    Scaleform::GFx::MovieDataDef::LoadTaskData::SetMetadata(v2->pLoadData.pObject, v7, v6);
    if ( v6 >= 255 )
      v6 = 255;
    v7[v6] = 0;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v13);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  }
}
