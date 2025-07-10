char __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetElement(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        const Scaleform::GFx::Value *value)
{
  Scaleform::GFx::AS2::ArrayObject *v4; // esi
  Scaleform::GFx::AS2::MovieRoot *pObject; // ecx
  Scaleform::GFx::AS2::Value asval; // [esp+4h] [ebp-10h] BYREF

  if ( pdata )
    v4 = (Scaleform::GFx::AS2::ArrayObject *)(pdata - 16);
  else
    v4 = 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  asval.T.Type = 0;
  Scaleform::GFx::AS2::MovieRoot::Value2ASValue(pObject, value, &asval);
  Scaleform::GFx::AS2::ArrayObject::SetElementSafe(v4, idx, &asval);
  if ( asval.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&asval);
  return 1;
}
