void __thiscall Scaleform::GFx::KeyboardState::KeyboardState(Scaleform::GFx::KeyboardState *this)
{
  this->__vftable = (Scaleform::GFx::KeyboardState_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::KeyboardState_vtbl *)&Scaleform::Render::Matrix4x4Ref<float>::`vftable';
  Scaleform::GFx::KeyboardState::KeyQueue::KeyQueue(&this->KeyQueue);
  this->pListener = 0;
  this->KeyboardIndex = 0;
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
