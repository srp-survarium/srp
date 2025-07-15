void __thiscall Scaleform::GFx::LoadProcess::ReadRgbaTag(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::Render::Color *pc,
        int tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // eax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( tagType > 22 )
  {
    if ( !pAltStream )
      pAltStream = &this->ProcessInfo;
    Scaleform::GFx::Stream::ReadRgba(&pAltStream->Stream, pc);
  }
  else
  {
    if ( !pAltStream )
      pAltStream = &this->ProcessInfo;
    Scaleform::GFx::Stream::ReadRgb(&pAltStream->Stream, pc);
  }
}
