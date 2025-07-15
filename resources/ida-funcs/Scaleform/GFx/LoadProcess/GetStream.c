Scaleform::GFx::SWFProcessInfo *__thiscall Scaleform::GFx::LoadProcess::GetStream(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *result; // eax

  result = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !result )
    return &this->ProcessInfo;
  return result;
}
