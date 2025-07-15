void __thiscall Scaleform::GFx::SetBackgroundColorTag::Read(
        Scaleform::GFx::SetBackgroundColorTag *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ecx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadRgb(&pAltStream->Stream, &this->Color);
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  SetBackgroundColor: (%d %d %d)\n",
    this->Color.Channels.Red,
    this->Color.Channels.Green,
    this->Color.Channels.Blue);
}
