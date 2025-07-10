Scaleform::GFx::ASString *__thiscall Scaleform::GFx::AS3::VMFile::GetInternedString(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASStringNode *strIndex)
{
  unsigned int v3; // esi
  unsigned int v5; // ebx
  Scaleform::GFx::ASString *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode> *v8; // esi
  Scaleform::GFx::ASStringNode *pObject; // ecx
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // ecx
  Scaleform::GFx::ASString *v13; // eax

  v3 = (unsigned int)strIndex;
  if ( (unsigned int)strIndex >= this->IntStrings.Data.Size )
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &this->IntStrings,
      (unsigned int)&strIndex->pData + 1);
  v5 = v3;
  if ( !this->IntStrings.Data.Data[v3].pObject )
  {
    v6 = this->MakeInternedString(this, &strIndex, v3);
    pNode = v6->pNode;
    v8 = &this->IntStrings.Data.Data[v5];
    if ( v6->pNode != v8->pObject )
    {
      if ( pNode )
        ++pNode->RefCount;
      pObject = v8->pObject;
      if ( v8->pObject )
      {
        if ( ((unsigned __int8)pObject & 1) != 0 )
        {
          v8->pObject = (Scaleform::GFx::ASStringNode *)((char *)pObject - 1);
        }
        else if ( pObject->RefCount-- == 1 )
        {
          Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
        }
      }
      v8->pObject = pNode;
    }
    v11 = strIndex;
    --strIndex->RefCount;
    if ( !v11->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  v12 = this->IntStrings.Data.Data[v5].pObject;
  v13 = result;
  ++v12->RefCount;
  result->pNode = v12;
  return v13;
}
