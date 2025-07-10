bool __thiscall Scaleform::GFx::KeyboardState::IsKeyToggled(Scaleform::GFx::KeyboardState *this, int code)
{
  switch ( code )
  {
    case 20:
      return this->Toggled[1];
    case 144:
      return this->Toggled[0];
    case 145:
      return this->Toggled[2];
  }
  return 0;
}
