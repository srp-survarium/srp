void __thiscall Scaleform::GFx::InteractiveObject::SetStateChangeFlags(
        Scaleform::GFx::InteractiveObject *this,
        unsigned __int8 flags)
{
  this->Flags ^= (this->Flags ^ (flags << 16)) & 0xF0000;
}
