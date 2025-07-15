void __thiscall Scaleform::GFx::AS2::MovieRoot::CreateString(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        __m128i *pstring)
{
  Scaleform::GFx::AS2::Environment *v4; // ebx
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::Value value; // [esp+Ch] [ebp-10h] BYREF

  v4 = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(char *))(*((_DWORD *)&this->pMovieImpl->pMainMovie->__vftable
                                                                           + this->pMovieImpl->pMainMovie->AvmObjOffset)
                                                                         + 124))(
                                             (char *)&this->pMovieImpl->pMainMovie->__vftable
                                           + 4 * this->pMovieImpl->pMainMovie->AvmObjOffset);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)v4->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 pstring);
  ++StringNode->RefCount;
  ++StringNode->RefCount;
  value.T.Type = 5;
  value.NV.Int32Value = (int)StringNode;
  Scaleform::GFx::AS2::MovieRoot::ASValue2Value(this, v4, &value, pvalue);
  Scaleform::GFx::AS2::Value::DropRefs(&value);
  if ( StringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
}
