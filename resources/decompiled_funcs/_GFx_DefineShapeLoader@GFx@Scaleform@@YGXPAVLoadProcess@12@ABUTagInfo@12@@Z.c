void __stdcall Scaleform::GFx::GFx_DefineShapeLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // edi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned __int16 v5; // cx
  Scaleform::GFx::ShapeDataBase *v6; // eax
  Scaleform::GFx::ShapeDataBase *v7; // edi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ecx
  Scaleform::GFx::SwfShapeCharacterDef *v9; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v10; // ecx
  Scaleform::GFx::Resource *v11; // eax
  Scaleform::GFx::Resource *v12; // ebx
  Scaleform::GFx::ResourceId v13; // [esp+30h] [ebp-14h]
  _BYTE v14[16]; // [esp+34h] [ebp-10h] BYREF

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
  v13.Id = v5;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>);
  v6 = (Scaleform::GFx::ShapeDataBase *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 64, 0);
  if ( v6 )
  {
    v6->__vftable = (Scaleform::GFx::ShapeDataBase_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v6->RefCount = 1;
    v6->Paths = 0;
    v6->Flags = 0;
    v6->__vftable = (Scaleform::GFx::ShapeDataBase_vtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
    v6[1].__vftable = 0;
    v6[1].RefCount = 0;
    v6[1].Paths = 0;
    *(float *)&v6[2].__vftable = 0.0;
    *(float *)&v6[2].RefCount = 0.0;
    v7 = v6;
    *(float *)&v6[2].Paths = 0.0;
    *(float *)&v6[2].Flags = 0.0;
    *(float *)&v6[3].__vftable = 0.0;
    *(float *)&v6[3].RefCount = 0.0;
    *(float *)&v6[3].Paths = 0.0;
    *(float *)&v6[3].Flags = 0.0;
  }
  else
  {
    v7 = 0;
  }
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v7->Read(
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
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v10);
  ((void (__thiscall *)(Scaleform::GFx::Resource *, _BYTE *, _DWORD))v12->__vftable[1].GetResourceReport)(v12, v14, 0.0);
  if ( p->LoadState == LS_LoadingRoot )
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, v13, v12);
  Scaleform::GFx::Resource::Release(v12);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
}
