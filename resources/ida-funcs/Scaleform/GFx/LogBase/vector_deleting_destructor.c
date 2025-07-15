Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger> *__thiscall Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vector deleting destructor'(
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger> *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
