unsigned int __thiscall Scaleform::GFx::LoadProcess::Tell(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ecx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  return pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize;
}
