Scaleform::GFx::AS2::GASPrototypeBase *__thiscall Scaleform::GFx::AS2::GASPrototypeBase::`vector deleting destructor'(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        char a2)
{
  Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
