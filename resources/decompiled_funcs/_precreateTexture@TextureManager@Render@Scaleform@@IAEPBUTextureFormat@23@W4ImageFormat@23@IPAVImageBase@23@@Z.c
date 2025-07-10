const Scaleform::Render::TextureFormat *__thiscall Scaleform::Render::TextureManager::precreateTexture(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::ImageFormat format,
        __int16 use,
        Scaleform::Render::ImageBase *pimage)
{
  const Scaleform::Render::TextureFormat *v6; // edi

  if ( pimage )
  {
    if ( (((unsigned __int16)format ^ (unsigned __int16)pimage->GetFormat(pimage)) & 0xFFF) != 0
      || pimage->GetImageType(pimage) == Type_ImageBase && (use & 0x100) == 0 )
    {
      return 0;
    }
  }
  else if ( (use & 0x4F0) == 0 )
  {
    return 0;
  }
  v6 = this->getTextureFormat(this, format);
  if ( !v6
    || (format & 0xFFFu) - 50 <= 0xB && (use & 0x4E2) != 0
    || (use & 0xC0) != 0 && !this->isScanlineCompatible(this, v6) )
  {
    return 0;
  }
  return v6;
}
