void __thiscall Scaleform::GFx::AS3::Instances::fl_events::Event::formatToString(
        Scaleform::GFx::AS3::Instances::fl_events::Event *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *v5; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::AS3::VM *pVM; // edi
  bool v9; // bl
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // ecx
  char *pData; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString asstr; // [esp+Ch] [ebp-480h] BYREF
  Scaleform::GFx::AS3::CheckResult v18; // [esp+13h] [ebp-479h] BYREF
  unsigned int i; // [esp+14h] [ebp-478h] BYREF
  Scaleform::GFx::ASStringNode *v20; // [esp+18h] [ebp-474h]
  Scaleform::GFx::AS3::Value *v21; // [esp+1Ch] [ebp-470h]
  Scaleform::GFx::AS3::CheckResult v22; // [esp+22h] [ebp-46Ah] BYREF
  Scaleform::GFx::AS3::CheckResult v23; // [esp+23h] [ebp-469h] BYREF
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
    Scaleform::GFx::AS3::Value::Convert2String(argv, &v18, &asstr);
    Scaleform::SFsprintf(str, 0x400u, "[%s", asstr.pNode->pData);
    Scaleform::StringBuffer::AppendString(&sb, str, 0xFFFFFFFF);
    i = 1;
    if ( argc <= 1 )
    {
LABEL_54:
      Scaleform::StringBuffer::AppendString(&sb, "]", 2u);
      pData = sb.pData;
      if ( !sb.pData )
        pData = (char *)&buf;
      i = (unsigned int)Scaleform::GFx::ASStringManager::CreateStringNode(pVM->StringManagerRef->pStringManager, pData);
      ++*(_DWORD *)(i + 12);
      Scaleform::GFx::AS3::Value::Assign(result, (const Scaleform::GFx::ASString *)&i);
      v15 = (Scaleform::GFx::ASStringNode *)i;
      --*(_DWORD *)(i + 12);
      if ( !v15->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    }
    else
    {
      v21 = argv + 1;
      while ( 1 )
      {
        Scaleform::GFx::AS3::Value::Convert2String(v21, &v18, &asstr);
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
        if ( (prop.This.Flags & 0x1F) == 0
          || ((int)prop.pSI & 1) != 0 && ((int)prop.pSI & 0xFFFFFFFE) == 0
          || ((int)prop.pSI & 2) != 0 && ((int)prop.pSI & 0xFFFFFFFD) == 0 )
        {
          Scaleform::SFsprintf(
            str,
            0x400u,
            "Property %s not found on flash.events.Event and there is no default value.",
            asstr.pNode->pData);
          Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&i, eReadSealedError, pVM);
          Scaleform::GFx::AS3::VM::ThrowReferenceError(pVM, v10);
          v11 = v20;
          --v20->RefCount;
          if ( !v11->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v11);
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
            }
            else
            {
              RefCount = mn.Obj.pObject->RefCount;
              pObject = mn.Obj.pObject;
              if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
              {
                mn.Obj.pObject->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
              }
            }
          }
          goto LABEL_58;
        }
        asval.Flags = 0;
        asval.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(&prop, &v23, pVM, &asval, valGet)->Result )
          break;
        Scaleform::SFsprintf(str, 0x400u, " %s=", asstr.pNode->pData);
        Scaleform::StringBuffer::AppendString(&sb, str, 0xFFFFFFFF);
        v9 = (asval.Flags & 0x1F) == 10;
        Scaleform::GFx::AS3::Value::Convert2String(&asval, &v22, &asstr);
        if ( v9 )
          Scaleform::StringBuffer::AppendChar(&sb, 0x22u);
        Scaleform::SFsprintf(str, 0x400u, "%s", asstr.pNode->pData);
        Scaleform::StringBuffer::AppendString(&sb, str, 0xFFFFFFFF);
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
        ++v21;
        if ( ++i >= argc )
          goto LABEL_54;
      }
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
        {
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&prop.This);
          Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
          goto LABEL_58;
        }
        Scaleform::GFx::AS3::Value::ReleaseInternal(&prop.This);
      }
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    }
LABEL_58:
    pNode = asstr.pNode;
    --asstr.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&sb);
  }
  else
  {
    v5 = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&i, eWrongArgumentCountError, v5);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(v5, v6);
    v7 = v20;
    --v20->RefCount;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
}
