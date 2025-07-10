void __thiscall Scaleform::Render::Text::TextFormat::SetUrl(
        Scaleform::Render::Text::TextFormat *this,
        char *purl,
        unsigned int urlSz)
{
  unsigned int v3; // edi

  v3 = urlSz;
  if ( urlSz == -1 )
    v3 = strlen(purl);
  Scaleform::String::Clear(&this->Url);
  Scaleform::String::AppendString(&this->Url, purl, v3);
  this->PresentMask |= 0x100u;
}
