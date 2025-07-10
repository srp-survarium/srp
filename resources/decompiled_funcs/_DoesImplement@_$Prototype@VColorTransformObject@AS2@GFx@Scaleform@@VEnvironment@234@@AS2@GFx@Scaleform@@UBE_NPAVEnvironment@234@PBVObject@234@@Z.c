char __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::DoesImplement(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment> *prototype)
{
  if ( this == prototype )
    return 1;
  else
    return Scaleform::GFx::AS2::GASPrototypeBase::DoesImplement(
             &this->Scaleform::GFx::AS2::GASPrototypeBase,
             penv,
             prototype);
}
