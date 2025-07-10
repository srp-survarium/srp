void __thiscall Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::unescape(
        Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::String argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v5; // ecx
  const Scaleform::GFx::AS3::Value *pStringManager; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  void *v8; // esi
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASString v; // [esp+4h] [ebp-4h] BYREF

  if ( argc.pData )
  {
    v5 = argv;
    if ( (argv->Flags & 0x1F) != 0 && ((argv->Flags & 0x1F) - 12 > 3 || argv->value.VS._1.VInt) )
    {
      pStringManager = (const Scaleform::GFx::AS3::Value *)this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
      argv = (Scaleform::GFx::AS3::Value *)&pStringManager[2];
      ++pStringManager[2].value.VS._2.VObj;
      if ( Scaleform::GFx::AS3::Value::Convert2String(
             v5,
             (Scaleform::GFx::AS3::CheckResult *)&argc,
             (Scaleform::GFx::ASString *)&argv)->Result )
      {
        Scaleform::String::String(&argc);
        Scaleform::GFx::ASUtils::AS3::Unescape(
          (const char *)argv->Flags,
          (const char *)argv[1].Bonus.pWeakProxy,
          &argc,
          0);
        v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                    this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                    (char *)((argc.HeapTypeBits & 0xFFFFFFFC) + 8),
                    *(_DWORD *)(argc.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++v.pNode->RefCount;
        Scaleform::GFx::AS3::Value::Assign(result, &v);
        pNode = v.pNode;
        --v.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v8 = (void *)(argc.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((argc.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
      v9 = (Scaleform::GFx::ASStringNode *)argv;
      --argv->value.VS._2.VObj;
      if ( !v9->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    }
    else
    {
      Scaleform::GFx::AS3::Value::Assign(
        result,
        (const Scaleform::GFx::ASString *)&this->pTraits.pObject->pVM->StringManagerRef->Builtins[2]);
    }
  }
  else
  {
    Scaleform::GFx::AS3::Value::Assign(
      result,
      (const Scaleform::GFx::ASString *)&this->pTraits.pObject->pVM->StringManagerRef->Builtins[1]);
  }
}
