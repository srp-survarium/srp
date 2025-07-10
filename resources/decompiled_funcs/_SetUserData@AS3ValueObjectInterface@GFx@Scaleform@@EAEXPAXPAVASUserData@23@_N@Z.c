void __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetUserData(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Object *pdata,
        Scaleform::GFx::ASUserData *puserdata,
        bool isdobj)
{
  if ( pdata )
    Scaleform::GFx::AS3::Object::SetUserData(pdata, this->pMovieRoot, puserdata, isdobj);
}
