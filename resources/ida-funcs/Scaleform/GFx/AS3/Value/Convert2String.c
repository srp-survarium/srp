Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::Convert2String(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::GFx::ASString *resulta)
{
  Scaleform::GFx::ASString *v3; // esi
  Scaleform::GFx::ASStringManager *pManager; // edi
  unsigned int v5; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  bool VBool; // cl
  char *v8; // eax
  Scaleform::String *v9; // eax
  const Scaleform::GFx::ASString *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::CheckResult *v12; // eax
  Scaleform::String *v13; // eax
  const Scaleform::GFx::ASString *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  unsigned int v16; // eax
  Scaleform::GFx::AS3::VM *v17; // esi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const char ***v19; // eax
  const Scaleform::GFx::AS3::VM::Error *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // edi
  Scaleform::GFx::AS3::Value::V1U v24; // ebp
  Scaleform::GFx::ASStringNode *v25; // ecx
  bool v26; // zf
  Scaleform::GFx::ASStringNode *v27; // ecx
  Scaleform::StringDataPtr val; // [esp+0h] [ebp-74h] BYREF
  Scaleform::GFx::AS3::CheckResult v29; // [esp+1Bh] [ebp-59h] BYREF
  unsigned int VUInt; // [esp+1Ch] [ebp-58h] BYREF
  Scaleform::GFx::ASString v31; // [esp+20h] [ebp-54h] BYREF
  Scaleform::String v32; // [esp+24h] [ebp-50h] BYREF
  Scaleform::GFx::ASString v33; // [esp+28h] [ebp-4Ch] BYREF
  Scaleform::String v34; // [esp+2Ch] [ebp-48h] BYREF
  Scaleform::GFx::ASStringNode *v35; // [esp+30h] [ebp-44h] BYREF
  Scaleform::GFx::AS3::VM::Error v36; // [esp+34h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+3Ch] [ebp-38h] BYREF
  char buffer[40]; // [esp+4Ch] [ebp-28h] BYREF

  v3 = resulta;
  pManager = resulta->pNode->pManager;
  v5 = this->Flags & 0x1F;
  switch ( v5 )
  {
    case 0u:
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pManager, "undefined", 9u, 0);
      goto LABEL_33;
    case 1u:
      VBool = this->value.VS._1.VBool;
      v8 = "true";
      if ( !VBool )
        v8 = "false";
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pManager, v8, !VBool + 4, 0);
      goto LABEL_33;
    case 2u:
      VUInt = this->value.VS._1.VUInt;
      v9 = Scaleform::AsString<long>(&v32, (int *)&VUInt);
      v10 = Scaleform::GFx::ASStringManager::CreateString(pManager, &v31, v9);
      Scaleform::GFx::ASString::operator=(v3, v10);
      pNode = v31.pNode;
      --v31.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::String::~String(&v32);
      v12 = result;
      result->Result = 1;
      return v12;
    case 3u:
      VUInt = this->value.VS._1.VUInt;
      v13 = Scaleform::AsString<unsigned long>(&v34, &VUInt);
      v14 = Scaleform::GFx::ASStringManager::CreateString(pManager, &v33, v13);
      Scaleform::GFx::ASString::operator=(v3, v14);
      v15 = v33.pNode;
      --v33.pNode->RefCount;
      if ( !v15->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      Scaleform::String::~String(&v34);
      v12 = result;
      result->Result = 1;
      return v12;
    case 4u:
      v16 = Scaleform::GFx::AS3::SF_ECMA_dtostr((char *)pManager, buffer, 0x28u, this->value.VNumber);
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pManager, (__m128i *)buffer, v16);
      goto LABEL_33;
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          pManager,
                          "function Function() {}",
                          0x16u,
                          0);
      goto LABEL_33;
    case 8u:
    case 9u:
      p_EmptyStringNode = &pManager->EmptyStringNode;
      goto LABEL_34;
    case 0xAu:
      v24 = this->value.VS._1;
      if ( !v24.VInt )
        goto LABEL_32;
      ++*(_DWORD *)(v24.VInt + 12);
      v25 = v3->pNode;
      v26 = v3->pNode->RefCount-- == 1;
      if ( v26 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v25);
      v12 = result;
      v3->pNode = (Scaleform::GFx::ASStringNode *)v24;
      result->Result = 1;
      return v12;
    case 0xBu:
      Scaleform::GFx::ASString::operator=(resulta, (const Scaleform::GFx::ASString *)(this->value.VS._1.VInt + 28));
      v12 = result;
      result->Result = 1;
      return v12;
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
      if ( v5 - 12 > 3 || this->value.VS._1.VInt )
      {
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        if ( !Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(
                this,
                (Scaleform::GFx::AS3::CheckResult *)&resulta,
                &v,
                hintString)->Result )
        {
LABEL_18:
          result->Result = 0;
          Scaleform::GFx::AS3::Value::~Value(&v);
          return result;
        }
        if ( Scaleform::GFx::AS3::Value::IsPrimitive(&v) )
        {
          if ( !Scaleform::GFx::AS3::Value::Convert2String(&v, &v29, v3)->Result )
            goto LABEL_18;
          Scaleform::GFx::AS3::Value::~Value(&v);
          v12 = result;
          result->Result = 1;
        }
        else
        {
          v17 = *(Scaleform::GFx::AS3::VM **)(*(_DWORD *)(v.value.VS._1.VInt + 20) + 64);
          ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(v17, &v);
          v19 = (const char ***)ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&v35);
          Scaleform::StringDataPtr::StringDataPtr(&val, **v19);
          Scaleform::GFx::AS3::VM::Error::Error(&v36, eConvertToPrimitiveError, (Scaleform::String)v17, val);
          Scaleform::GFx::AS3::VM::ThrowErrorInternal(
            v17,
            v20,
            (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
          v21 = v36.Message.pNode;
          --v36.Message.pNode->RefCount;
          if ( !v21->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v21);
          v22 = v35;
          --v35->RefCount;
          if ( !v22->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v22);
          result->Result = 0;
          Scaleform::GFx::AS3::Value::~Value(&v);
          return result;
        }
      }
      else
      {
LABEL_32:
        ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pManager, "null", 4u, 0);
LABEL_33:
        p_EmptyStringNode = ConstStringNode;
LABEL_34:
        ++p_EmptyStringNode->RefCount;
        v27 = v3->pNode;
        v26 = v3->pNode->RefCount-- == 1;
        if ( v26 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v27);
        v3->pNode = p_EmptyStringNode;
LABEL_37:
        v12 = result;
        result->Result = 1;
      }
      return v12;
    default:
      goto LABEL_37;
  }
}


Scaleform::GFx::AS3::CheckResult *__userpurge Scaleform::GFx::AS3::Value::Convert2String@<eax>(
        Scaleform::GFx::AS3::Value *this@<ecx>,
        char *a2@<edi>,
        Scaleform::GFx::AS3::CheckResult *result,
        Scaleform::StringBuffer *resulta)
{
  unsigned int v4; // eax
  const __m128i *v5; // eax
  Scaleform::String *v6; // eax
  Scaleform::GFx::AS3::CheckResult *v7; // eax
  Scaleform::String *v8; // eax
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
      Scaleform::StringBuffer::AppendString(resulta, (const __m128i *)"undefined", 0xFFFFFFFF);
      goto LABEL_20;
    case 1u:
      v5 = (const __m128i *)"true";
      if ( !this->value.VS._1.VBool )
        v5 = (const __m128i *)"false";
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
      Scaleform::StringBuffer::AppendString(resulta, (const __m128i *)buffer, val_4);
      goto LABEL_20;
    case 5u:
    case 7u:
    case 0x10u:
    case 0x11u:
      Scaleform::StringBuffer::AppendString(resulta, (const __m128i *)"function Function() {}", 0xFFFFFFFF);
      goto LABEL_20;
    case 0xAu:
      v9 = this->value.VS._1;
      if ( !v9.VInt )
        goto LABEL_19;
      Scaleform::StringBuffer::AppendString(resulta, *(const __m128i **)v9.VInt, *(_DWORD *)(v9.VInt + 20));
      goto LABEL_20;
    case 0xBu:
      Scaleform::StringBuffer::AppendString(resulta, **(const __m128i ***)(this->value.VS._1.VInt + 28), 0xFFFFFFFF);
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
        Scaleform::StringBuffer::AppendString(resulta, (const __m128i *)"null", 0xFFFFFFFF);
LABEL_20:
        v7 = result;
        result->Result = 1;
      }
      return v7;
    default:
      goto LABEL_20;
  }
}
