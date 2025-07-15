void __thiscall Scaleform::GFx::AS3ValueObjectInterface::ToString(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::String *pstr,
        Scaleform::GFx::ASStringNode *thisVal)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // esi
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::ASString asStr; // [esp+4h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value asVal; // [esp+8h] [ebp-10h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  asVal.Flags = 0;
  asVal.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, thisVal, &asVal);
  pStringManager = pObject->BuiltinsMgr.pStringManager;
  asStr.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  Scaleform::GFx::AS3::Value::Convert2String(&asVal, (Scaleform::GFx::AS3::CheckResult *)&thisVal, &asStr);
  Scaleform::String::AssignString(pstr, (char *)asStr.pNode->pData, asStr.pNode->Size);
  pNode = asStr.pNode;
  --asStr.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (asVal.Flags & 0x1F) > 9 )
  {
    if ( (asVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = asVal.Bonus.pWeakProxy;
      --asVal.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&asVal);
    }
  }
}
