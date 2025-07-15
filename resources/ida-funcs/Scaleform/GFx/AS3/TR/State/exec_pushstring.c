void __thiscall Scaleform::GFx::AS3::TR::State::exec_pushstring(Scaleform::GFx::AS3::TR::State *this, int v)
{
  Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *WCode; // edi
  unsigned int v4; // esi
  int *Data; // ecx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringManager *pManager; // ecx
  char v8; // di
  Scaleform::GFx::AS3::Value result; // [esp+Ch] [ebp-10h] BYREF

  WCode = (Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *)this->pTracer->WCode;
  v4 = WCode->Size + 1;
  if ( v4 >= WCode->Size )
  {
    if ( v4 >= WCode->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        WCode,
        WCode,
        v4 + (v4 >> 2));
  }
  else if ( v4 < WCode->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      WCode,
      WCode,
      WCode->Size + 1);
  }
  Data = WCode->Data;
  WCode->Size = v4;
  Data[v4 - 1] = v;
  Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(
    &this->pTracer->CF->pFile->File.pObject->Const_Pool.ConstStr.Data.Data[v],
    (Scaleform::StringDataPtr *)&result);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pTracer->CF->pFile->VMRef->StringManagerRef->pStringManager,
                 (__m128i *)result.Flags,
                 (unsigned int)result.Bonus.pWeakProxy);
  pManager = StringNode->pManager;
  ++StringNode->RefCount;
  v8 = 10;
  result.Flags = 10;
  result.Bonus.pWeakProxy = 0;
  result.value.VS._1.VInt = (int)StringNode;
  if ( StringNode == &pManager->NullStringNode )
  {
    v8 = 12;
    result.value.VS._1.VInt = 0;
    result.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result.Bonus.pWeakProxy;
    result.Flags = 12;
  }
  else
  {
    ++StringNode->RefCount;
  }
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->OpStack.Data,
    &result);
  if ( (v8 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&result);
  if ( StringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
}
