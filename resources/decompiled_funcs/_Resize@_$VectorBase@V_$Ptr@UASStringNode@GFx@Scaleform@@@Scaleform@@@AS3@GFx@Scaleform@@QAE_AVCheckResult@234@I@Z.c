Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int newSise)
{
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *v3; // esi
  unsigned int Size; // ebp
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  Scaleform::GFx::ASStringNode *pNode; // esi
  Scaleform::GFx::ASStringNode **p_pObject; // edi
  Scaleform::GFx::ASStringNode *v8; // ecx
  bool v9; // zf
  Scaleform::GFx::AS3::CheckResult *v10; // eax
  Scaleform::GFx::AS3::CheckResult v11; // [esp+Bh] [ebp-5h] BYREF
  Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *v12; // [esp+Ch] [ebp-4h]

  v3 = this;
  v12 = this;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v11)->Result )
  {
    Size = v3->ValueA.Data.Size;
    p_ValueA = &v3->ValueA;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &v3->ValueA,
      newSise);
    if ( Size < newSise )
    {
      while ( 1 )
      {
        pNode = v3->VMRef->StringManagerRef->Builtins[2].pNode;
        if ( pNode )
          ++pNode->RefCount;
        p_pObject = &p_ValueA->Data.Data[Size].pObject;
        if ( pNode )
          ++pNode->RefCount;
        v8 = *p_pObject;
        if ( *p_pObject )
        {
          v9 = v8->RefCount-- == 1;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v8);
        }
        *p_pObject = pNode;
        if ( pNode )
        {
          v9 = pNode->RefCount-- == 1;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
        if ( ++Size >= newSise )
          break;
        v3 = v12;
      }
    }
    v10 = result;
    result->Result = 1;
  }
  else
  {
    v10 = result;
    result->Result = 0;
  }
  return v10;
}
