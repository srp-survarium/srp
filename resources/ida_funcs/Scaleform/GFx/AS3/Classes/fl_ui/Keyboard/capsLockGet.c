void __thiscall Scaleform::GFx::AS3::Classes::fl_ui::Keyboard::capsLockGet(
        Scaleform::GFx::AS3::Classes::fl_ui::Keyboard *this,
        bool *result)
{
  Scaleform::KeyModifiers sks; // [esp+1h] [ebp-1h] BYREF

  sks.States = HIBYTE(this);
  Scaleform::GFx::KeyboardState::GetKeyModifiers(
    (Scaleform::GFx::KeyboardState *)((char *)this->pTraits.pObject->pVM[1].__vftable[1].~Scaleform::GFx::AS3::VM + 4936),
    &sks);
  *result = (sks.States & 8) != 0;
}
