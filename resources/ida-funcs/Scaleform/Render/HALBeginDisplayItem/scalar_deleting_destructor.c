Scaleform::Render::SKI_BlendMode::RQII_BlendMode *__thiscall Scaleform::Render::HALBeginDisplayItem::`scalar deleting destructor'(
        Scaleform::Render::SKI_BlendMode::RQII_BlendMode *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::SKI_BlendMode::RQII_BlendMode_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
