Scaleform::GFx::AS3::VMAppDomain *__thiscall Scaleform::GFx::AS3::Traits::GetAppDomain(
        Scaleform::GFx::AS3::Traits *this)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx

  pVM = this->pVM;
  if ( pVM->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    return pVM->CallStack.Pages[(pVM->CallStack.Size - 1) >> 6][(pVM->CallStack.Size - 1) & 0x3F].pFile->AppDomain;
  else
    return pVM->CurrentDomain;
}
