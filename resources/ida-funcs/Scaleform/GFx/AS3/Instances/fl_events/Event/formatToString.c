void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::Value *v8; // edi
  bool v9; // bl
  __m128i *pData; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v13; // ecx
  bool v14; // zf
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::StringDataPtr v22; // [esp-14h] [ebp-4A0h]
  Scaleform::StringDataPtr v23; // [esp-8h] [ebp-494h]
  Scaleform::GFx::ASString asstr; // [esp+10h] [ebp-47Ch] BYREF
  Scaleform::GFx::AS3::CheckResult v25; // [esp+17h] [ebp-475h] BYREF
  unsigned int i; // [esp+18h] [ebp-474h] BYREF
  Scaleform::GFx::ASStringNode *v27; // [esp+1Ch] [ebp-470h]
  Scaleform::GFx::AS3::CheckResult v28; // [esp+22h] [ebp-46Ah] BYREF
  Scaleform::GFx::AS3::CheckResult v29; // [esp+23h] [ebp-469h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+24h] [ebp-468h] BYREF
  Scaleform::GFx::AS3::Value asval; // [esp+3Ch] [ebp-450h] BYREF
  Scaleform::StringBuffer sb; // [esp+4Ch] [ebp-440h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+64h] [ebp-428h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+7Ch] [ebp-410h] BYREF
  char str[1024]; // [esp+8Ch] [ebp-400h] BYREF

  if ( argc )
  {
    Scaleform::StringBuffer::StringBuffer(&sb, this->pTraits.pObject->pVM->MHeap);
    pVM = this->pTraits.pObject->pVM;
    asstr.pNode = (Scaleform::GFx::ASStringNode *)pVM[1].__vftable[23].~Scaleform::GFx::AS3::VM;
    ++asstr.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Convert2String(argv, &v25, &asstr);
    Scaleform::SFsprintf(str, 0x400u, "[%s", asstr.pNode->pData);
    Scaleform::StringBuffer::AppendString(&sb, (const __m128i *)str, 0xFFFFFFFF);
    i = 1;
    if ( argc <= 1 )
    {
LABEL_29:
      Scaleform::StringBuffer::AppendString(&sb, (const __m128i *)"]", 2u);
      pData = (__m128i *)sb.pData;
      if ( !sb.pData )
        pData = (__m128i *)uri;
      i = (unsigned int)Scaleform::GFx::ASStringManager::CreateStringNode(pVM->StringManagerRef->pStringManager, pData);
      ++*(_DWORD *)(i + 12);
      Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&i);
      v11 = (Scaleform::GFx::ASStringNode *)i;
      --*(_DWORD *)(i + 12);
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      pNode = asstr.pNode;
      --asstr.pNode->RefCount;
      v13 = pNode;
      v14 = pNode->RefCount == 0;
    }
    else
    {
      v8 = argv + 1;
      while ( 1 )
      {
        Scaleform::GFx::AS3::Value::Convert2String(v8, &v25, &asstr);
        Scaleform::GFx::AS3::Value::Value(&name, &asstr);
        Scaleform::GFx::AS3::Multiname::Multiname(&mn, pVM->PublicNamespace.pObject, &name);
        if ( (name.Flags & 0x1F) > 9 )
        {
          if ( (name.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
        }
        memset(&prop, 0, 16);
        Scaleform::GFx::AS3::Object::FindProperty(
          &this->Scaleform::GFx::AS3::Instances::fl::Object,
          &prop,
          &mn,
          FindGet);
        if ( (prop.This.Flags & 0x1F) == 0 || ((int)prop.pSI & 1) != 0 && ((int)prop.pSI & 0xFFFFFFFE) == 0 )
          break;
        if ( ((int)prop.pSI & 2) != 0 && ((int)prop.pSI & 0xFFFFFFFD) == 0 )
          break;
        asval.Flags = 0;
        asval.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop, &v29, pVM, &asval, valGet)->Result )
        {
          if ( (asval.Flags & 0x1F) > 9 )
          {
            if ( (asval.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&asval);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&asval);
          }
          if ( (prop.This.Flags & 0x1F) > 9 )
          {
            if ( (prop.This.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop.This);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&prop.This);
          }
          Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
          v21 = asstr.pNode;
          --asstr.pNode->RefCount;
          v13 = v21;
          v14 = v21->RefCount == 0;
          goto LABEL_34;
        }
        Scaleform::SFsprintf(str, 0x400u, " %s=", asstr.pNode->pData);
        Scaleform::StringBuffer::AppendString(&sb, (const __m128i *)str, 0xFFFFFFFF);
        v9 = (asval.Flags & 0x1F) == 10;
        Scaleform::GFx::AS3::Value::Convert2String(&asval, &v28, &asstr);
        if ( v9 )
          Scaleform::StringBuffer::AppendChar(&sb, 0x22u);
        Scaleform::SFsprintf(str, 0x400u, (char *)&stru_7F9BE8.allocator, asstr.pNode->pData);
        Scaleform::StringBuffer::AppendString(&sb, (const __m128i *)str, 0xFFFFFFFF);
        if ( v9 )
          Scaleform::StringBuffer::AppendChar(&sb, 0x22u);
        if ( (asval.Flags & 0x1F) > 9 )
        {
          if ( (asval.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&asval);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&asval);
        }
        if ( (prop.This.Flags & 0x1F) > 9 )
        {
          if ( (prop.This.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop.This);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&prop.This);
        }
        Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
        ++v8;
        if ( ++i >= argc )
          goto LABEL_29;
      }
      Scaleform::SFsprintf(
        str,
        0x400u,
        "Property %s not found on flash.events.Event and there is no default value.",
        asstr.pNode->pData);
      v23.pStr = str;
      v23.Size = strlen(str);
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&i, eReadSealedError, pVM, v23);
      Scaleform::GFx::AS3::VM::ThrowReferenceError(pVM, v15);
      v16 = v27;
      --v27->RefCount;
      if ( !v16->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( (prop.This.Flags & 0x1F) > 9 )
      {
        if ( (prop.This.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop.This);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&prop.This);
      }
      if ( (mn.Name.Flags & 0x1F) > 9 )
      {
        if ( (mn.Name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&mn.Name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
      }
      if ( mn.Obj.pObject )
      {
        if ( ((int)mn.Obj.pObject & 1) != 0 )
        {
          --mn.Obj.pObject;
          v17 = asstr.pNode;
          --asstr.pNode->RefCount;
          v13 = v17;
          v14 = v17->RefCount == 0;
          goto LABEL_34;
        }
        RefCount = mn.Obj.pObject->RefCount;
        pObject = mn.Obj.pObject;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          mn.Obj.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
        }
      }
      v20 = asstr.pNode;
      --asstr.pNode->RefCount;
      v13 = v20;
      v14 = v20->RefCount == 0;
    }
LABEL_34:
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&sb);
  }
  else
  {
    v22.pStr = "Event::formatToString";
    v22.Size = 21;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&i,
      eWrongArgumentCountError,
      this->pTraits.pObject->pVM,
      v22,
      1,
      1,
      0);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(this->pTraits.pObject->pVM, v5);
    v6 = v27;
    --v27->RefCount;
    if ( !v6->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
}
