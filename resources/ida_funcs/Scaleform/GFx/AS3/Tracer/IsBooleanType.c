bool __thiscall Scaleform::GFx::AS3::Tracer::IsBooleanType(
        Scaleform::GFx::AS3::Tracer *this,
        const Scaleform::GFx::AS3::Value *v)
{
  unsigned int v3; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *ITr; // eax
  Scaleform::GFx::AS3::VM *VMRef; // ecx

  v3 = v->Flags & 0x1F;
  if ( v3 )
  {
    if ( v3 - 8 < 2 )
      ITr = v->value.VS._1.ITr;
    else
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)Scaleform::GFx::AS3::VM::GetValueTraits(
                                                             this->CF->pFile->VMRef,
                                                             v);
  }
  else
  {
    ITr = this->CF->pFile->VMRef->TraitsVoid.pObject;
  }
  if ( ITr )
  {
    VMRef = this->CF->pFile->VMRef;
    if ( ITr == (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsClassClass.pObject )
      ITr = (Scaleform::GFx::AS3::InstanceTraits::Traits *)VMRef->TraitsObject.pObject;
  }
  return ITr == this->CF->pFile->VMRef->TraitsBoolean.pObject->ITraits.pObject;
}
