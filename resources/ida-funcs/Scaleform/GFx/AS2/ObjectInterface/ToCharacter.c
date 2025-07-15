Scaleform::GFx::AS2::ObjectInterface_vtbl *__thiscall Scaleform::GFx::AS2::ObjectInterface::ToCharacter(
        Scaleform::GFx::AS2::ObjectInterface *this)
{
  if ( (unsigned int)(this->GetObjectType(this) - 2) > 3 )
    return 0;
  else
    return this[1].__vftable;
}
