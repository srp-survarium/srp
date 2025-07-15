void __thiscall Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo::loaderURLGet(
        Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl_display::Loader *pObject; // eax
  int v4; // eax
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  __m128i *v6; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v9; // zf

  pObject = this->pLoader.pObject;
  if ( pObject )
  {
    v4 = (int)pObject->pDispObj.pObject->GetResourceMovieDef(pObject->pDispObj.pObject);
    StringManagerRef = this->pTraits.pObject->pVM->StringManagerRef;
    v6 = (__m128i *)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 48))(v4);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v6);
  }
  else
  {
    StringNode = &this->pTraits.pObject->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  }
  StringNode->RefCount += 2;
  pNode = result->pNode;
  v9 = result->pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  result->pNode = StringNode;
  v9 = StringNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
}
