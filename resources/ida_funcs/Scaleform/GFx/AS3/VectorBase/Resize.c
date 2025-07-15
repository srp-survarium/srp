Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<long>::Resize(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int newSise)
{
  unsigned int Size; // esi
  Scaleform::ArrayDH<long,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  Scaleform::GFx::AS3::CheckResult v7; // [esp+Bh] [ebp-1h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v7)->Result )
  {
    Size = this->ValueA.Data.Size;
    p_ValueA = &this->ValueA;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      p_ValueA,
      newSise);
    for ( ; Size < newSise; ++Size )
      p_ValueA->Data.Data[Size] = 0;
    v6 = result;
    result->Result = 1;
  }
  else
  {
    v6 = result;
    result->Result = 0;
  }
  return v6;
}


Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<double>::Resize(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int newSise)
{
  unsigned int Size; // esi
  Scaleform::ArrayDH<double,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  Scaleform::GFx::AS3::CheckResult *v6; // eax
  Scaleform::GFx::AS3::CheckResult v7; // [esp+13h] [ebp-5h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v7)->Result )
  {
    Size = this->ValueA.Data.Size;
    p_ValueA = &this->ValueA;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      p_ValueA,
      newSise);
    if ( Size < newSise )
    {
      if ( (int)(newSise - Size) >= 4 )
      {
        do
        {
          p_ValueA->Data.Data[Size] = 0.0;
          p_ValueA->Data.Data[Size + 1] = 0.0;
          p_ValueA->Data.Data[Size + 2] = 0.0;
          p_ValueA->Data.Data[Size + 3] = 0.0;
          Size += 4;
        }
        while ( Size < newSise - 3 );
      }
      for ( ; Size < newSise; ++Size )
        p_ValueA->Data.Data[Size] = 0.0;
    }
    v6 = result;
    result->Result = 1;
  }
  else
  {
    v6 = result;
    result->Result = 0;
  }
  return v6;
}


Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Resize(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int newSise)
{
  unsigned int Size; // ebx
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // ebp
  int v6; // edi
  int v7; // esi
  Scaleform::GFx::AS3::Value *Null; // ecx
  Scaleform::GFx::AS3::CheckResult *v9; // eax
  Scaleform::GFx::AS3::CheckResult v10; // [esp+Bh] [ebp-11h] BYREF
  Scaleform::GFx::AS3::Value other; // [esp+Ch] [ebp-10h] BYREF

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &v10)->Result )
  {
    Size = this->ValueA.Data.Size;
    p_ValueA = &this->ValueA;
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->ValueA.Data,
      newSise);
    if ( Size < newSise )
    {
      v6 = Size;
      v7 = newSise - Size;
      do
      {
        Null = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
        other = *Null;
        if ( (Null->Flags & 0x1F) > 9 )
        {
          if ( (Null->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(Null);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(Null);
        }
        Scaleform::GFx::AS3::Value::Assign(&p_ValueA->Data.Data[v6], &other);
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&other);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
        ++v6;
        --v7;
      }
      while ( v7 );
    }
    v9 = result;
    result->Result = 1;
  }
  else
  {
    v9 = result;
    result->Result = 0;
  }
  return v9;
}


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
