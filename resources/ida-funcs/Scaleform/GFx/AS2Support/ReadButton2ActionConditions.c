void __thiscall Scaleform::GFx::AS2Support::ReadButton2ActionConditions(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::ButtonDef *pbuttonDef,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v6; // eax
  unsigned int Pos; // eax
  unsigned __int16 v8; // cx
  int v9; // esi
  int v10; // ebp
  int v11; // ebx
  Scaleform::GFx::Resource *v12; // eax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ecx
  int TagEndPosition; // ebp
  Scaleform::GFx::SWFProcessInfo *Stream; // eax
  Scaleform::GFx::SWFProcessInfo *v16; // eax
  signed int v17; // esi
  Scaleform::GFx::SWFProcessInfo *v18; // eax
  Scaleform::GFx::Resource_vtbl *v19; // [esp+10h] [ebp-4h]
  Scaleform::GFx::Resource *pa; // [esp+18h] [ebp+4h]

  while ( 1 )
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !pAltStream )
      pAltStream = &p->ProcessInfo;
    v6 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v6 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    Pos = pAltStream->Stream.Pos;
    v8 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
    pAltStream->Stream.Pos = Pos + 2;
    v9 = v8;
    v10 = v8 - 2;
    v11 = v10 + Scaleform::GFx::LoadProcess::Tell(p);
    v12 = (Scaleform::GFx::Resource *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 24, 0);
    if ( v12 )
    {
      v12->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v12->RefCount.Value = 1;
      v12->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AS2::ButtonAction::`vftable';
      v12[1].__vftable = 0;
      v12[1].RefCount.Value = 0;
      v12[1].pLib = 0;
      pa = v12;
    }
    else
    {
      pa = 0;
    }
    Scaleform::GFx::ButtonDef::AddButtonAction(pbuttonDef, pa);
    if ( !v9 )
    {
      p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !p_ProcessInfo )
        p_ProcessInfo = &p->ProcessInfo;
      TagEndPosition = Scaleform::GFx::Stream::GetTagEndPosition(&p_ProcessInfo->Stream);
      v10 = TagEndPosition - Scaleform::GFx::LoadProcess::Tell(p);
    }
    v19 = pa->__vftable;
    Stream = Scaleform::GFx::LoadProcess::GetStream(p);
    ((void (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::SWFProcessInfo *, Scaleform::GFx::TagType, int))v19->GetKey)(
      pa,
      Stream,
      tagType,
      v10);
    if ( !v9 )
      break;
    v16 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v16 )
      v16 = &p->ProcessInfo;
    v17 = Scaleform::GFx::Stream::GetTagEndPosition(&v16->Stream);
    if ( (int)Scaleform::GFx::LoadProcess::Tell(p) >= v17 )
      break;
    v18 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v18 )
      v18 = &p->ProcessInfo;
    Scaleform::GFx::Stream::SetPosition(&v18->Stream, v11);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pa);
  }
  if ( pa )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pa);
}
