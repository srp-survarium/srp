void __thiscall Scaleform::GFx::InteractiveObject::SetStateChangeFlags(
        Scaleform::GFx::InteractiveObject *this,
        unsigned __int8 flags)
{
  this->Flags ^= (unsigned int)&locret_F0000 & (this->Flags ^ (flags << 16));
}
