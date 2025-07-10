void __thiscall Scaleform::Render::Text::TextFormat::SetUrl(
        Scaleform::Render::Text::TextFormat *this,
        const wchar_t *purl,
        unsigned int urlSz)
{
  int v3; // ebx

  v3 = urlSz;
  if ( urlSz == -1 )
    v3 = Scaleform::SFwcslen(purl);
  Scaleform::String::Clear(&this->Url);
  Scaleform::String::AppendString(&this->Url, purl, v3);
  this->PresentMask |= 0x100u;
}
