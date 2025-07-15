int __thiscall Scaleform::GFx::InteractiveObject::GetStateChangeFlags(Scaleform::GFx::InteractiveObject *this)
{
  return HIWORD(this->Flags) & 0xF;
}
