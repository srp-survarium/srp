Scaleform::Render::D3D1x::RenderEvent *__thiscall Scaleform::Render::D3D1x::RenderEvent::`vector deleting destructor'(
        Scaleform::Render::D3D1x::RenderEvent *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::D3D1x::RenderEvent_vtbl *)&Scaleform::Render::RenderEvent::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
