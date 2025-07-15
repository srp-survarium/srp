BOOL __thiscall Scaleform::GFx::InteractiveObject::IsValidOptAdvListMember(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::MovieImpl *proot)
{
  return (this->Flags & 0x200000) != 0
      && (((unsigned __int8)(this->Flags >> 23) ^ (unsigned __int8)(proot->Flags2 >> 3)) & 1) == 0;
}
