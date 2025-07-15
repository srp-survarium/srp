void __thiscall Scaleform::GFx::Button::OnEventUnload(Scaleform::GFx::Button *this)
{
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x1000u;
  Scaleform::GFx::Button::UnloadCharactersForState(this, None);
  Scaleform::GFx::Button::UnloadCharactersForState(this, (Scaleform::GFx::Button::ButtonState)1);
  Scaleform::GFx::Button::UnloadCharactersForState(this, (Scaleform::GFx::Button::ButtonState)2);
  Scaleform::GFx::Button::UnloadCharactersForState(this, (Scaleform::GFx::Button::ButtonState)3);
  Scaleform::GFx::InteractiveObject::OnEventUnload(this);
}
