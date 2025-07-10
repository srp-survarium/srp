void __thiscall Scaleform::GFx::Button::PropagateMouseEvent(
        Scaleform::GFx::Button *this,
        const Scaleform::GFx::EventId *evt)
{
  if ( evt->Id == 8 )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(this, evt->ControllerIndex);
  this->OnEvent(this, evt);
}
