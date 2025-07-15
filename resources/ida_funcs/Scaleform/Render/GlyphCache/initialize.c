void __thiscall Scaleform::Render::GlyphCache::Initialize(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::HAL *ren,
        Scaleform::Render::PrimitiveFillManager *fillMan)
{
  this->pFillMan = fillMan;
  this->pRenderer = ren;
  if ( ren->IsInitialized(ren) )
    Scaleform::Render::GlyphCache::initialize(this);
}
