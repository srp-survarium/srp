void __thiscall Scaleform::GFx::AS2ValueObjectInterface::SetUserData(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        Scaleform::GFx::AS2::ObjectInterface *pdata,
        Scaleform::GFx::ASUserData *puserdata,
        bool isdobj)
{
  Scaleform::GFx::Value_AS2ObjectData v; // [esp+8h] [ebp-Ch] BYREF

  Scaleform::GFx::Value_AS2ObjectData::Value_AS2ObjectData(&v, this, pdata, isdobj);
  if ( v.pObject )
    Scaleform::GFx::AS2::ObjectInterface::SetUserData(v.pObject, this->pMovieRoot, puserdata, isdobj);
}
