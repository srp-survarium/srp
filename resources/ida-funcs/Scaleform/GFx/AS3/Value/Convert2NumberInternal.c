Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Value::Convert2NumberInternal(
        Scaleform::GFx::AS3::Value *this,
        Scaleform::GFx::AS3::CheckResult *result,
        long double *resulta,
        Scaleform::GFx::AS3::Value::KindType kind)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ecx
  unsigned int v5; // esi
  char *v6; // edi
  double v7; // st7
  Scaleform::GFx::AS3::CheckResult *v8; // eax
  int v9; // eax
  const char *ByteIndex; // ebx
  int v11; // eax
  const char *v12; // edi
  double v13; // st7
  const char *v14; // [esp+0h] [ebp-48h]
  const char *v15; // [esp+0h] [ebp-48h]
  int v16; // [esp+4h] [ebp-44h]
  int v17; // [esp+4h] [ebp-44h]
  Scaleform::GFx::AS3::CheckResult v18; // [esp+2Fh] [ebp-19h] BYREF
  unsigned int offset; // [esp+30h] [ebp-18h] BYREF
  Scaleform::String str; // [esp+34h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+38h] [ebp-10h] BYREF

  if ( kind == kString )
  {
    v4 = this->value.VS._1;
    if ( v4.VInt )
    {
      v5 = *(_DWORD *)(v4.VInt + 20);
      if ( !v5 )
      {
LABEL_7:
        v7 = Scaleform::GFx::NumberUtil::POSITIVE_ZERO();
        v8 = result;
        *resulta = v7;
        result->Result = 1;
        return v8;
      }
      v6 = *(char **)v4.VInt;
      *(double *)&v.Flags = Scaleform::GFx::NumberUtil::StringToDouble((char *)*(_DWORD *)v4.VInt, v5, &offset);
      if ( Scaleform::GFx::NumberUtil::IsNaN(*(long double *)&v.Flags) || 0.0 == *(double *)&v.Flags )
      {
        if ( offset == v5 )
          goto LABEL_7;
        if ( 0.0 == *(double *)&v.Flags )
        {
          Scaleform::String::String(&str, &v6[offset]);
          v16 = v5 - offset;
          v14 = &v6[offset];
          v9 = Scaleform::GFx::ASUtils::SkipWhiteSpace(&str);
          ByteIndex = Scaleform::UTF8Util::GetByteIndex(v9, v14, v16);
          Scaleform::String::~String(&str);
          if ( (unsigned int)&ByteIndex[offset] >= v5 )
            goto LABEL_10;
        }
        *(double *)&v.Flags = Scaleform::GFx::NumberUtil::StringToInt(v6, v5, 0, &offset);
      }
      Scaleform::String::String(&str, &v6[offset]);
      v17 = v5 - offset;
      v15 = &v6[offset];
      v11 = Scaleform::GFx::ASUtils::SkipWhiteSpace(&str);
      v12 = Scaleform::UTF8Util::GetByteIndex(v11, v15, v17);
      Scaleform::String::~String(&str);
      if ( (unsigned int)&v12[offset] >= v5 )
      {
LABEL_10:
        v8 = result;
        *resulta = *(double *)&v.Flags;
        result->Result = 1;
        return v8;
      }
      *resulta = Scaleform::GFx::NumberUtil::NaN();
      v8 = result;
      result->Result = 1;
    }
    else
    {
      v13 = Scaleform::GFx::NumberUtil::POSITIVE_ZERO();
      v8 = result;
      *resulta = v13;
      result->Result = 1;
    }
  }
  else if ( (this->Flags & 0x1F) - 12 > 3 || this->value.VS._1.VInt )
  {
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    if ( Scaleform::GFx::AS3::Value::Convert2PrimitiveValueUnsafe(this, &v18, &v, hintNumber)->Result
      && (Scaleform::GFx::AS3::Value::Convert2NumberInline(&v, &v18, resulta), v18.Result) )
    {
      Scaleform::GFx::AS3::Value::~Value(&v);
      v8 = result;
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
    *resulta = Scaleform::GFx::NumberUtil::POSITIVE_ZERO();
    v8 = result;
    result->Result = 1;
  }
  return v8;
}
