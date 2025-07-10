char __thiscall Scaleform::GFx::AS2::BitmapData::SetMember(
        Scaleform::GFx::AS2::BitmapData *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  if ( !strcmp(name->pNode->pData, "width") || !strcmp(name->pNode->pData, "height") )
    return 1;
  else
    return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
}
