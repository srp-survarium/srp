Scaleform::GFx::AS2::FnCall *__thiscall Scaleform::GFx::AS2::FnCall::`vector deleting destructor'(
        Scaleform::GFx::AS2::FnCall *this,
        char a2)
{
  Scaleform::GFx::AS2::FnCall::~FnCall(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
