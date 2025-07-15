Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::VTable::GetValue(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::AbsoluteIndex ind)
{
  Scaleform::GFx::AS3::Value *v3; // eax
  Scaleform::GFx::AS3::Traits *pTraits; // esi
  Scaleform::GFx::AS3::Value *v5; // eax

  v3 = &this->VTMethods.Data.Data[ind.Index];
  if ( (v3->Flags & 0x1F) == 6 )
  {
    pTraits = this->pTraits;
    v5 = result;
    result->Flags = 7;
    result->Bonus.pWeakProxy = 0;
    LODWORD(result->value.VNumber) = ind;
    result->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pTraits;
    return v5;
  }
  *result = *v3;
  if ( (v3->Flags & 0x1F) > 9 )
  {
    if ( (v3->Flags & 0x200) != 0 )
    {
      ++v3->Bonus.pWeakProxy->RefCount;
      return result;
    }
    Scaleform::GFx::AS3::Value::AddRefInternal(v3);
  }
  return result;
}
