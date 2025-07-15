Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::Class::ConvertCopy(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // edi

  Flags = v->Flags;
  result->value.VNumber = v->value.VNumber;
  pWeakProxy = v->Bonus.pWeakProxy;
  result->Flags = Flags;
  result->Bonus.pWeakProxy = pWeakProxy;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      ++pWeakProxy->RefCount;
      return result;
    }
    Scaleform::GFx::AS3::Value::AddRefInternal(v);
  }
  return result;
}
