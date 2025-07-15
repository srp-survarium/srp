void __thiscall Scaleform::GFx::AS3::Tracer::ThrowMergeTypeError(
        Scaleform::GFx::AS3::Tracer *this,
        const Scaleform::GFx::AS3::Traits *to_tr,
        const Scaleform::GFx::AS3::Traits *from_tr)
{
  Scaleform::GFx::ASStringNode *VMRef; // esi
  Scaleform::GFx::AS3::Value::V1U *v4; // eax
  Scaleform::GFx::AS3::Value::V1U v5; // ecx
  Scaleform::GFx::AS3::Value::V1U *v6; // eax
  Scaleform::GFx::AS3::Value::V1U v7; // ecx
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::WeakProxy *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *v14; // [esp+8h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::VM::Error v15; // [esp+Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value arg1; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value arg2; // [esp+24h] [ebp-10h] BYREF

  VMRef = (Scaleform::GFx::ASStringNode *)this->CF->pFile->VMRef;
  v4 = (Scaleform::GFx::AS3::Value::V1U *)from_tr->GetName(from_tr, &v14);
  arg2.Flags = 10;
  arg2.Bonus.pWeakProxy = 0;
  v5 = *v4;
  arg2.value.VS._1 = *v4;
  if ( v4->VInt == *(_DWORD *)(v4->VInt + 4) + 56 )
  {
    arg2.value.VS._1.VInt = 0;
    arg2.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v15.Message.pNode;
    arg2.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(v5.VInt + 12);
  }
  v6 = (Scaleform::GFx::AS3::Value::V1U *)to_tr->GetName(to_tr, &from_tr);
  arg1.Flags = 10;
  arg1.Bonus.pWeakProxy = 0;
  v7 = *v6;
  arg1.value.VS._1 = *v6;
  if ( v6->VInt == *(_DWORD *)(v6->VInt + 4) + 56 )
  {
    arg1.value.VS._1.VInt = 0;
    arg1.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v15.Message.pNode;
    arg1.Flags = 12;
  }
  else
  {
    ++*(_DWORD *)(v7.VInt + 12);
  }
  Scaleform::GFx::AS3::VM::Error::Error(&v15, (Scaleform::GFx::AS3::VM_vtbl *)0x42C, VMRef, &arg1, &arg2);
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    (Scaleform::GFx::AS3::VM *)VMRef,
    v8,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::VerifyErrorTI);
  pNode = v15.Message.pNode;
  --v15.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( (arg1.Flags & 0x1F) > 9 )
  {
    if ( (arg1.Flags & 0x200) != 0 )
    {
      pWeakProxy = arg1.Bonus.pWeakProxy;
      --arg1.Bonus.pWeakProxy->RefCount;
      if ( !pWeakProxy->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      arg1.Flags &= 0xFFFFFDE0;
      memset(&arg1.Bonus, 0, 12);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&arg1);
    }
  }
  v11 = (Scaleform::GFx::ASStringNode *)from_tr;
  --from_tr->pPrev;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( (arg2.Flags & 0x1F) > 9 )
  {
    if ( (arg2.Flags & 0x200) != 0 )
    {
      v12 = arg2.Bonus.pWeakProxy;
      --arg2.Bonus.pWeakProxy->RefCount;
      if ( !v12->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
      arg2.Flags &= 0xFFFFFDE0;
      memset(&arg2.Bonus, 0, 12);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&arg2);
    }
  }
  v13 = v14;
  --v14->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
}
