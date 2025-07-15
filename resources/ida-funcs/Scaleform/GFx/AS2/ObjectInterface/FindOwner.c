Scaleform::Ptr<Scaleform::GFx::AS2::Object> *__thiscall Scaleform::GFx::AS2::ObjectInterface::FindOwner(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi
  Scaleform::GFx::AS2::Object *pObject; // esi

  v3 = this;
  if ( !this )
    return 0;
  while ( !v3->HasMember(v3, psc, name, 0) )
  {
    pObject = v3->pProto.pObject;
    if ( pObject )
    {
      v3 = &pObject->Scaleform::GFx::AS2::ObjectInterface;
      if ( v3 )
        continue;
    }
    return 0;
  }
  return &v3[-2].pProto;
}
