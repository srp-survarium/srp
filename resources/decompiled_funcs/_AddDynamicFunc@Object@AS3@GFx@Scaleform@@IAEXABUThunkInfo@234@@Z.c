void __thiscall Scaleform::GFx::AS3::Object::AddDynamicFunc(
        Scaleform::GFx::AS3::Object *this,
        Scaleform::GFx::ASStringNode *func)
{
  char *pLower; // edx
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::ASStringNode *v5; // eax
  Scaleform::GFx::AS3::Value v; // [esp+Ch] [ebp-10h] BYREF

  pLower = (char *)func->pLower;
  v.value.VS._1.VInt = (int)func;
  pObject = this->pTraits.pObject;
  v.Flags = 5;
  v.Bonus.pWeakProxy = 0;
  func = Scaleform::GFx::ASStringManager::CreateConstStringNode(
           pObject->pVM->StringManagerRef->pStringManager,
           pLower,
           strlen(pLower),
           0);
  ++func->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(this, (const Scaleform::GFx::ASString *)&func, &v, aDontEnum);
  v5 = func;
  --func->RefCount;
  if ( !v5->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
