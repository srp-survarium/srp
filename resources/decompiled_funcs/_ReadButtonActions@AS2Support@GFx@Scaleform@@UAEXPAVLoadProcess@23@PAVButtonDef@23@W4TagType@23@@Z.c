void __thiscall Scaleform::GFx::AS2Support::ReadButtonActions(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::ButtonDef *pbuttonDef,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::Resource *v4; // eax
  Scaleform::GFx::Resource *v5; // ebx
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ecx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  int v8; // esi
  int TagEndPosition; // eax
  Scaleform::GFx::SWFProcessInfo *v10; // ecx

  v4 = (Scaleform::GFx::Resource *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 24, 0);
  if ( v4 )
  {
    v4->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v4->RefCount.Value = 1;
    v4->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::GFx::AS2::ButtonAction::`vftable';
    v4[1].__vftable = 0;
    v4[1].RefCount.Value = 0;
    v4[1].pLib = 0;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  Scaleform::GFx::ButtonDef::AddButtonAction(pbuttonDef, v5);
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  p_ProcessInfo = &p->ProcessInfo;
  if ( pAltStream )
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v8 = p_ProcessInfo->Stream.Pos + p_ProcessInfo->Stream.FilePos - p_ProcessInfo->Stream.DataSize;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  TagEndPosition = Scaleform::GFx::Stream::GetTagEndPosition(&pAltStream->Stream);
  v10 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v10 )
    v10 = &p->ProcessInfo;
  ((void (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::SWFProcessInfo *, Scaleform::GFx::TagType, int))v5->GetKey)(
    v5,
    v10,
    tagType,
    TagEndPosition - v8);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v5);
}
