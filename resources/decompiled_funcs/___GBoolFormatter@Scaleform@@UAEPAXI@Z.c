Scaleform::ResourceFormatter *__thiscall Scaleform::BoolFormatter::`scalar deleting destructor'(
        Scaleform::ResourceFormatter *this,
        char a2)
{
  this->__vftable = (Scaleform::ResourceFormatter_vtbl *)&Scaleform::FmtResource::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
