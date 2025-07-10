Scaleform::GFx::AS3::VMAppDomain *__thiscall Scaleform::GFx::AS3::VM::GetFrameAppDomain(Scaleform::GFx::AS3::VM *this)
{
  if ( this->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    return this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F].pFile->AppDomain;
  else
    return this->CurrentDomain;
}
