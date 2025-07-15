Scaleform::GFx::ASUserData *__thiscall Scaleform::GFx::AS2ValueObjectInterface::GetUserData(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        bool isdobj)
{
  Scaleform::GFx::Value_AS2ObjectData v; // [esp+0h] [ebp-Ch] BYREF

  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&v, this, pdata, isdobj);
  if ( v.pObject && v.pObject->pUserDataHolder )
    return v.pObject->pUserDataHolder->pUserData;
  else
    return 0;
}
