char __thiscall Scaleform::GFx::AS2::ArrayObject::DeleteMember(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name)
{
  int v4; // eax
  Scaleform::GFx::AS2::Value val; // [esp+8h] [ebp-10h] BYREF

  if ( !name->pNode->Size || !isdigit(*name->pNode->pData) )
    return Scaleform::GFx::AS2::Object::DeleteMember(this, psc, name);
  v4 = Scaleform::GFx::AS2::ArrayObject::ParseIndex(name);
  if ( v4 < 0 )
    return 0;
  val.T.Type = 0;
  Scaleform::GFx::AS2::ArrayObject::SetElement((Scaleform::GFx::AS2::ArrayObject *)((char *)this - 16), v4, &val);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  return 1;
}
