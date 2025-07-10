bool __thiscall Scaleform::GFx::AS3::Value::IsValidWeakRef(Scaleform::GFx::AS3::Value *this)
{
  return (this->Flags & 0x200) == 0 || this->Bonus.pWeakProxy->pObject != 0;
}
