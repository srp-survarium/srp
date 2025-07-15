char __thiscall Scaleform::GFx::AS2::XmlNodeObject::SetMember(
        Scaleform::GFx::AS2::XmlNodeObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        const Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Environment *v5; // esi
  Scaleform::Log *Log; // eax
  const Scaleform::GFx::ASString *v8; // ebp
  Scaleform::GFx::LogState *v9; // ebx
  Scaleform::GFx::AS2::XmlNodeObject::StandardMember StandardMemberConstant; // eax
  __int32 v11; // eax
  int v12; // eax
  Scaleform::GFx::XML::DOMString *String; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  int v16; // eax
  unsigned __int8 v17; // al
  Scaleform::GFx::XML::ObjectManager *v18; // ecx
  char *v19; // ebx
  int v20; // eax
  Scaleform::GFx::XML::ObjectManager *v21; // ecx
  int v22; // ebp
  Scaleform::GFx::XML::DOMString *v23; // eax
  Scaleform::GFx::XML::DOMString *v24; // eax
  Scaleform::GFx::XML::DOMString *v25; // ecx
  Scaleform::GFx::XML::DOMString *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // ebx
  Scaleform::GFx::ASStringNode *v28; // eax
  int v29; // edi
  unsigned __int8 v30; // al
  int v31; // edi
  Scaleform::GFx::AS2::Object *v32; // eax
  Scaleform::GFx::AS2::Object *v33; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v34; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::XML::DOMString v36; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::XML::DOMString v37; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::GFx::XML::DOMString v38; // [esp+18h] [ebp-8h] BYREF
  Scaleform::GFx::XML::DOMString *v39; // [esp+1Ch] [ebp-4h]

  v5 = penv;
  Log = Scaleform::GFx::AS2::Environment::GetLog(penv);
  v8 = name;
  v9 = (Scaleform::GFx::LogState *)Log;
  if ( !*(_DWORD *)&this->ResolveHandler.Flags )
    return Scaleform::GFx::AS2::Object::SetMember(this, v5, v8, val, flags);
  StandardMemberConstant = Scaleform::GFx::AS2::XmlNodeObject::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::XmlNodeObject *)((char *)this - 16),
                             v5,
                             name);
  if ( StandardMemberConstant )
  {
    v11 = StandardMemberConstant - 7;
    if ( v11 )
    {
      if ( v11 == 2 )
      {
        v12 = *(_DWORD *)&this->ResolveHandler.Flags;
        if ( !v12 || *(_BYTE *)(v12 + 32) == 1 )
        {
          if ( v9 )
          {
            Scaleform::GFx::LogState::LogMessageByType(
              v9,
              (Scaleform::LogMessageId)147456,
              "XMLNodeObject::SetMember - cannot set nodeValue of a malformed node");
            return 1;
          }
        }
        else
        {
          Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&val, v5, -1, 0);
          String = Scaleform::GFx::XML::ObjectManager::CreateString(
                     *(Scaleform::GFx::XML::ObjectManager **)(*(_DWORD *)&this->ResolveHandler.Flags + 8),
                     (Scaleform::GFx::XML::DOMString *)&flags,
                     *(char **)&val->T.Type,
                     val[1].NV.UInt32Value);
          Scaleform::GFx::XML::DOMString::AssignNode(
            (Scaleform::GFx::XML::DOMString *)(*(_DWORD *)&this->ResolveHandler.Flags + 12),
            String->pNode);
          Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&flags);
          v14 = (Scaleform::GFx::ASStringNode *)val;
          --*((_DWORD *)&val->NV + 3);
          if ( !v14->RefCount )
          {
            Scaleform::GFx::ASStringNode::ReleaseNode(v14);
            return 1;
          }
        }
        return 1;
      }
      return Scaleform::GFx::AS2::Object::SetMember(this, v5, v8, val, flags);
    }
    v16 = *(_DWORD *)&this->ResolveHandler.Flags;
    if ( v16 )
    {
      v17 = *(_BYTE *)(v16 + 32);
      if ( v17 == 1 )
      {
        v18 = *(Scaleform::GFx::XML::ObjectManager **)(*(_DWORD *)&this->ResolveHandler.Flags + 8);
        v39 = *(Scaleform::GFx::XML::DOMString **)&this->ResolveHandler.Flags;
        Scaleform::GFx::XML::ObjectManager::EmptyString(v18, (Scaleform::GFx::XML::DOMString *)&name);
        Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&penv, v5, -1, 0);
        v19 = (char *)penv->__vftable;
        strchr((char *)penv->__vftable, 0x3Au);
        v21 = *(Scaleform::GFx::XML::ObjectManager **)(*(_DWORD *)&this->ResolveHandler.Flags + 8);
        v22 = v20;
        if ( v20 )
        {
          v23 = Scaleform::GFx::XML::ObjectManager::CreateString(v21, &v36, v19, v20 - (_DWORD)v19);
          Scaleform::GFx::XML::DOMString::AssignNode((Scaleform::GFx::XML::DOMString *)&name, v23->pNode);
          Scaleform::GFx::XML::DOMString::~DOMString(&v36);
          v24 = Scaleform::GFx::XML::ObjectManager::CreateString(
                  *(Scaleform::GFx::XML::ObjectManager **)(*(_DWORD *)&this->ResolveHandler.Flags + 8),
                  &v37,
                  (char *)(v22 + 1),
                  strlen((const char *)(v22 + 1)));
          Scaleform::GFx::XML::DOMString::AssignNode(
            (Scaleform::GFx::XML::DOMString *)(*(_DWORD *)&this->ResolveHandler.Flags + 12),
            v24->pNode);
          v25 = &v37;
        }
        else
        {
          v26 = Scaleform::GFx::XML::ObjectManager::CreateString(
                  v21,
                  &v38,
                  (char *)penv->__vftable,
                  (unsigned int)penv->Stack.Pages.Data.Data);
          Scaleform::GFx::XML::DOMString::AssignNode(
            (Scaleform::GFx::XML::DOMString *)(*(_DWORD *)&this->ResolveHandler.Flags + 12),
            v26->pNode);
          v25 = &v38;
        }
        Scaleform::GFx::XML::DOMString::~DOMString(v25);
        v27 = (Scaleform::GFx::ASStringNode *)v39;
        Scaleform::GFx::XML::DOMString::AssignNode(v39 + 9, (Scaleform::GFx::XML::DOMStringNode *)name);
        Scaleform::GFx::AS2::ResolveNamespace(
          v5,
          v27,
          (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
        v28 = (Scaleform::GFx::ASStringNode *)penv;
        --penv->Stack.pPageEnd;
        if ( !v28->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v28);
        Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&name);
        return 1;
      }
      if ( v9 )
      {
        Scaleform::GFx::LogState::LogMessageByType(
          v9,
          (Scaleform::LogMessageId)147456,
          "XMLNodeObject::SetMember - cannot set nodeName of node type %d. Only type 1 allowed",
          v17);
        return 1;
      }
    }
    else if ( v9 )
    {
      Scaleform::GFx::LogState::LogMessageByType(
        v9,
        (Scaleform::LogMessageId)147456,
        "XMLNodeObject::SetMember - cannot set nodeName of a malformed node");
    }
    return 1;
  }
  v29 = *(_DWORD *)&this->ResolveHandler.Flags;
  if ( !v29 )
  {
    if ( v9 )
    {
      Scaleform::GFx::LogState::LogMessageByType(
        v9,
        (Scaleform::LogMessageId)147456,
        "XMLNodeObject::SetMember - cannot set attributes of a malformed node");
      return 1;
    }
    return 1;
  }
  v30 = *(_BYTE *)(v29 + 32);
  if ( v30 != 1 )
  {
    if ( v9 )
    {
      Scaleform::GFx::LogState::LogMessageByType(
        v9,
        (Scaleform::LogMessageId)147456,
        "XMLNodeObject::SetMember - cannot set attributes of node type %d. Only type 1 allowed",
        v30);
      return 1;
    }
    return 1;
  }
  v31 = *(_DWORD *)(v29 + 28);
  v32 = Scaleform::GFx::AS2::Value::ToObject(val, v5);
  v33 = v32;
  if ( v32 )
    v32->RefCount = (v32->RefCount + 1) & 0x8FFFFFFF;
  v34 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v31 + 8);
  if ( v34 )
  {
    RefCount = v34->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v34->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v34);
    }
  }
  *(_DWORD *)(v31 + 8) = v33;
  return 1;
}
