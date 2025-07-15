void __thiscall Scaleform::GFx::KeyboardState::KeyQueue::Put(
        Scaleform::GFx::KeyboardState::KeyQueue *this,
        __int16 code,
        unsigned __int8 ascii,
        unsigned int wcharCode,
        Scaleform::GFx::Event::EventType event,
        Scaleform::KeyModifiers specialKeysState)
{
  if ( this->Count < 0x64 )
  {
    this->Buffer[this->PutIdx].code = code;
    this->Buffer[this->PutIdx].ascii = ascii;
    this->Buffer[this->PutIdx].wcharCode = wcharCode;
    this->Buffer[this->PutIdx].event = event;
    this->Buffer[this->PutIdx++].keyMods = specialKeysState;
    if ( this->PutIdx >= 0x64 )
      this->PutIdx = 0;
    ++this->Count;
  }
}
