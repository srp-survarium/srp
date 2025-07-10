Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VM::ConstructBuiltinValue(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::Value *v,
        const char *gname,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::CheckResult *v7; // eax

  Scaleform::GFx::AS3::VM::Construct(this, gname, this->CurrentDomain, v, argc, argv, 1);
  if ( !this->HandleException && (v->Flags & 0x1F) != 0 && ((v->Flags & 0x1F) - 12 > 3 || v->value.VS._1.VInt) )
  {
    v7 = result;
    result->Result = 1;
  }
  else
  {
    v7 = result;
    result->Result = 0;
  }
  return v7;
}
