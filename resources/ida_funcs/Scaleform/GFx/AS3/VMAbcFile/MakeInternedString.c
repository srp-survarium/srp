Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::VMAbcFile::MakeInternedString(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::ASString *result,
        unsigned int strIndex)
{
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::StringDataPtr v6; // [esp+4h] [ebp-8h] BYREF

  Scaleform::GFx::AS3::Abc::StringView::ToStringDataPtr(
    &this->File.pObject->Const_Pool.ConstStr.Data.Data[strIndex],
    &v6);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->VMRef->StringManagerRef->pStringManager,
                 (char *)v6.pStr,
                 v6.Size);
  ++StringNode->RefCount;
  result->pNode = StringNode;
  return result;
}
