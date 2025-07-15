Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::Convert2String(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASString *resulta)
{
  Scaleform::GFx::ASString *v3; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  unsigned int v5; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // edi
  Scaleform::GFx::ASStringNode *v8; // ecx
  bool v9; // zf
  Scaleform::GFx::AS3::CheckResult *v10; // eax
  bool VBool; // cl
  char *v12; // eax
  Scaleform::String *v13; // eax
  const Scaleform::GFx::ASString *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  const Scaleform::String *v16; // eax
  const Scaleform::GFx::ASString *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  unsigned int v19; // eax
  Scaleform::GFx::AS3::VM *v20; // esi
  const Scaleform::GFx::AS3::VM::Error *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::AS3::Value::V1U v23; // ebp
  Scaleform::GFx::ASStringNode *v24; // ecx
  Scaleform::GFx::ASStringNode *v25; // edi
  Scaleform::GFx::ASStringNode *v26; // ecx
  Scaleform::GFx::AS3::CheckResult v27; // [esp+17h] [ebp-55h] BYREF
  unsigned int VUInt; // [esp+18h] [ebp-54h] BYREF
  Scaleform::GFx::ASString v29; // [esp+1Ch] [ebp-50h] BYREF
  Scaleform::String v30; // [esp+20h] [ebp-4Ch] BYREF
  Scaleform::GFx::ASString v31; // [esp+24h] [ebp-48h] BYREF
  Scaleform::String v32; // [esp+28h] [ebp-44h] BYREF
  Scaleform::GFx::AS3::VM::Error v33; // [esp+2Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+34h] [ebp-38h] BYREF
  char buffer[40]; // [esp+44h] [ebp-28h] BYREF

  v3 = resulta;
  pManager = resulta->pNode->pManager;
  v5 = this->Flags & 0x1F;
  switch ( v5 )
  {
    case 0u:
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pManager, "undefined", 9u, 0);
      goto LABEL_3;
    case 1u:
      VBool = this->value.VS._1.VBool;
      v12 = (char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1];
      if ( !VBool )
        v12 = (char *)&stru_95AF78.m_key_bindings[6];
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pManager, v12, !VBool + 4, 0);
      goto LABEL_3;
    case 2u:
      VUInt = this->value.VS._1.VUInt;
      v13 = Scaleform::AsString<long>(&v30, (int *)&VUInt);
      v14 = Scaleform::GFx::ASStringManager::CreateString(pManager, &v29, v13);
      Scaleform::GFx::ASString::operator=(v3, v14);
      pNode = v29.pNode;
      --v29.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::String::~String(&v30);
      v10 = result;
      result->Result = 1;
      return v10;
    case 3u:
      VUInt = this->value.VS._1.VUInt;
      v16 = Scaleform::AsString<unsigned long>(&v32, &VUInt);
      v17 = Scaleform::GFx::ASStringManager::CreateString(pManager, &v31, v16);
      Scaleform::GFx::ASString::operator=(v3, v17);
      v18 = v31.pNode;
      --v31.pNode->RefCount;
      if ( !v18->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      Scaleform::String::~String(&v32);
      v10 = result;
      result->Result = 1;
      return v10;
    case 4u:
      v19 = Scaleform::GFx::AS3::SF_ECMA_dtostr((char *)pManager, buffer, 0x28u, this->value.VNumber);
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pManager, buffer, v19);
      goto LABEL_3;
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          pManager,
                          "function Function() {}",
                          0x16u,
                          0);
      goto LABEL_3;
    case 8u:
    case 9u:
      p_EmptyStringNode = &pManager->EmptyStringNode;
      goto LABEL_4;
    case 0xAu:
      v23 = this->value.VS._1;
      if ( v23.VInt )
      {
        ++*(_DWORD *)(v23.VInt + 12);
        v24 = v3->pNode;
        v9 = v3->pNode->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v24);
        v10 = result;
        v3->pNode = (Scaleform::GFx::ASStringNode *)v23;
        result->Result = 1;
      }
      else
      {
        v25 = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                pManager,
                (char *)&stru_96A440.m_projection.lines[0].elements[1],
                4u,
                0);
        ++v25->RefCount;
        v26 = v3->pNode;
        v9 = v3->pNode->RefCount-- == 1;
        if ( v9 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        v3->pNode = v25;
LABEL_38:
        v10 = result;
        result->Result = 1;
      }
      return v10;
    case 0xBu:
      Scaleform::GFx::ASString::operator=(resulta, (const Scaleform::GFx::ASString *)(this->value.VS._1.VInt + 28));
      v10 = result;
      result->Result = 1;
      return v10;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( v5 - 12 > 3 || this->value.VS._1.VInt )
      {
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
               this,
               (Scaleform::GFx::AS3::CheckResult *)&resulta,
               &v,
               hintString)->Result )
        {
          if ( !Scaleform::GFx::AS3::Value::IsPrimitive(&v) )
          {
            v20 = *(Scaleform::GFx::AS3::VM **)(*(_DWORD *)(v.value.VS._1.VInt + 20) + 64);
            Scaleform::GFx::AS3::VM::Error::Error(&v33, eConvertToPrimitiveError, v20);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              v20,
              v21,
              (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
            v22 = v33.Message.pNode;
            --v33.Message.pNode->RefCount;
            if ( !v22->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v22);
            result->Result = 0;
            Scaleform::GFx::AS3::Value::~Value(&v);
            return result;
          }
          if ( Scaleform::GFx::AS3::Value::Convert2String(&v, &v27, v3)->Result )
          {
            Scaleform::GFx::AS3::Value::~Value(&v);
            v10 = result;
            result->Result = 1;
            return v10;
          }
        }
        result->Result = 0;
        Scaleform::GFx::AS3::Value::~Value(&v);
        return result;
      }
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          pManager,
                          (char *)&stru_96A440.m_projection.lines[0].elements[1],
                          4u,
                          0);
LABEL_3:
      p_EmptyStringNode = ConstStringNode;
LABEL_4:
      ++p_EmptyStringNode->RefCount;
      v8 = v3->pNode;
      v9 = v3->pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      v10 = result;
      v3->pNode = p_EmptyStringNode;
      result->Result = 1;
      return v10;
    default:
      goto LABEL_38;
  }
}


Scaleform::GFx::AS3::CheckResult *__userpurge Scaleform::GFx::AS3::Value::Convert2String@<eax>(
        Scaleform::GFx::AS3::Value *this@<ecx>,
        char *a2@<edi>,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::StringBuffer *resulta)
{
  unsigned int v4; // eax
  char *v5; // eax
  Scaleform::String *v6; // eax
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  const Scaleform::String *v8; // eax
  Scaleform::GFx::AS3::Value::V1U v9; // ecx
  unsigned int val_4; // [esp+4h] [ebp-50h]
  Scaleform::GFx::AS3::CheckResult v11; // [esp+Eh] [ebp-46h] BYREF
  Scaleform::GFx::AS3::CheckResult v12; // [esp+Fh] [ebp-45h] BYREF
  unsigned int VUInt; // [esp+10h] [ebp-44h] BYREF
  Scaleform::String v14; // [esp+14h] [ebp-40h] BYREF
  Scaleform::String v15; // [esp+18h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+1Ch] [ebp-38h] BYREF
  char buffer[40]; // [esp+2Ch] [ebp-28h] BYREF

  v4 = this->Flags & 0x1F;
  switch ( v4 )
  {
    case 0u:
      Scaleform::StringBuffer::AppendString(resulta, "undefined", 0xFFFFFFFF);
      goto LABEL_20;
    case 1u:
      v5 = (char *)&stru_95AF78.m_key_bindings[4].m_keyboard[1];
      if ( !this->value.VS._1.VBool )
        v5 = (char *)&stru_95AF78.m_key_bindings[6];
      Scaleform::StringBuffer::AppendString(resulta, v5, 0xFFFFFFFF);
      goto LABEL_20;
    case 2u:
      VUInt = this->value.VS._1.VUInt;
      v6 = Scaleform::AsString<long>(&v14, (int *)&VUInt);
      Scaleform::StringBuffer::operator+=(resulta, v6);
      Scaleform::String::~String(&v14);
      v7 = result;
      result->Result = 1;
      return v7;
    case 3u:
      VUInt = this->value.VS._1.VUInt;
      v8 = Scaleform::AsString<unsigned long>(&v15, &VUInt);
      Scaleform::StringBuffer::operator+=(resulta, v8);
      Scaleform::String::~String(&v15);
      v7 = result;
      result->Result = 1;
      return v7;
    case 4u:
      val_4 = Scaleform::GFx::AS3::SF_ECMA_dtostr(a2, buffer, 0x28u, this->value.VNumber);
      Scaleform::StringBuffer::AppendString(resulta, buffer, val_4);
      goto LABEL_20;
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      Scaleform::StringBuffer::AppendString(resulta, "function Function() {}", 0xFFFFFFFF);
      goto LABEL_20;
    case 0xAu:
      v9 = this->value.VS._1;
      if ( !v9.VInt )
        goto LABEL_19;
      Scaleform::StringBuffer::AppendString(resulta, *(char **)v9.VInt, *(_DWORD *)(v9.VInt + 20));
      goto LABEL_20;
    case 0xBu:
      Scaleform::StringBuffer::AppendString(resulta, **(char ***)(this->value.VS._1.VInt + 28), 0xFFFFFFFF);
      goto LABEL_20;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( v4 - 12 > 3 || this->value.VS._1.VInt )
      {
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(this, &v11, &v, hintString)->Result
          && Scaleform::GFx::AS3::Value::Convert2String(&v, &v12, resulta)->Result )
        {
          Scaleform::GFx::AS3::Value::~Value(&v);
          v7 = result;
          result->Result = 1;
        }
        else
        {
          result->Result = 0;
          Scaleform::GFx::AS3::Value::~Value(&v);
          return result;
        }
      }
      else
      {
LABEL_19:
        Scaleform::StringBuffer::AppendString(
          resulta,
          (char *)&stru_96A440.m_projection.lines[0].elements[1],
          0xFFFFFFFF);
LABEL_20:
        v7 = result;
        result->Result = 1;
      }
      return v7;
    default:
      goto LABEL_20;
  }
}
