void __stdcall Scaleform::GFx::GFx_CSMTextSettings(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v7; // dx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  unsigned __int16 v9; // bp
  int v10; // eax
  int v11; // edx
  unsigned int v12; // ecx
  int v13; // edx
  unsigned int v14; // eax
  int v15; // ecx
  unsigned int v16; // ecx
  int v17; // edx
  const char *v18; // eax
  unsigned int SizeMask; // esi
  int v20; // [esp+20h] [ebp-14h]
  float v21; // [esp+24h] [ebp-10h]
  float v22; // [esp+28h] [ebp-Ch]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType v23; // [esp+2Ch] [ebp-8h] BYREF
  int UInt; // [esp+38h] [ebp+4h]

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
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v9 = (unsigned __int16)pBuffer | (v7 << 8);
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  UInt = Scaleform::GFx::Stream::ReadUInt(&p_ProcessInfo->Stream, 2);
  v10 = Scaleform::GFx::Stream::ReadUInt(&p_ProcessInfo->Stream, 3);
  v11 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
  v20 = v10;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v11 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 4);
  v12 = p_ProcessInfo->Stream.Pos;
  v13 = p_ProcessInfo->Stream.pBuffer[v12]
      | ((p_ProcessInfo->Stream.pBuffer[v12 + 1]
        | ((p_ProcessInfo->Stream.pBuffer[v12 + 2] | (p_ProcessInfo->Stream.pBuffer[v12 + 3] << 8)) << 8)) << 8);
  v14 = v12 + 4;
  v15 = p_ProcessInfo->Stream.DataSize - (v12 + 4);
  v22 = *(float *)&v13;
  p_ProcessInfo->Stream.Pos = v14;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v15 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 4);
  v16 = p_ProcessInfo->Stream.Pos;
  v17 = p_ProcessInfo->Stream.pBuffer[v16]
      | ((p_ProcessInfo->Stream.pBuffer[v16 + 1] | (*(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v16 + 2] << 8)) << 8);
  p_ProcessInfo->Stream.Pos = v16 + 4;
  v21 = *(float *)&v17;
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&p_ProcessInfo->Stream) )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "CSMTextSettings, id = %d\n",
      v9);
    v18 = "System";
    if ( UInt )
      v18 = "Internal";
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  FlagType = %s, GridFit = %s\n",
      v18,
      gridfittypes[v20]);
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  Thinkness = %f, Sharpnesss = %f\n",
      v22,
      v21);
  }
  v23.EntryCount = 0;
  v23.SizeMask = 0;
  if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
         p->pLoadData.pObject,
         &v23,
         (Scaleform::GFx::ResourceId)v9) )
  {
    if ( v23.EntryCount )
      return;
    SizeMask = v23.SizeMask;
    if ( !v23.SizeMask )
      return;
    if ( ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)v23.SizeMask + 8))(v23.SizeMask) & 0xFF00) == 0x8300 )
    {
      *(_WORD *)(SizeMask + 84) |= 0x400u;
    }
    else if ( ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)SizeMask + 8))(SizeMask) & 0xFF00) == 0x8200 )
    {
      *(_BYTE *)(SizeMask + 76) |= 1u;
    }
  }
  if ( !v23.EntryCount )
  {
    if ( v23.SizeMask )
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v23.SizeMask);
  }
}
