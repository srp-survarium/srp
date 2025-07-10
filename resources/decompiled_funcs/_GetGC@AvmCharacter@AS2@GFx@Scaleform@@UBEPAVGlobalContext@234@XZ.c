Scaleform::GFx::AS2::GlobalContext *__thiscall Scaleform::GFx::AS2::AvmCharacter::GetGC(
        Scaleform::GFx::AS2::AvmCharacter *this)
{
  return (Scaleform::GFx::AS2::GlobalContext *)this->pDispObj->pASRoot[2].RefCount;
}
