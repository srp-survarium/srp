void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::SetExtMovieDef(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::MovieDef *m)
{
  Scaleform::GFx::MovieDef *pObject; // ecx

  if ( m )
    Scaleform::RefCountImpl::AddRef(m);
  pObject = this->pExtMovieDef.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pExtMovieDef.pObject = m;
}
