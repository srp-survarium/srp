void __thiscall Scaleform::GFx::AS3::Classes::fl::XML::AS3defaultSettings(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::ASStringNode *result)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v4; // edi
  Scaleform::GFx::AS3::Instances::fl::Object *pData; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringManager *v9; // ecx
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringManager *v11; // ecx
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringManager *v13; // ecx
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringManager *v15; // ecx
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> obj; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS3::Value v; // [esp+18h] [ebp-10h] BYREF

  pVM = this->pTraits.pObject->pVM;
  StringManagerRef = pVM->StringManagerRef;
  Scaleform::GFx::AS3::VM::MakeObject(pVM, &obj);
  v4 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *)result;
  pData = (Scaleform::GFx::AS3::Instances::fl::Object *)result->pData;
  pV = obj.pV;
  if ( obj.pV != pData )
  {
    if ( pData )
    {
      if ( ((unsigned __int8)pData & 1) != 0 )
      {
        result->pData = (char *)&pData[-1].pUserDataHolder + 3;
      }
      else
      {
        RefCount = pData->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          pData->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pData);
        }
      }
    }
    v4->pObject = pV;
  }
  pStringManager = StringManagerRef->pStringManager;
  v.Flags = 1;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VBool = 1;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, "ignoreComments", 0xEu, 0);
  ++result->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj.pV, (const Scaleform::GFx::ASString *)&result, &v, aNone);
  v8 = result;
  --result->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  v9 = StringManagerRef->pStringManager;
  v.Flags = 1;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VBool = 1;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(v9, "ignoreProcessingInstructions", 0x1Cu, 0);
  ++result->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj.pV, (const Scaleform::GFx::ASString *)&result, &v, aNone);
  v10 = result;
  --result->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  v11 = StringManagerRef->pStringManager;
  v.Flags = 1;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VBool = 1;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(v11, "ignoreWhitespace", 0x10u, 0);
  ++result->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj.pV, (const Scaleform::GFx::ASString *)&result, &v, aNone);
  v12 = result;
  --result->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  v13 = StringManagerRef->pStringManager;
  v.Flags = 1;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VBool = 1;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(v13, "prettyPrinting", 0xEu, 0);
  ++result->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj.pV, (const Scaleform::GFx::ASString *)&result, &v, aNone);
  v14 = result;
  --result->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  v15 = StringManagerRef->pStringManager;
  v.Flags = 2;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VInt = 2;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(v15, "prettyIndent", 0xCu, 0);
  ++result->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj.pV, (const Scaleform::GFx::ASString *)&result, &v, aNone);
  v16 = result;
  --result->RefCount;
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
