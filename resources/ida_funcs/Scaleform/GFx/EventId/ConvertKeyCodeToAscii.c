char __thiscall Scaleform::GFx::EventId::ConvertKeyCodeToAscii(Scaleform::GFx::EventId *this)
{
  char result; // al
  char v2; // dl
  unsigned int KeyCode; // ecx

  result = 0;
  v2 = this->KeysState.States & 1;
  if ( (this->KeysState.States & 8) != 0 )
    v2 = v2 == 0;
  KeyCode = this->KeyCode;
  if ( KeyCode < 0x20 || KeyCode > 0x70 )
  {
    if ( KeyCode >= 0xBA && KeyCode <= 0x10A )
    {
      if ( v2 )
        return byte_85A276[KeyCode];
      else
        return byte_85A29E[KeyCode];
    }
  }
  else if ( v2 )
  {
    return ascii2[KeyCode + 8];
  }
  else
  {
    return asciiShift1[KeyCode + 48];
  }
  return result;
}
