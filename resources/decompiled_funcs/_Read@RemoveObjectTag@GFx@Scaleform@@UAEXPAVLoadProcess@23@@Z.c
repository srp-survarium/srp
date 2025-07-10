void __thiscall Scaleform::GFx::RemoveObjectTag::Read(
        Scaleform::GFx::RemoveObjectTag *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int16 v6; // dx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  int v8; // edx
  unsigned int v9; // eax
  unsigned __int16 v10; // dx

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
  this->Id = v6;
  p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !p_ProcessInfo )
    p_ProcessInfo = &p->ProcessInfo;
  v8 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v8 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
  v9 = p_ProcessInfo->Stream.Pos;
  v10 = *(_WORD *)&p_ProcessInfo->Stream.pBuffer[v9];
  p_ProcessInfo->Stream.Pos = v9 + 2;
  this->Depth = v10;
}
