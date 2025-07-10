Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::PropRef::SetSlotValue(
        Scaleform::GFx::AS3::PropRef *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::SlotInfo *pSI; // ecx
  Scaleform::GFx::AS3::CheckResult *v6; // eax

  pSI = (Scaleform::GFx::AS3::SlotInfo *)this->pSI;
  if ( ((unsigned __int8)pSI & 3) != 0 )
  {
    if ( ((unsigned __int8)pSI & 3) == 1 )
    {
      Scaleform::GFx::AS3::Value::Assign((Scaleform::GFx::AS3::Value *)((unsigned int)pSI & 0xFFFFFFFE), value);
      v6 = result;
    }
    else
    {
      v6 = result;
      if ( ((unsigned __int8)pSI & 3) == 2 )
      {
        result->Result = 0;
        return v6;
      }
    }
    v6->Result = 1;
  }
  else
  {
    result->Result = Scaleform::GFx::AS3::SlotInfo::SetSlotValue(
                       pSI,
                       (Scaleform::GFx::AS3::CheckResult *)&value,
                       vm,
                       value,
                       &this->This,
                       0)->Result;
    return result;
  }
  return v6;
}
