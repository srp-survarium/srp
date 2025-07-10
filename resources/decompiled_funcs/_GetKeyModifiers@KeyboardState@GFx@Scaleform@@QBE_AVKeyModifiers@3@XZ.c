Scaleform::KeyModifiers *__thiscall Scaleform::GFx::KeyboardState::GetKeyModifiers(
        Scaleform::GFx::KeyboardState *this,
        Scaleform::KeyModifiers *result)
{
  Scaleform::KeyModifiers *v2; // eax
  unsigned __int8 v3; // dl

  v2 = result;
  v3 = this->Keymap[2];
  result->States = 0;
  result->States = v3 & 4;
  if ( (v3 & 2) != 0 )
    result->States |= 2u;
  else
    result->States &= ~2u;
  if ( (v3 & 1) != 0 )
    result->States |= 1u;
  else
    result->States &= ~1u;
  if ( this->Toggled[0] )
    result->States |= 0x10u;
  else
    result->States &= ~0x10u;
  if ( this->Toggled[1] )
    result->States |= 8u;
  else
    result->States &= ~8u;
  if ( this->Toggled[2] )
    result->States |= 0x20u;
  else
    result->States &= ~0x20u;
  return v2;
}
