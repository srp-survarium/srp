Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::Environment::LocalRegisterPtr(
        Scaleform::GFx::AS2::Environment *this,
        unsigned int reg)
{
  unsigned int Size; // eax

  Size = this->LocalRegister.Data.Size;
  if ( reg < Size )
    return &this->LocalRegister.Data.Data[Size - reg - 1];
  Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
    this,
    "Invalid local register %d, stack only has %d entries",
    reg,
    Size);
  return this->GlobalRegister;
}
