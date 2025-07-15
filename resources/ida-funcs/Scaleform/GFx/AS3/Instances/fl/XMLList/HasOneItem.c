Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::HasOneItem(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::CheckResult *result,
        const char *fn)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  unsigned int v4; // eax
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  Scaleform::StringDataPtr v8; // [esp-8h] [ebp-18h]
  Scaleform::GFx::AS3::VM::Error v9; // [esp+8h] [ebp-8h] BYREF

  if ( this->List.Data.Size == 1 )
  {
    v7 = result;
    result->Result = 1;
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    v8.pStr = fn;
    if ( fn )
      v4 = strlen(fn);
    else
      v4 = 0;
    v8.Size = v4;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eXMLOnlyWorksWithOneItemLists, pVM, v8);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v7 = result;
    result->Result = 0;
  }
  return v7;
}
