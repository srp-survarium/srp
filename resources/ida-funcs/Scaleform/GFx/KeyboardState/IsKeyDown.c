bool __thiscall Scaleform::GFx::KeyboardState::IsKeyDown(Scaleform::GFx::KeyboardState *this, int code)
{
  return (unsigned int)code <= 0xE4 && ((unsigned __int8)(1 << (code - 8 * (code >> 3))) & this->Keymap[code >> 3]) != 0;
}
