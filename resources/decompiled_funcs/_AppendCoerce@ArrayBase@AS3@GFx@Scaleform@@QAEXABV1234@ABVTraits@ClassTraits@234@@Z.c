void __thiscall Scaleform::GFx::AS3::ArrayBase::AppendCoerce(
        Scaleform::GFx::AS3::ArrayBase *this,
        Scaleform::GFx::AS3::ArrayBase *arr,
        const Scaleform::GFx::AS3::ClassTraits::Traits *tr)
{
  unsigned int v5; // esi
  void (__thiscall *GetValueUnsafe)(Scaleform::GFx::AS3::ArrayBase *, unsigned int, Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::VM *VMRef; // esi
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+Fh] [ebp-29h] BYREF
  Scaleform::GFx::AS3::VM::Error v11; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+18h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value r; // [esp+28h] [ebp-10h] BYREF
  unsigned int size; // [esp+3Ch] [ebp+4h]

  if ( Scaleform::GFx::AS3::ArrayBase::CheckFixed(this, &result)->Result )
  {
    v5 = 0;
    size = arr->GetArraySize(arr);
    if ( size )
    {
      while ( 1 )
      {
        GetValueUnsafe = arr->GetValueUnsafe;
        r.Flags = 0;
        r.Bonus.pWeakProxy = 0;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        GetValueUnsafe(arr, v5, &v);
        if ( !tr->Coerce(tr, &v, &r) )
          break;
        this->PushBackValueUnsafe(this, &r);
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
        if ( (r.Flags & 0x1F) > 9 )
        {
          if ( (r.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
        }
        if ( ++v5 >= size )
          return;
      }
      VMRef = this->VMRef;
      Scaleform::GFx::AS3::VM::Error::Error(&v11, eCheckTypeFailedError, VMRef);
      Scaleform::GFx::AS3::VM::ThrowTypeError(VMRef, v8);
      pNode = v11.Message.pNode;
      --v11.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( (v.Flags & 0x1F) > 9 )
      {
        if ( (v.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
      }
      if ( (r.Flags & 0x1F) > 9 )
      {
        if ( (r.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&r);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&r);
      }
    }
  }
}
