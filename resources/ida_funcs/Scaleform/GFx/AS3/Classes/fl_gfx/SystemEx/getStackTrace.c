void __thiscall Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx::getStackTrace(
        Scaleform::GFx::AS3::Classes::fl_gfx::SystemEx *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::VM::GetStackTraceASString(this->pTraits.pObject->pVM, result, "\t");
}
