void __thiscall Scaleform::GFx::KeyboardState::SetKeyDown(
        Scaleform::GFx::KeyboardState *this,
        int code,
        unsigned __int8 ascii,
        Scaleform::KeyModifiers mods,
        bool putInQueue)
{
  if ( (unsigned int)code <= 0xE4 )
  {
    this->Keymap[code >> 3] |= 1 << (code - 8 * (code >> 3));
    if ( putInQueue )
      Scaleform::GFx::KeyboardState::KeyQueue::Put(&this->KeyQueue, code, ascii, 0, KeyDown, mods);
  }
}
