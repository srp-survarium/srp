void __stdcall Scaleform::GFx::GFx_CSMTextSettings(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v6; // dx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  unsigned __int16 v8; // bp
  int UInt; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v13; // ecx
  unsigned int BindIndex; // esi
  unsigned int gridFit; // [esp+20h] [ebp-14h]
  Scaleform::GFx::ResourceHandle handle; // [esp+2Ch] [ebp-8h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  pBuffer = pAltStream->Stream.pBuffer;
  v6 = pBuffer[Pos + 1];
  LOWORD(pBuffer) = pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v8 = (unsigned __int16)pBuffer | (v6 << 8);
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadUInt(&p_ProcessInfo->Stream, 2);
  UInt = Scaleform::GFx::Stream::ReadUInt(&p_ProcessInfo->Stream, 3);
  v10 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
  gridFit = UInt;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v10 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 4);
  v11 = p_ProcessInfo->Stream.Pos + 4;
  v12 = p_ProcessInfo->Stream.DataSize - v11;
  p_ProcessInfo->Stream.Pos = v11;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v12 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 4);
  p_ProcessInfo->Stream.Pos += 4;
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&p_ProcessInfo->Stream) )
  {
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v8);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)gridfittypes[gridFit]);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v13);
  }
  handle.HType = RH_Pointer;
  handle.BindIndex = 0;
  if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
         p->pLoadData.pObject,
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&handle,
         (Scaleform::GFx::ResourceId)v8) )
  {
    if ( handle.HType )
      return;
    BindIndex = handle.BindIndex;
    if ( !handle.BindIndex )
      return;
    if ( ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)handle.BindIndex + 8))(handle.BindIndex) & 0xFF00) == 0x8300 )
    {
      *(_WORD *)(BindIndex + 84) |= 0x400u;
    }
    else if ( ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)BindIndex + 8))(BindIndex) & 0xFF00) == 0x8200 )
    {
      *(_BYTE *)(BindIndex + 76) |= 1u;
    }
  }
  if ( handle.HType == RH_Pointer )
  {
    if ( handle.BindIndex )
      Scaleform::GFx::Resource::Release(handle.pResource);
  }
}
