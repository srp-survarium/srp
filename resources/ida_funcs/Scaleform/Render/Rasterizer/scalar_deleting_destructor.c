Scaleform::Render::Rasterizer *__thiscall Scaleform::Render::Rasterizer::`scalar deleting destructor'(
        Scaleform::Render::Rasterizer *this,
        char a2)
{
  Scaleform::Render::LinearHeap::ClearAndRelease(&this->LHeap);
  this->__vftable = (Scaleform::Render::Rasterizer_vtbl *)&Scaleform::Render::TessBase::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
