void __thiscall Scaleform::GFx::AS3::VM::FindProperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::PropRef *result,
        const Scaleform::GFx::AS3::Multiname *mn,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  unsigned int ScopeStackBaseInd; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *RegisteredClassTraits; // eax

  if ( this->CallStack.Size )
    ScopeStackBaseInd = this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F].ScopeStackBaseInd;
  else
    ScopeStackBaseInd = 0;
  Scaleform::GFx::AS3::FindScopeProperty(result, this, ScopeStackBaseInd, &this->ScopeStack, mn);
  if ( ((result->This.Flags & 0x1F) == 0
     || ((int)result->pSI & 1) != 0 && ((int)result->pSI & 0xFFFFFFFE) == 0
     || ((int)result->pSI & 2) != 0 && ((int)result->pSI & 0xFFFFFFFD) == 0)
    && ss->Data.Size )
  {
    Scaleform::GFx::AS3::FindScopeProperty(result, this, 0, ss, mn);
  }
  if ( (result->This.Flags & 0x1F) == 0
    || ((int)result->pSI & 1) != 0 && ((int)result->pSI & 0xFFFFFFFE) == 0
    || ((int)result->pSI & 2) != 0 && ((int)result->pSI & 0xFFFFFFFD) == 0 )
  {
    RegisteredClassTraits = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(this, mn, appDomain);
    Scaleform::GFx::AS3::FindGOProperty(
      result,
      this,
      &this->GlobalObjects,
      (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)mn,
      RegisteredClassTraits);
  }
}
