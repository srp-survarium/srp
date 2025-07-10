char __thiscall Scaleform::Render::GlyphCache::SetParams(
        Scaleform::Render::GlyphCache *this,
        const Scaleform::Render::GlyphCacheParams *params)
{
  float ShadowQuality; // ecx

  qmemcpy((void *)&this->RefCount, params, 0x38u);
  ShadowQuality = this->Param.ShadowQuality;
  if ( ShadowQuality != 0.0
    && (*(unsigned __int8 (__thiscall **)(float))(*(_DWORD *)LODWORD(ShadowQuality) + 12))(COERCE_FLOAT(LODWORD(ShadowQuality))) )
  {
    Scaleform::Render::GlyphCache::initialize((Scaleform::Render::GlyphCache *)((char *)this - 12));
  }
  return 1;
}
