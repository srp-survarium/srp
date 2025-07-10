void __thiscall Scaleform::GFx::Button::OnEventUnload(Scaleform::GFx::Button *this)
{
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x1000u;
  Scaleform::GFx::Button::UnloadCharactersForState(this, Up);
  Scaleform::GFx::Button::UnloadCharactersForState(this, Over);
  Scaleform::GFx::Button::UnloadCharactersForState(this, Down);
  Scaleform::GFx::Button::UnloadCharactersForState(this, Hit);
  Scaleform::GFx::InteractiveObject::OnEventUnload(this);
}
