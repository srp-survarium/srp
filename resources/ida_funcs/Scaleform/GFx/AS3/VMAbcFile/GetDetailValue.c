Scaleform::GFx::AS3::Value *__thiscall Scaleform::GFx::AS3::VMAbcFile::GetDetailValue(
        Scaleform::GFx::AS3::VMAbcFile *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *d)
{
  int pData; // eax
  Scaleform::GFx::AS3::Value::V1U v5; // ecx
  Scaleform::GFx::AS3::Value *v6; // eax
  Scaleform::GFx::AS3::Value::V1U v7; // ecx
  long double Double; // st7
  Scaleform::GFx::ASString *String; // eax
  Scaleform::GFx::AS3::Value *v10; // esi
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS3::Value *Undefined; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  Scaleform::StringDataPtr v14; // [esp+8h] [ebp-8h] BYREF

  pData = (int)d->pData;
  if ( (int)d->pData <= 0 )
  {
LABEL_18:
    if ( (_S10_0 & 1) == 0 )
    {
      _S10_0 |= 1u;
      v.Flags = 0;
      v.Bonus.pWeakProxy = 0;
      atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
    }
    v10 = result;
    *result = v;
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
      {
        ++v.Bonus.pWeakProxy->RefCount;
        return result;
      }
      Scaleform::GFx::AS3::Value::AddRefInternal(&v);
    }
    return v10;
  }
  else
  {
    switch ( (unsigned int)d->pManager )
    {
      case 0u:
        Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetUndefined();
        goto LABEL_11;
      case 1u:
        Scaleform::GFx::AS3::Abc::ConstPool::GetString(
          &this->File.pObject->Const_Pool,
          &v14,
          (Scaleform::GFx::AS3::AbsoluteIndex)d->pData);
        String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
                   this->VMRef->StringManagerRef,
                   (Scaleform::GFx::ASString *)&d,
                   (char *)v14.pStr,
                   v14.Size);
        v10 = result;
        Scaleform::GFx::AS3::Value::Value(result, String);
        v11 = d;
        --d->RefCount;
        if ( v11->RefCount )
          return v10;
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        return result;
      case 3u:
        v5 = (Scaleform::GFx::AS3::Value::V1U)this->File.pObject->Const_Pool.ConstInt.Data.Data[pData];
        v6 = result;
        result->Flags = 2;
        result->Bonus.pWeakProxy = 0;
        result->value.VS._1 = v5;
        return v6;
      case 4u:
        v7 = (Scaleform::GFx::AS3::Value::V1U)this->File.pObject->Const_Pool.ConstUInt.Data.Data[pData];
        v6 = result;
        result->Flags = 3;
        result->Bonus.pWeakProxy = 0;
        result->value.VS._1 = v7;
        return v6;
      case 5u:
      case 8u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
      case 0x19u:
      case 0x1Au:
        InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(
                              this,
                              (Scaleform::GFx::AS3::Instances::fl::Namespace *)d->pData);
        Scaleform::GFx::AS3::Value::Value(result, InternedNamespace);
        return result;
      case 6u:
        Double = Scaleform::GFx::AS3::Abc::ConstPool::GetDouble(&this->File.pObject->Const_Pool, (unsigned int)d->pData);
        v6 = result;
        result->Flags = 4;
        result->value.VNumber = Double;
        result->Bonus.pWeakProxy = 0;
        return v6;
      case 0xAu:
        v6 = result;
        result->Flags = 1;
        result->Bonus.pWeakProxy = 0;
        result->value.VS._1.VBool = 0;
        return v6;
      case 0xBu:
        v6 = result;
        result->Flags = 1;
        result->Bonus.pWeakProxy = 0;
        result->value.VS._1.VBool = 1;
        return v6;
      case 0xCu:
        Undefined = (Scaleform::GFx::AS3::Value *)Scaleform::GFx::AS3::Value::GetNull();
LABEL_11:
        v10 = result;
        *result = *Undefined;
        if ( (Undefined->Flags & 0x1F) <= 9 )
          return v10;
        if ( (Undefined->Flags & 0x200) != 0 )
          ++Undefined->Bonus.pWeakProxy->RefCount;
        else
          Scaleform::GFx::AS3::Value::AddRefInternal(Undefined);
        v6 = result;
        break;
      default:
        goto LABEL_18;
    }
  }
  return v6;
}
