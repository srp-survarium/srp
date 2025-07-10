Scaleform::Render::RenderEvent *__thiscall Scaleform::Render::RenderEvent::`vector deleting destructor'(
        Scaleform::Render::RenderEvent *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::RenderEvent_vtbl *)&Scaleform::Render::RenderEvent::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
