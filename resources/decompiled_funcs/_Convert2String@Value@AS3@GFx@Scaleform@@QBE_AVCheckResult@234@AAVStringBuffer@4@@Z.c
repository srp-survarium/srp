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
