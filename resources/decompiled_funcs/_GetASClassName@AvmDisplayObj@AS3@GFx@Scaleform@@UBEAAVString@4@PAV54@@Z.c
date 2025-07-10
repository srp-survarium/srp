Scaleform::String *__thiscall Scaleform::GFx::AS3::AvmDisplayObj::GetASClassName(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::String *className)
{
  char *pClassName; // eax
  Scaleform::GFx::MovieDefImpl *v4; // eax
  const Scaleform::String *NameOfExportedResource; // eax
  unsigned int Id; // [esp-4h] [ebp-8h]

  pClassName = (char *)this->pClassName;
  if ( pClassName )
    goto LABEL_4;
  Id = this->pDispObj->Id.Id;
  v4 = this->pDispObj->GetResourceMovieDef(this->pDispObj);
  NameOfExportedResource = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(v4, (Scaleform::GFx::ResourceId)Id);
  if ( !NameOfExportedResource )
  {
    pClassName = (char *)this->GetDefaultASClassName(this);
LABEL_4:
    Scaleform::String::operator=(className, pClassName);
    return className;
  }
  Scaleform::String::operator=(className, NameOfExportedResource);
  return className;
}
