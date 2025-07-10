Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Set(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int ind,
        const Scaleform::GFx::AS3::Value *v,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v6; // edi
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v10; // eax
  unsigned int Size; // eax
  __int16 v12; // ax
  Scaleform::GFx::AS3::CheckResult *v13; // esi
  char v14; // cl
  __int16 Flags; // ax
  char v16; // cl
  Scaleform::GFx::AS3::VM::Error v17; // [esp+8h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+10h] [ebp-10h] BYREF

  v6 = ind;
  if ( this->Fixed && ind >= this->ValueA.Data.Size || (Size = this->ValueA.Data.Size, ind > Size) )
  {
    VMRef = this->VMRef;
    Scaleform::GFx::AS3::VM::Error::Error(&v17, eOutOfRangeError, VMRef);
    Scaleform::GFx::AS3::VM::ThrowRangeError(VMRef, v8);
    pNode = v17.Message.pNode;
    --v17.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_5:
    v10 = result;
    result->Result = 0;
    return v10;
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
  if ( Scaleform::GFx::AS3::ArrayBase::CheckCoerce(this, (Scaleform::GFx::AS3::CheckResult *)&ind, tr, v, &r)->Result )
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
