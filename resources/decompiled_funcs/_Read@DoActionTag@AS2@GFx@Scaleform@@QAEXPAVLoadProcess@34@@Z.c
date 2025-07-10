void __thiscall Scaleform::GFx::AS2::DoActionTag::Read(
        Scaleform::GFx::AS2::DoActionTag *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ebp
  Scaleform::GFx::AS2::ActionBufferData *New; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::AS2::ActionBufferData *v6; // edi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // eax
  int TagEndPosition; // eax
  Scaleform::GFx::SWFProcessInfo *v9; // ecx

  p_ProcessInfo = &p->ProcessInfo;
  if ( p->pAltStream )
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  New = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
  pObject = (Scaleform::RefCountVImpl *)this->pBuf.pObject;
  v6 = New;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pBuf.pObject = v6;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  TagEndPosition = Scaleform::GFx::Stream::GetTagEndPosition(&pAltStream->Stream);
  v9 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v9 )
    v9 = &p->ProcessInfo;
  Scaleform::GFx::AS2::ActionBufferData::Read(
    this->pBuf.pObject,
    &p_ProcessInfo->Stream,
    TagEndPosition + v9->Stream.DataSize - v9->Stream.FilePos - v9->Stream.Pos);
}
