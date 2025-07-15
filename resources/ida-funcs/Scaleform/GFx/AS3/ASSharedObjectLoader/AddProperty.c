void __userpurge Scaleform::GFx::AS3::ASSharedObjectLoader::AddProperty(
        Scaleform::GFx::AS3::ASSharedObjectLoader *this@<ecx>,
        int a2@<ebx>,
        Scaleform::String *name,
        Scaleform::String *value,
        Scaleform::GFx::Value::ValueType type)
{
  Scaleform::GFx::AS3::Instances::fl::Object *v6; // ebp
  unsigned int v7; // eax
  unsigned int v8; // eax
  long double v9; // st7
  const Scaleform::GFx::ASString *String; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  int v12; // eax
  unsigned int v13; // esi
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::AS3::Instances::fl::Object_vtbl *v15; // esi
  const Scaleform::GFx::AS3::Multiname *v16; // eax
  Scaleform::StringDataPtr qname; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname v19; // [esp+28h] [ebp-18h] BYREF

  v6 = this->ObjectStack.Data.Data[this->ObjectStack.Data.Size - 1];
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
      v12 = strncmp((const char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8), "true", 4u);
      Scaleform::GFx::AS3::Value::SetBool(&v, v12 == 0);
      break;
    case VT_Int:
      v7 = atoi(a2, (char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::AS3::Value::SetSInt32(&v, v7);
      break;
    case VT_UInt:
      v8 = atoi(a2, (char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::AS3::Value::SetUInt32(&v, v8);
      break;
    case VT_Number:
      v9 = atof((int)this, (char *)((value->HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::AS3::Value::SetNumber(&v, v9);
      break;
    case VT_String:
      String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateString(
                 this->pVM->StringManagerRef,
                 (Scaleform::GFx::ASString *)&value,
                 value);
      Scaleform::GFx::AS3::Value::Assign(&v, String);
      v11 = (Scaleform::GFx::ASStringNode *)value;
      --value[3].HeapTypeBits;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      break;
    default:
      break;
  }
  if ( this->bArrayIsTop )
  {
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack((Scaleform::GFx::AS3::Impl::SparseArray *)&v6[1], &v);
  }
  else
  {
    v13 = name->HeapTypeBits & 0xFFFFFFFC;
    qname.Size = Scaleform::String::GetLength(name);
    pVM = this->pVM;
    qname.pStr = (const char *)(v13 + 8);
    v15 = v6->__vftable;
    Scaleform::GFx::AS3::Multiname::Multiname(&v19, pVM, &qname);
    v15->SetProperty(v6, (Scaleform::GFx::AS3::CheckResult *)&value, v16, &v);
    Scaleform::GFx::AS3::Multiname::~Multiname(&v19);
  }
  if ( (v.Flags & 0x1F) > 9 )
  {
    if ( (v.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
  }
}
