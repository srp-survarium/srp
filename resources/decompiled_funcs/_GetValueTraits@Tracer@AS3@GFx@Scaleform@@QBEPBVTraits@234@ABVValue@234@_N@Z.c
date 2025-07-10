Scaleform::GFx::AS3::InstanceTraits::Traits *__thiscall Scaleform::GFx::AS3::Tracer::GetValueTraits(
        Scaleform::GFx::AS3::Tracer *this,
        const Scaleform::GFx::AS3::Value *v,
        bool super_tr)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *result; // eax
  unsigned int v5; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx

  if ( !super_tr || (result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)this->CF->OriginationTraits) == 0 )
  {
    v5 = v->Flags & 0x1F;
    if ( v5 )
      result = v5 - 8 < 2
             ? (Scaleform::GFx::AS3::InstanceTraits::Traits *)v->value.VS._1.VInt
             : (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                                this->CF->pFile->VMRef,
                                                                v);
    else
      result = this->CF->pFile->VMRef->TraitsVoid.pObject;
    if ( result )
    {
      VMRef = this->CF->pFile->VMRef;
      if ( result == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
        result = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
    }
  }
  if ( super_tr )
  {
    if ( result )
      return (Scaleform::GFx::AS3::InstanceTraits::Traits *)result->pParent.pObject;
  }
  return result;
}
