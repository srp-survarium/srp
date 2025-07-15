Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Set(
        Scaleform::GFx::AS3::VectorBase<long> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v6; // edi
  unsigned int Size; // eax
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v11; // eax
  __int16 v12; // ax
  Scaleform::GFx::AS3::CheckResult *v13; // esi
  char v14; // cl
  int *Data; // edx
  __int16 Flags; // ax
  char v17; // cl
  Scaleform::GFx::AS3::VM::Error v18; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-10h] BYREF

  v6 = ind;
  if ( this->Fixed && (Size = this->ValueA.Data.Size, ind >= Size) || (Size = this->ValueA.Data.Size, ind > Size) )
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eOutOfRangeError, (Scaleform::String)VMRef, ind, Size - 1);
    Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v9);
    pNode = v18.Message.pNode;
    --v18.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_5:
    v11 = result;
    result->Result = 0;
    return v11;
  }
  if ( ind == Size
    && !Scaleform::GFx::AS3::VectorBase<long>::Resize(this, (Scaleform::GFx::AS3::CheckResult *)&ind, ind + 1)->Result )
  {
    goto LABEL_5;
  }
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
         this,
         (Scaleform::GFx::AS3::CheckResult *)&ind,
         tr,
         v,
         (Scaleform::GFx::ASStringNode *)&r)->Result )
  {
    Data = this->ValueA.Data.Data;
    v13 = result;
    Data[v6] = r.value.VS._1.VInt;
    Flags = r.Flags;
    v17 = r.Flags & 0x1F;
    result->Result = 1;
    if ( v17 > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        goto LABEL_12;
LABEL_15:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  else
  {
    v12 = r.Flags;
    v13 = result;
    v14 = r.Flags & 0x1F;
    result->Result = 0;
    if ( v14 > 9 )
    {
      if ( (v12 & 0x200) != 0 )
      {
LABEL_12:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        return v13;
      }
      goto LABEL_15;
    }
  }
  return v13;
}


Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<double>::Set(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        const Scaleform::GFx::AS3::Value *v,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v6; // edi
  unsigned int Size; // eax
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v11; // eax
  __int16 v12; // ax
  Scaleform::GFx::AS3::CheckResult *v13; // esi
  char v14; // cl
  long double *Data; // edx
  __int16 Flags; // ax
  char v17; // cl
  Scaleform::GFx::AS3::VM::Error v18; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-10h] BYREF

  v6 = ind;
  if ( this->Fixed && (Size = this->ValueA.Data.Size, ind >= Size) || (Size = this->ValueA.Data.Size, ind > Size) )
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v18, eOutOfRangeError, VMRef, ind, Size - 1);
    Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v9);
    pNode = v18.Message.pNode;
    --v18.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_5:
    v11 = result;
    result->Result = 0;
    return v11;
  }
  if ( ind == Size
    && !Scaleform::GFx::AS3::VectorBase<double>::Resize(this, (Scaleform::GFx::AS3::CheckResult *)&ind, ind + 1)->Result )
  {
    goto LABEL_5;
  }
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&ind, tr, v, &r)->Result )
  {
    Data = this->ValueA.Data.Data;
    v13 = result;
    Data[v6] = r.value.VNumber;
    Flags = r.Flags;
    v17 = r.Flags & 0x1F;
    result->Result = 1;
    if ( v17 > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        goto LABEL_12;
LABEL_15:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  else
  {
    v12 = r.Flags;
    v13 = result;
    v14 = r.Flags & 0x1F;
    result->Result = 0;
    if ( v14 > 9 )
    {
      if ( (v12 & 0x200) != 0 )
      {
LABEL_12:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        return v13;
      }
      goto LABEL_15;
    }
  }
  return v13;
}


Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Set(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v6; // edi
  unsigned int Size; // eax
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v11; // eax
  __int16 v12; // ax
  Scaleform::GFx::AS3::CheckResult *v13; // esi
  char v14; // cl
  __int16 Flags; // ax
  char v16; // cl
  Scaleform::GFx::AS3::VM::Error v17; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-10h] BYREF

  v6 = ind;
  if ( this->Fixed && (Size = this->ValueA.Data.Size, ind >= Size) || (Size = this->ValueA.Data.Size, ind > Size) )
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v17, eOutOfRangeError, (Scaleform::String)VMRef, ind, Size - 1);
    Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v9);
    pNode = v17.Message.pNode;
    --v17.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_5:
    v11 = result;
    result->Result = 0;
    return v11;
  }
  if ( ind == Size
    && !Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Resize(
          this,
          (Scaleform::GFx::AS3::CheckResult *)&ind,
          ind + 1)->Result )
  {
    goto LABEL_5;
  }
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
         this,
         (Scaleform::GFx::AS3::CheckResult *)&ind,
         tr,
         v,
         (Scaleform::GFx::ASStringNode *)&r)->Result )
  {
    Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::SetUnsafe(this, v6, &r);
    Flags = r.Flags;
    v13 = result;
    v16 = r.Flags & 0x1F;
    result->Result = 1;
    if ( v16 > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        goto LABEL_12;
LABEL_15:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  else
  {
    v12 = r.Flags;
    v13 = result;
    v14 = r.Flags & 0x1F;
    result->Result = 0;
    if ( v14 > 9 )
    {
      if ( (v12 & 0x200) != 0 )
      {
LABEL_12:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        return v13;
      }
      goto LABEL_15;
    }
  }
  return v13;
}


Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Set(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        const Scaleform::GFx::AS3::Value *v,
        Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v6; // edi
  unsigned int Size; // eax
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v11; // eax
  __int16 v12; // ax
  Scaleform::GFx::AS3::CheckResult *v13; // esi
  char v14; // cl
  __int16 Flags; // ax
  char v16; // cl
  Scaleform::GFx::AS3::VM::Error v17; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-10h] BYREF

  v6 = ind;
  if ( this->Fixed && (Size = this->ValueA.Data.Size, ind >= Size) || (Size = this->ValueA.Data.Size, ind > Size) )
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v17, eOutOfRangeError, (Scaleform::String)VMRef, ind, Size - 1);
    Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v9);
    pNode = v17.Message.pNode;
    --v17.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_5:
    v11 = result;
    result->Result = 0;
    return v11;
  }
  if ( ind == Size
    && !Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Resize(
          this,
          (Scaleform::GFx::AS3::CheckResult *)&ind,
          ind + 1)->Result )
  {
    goto LABEL_5;
  }
  r.Flags = 0;
  r.Bonus.pWeakProxy = 0;
  if ( Scaleform::GFx::AS3::ArrayBase::CheckCoerce(
         this,
         (Scaleform::GFx::AS3::CheckResult *)&ind,
         tr,
         v,
         (Scaleform::GFx::ASStringNode *)&r)->Result )
  {
    Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::SetUnsafe(this, v6, &r);
    Flags = r.Flags;
    v13 = result;
    v16 = r.Flags & 0x1F;
    result->Result = 1;
    if ( v16 > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        goto LABEL_12;
LABEL_15:
      Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
    }
  }
  else
  {
    v12 = r.Flags;
    v13 = result;
    v14 = r.Flags & 0x1F;
    result->Result = 0;
    if ( v14 > 9 )
    {
      if ( (v12 & 0x200) != 0 )
      {
LABEL_12:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        return v13;
      }
      goto LABEL_15;
    }
  }
  return v13;
}
