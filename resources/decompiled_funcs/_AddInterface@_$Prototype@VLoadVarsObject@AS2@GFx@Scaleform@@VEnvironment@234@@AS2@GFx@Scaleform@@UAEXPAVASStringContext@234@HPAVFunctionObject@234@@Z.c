void __thiscall Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::AddInterface(
        Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::NumberObject,Scaleform::GFx::AS2::Environment> *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        unsigned int index,
        Scaleform::GFx::AS2::FunctionObject *ctor)
{
  Scaleform::GFx::AS2::GASPrototypeBase::AddInterface(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&this->mValue,
    psc,
    index,
    ctor);
}
