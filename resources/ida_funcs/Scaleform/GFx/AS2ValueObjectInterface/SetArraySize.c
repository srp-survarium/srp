char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetArraySize(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        unsigned int sz)
{
  if ( pdata )
    Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)(pdata - 16), sz);
  else
    Scaleform::GFx::AS2::ArrayObject::Resize(0, sz);
  return 1;
}
