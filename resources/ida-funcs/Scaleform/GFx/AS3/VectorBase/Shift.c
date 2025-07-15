void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Shift<unsigned long>(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        unsigned int *result)
{
  unsigned int v3; // edx
  Scaleform::ArrayDH<unsigned long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  unsigned int Size; // ecx
  Scaleform::GFx::AS3::CheckResult v6; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v6)->Result && this->ValueA.Data.Size )
  {
    v3 = *this->ValueA.Data.Data;
    p_ValueA = &this->ValueA;
    *result = v3;
    Size = p_ValueA->Data.Size;
    if ( Size == 1 )
    {
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::Clear(p_ValueA);
    }
    else
    {
      memmove((unsigned __int8 *)p_ValueA->Data.Data, (unsigned __int8 *)p_ValueA->Data.Data + 4, 4 * Size - 4);
      --p_ValueA->Data.Size;
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Shift<double>(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        long double *result)
{
  long double v3; // st7
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  unsigned int Size; // ecx
  Scaleform::GFx::AS3::CheckResult v6; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v6)->Result && this->ValueA.Data.Size )
  {
    v3 = *this->ValueA.Data.Data;
    p_ValueA = &this->ValueA;
    *result = v3;
    Size = p_ValueA->Data.Size;
    if ( Size == 1 )
    {
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::Clear(p_ValueA);
    }
    else
    {
      memmove((unsigned __int8 *)p_ValueA->Data.Data, (unsigned __int8 *)p_ValueA->Data.Data + 8, 8 * Size - 8);
      --p_ValueA->Data.Size;
    }
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Shift<Scaleform::GFx::ASString>(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebx
  Scaleform::GFx::ASStringNode *pObject; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS3::CheckResult v7; // [esp+7h] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v7)->Result && this->ValueA.Data.Size )
  {
    p_ValueA = &this->ValueA;
    pObject = this->ValueA.Data.Data->pObject;
    if ( !pObject )
      pObject = &result->pNode->pManager->NullStringNode;
    ++pObject->RefCount;
    pNode = result->pNode;
    if ( result->pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    result->pNode = pObject;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      p_ValueA,
      0);
  }
}
