void __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetUserData(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        Scaleform::GFx::ASUserData *puserdata,
        bool isdobj)
{
  Scaleform::GFx::Value_AS2ObjectData v5; // [esp+8h] [ebp-Ch] BYREF

  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&v5, this, pdata, isdobj);
  if ( v5.pObject )
    Scaleform::GFx::AS2::ObjectInterface::SetUserData(v5.pObject, this->pMovieRoot, puserdata, isdobj);
}
