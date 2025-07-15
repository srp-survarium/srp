Scaleform::GFx::AS3::InstanceTraits::Traits *__thiscall Scaleform::GFx::AS3::TR::State::GetValueTraits(
        Scaleform::GFx::AS3::TR::State *this,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Tracer *pTracer; // esi
  unsigned int v3; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *result; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx

  pTracer = this->pTracer;
  v3 = v->Flags & 0x1F;
  if ( v3 )
  {
    if ( v3 - 8 < 2 )
      result = v->value.VS._1.ITr;
    else
      result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                pTracer->CF->pFile->VMRef,
                                                                v);
  }
  else
  {
    result = pTracer->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( result )
  {
    VMRef = pTracer->CF->pFile->VMRef;
    if ( result == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
      return (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
  }
  return result;
}
