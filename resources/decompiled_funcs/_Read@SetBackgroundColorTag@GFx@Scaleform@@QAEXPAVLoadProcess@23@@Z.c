void __thiscall Scaleform::GFx::SetBackgroundColorTag::Read(
        Scaleform::GFx::SetBackgroundColorTag *this,
        Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ecx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  Scaleform::GFx::Stream::ReadRgb(&pAltStream->Stream, &this->Color);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this->Color.Channels.Green);
}
