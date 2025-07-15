unsigned int __thiscall Scaleform::Render::GlyphCache::GetNumTextures(Scaleform::Render::GlyphCache *this)
{
  unsigned int MaxNumTextures; // edx
  unsigned int result; // eax
  Scaleform::Render::GlyphTextureMapper *Textures; // ecx

  MaxNumTextures = this->MaxNumTextures;
  result = 0;
  if ( MaxNumTextures )
  {
    Textures = this->Textures;
    do
    {
      if ( Textures->Valid )
        ++result;
      ++Textures;
      --MaxNumTextures;
    }
    while ( MaxNumTextures );
  }
  return result;
}
