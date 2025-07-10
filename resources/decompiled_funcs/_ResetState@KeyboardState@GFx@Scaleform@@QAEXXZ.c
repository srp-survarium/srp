void __thiscall Scaleform::GFx::KeyboardState::ResetState(Scaleform::GFx::KeyboardState *this)
{
  this->KeyQueue.PutIdx = 0;
  this->KeyQueue.GetIdx = 0;
  this->KeyQueue.Count = 0;
  memset((int)&this->KeyQueue, 0, 0x640u);
  *(_DWORD *)this->Keymap = 0;
  *(_DWORD *)&this->Keymap[4] = 0;
  *(_DWORD *)&this->Keymap[8] = 0;
  *(_DWORD *)&this->Keymap[12] = 0;
  *(_DWORD *)&this->Keymap[16] = 0;
  *(_DWORD *)&this->Keymap[20] = 0;
  *(_DWORD *)&this->Keymap[24] = 0;
  this->Keymap[28] = 0;
  *(_WORD *)this->Toggled = 0;
  this->Toggled[2] = 0;
}
