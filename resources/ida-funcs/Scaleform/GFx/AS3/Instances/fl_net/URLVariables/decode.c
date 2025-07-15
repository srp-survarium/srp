void __thiscall Scaleform::GFx::AS3::Instances::fl_net::URLVariables::decode(
        Scaleform::GFx::AS3::Instances::fl_net::URLVariables *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::ASString *source)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLVariables *v3; // ebp
  unsigned int FirstCharAt; // esi
  int v5; // ebx
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // ebx
  unsigned int v10; // eax
  Scaleform::StringBuffer *p_name; // edi
  unsigned int Size; // ebp
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // esi
  char *pData; // eax
  char *v15; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // edi
  void (__thiscall **p_SetProperty)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, char *, int, int); // esi
  int v18; // eax
  int v19; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v21; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::StringBuffer *p_value; // ecx
  char *v25; // eax
  Scaleform::GFx::AS3::StringManager *v26; // esi
  char *v27; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v28; // edi
  void (__thiscall **v29)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, char *, int, int); // esi
  int v30; // eax
  int v31; // eax
  unsigned int v32; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v33; // ecx
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  int v36; // [esp-4h] [ebp-94h]
  int v37; // [esp-4h] [ebp-94h]
  bool parseName; // [esp+12h] [ebp-7Eh]
  char v39; // [esp+13h] [ebp-7Dh] BYREF
  Scaleform::GFx::ASString v; // [esp+14h] [ebp-7Ch] BYREF
  Scaleform::GFx::ASString v41; // [esp+18h] [ebp-78h] BYREF
  const char *pstr; // [esp+1Ch] [ebp-74h] BYREF
  Scaleform::GFx::AS3::Instances::fl_net::URLVariables *v43; // [esp+20h] [ebp-70h]
  Scaleform::GFx::AS3::Value v44; // [esp+24h] [ebp-6Ch] BYREF
  Scaleform::GFx::AS3::Multiname v45; // [esp+34h] [ebp-5Ch] BYREF
  Scaleform::GFx::AS3::Value v46; // [esp+4Ch] [ebp-44h] BYREF
  Scaleform::StringBuffer name; // [esp+5Ch] [ebp-34h] BYREF
  Scaleform::StringBuffer value; // [esp+74h] [ebp-1Ch] BYREF

  v3 = this;
  v43 = this;
  parseName = 1;
  Scaleform::StringBuffer::StringBuffer(&name, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&value, Scaleform::Memory::pGlobalHeap);
  FirstCharAt = Scaleform::GFx::ASConstString::GetFirstCharAt(&source->Scaleform::GFx::ASConstString, 0, &pstr);
  while ( FirstCharAt )
  {
    switch ( FirstCharAt )
    {
      case 0x25u:
        FirstCharAt = Scaleform::GFx::ASConstString::GetNextChar(&source->Scaleform::GFx::ASConstString, &pstr);
        v5 = 0;
        if ( FirstCharAt )
        {
          v6 = 0;
          do
          {
            if ( v6 >= 8 )
              break;
            v7 = BYTE1(FirstCharAt);
            v8 = Scaleform::UnicodeXDigitBits[v7];
            if ( !Scaleform::UnicodeXDigitBits[v7] )
              goto LABEL_54;
            if ( v8 != 1 )
            {
              v3 = v43;
              if ( (Scaleform::UnicodeXDigitBits[v8 + ((unsigned __int8)FirstCharAt >> 4)] & (1 << (FirstCharAt & 0xF))) == 0 )
                goto LABEL_54;
            }
            if ( FirstCharAt - 65 <= 0x19 )
              FirstCharAt += 32;
            v9 = v5 << v6;
            v10 = FirstCharAt - 48;
            if ( FirstCharAt > 0x39 )
              v10 = FirstCharAt - 87;
            v5 = v10 | v9;
            FirstCharAt = Scaleform::GFx::ASConstString::GetNextChar(&source->Scaleform::GFx::ASConstString, &pstr);
            v6 += 4;
          }
          while ( FirstCharAt );
          if ( v5 )
          {
            p_name = &name;
            if ( !parseName )
              p_name = &value;
            Size = p_name->Size;
            Scaleform::StringBuffer::Resize(p_name, Size + 1);
            p_name->pData[Size] = v5;
            v3 = v43;
            continue;
          }
        }
        break;
      case 0xDu:
        FirstCharAt = 10;
        break;
      case 0x26u:
        StringManagerRef = v3->pTraits.pObject->pVM->StringManagerRef;
        pData = name.pData;
        if ( !name.pData )
          pData = (char *)&buf;
        v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, pData);
        ++v.pNode->RefCount;
        Scaleform::GFx::AS3::Value::Value(&v44, &v);
        v15 = value.pData;
        if ( !value.pData )
          v15 = (char *)&buf;
        v41.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManagerRef->pStringManager, v15);
        ++v41.pNode->RefCount;
        pObject = v3->pTraits.pObject->pVM->PublicNamespace.pObject;
        p_SetProperty = (void (__thiscall **)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, char *, int, int))&v3->SetProperty;
        Scaleform::GFx::AS3::Value::Value(&v46, &v41);
        v36 = v18;
        Scaleform::GFx::AS3::Multiname::Multiname(&v45, pObject, &v44);
        (*p_SetProperty)(v3, &v39, v19, v36);
        if ( (v45.Name.Flags & 0x1F) > 9 )
        {
          if ( (v45.Name.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v45.Name);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v45.Name);
        }
        if ( v45.Obj.pObject )
        {
          if ( ((int)v45.Obj.pObject & 1) != 0 )
          {
            --v45.Obj.pObject;
          }
          else
          {
            RefCount = v45.Obj.pObject->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              v21 = v45.Obj.pObject;
              v45.Obj.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
            }
          }
        }
        if ( (v46.Flags & 0x1F) > 9 )
        {
          if ( (v46.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v46);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v46);
        }
        pNode = v41.pNode;
        --v41.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( (v44.Flags & 0x1F) > 9 )
        {
          if ( (v44.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v44);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v44);
        }
        v23 = v.pNode;
        --v.pNode->RefCount;
        if ( !v23->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        Scaleform::StringBuffer::Clear(&name);
        Scaleform::StringBuffer::Clear(&value);
        parseName = 1;
        break;
      default:
        if ( !parseName )
        {
          p_value = &value;
          goto LABEL_53;
        }
        if ( FirstCharAt != 61 )
        {
          p_value = &name;
LABEL_53:
          Scaleform::StringBuffer::AppendChar(p_value, FirstCharAt);
          break;
        }
        parseName = 0;
        break;
    }
LABEL_54:
    FirstCharAt = Scaleform::GFx::ASConstString::GetNextChar(&source->Scaleform::GFx::ASConstString, &pstr);
  }
  if ( Scaleform::StringBuffer::GetLength(&name) )
  {
    v25 = name.pData;
    v26 = v3->pTraits.pObject->pVM->StringManagerRef;
    if ( !name.pData )
      v25 = (char *)&buf;
    v41.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(v26->pStringManager, v25);
    ++v41.pNode->RefCount;
    Scaleform::GFx::AS3::Value::Value(&v44, &v41);
    v27 = value.pData;
    if ( !value.pData )
      v27 = (char *)&buf;
    v.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(v26->pStringManager, v27);
    ++v.pNode->RefCount;
    v28 = v3->pTraits.pObject->pVM->PublicNamespace.pObject;
    v29 = (void (__thiscall **)(Scaleform::GFx::AS3::Instances::fl_net::URLVariables *, char *, int, int))&v3->SetProperty;
    Scaleform::GFx::AS3::Value::Value(&v46, &v);
    v37 = v30;
    Scaleform::GFx::AS3::Multiname::Multiname(&v45, v28, &v44);
    (*v29)(v3, &v39, v31, v37);
    if ( (v45.Name.Flags & 0x1F) > 9 )
    {
      if ( (v45.Name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v45.Name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v45.Name);
    }
    if ( v45.Obj.pObject )
    {
      if ( ((int)v45.Obj.pObject & 1) != 0 )
      {
        --v45.Obj.pObject;
      }
      else
      {
        v32 = v45.Obj.pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v32) != 0 )
        {
          v33 = v45.Obj.pObject;
          v45.Obj.pObject->RefCount = v32 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v33);
        }
      }
    }
    if ( (v46.Flags & 0x1F) > 9 )
    {
      if ( (v46.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v46);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v46);
    }
    v34 = v.pNode;
    --v.pNode->RefCount;
    if ( !v34->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    if ( (v44.Flags & 0x1F) > 9 )
    {
      if ( (v44.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v44);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v44);
    }
    v35 = v41.pNode;
    --v41.pNode->RefCount;
    if ( !v35->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  }
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&value);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&name);
}
