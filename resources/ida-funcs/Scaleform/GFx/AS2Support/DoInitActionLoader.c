void __thiscall Scaleform::GFx::AS2Support::DoInitActionLoader(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int16 v6; // cx
  int v7; // ebp
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // eax
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // edx
  int v12; // esi
  unsigned __int8 *v13; // eax
  Scaleform::GFx::AS2::DoActionTag *v14; // ebp
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *p_InitActionTags; // edi
  unsigned int v16; // esi
  Scaleform::GFx::AS2::DoActionTag **v17; // eax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v4 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v7 = v6;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  tag %d: DoInitActionLoader\n",
    tagInfo->TagType);
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParseAction(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  -- init actions for sprite %d\n",
    v7);
  pObject = p->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 8 )
  {
    v13 = Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 8u);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    v12 = (int)(p_TagMemAllocator->pCurrent + 8);
    p_TagMemAllocator->BytesLeft = BytesLeft - 8;
    p_TagMemAllocator->pCurrent = (unsigned __int8 *)v12;
    v13 = pCurrent;
  }
  if ( v13 )
  {
    *((_DWORD *)v13 + 1) = 0;
    *(_DWORD *)v13 = &Scaleform::GFx::AS2::DoInitActionTag::`vftable';
    v14 = (Scaleform::GFx::AS2::DoActionTag *)v13;
  }
  else
  {
    v14 = 0;
  }
  Scaleform::GFx::AS2::DoActionTag::Read(v14, p);
  p_InitActionTags = &p->InitActionTags;
  v16 = p->InitActionTags.Data.Size + 1;
  if ( v16 >= p->InitActionTags.Data.Size )
  {
    if ( v16 >= p->InitActionTags.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
        &p_InitActionTags->Data,
        p_InitActionTags,
        v16 + (v16 >> 2));
  }
  else if ( v16 < p->InitActionTags.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
      &p_InitActionTags->Data,
      p_InitActionTags,
      v16);
  }
  v17 = (Scaleform::GFx::AS2::DoActionTag **)&p_InitActionTags->Data.Data[v16 - 1];
  p->InitActionTags.Data.Size = v16;
  if ( v17 )
    *v17 = v14;
}
