void __thiscall Scaleform::GFx::AS3::MovieRoot::CreateStringW(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        wchar_t *pstring)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::ASStringNode *v5; // esi
  Scaleform::GFx::ASStringManager *pManager; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value value; // [esp+8h] [ebp-10h] BYREF

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->BuiltinsMgr.pStringManager, pstring, -1);
  v5 = StringNode;
  pManager = StringNode->pManager;
  ++StringNode->RefCount;
  value.Flags = 10;
  value.Bonus.pWeakProxy = 0;
  value.value.VS._1.VInt = (int)StringNode;
  if ( StringNode == &pManager->NullStringNode )
  {
    value.value.VS._1.VInt = 0;
    value.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)value.Bonus.pWeakProxy;
    value.Flags = 12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &value, (Scaleform::GFx::ASStringNode *)pvalue);
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      pWeakProxy = value.Bonus.pWeakProxy;
      --value.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  if ( v5->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}
