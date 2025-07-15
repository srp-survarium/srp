void __thiscall Scaleform::GFx::KeyboardState::KeyQueue::KeyQueue(Scaleform::GFx::KeyboardState::KeyQueue *this)
{
  int v2; // ecx
  Scaleform::KeyModifiers *p_keyMods; // eax

  v2 = 99;
  p_keyMods = &this->Buffer[0].keyMods;
  do
  {
    p_keyMods->States = 0;
    p_keyMods += 16;
    --v2;
  }
  while ( v2 >= 0 );
  this->PutIdx = 0;
  this->GetIdx = 0;
  this->Count = 0;
  memset((int)this, 0, 0x640u);
}
