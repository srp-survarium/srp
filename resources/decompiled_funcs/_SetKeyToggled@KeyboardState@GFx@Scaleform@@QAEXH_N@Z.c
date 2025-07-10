void __thiscall Scaleform::GFx::KeyboardState::SetKeyToggled(
        Scaleform::GFx::KeyboardState *this,
        int code,
        bool toggle)
{
  switch ( code )
  {
    case 20:
      this->Toggled[1] = toggle;
      break;
    case 144:
      this->Toggled[0] = toggle;
      break;
    case 145:
      this->Toggled[2] = toggle;
      break;
  }
}
