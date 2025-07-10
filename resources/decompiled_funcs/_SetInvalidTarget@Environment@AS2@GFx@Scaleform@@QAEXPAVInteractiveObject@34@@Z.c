void __thiscall Scaleform::GFx::AS2::Environment::SetInvalidTarget(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  *((_BYTE *)this + 194) |= 2u;
  this->Target = ptarget;
  this->StringContext.SWFVersion = Scaleform::GFx::DisplayObjectBase::GetVersion(ptarget);
}
