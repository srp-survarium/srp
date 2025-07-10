Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::Instances::fl::RegExp::ToString(
        Scaleform::GFx::AS3::Instances::fl::RegExp *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASString *v5; // eax
  Scaleform::GFx::ASString *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  const Scaleform::GFx::ASString *v14; // [esp-4h] [ebp-24h]
  Scaleform::GFx::ASString str; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::ASString v16; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::ASString v17; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::ASString v18; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::ASString v19; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::ASString v20; // [esp+1Ch] [ebp-4h] BYREF

  StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
  v17.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "/", 1u, 0);
  ++v17.pNode->RefCount;
  pStringManager = this->pTraits.pObject->pVM->StringManagerRef->pStringManager;
  str.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  Scaleform::GFx::AS3::Instances::fl::RegExp::sourceGet(this, &str);
  v16.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(StringManagerRef->pStringManager, "/", 1u, 0);
  ++v16.pNode->RefCount;
  v14 = Scaleform::GFx::AS3::Instances::fl::RegExp::optionFlagsGet(this, &v20);
  v5 = Scaleform::GFx::ASString::operator+(&v16, &v19, &str);
  v6 = Scaleform::GFx::ASString::operator+(v5, &v18, &v17);
  Scaleform::GFx::ASString::operator+(v6, result, v14);
  pNode = v18.pNode;
  --v18.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v8 = v19.pNode;
  --v19.pNode->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v9 = v16.pNode;
  --v16.pNode->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v10 = str.pNode;
  --str.pNode->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  v11 = v17.pNode;
  --v17.pNode->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v12 = v20.pNode;
  --v20.pNode->RefCount;
  if ( !v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  return result;
}
