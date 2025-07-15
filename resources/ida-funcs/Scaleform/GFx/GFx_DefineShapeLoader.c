void __stdcall Scaleform::GFx::GFx_DefineShapeLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // edi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned __int16 v5; // cx
  Scaleform::GFx::Resource *v6; // eax
  Scaleform::GFx::Resource *v7; // edi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ecx
  Scaleform::GFx::SwfShapeCharacterDef *v9; // eax
  Scaleform::GFx::Resource *v10; // eax
  Scaleform::GFx::Resource *v11; // ebx
  Scaleform::GFx::SWFProcessInfo *v12; // eax
  const Scaleform::Render::Rect<float> *v13; // eax
  Scaleform::GFx::Stream *p_Stream; // [esp+3Ch] [ebp-18h]
  Scaleform::GFx::ResourceId v15; // [esp+40h] [ebp-14h]
  _BYTE v16[16]; // [esp+44h] [ebp-10h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v15.Id = v5;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  ShapeLoader: id = %d\n",
    v5);
  v6 = (Scaleform::GFx::Resource *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 64, 0);
  if ( v6 )
  {
    v6->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v6->RefCount.Value = 1;
    v6->pLib = 0;
    LOBYTE(v6[1].__vftable) = 0;
    v6->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
    v6[1].RefCount.Value = 0;
    v6[1].pLib = 0;
    v6[2].__vftable = 0;
    *(float *)&v6[2].pLib = 0.0;
    *(float *)&v6[3].__vftable = 0.0;
    v7 = v6;
    *(float *)&v6[3].RefCount.Value = 0.0;
    *(float *)&v6[3].pLib = 0.0;
    *(float *)&v6[4].__vftable = 0.0;
    *(float *)&v6[4].RefCount.Value = 0.0;
    *(float *)&v6[4].pLib = 0.0;
    *(float *)&v6[5].__vftable = 0.0;
  }
  else
  {
    v7 = 0;
  }
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  ((void (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::LoadProcess *, Scaleform::GFx::TagType, unsigned int, int))v7->__vftable[3].GetResourceReport)(
    v7,
    p,
    tagInfo->TagType,
    tagInfo->TagLength
  + tagInfo->TagDataOffset
  - (p_ProcessInfo->Stream.Pos
   + p_ProcessInfo->Stream.FilePos
   - p_ProcessInfo->Stream.DataSize),
    1);
  v9 = (Scaleform::GFx::SwfShapeCharacterDef *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 24, 0);
  if ( v9 )
  {
    Scaleform::GFx::SwfShapeCharacterDef::SwfShapeCharacterDef(v9, v7);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  bound rect:");
  v12 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v12 )
    v12 = &p->ProcessInfo;
  p_Stream = &v12->Stream;
  v13 = (const Scaleform::Render::Rect<float> *)((int (__thiscall *)(Scaleform::GFx::Resource *, _BYTE *, _DWORD))v11->__vftable[1].GetResourceReport)(
                                                  v11,
                                                  v16,
                                                  0.0);
  Scaleform::GFx::Stream::LogParseClass(p_Stream, v13);
  if ( p->LoadState == LS_LoadingRoot )
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, v15, v11);
  Scaleform::GFx::Resource::Release(v11);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
}
