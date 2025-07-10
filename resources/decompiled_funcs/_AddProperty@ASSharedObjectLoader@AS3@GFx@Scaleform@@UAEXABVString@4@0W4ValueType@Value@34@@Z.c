void __thiscall Scaleform::GFx::AS3::ASSharedObjectLoader::AddProperty(
        Scaleform::GFx::AS3::ASSharedObjectLoader *this,
        Scaleform::String *name,
        Scaleform::String *value,
        Scaleform::GFx::Value::ValueType type)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v5; // ebp
  int v6; // eax
  unsigned int v7; // eax
  long double v8; // st7
  const Scaleform::GFx::ASString *String; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  int v11; // eax
  unsigned int v12; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::AS3::Instances::fl::Object_vtbl *v14; // esi
  const Scaleform::GFx::AS3::Multiname *v15; // eax
  Scaleform::StringDataPtr qname; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname v18; // [esp+28h] [ebp-18h] BYREF

  v5 = this->ObjectStack.Data.Data[this->ObjectStack.Data.Size - 1];
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  switch ( type )
  {
    case VT_Undefined:
      Scaleform::GFx::AS3::Value::SetUndefined(&v);
      break;
    case VT_Null:
      Scaleform::GFx::AS3::Value::SetNull(&v);
      break;
    case VT_Boolean:
      v11 = strncmp(
              (const char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8),
              (const char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1],
              4u);
      Scaleform::GFx::AS3::Value::SetBool(&v, v11 == 0);
      break;
    case VT_Int:
      v6 = atoi((const char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::AS3::Value::SetSInt32(&v, v6);
      break;
    case VT_UInt:
      v7 = atoi((const char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::AS3::Value::SetUInt32(&v, v7);
      break;
    case VT_Number:
      v8 = atof((char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::AS3::Value::SetNumber(&v, v8);
      break;
    case VT_String:
      String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
                 this->pVM->StringManagerRef,
                 (Scaleform::GFx::ASString *)&value,
                 value);
      Scaleform::GFx::AS3::Value::Assign(&v, String);
      v10 = (Scaleform::GFx::ASStringNode *)value;
      --value[3].HeapTypeBits;
      if ( !v10->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      break;
    default:
      break;
  }
  if ( this->bArrayIsTop )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack((Scaleform::GFx::AS3::Impl::SparseArray *)&v5[1], &v);
  }
  else
  {
    v12 = name->HeapTypeBits & 0xFFFFFFFC;
    qname.Size = Scaleform::String::GetLength(name);
    pVM = this->pVM;
    qname.pStr = (const char *)(v12 + 8);
    v14 = v5->__vftable;
    Scaleform::GFx::AS3::Multiname::Multiname(&v18, pVM, &qname);
    v14->SetProperty(v5, (Scaleform::GFx::AS3::CheckResult *)&value, v15, &v);
    Scaleform::GFx::AS3::Multiname::~Multiname(&v18);
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
