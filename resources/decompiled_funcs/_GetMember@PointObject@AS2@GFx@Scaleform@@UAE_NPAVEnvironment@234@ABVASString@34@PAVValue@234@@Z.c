char __thiscall Scaleform::GFx::AS2::PointObject::GetMember(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        const Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value v; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::Render::Point<double> pt; // [esp+1Ch] [ebp-10h] BYREF

  if ( name->pNode != (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].RefCount )
    return ((int (__thiscall *)(Scaleform::GFx::AS2::PointObject *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].~Scaleform::GFx::AS2::PointObject)(
             this,
             &penv->StringContext,
             name,
             val);
  Scaleform::GFx::AS2::PointObject::GetProperties((Scaleform::GFx::AS2::PointObject *)((char *)this - 16), penv, &pt);
  v.T.Type = 3;
  v.NV.NumberValue = sqrt(pt.y * pt.y + pt.x * pt.x);
  Scaleform::GFx::AS2::Value::operator=(val, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  return 1;
}
