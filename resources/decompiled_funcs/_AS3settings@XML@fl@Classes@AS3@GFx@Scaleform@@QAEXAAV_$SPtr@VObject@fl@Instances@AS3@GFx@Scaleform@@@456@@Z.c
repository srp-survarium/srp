void __thiscall Scaleform::GFx::AS3::Classes::fl::XML::AS3settings(
        Scaleform::GFx::AS3::Classes::fl::XML *this,
        Scaleform::GFx::ASStringNode *result)
{
  Scaleform::GFx::AS3::VM *pVM; // ecx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *v5; // ebp
  Scaleform::GFx::AS3::Instances::fl::Object *pData; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::ASStringNode *v9; // eax
  bool ignoreProcessingInstructions; // dl
  Scaleform::GFx::ASStringManager *v11; // ecx
  Scaleform::GFx::ASStringNode *v12; // eax
  bool ignoreWhitespace; // al
  Scaleform::GFx::ASStringManager *v14; // ecx
  Scaleform::GFx::ASStringNode *v15; // eax
  bool prettyPrinting; // dl
  Scaleform::GFx::ASStringManager *v17; // ecx
  Scaleform::GFx::ASStringNode *v18; // eax
  int prettyIndent; // eax
  Scaleform::GFx::ASStringManager *v20; // ecx
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Object> obj; // [esp+10h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Instances::fl::Object *pV; // [esp+14h] [ebp-14h]
  Scaleform::GFx::AS3::Value v; // [esp+18h] [ebp-10h] BYREF

  pVM = this->pTraits.pObject->pVM;
  StringManagerRef = pVM->StringManagerRef;
  Scaleform::GFx::AS3::VM::MakeObject(pVM, &obj);
  v5 = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *)result;
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
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          pData->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pData);
        }
      }
    }
    v5->pObject = pV;
  }
  v.value.VS._1.VBool = this->ignoreComments;
  pStringManager = StringManagerRef->pStringManager;
  v.Flags = 1;
  v.Bonus.pWeakProxy = 0;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, "ignoreComments", 0xEu, 0);
  ++result->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj.pV, (const Scaleform::GFx::ASString *)&result, &v, aNone);
  v9 = result;
  --result->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  ignoreProcessingInstructions = this->ignoreProcessingInstructions;
  v11 = StringManagerRef->pStringManager;
  v.Flags = 1;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VBool = ignoreProcessingInstructions;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(v11, "ignoreProcessingInstructions", 0x1Cu, 0);
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
  ignoreWhitespace = this->ignoreWhitespace;
  v14 = StringManagerRef->pStringManager;
  v.Flags = 1;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VBool = ignoreWhitespace;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(v14, "ignoreWhitespace", 0x10u, 0);
  ++result->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj.pV, (const Scaleform::GFx::ASString *)&result, &v, aNone);
  v15 = result;
  --result->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  prettyPrinting = this->prettyPrinting;
  v17 = StringManagerRef->pStringManager;
  v.Flags = 1;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VBool = prettyPrinting;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(v17, "prettyPrinting", 0xEu, 0);
  ++result->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj.pV, (const Scaleform::GFx::ASString *)&result, &v, aNone);
  v18 = result;
  --result->RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
  prettyIndent = this->prettyIndent;
  v20 = StringManagerRef->pStringManager;
  v.Flags = 2;
  v.Bonus.pWeakProxy = 0;
  v.value.VS._1.VInt = prettyIndent;
  result = Scaleform::GFx::ASStringManager::CreateConstStringNode(v20, "prettyIndent", 0xCu, 0);
  ++result->RefCount;
  Scaleform::GFx::AS3::Object::AddDynamicSlotValuePair(obj.pV, (const Scaleform::GFx::ASString *)&result, &v, aNone);
  v21 = result;
  --result->RefCount;
  if ( !v21->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
