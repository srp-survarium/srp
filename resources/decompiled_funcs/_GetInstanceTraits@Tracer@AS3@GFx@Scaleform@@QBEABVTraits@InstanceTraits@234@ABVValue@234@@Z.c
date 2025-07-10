const Scaleform::GFx::AS3::InstanceTraits::Traits *__thiscall Scaleform::GFx::AS3::Tracer::GetInstanceTraits(
        Scaleform::GFx::AS3::Tracer *this,
        const Scaleform::GFx::AS3::Value *v)
{
  unsigned int v2; // eax
  unsigned int v4; // eax

  v2 = v->Flags & 0x1F;
  if ( v2 - 12 <= 3 && !v->value.VS._1.VInt )
    return this->CF->pFile->VMRef->TraitsNull.pObject;
  if ( !v2 )
    return this->CF->pFile->VMRef->TraitsClassClass.pObject->ITraits.pObject;
  v4 = v2 - 8;
  if ( !v4 )
    return v->value.VS._1.ITr;
  if ( v4 == 1 )
    return *(const Scaleform::GFx::AS3::InstanceTraits::Traits **)(v->value.VS._1.VInt + 100);
  return Scaleform::GFx::AS3::VM::GetInstanceTraits(this->CF->pFile->VMRef, v);
}
