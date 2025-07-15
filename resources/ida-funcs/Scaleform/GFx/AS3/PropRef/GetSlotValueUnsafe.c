Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
        Scaleform::GFx::AS3::PropRef *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::SlotInfo::ValTarget vtt)
{
  Scaleform::GFx::AS3::SlotInfo *pSI; // ecx
  bool v7; // bl
  Scaleform::GFx::AS3::Value *v8; // eax
  unsigned int v9; // ecx
  Scaleform::GFx::AS3::CheckResult *v10; // eax
  Scaleform::GFx::AS3::Value::V2U v11; // [esp+8h] [ebp-4h]

  pSI = (Scaleform::GFx::AS3::SlotInfo *)this->pSI;
  v7 = 1;
  if ( ((unsigned __int8)pSI & 3) != 0 )
  {
    if ( ((unsigned __int8)pSI & 3) == 1 )
    {
      Scaleform::GFx::AS3::Value::AssignUnsafe(
        value,
        (const Scaleform::GFx::AS3::Value *)((unsigned int)pSI & 0xFFFFFFFE));
      v10 = result;
      result->Result = 1;
      return v10;
    }
    if ( ((unsigned __int8)pSI & 3) == 2 )
    {
      v8 = value;
      v9 = (unsigned int)pSI & 0xFFFFFFFD;
      value->Flags = value->Flags & 0xFFFFFFE0 | 0xC;
      v8->value.VS._1.VInt = v9;
      v8->value.VS._2 = v11;
      if ( v9 )
      {
        *(_DWORD *)(v9 + 16) = (*(_DWORD *)(v9 + 16) + 1) & 0x8FBFFFFF;
        v10 = result;
        result->Result = 1;
        return v10;
      }
    }
  }
  else
  {
    v7 = Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
           pSI,
           (Scaleform::GFx::AS3::CheckResult *)&value,
           vm,
           value,
           (Scaleform::GFx::ASStringNode *)&this->This,
           0,
           vtt)->Result;
  }
  v10 = result;
  result->Result = v7;
  return v10;
}
