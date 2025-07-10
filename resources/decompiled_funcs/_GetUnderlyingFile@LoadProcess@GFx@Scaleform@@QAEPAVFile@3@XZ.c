Scaleform::File *__thiscall Scaleform::GFx::LoadProcess::GetUnderlyingFile(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::File *result; // eax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  Scaleform::GFx::Stream::SyncFileStream(&pAltStream->Stream);
  result = pAltStream->Stream.pInput.pObject;
  pAltStream->Stream.ResyncFile = 1;
  return result;
}
