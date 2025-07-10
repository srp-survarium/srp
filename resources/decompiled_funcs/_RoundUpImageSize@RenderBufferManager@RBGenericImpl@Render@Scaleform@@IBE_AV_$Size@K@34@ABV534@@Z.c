Scaleform::Render::Size<unsigned long> *__thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::RoundUpImageSize(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        Scaleform::Render::Size<unsigned long> *result,
        const Scaleform::Render::Size<unsigned long> *size)
{
  unsigned int v3; // edx
  unsigned int i; // ecx
  unsigned int Height; // eax
  Scaleform::Render::Size<unsigned long> *v6; // eax
  unsigned int v7; // edx
  unsigned int v8; // ecx

  if ( this->RequirePow2 )
  {
    v3 = 1;
    for ( i = 1; v3 < size->Width; v3 *= 2 )
      ;
    Height = size->Height;
    if ( Height > 1 )
    {
      do
        i *= 2;
      while ( i < Height );
    }
    v6 = result;
    result->Width = v3;
    result->Height = i;
  }
  else
  {
    v7 = 32;
    if ( ((size->Height + 31) & 0xFFFFFFE0) >= 0x20 )
      v7 = (size->Height + 31) & 0xFFFFFFE0;
    v8 = 32;
    if ( ((size->Width + 31) & 0xFFFFFFE0) >= 0x20 )
      v8 = (size->Width + 31) & 0xFFFFFFE0;
    v6 = result;
    result->Width = v8;
    result->Height = v7;
  }
  return v6;
}
