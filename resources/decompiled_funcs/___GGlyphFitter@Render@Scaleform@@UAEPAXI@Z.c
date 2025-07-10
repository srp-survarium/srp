Scaleform::Render::GlyphFitter *__thiscall Scaleform::Render::GlyphFitter::`scalar deleting destructor'(
        Scaleform::Render::GlyphFitter *this,
        char a2)
{
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->LHeap);
  this->__vftable = (Scaleform::Render::GlyphFitter_vtbl *)&Scaleform::Render::TessBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
