void __thiscall Scaleform::GFx::AS2::DoActionTag::Read(
        Scaleform::GFx::AS2::DoActionTag *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ebx
  Scaleform::GFx::AS2::ActionBufferData *New; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::AS2::ActionBufferData *v6; // ebp
  unsigned int SWFFlags; // ecx
  unsigned int v8; // eax
  unsigned int NextActionBlock; // edx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  int TagEndPosition; // eax
  Scaleform::GFx::SWFProcessInfo *v12; // ecx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  New = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
  pObject = (Scaleform::RefCountVImpl *)this->pBuf.pObject;
  v6 = New;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pBuf.pObject = v6;
  SWFFlags = p->ProcessInfo.Header.SWFFlags;
  v8 = pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize;
  if ( (SWFFlags & 0x10) != 0 )
  {
    NextActionBlock = p->ProcessInfo.NextActionBlock;
    if ( p->ProcessInfo.Header.mExporterInfo.CodeOffsets.Data.Size > NextActionBlock )
    {
      p->ProcessInfo.NextActionBlock = NextActionBlock + 1;
      v8 = p->ProcessInfo.Header.mExporterInfo.CodeOffsets.Data.Data[NextActionBlock];
    }
  }
  if ( (SWFFlags & 1) != 0 )
    v8 += 8;
  this->pBuf.pObject->SWFFileOffset = v8;
  this->pBuf.pObject->SwdHandle = p->pLoadData.pObject->SwdHandle;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  TagEndPosition = Scaleform::GFx::Stream::GetTagEndPosition(&p_ProcessInfo->Stream);
  v12 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !v12 )
    v12 = &p->ProcessInfo;
  Scaleform::GFx::AS2::ActionBufferData::Read(
    this->pBuf.pObject,
    &pAltStream->Stream,
    TagEndPosition + v12->Stream.DataSize - v12->Stream.FilePos - v12->Stream.Pos);
}
