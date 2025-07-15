void __thiscall Scaleform::GFx::AS3::VM::OutputError(Scaleform::GFx::AS3::VM *this, Scaleform::GFx::AS3::Value *e)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v5; // esi
  Scaleform::GFx::ASStringManager *pManager; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  void *pWeakProxy; // eax
  bool v9; // zf
  Scaleform::GFx::AS3::Value *v10; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString errorString; // [esp+Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value::V2U v13; // [esp+10h] [ebp-3Ch]
  Scaleform::GFx::AS3::Value nameVal; // [esp+14h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+24h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+34h] [ebp-18h] BYREF

  errorString.pNode = 0;
  StringManagerRef = this->StringManagerRef;
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  errorString.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++errorString.pNode->RefCount;
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      this->StringManagerRef->pStringManager,
                      "getStackTrace",
                      0xDu,
                      0);
  v5 = ConstStringNode;
  pManager = ConstStringNode->pManager;
  ++ConstStringNode->RefCount;
  nameVal.Flags = 10;
  nameVal.Bonus.pWeakProxy = 0;
  nameVal.value.VS._1.VInt = (int)ConstStringNode;
  if ( ConstStringNode == &pManager->NullStringNode )
  {
    nameVal.value.VS._1.VInt = 0;
    nameVal.value.VS._2 = v13;
    nameVal.Flags = 12;
  }
  else
  {
    ++ConstStringNode->RefCount;
  }
  pObject = this->PublicNamespace.pObject;
  prop_name.Kind = MN_QName;
  prop_name.Obj.pObject = &pObject->Scaleform::GFx::AS3::GASRefCountBase;
  if ( pObject )
  {
    ++pObject->RefCount;
    pObject->RefCount &= 0x8FBFFFFF;
  }
  prop_name.Name.Flags = 0;
  prop_name.Name.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Multiname::SetRTNameUnsafe(&prop_name, &nameVal);
  if ( (nameVal.Flags & 0x1F) > 9 )
  {
    if ( (nameVal.Flags & 0x200) != 0 )
    {
      pWeakProxy = nameVal.Bonus.pWeakProxy;
      v9 = nameVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&nameVal);
    }
  }
  v9 = v5->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v10 = e;
  if ( ((e->Flags & 0x1F) == 0
     || (e->Flags & 0x1F) - 12 <= 3 && !e->value.VS._1.VInt
     || !Scaleform::GFx::AS3::ExecutePropertyUnsafe(
           (Scaleform::GFx::AS3::CheckResult *)&e,
           this,
           (const Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Namespace>,2,Scaleform::ArrayDefaultPolicy> *)&prop_name,
           e,
           &r,
           0,
           0)->Result
     || Scaleform::GFx::AS3::Value::Convert2String(&r, (Scaleform::GFx::AS3::CheckResult *)&e, &errorString)->Result)
    && ((v10->Flags & 0x1F) != 0 && ((v10->Flags & 0x1F) - 12 > 3 || v10->value.VS._1.VInt) && errorString.pNode->Size
     || Scaleform::GFx::AS3::Value::Convert2String(v10, (Scaleform::GFx::AS3::CheckResult *)&e, &errorString)->Result) )
  {
    this->UI->Output(this->UI, Output_Error, errorString.pNode->pData);
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
  pNode = errorString.pNode;
  --errorString.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS3::Value::~Value(&r);
}
