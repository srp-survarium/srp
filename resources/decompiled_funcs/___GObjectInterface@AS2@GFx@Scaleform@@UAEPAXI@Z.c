Scaleform::GFx::AS2::ObjectInterface *__thiscall Scaleform::GFx::AS2::ObjectInterface::`scalar deleting destructor'(
        Scaleform::GFx::AS2::ObjectInterface *this,
        char a2)
{
  Scaleform::GFx::AS2::ObjectInterface::~ObjectInterface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
