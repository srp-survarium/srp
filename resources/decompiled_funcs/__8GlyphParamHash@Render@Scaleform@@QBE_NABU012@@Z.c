BOOL __thiscall Scaleform::Render::GlyphParamHash::operator==(
        Scaleform::Render::GlyphParamHash *this,
        const Scaleform::Render::GlyphParamHash *key)
{
  const Scaleform::Render::GlyphParam *Param; // ecx
  const Scaleform::Render::GlyphParam *v3; // eax

  Param = this->Param;
  v3 = key->Param;
  return Param->pFont == key->Param->pFont
      && Param->GlyphIndex == v3->GlyphIndex
      && Param->FontSize == v3->FontSize
      && Param->Flags == v3->Flags
      && Param->BlurX == v3->BlurX
      && Param->BlurY == v3->BlurY
      && Param->BlurStrength == v3->BlurStrength;
}
