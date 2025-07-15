void __cdecl Scaleform::GFx::AS3::CSSTextFormatLoader::processSub(
        Scaleform::GFx::AS3::Instances::fl_text::TextFormat *tf,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Value *val)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  const char *pData; // esi
  unsigned int Size; // edi
  unsigned int v; // eax
  long double v7; // st7
  Scaleform::GFx::AS3::Value *p_mSize; // ecx
  unsigned int v9; // eax
  const char *v10; // esi
  unsigned int v11; // eax
  unsigned int v12; // eax
  const char *v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // eax
  const char *v16; // esi
  unsigned int v17; // eax
  unsigned int v18; // eax
  const char *v19; // esi
  unsigned int v20; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+17h] [ebp-21h] BYREF
  const char *pstr; // [esp+18h] [ebp-20h]
  char *temp; // [esp+1Ch] [ebp-1Ch] BYREF
  Scaleform::StringBuffer buff; // [esp+20h] [ebp-18h] BYREF
  float num; // [esp+40h] [ebp+8h]

  Scaleform::StringBuffer::StringBuffer(&buff, Scaleform::Memory::pGlobalHeap);
  Scaleform::GFx::AS3::Value::Convert2String(val, &result, &buff);
  pstr = buff.pData;
  if ( !buff.pData )
    pstr = uri;
  pNode = name->pNode;
  temp = 0;
  pData = pNode->pData;
  Size = buff.Size;
  if ( !strcmp(pNode->pData, "color") )
  {
    v = strtol((int)name, pstr + 1, (const char **)&temp, 16);
    Scaleform::GFx::AS3::Value::SetUInt32(&tf->mColor, v);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
    return;
  }
  if ( !strcmp(pData, "display") )
    goto LABEL_59;
  if ( !strcmp(pData, "fontFamily") )
  {
    Scaleform::GFx::AS3::Value::Assign(&tf->mFont, val);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
    return;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "fontSize") )
  {
    v7 = Scaleform::SFstrtod(Size, (char *)pstr, &temp);
    p_mSize = &tf->mSize;
LABEL_58:
    num = v7;
    Scaleform::GFx::AS3::Value::SetNumber(p_mSize, num);
    goto LABEL_59;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "fontStyle") )
  {
    v9 = Size;
    if ( Size >= 4 )
      v9 = 4;
    v10 = pstr;
    if ( !strncmp("normal", pstr, v9) )
    {
      Scaleform::GFx::AS3::Value::SetBool(&tf->mItalic, 0);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
      return;
    }
    v11 = Size;
    if ( Size >= 9 )
      v11 = 9;
    if ( !strncmp("italic", v10, v11) )
    {
      Scaleform::GFx::AS3::Value::SetBool(&tf->mItalic, 1);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
      return;
    }
    goto LABEL_59;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "fontWeight") )
  {
    v12 = Size;
    if ( Size >= 6 )
      v12 = 6;
    v13 = pstr;
    if ( !strncmp("normal", pstr, v12) )
    {
      Scaleform::GFx::AS3::Value::SetBool(&tf->mBold, 0);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
      return;
    }
    v14 = Size;
    if ( Size >= 4 )
      v14 = 4;
    if ( !strncmp("bold", v13, v14) )
    {
      Scaleform::GFx::AS3::Value::SetBool(&tf->mBold, 1);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
      return;
    }
    goto LABEL_59;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "kerning") )
  {
    v15 = Size;
    if ( Size >= 5 )
      v15 = 5;
    v16 = pstr;
    if ( !strncmp("false", pstr, v15) )
    {
      Scaleform::GFx::AS3::Value::SetBool(&tf->mKerning, 0);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
      return;
    }
    v17 = Size;
    if ( Size >= 4 )
      v17 = 4;
    if ( !strncmp("true", v16, v17) )
    {
      Scaleform::GFx::AS3::Value::SetBool(&tf->mKerning, 1);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
      return;
    }
    goto LABEL_59;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "leading") )
  {
    v7 = Scaleform::SFstrtod(Size, (char *)pstr, &temp);
    p_mSize = &tf->mLeading;
    goto LABEL_58;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "letterSpacing") )
  {
    v7 = Scaleform::SFstrtod(Size, (char *)pstr, &temp);
    p_mSize = &tf->mLetterSpacing;
    goto LABEL_58;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "marginLeft") )
  {
    v7 = Scaleform::SFstrtod(Size, (char *)pstr, &temp);
    p_mSize = &tf->mLeftMargin;
    goto LABEL_58;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "marginRight") )
  {
    v7 = Scaleform::SFstrtod(Size, (char *)pstr, &temp);
    p_mSize = &tf->mRightMargin;
    goto LABEL_58;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "textAlign") )
  {
    Scaleform::GFx::AS3::Value::operator=(&tf->mAlign, val);
    Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
    return;
  }
  if ( Scaleform::GFx::ASString::operator==(name, "textDecoration") )
  {
    v18 = Size;
    if ( Size >= 4 )
      v18 = 4;
    v19 = pstr;
    if ( !strncmp("none", pstr, v18) )
    {
      Scaleform::GFx::AS3::Value::SetBool(&tf->mUnderline, 0);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
      return;
    }
    v20 = Size;
    if ( Size >= 9 )
      v20 = 9;
    if ( !strncmp("underline", v19, v20) )
    {
      Scaleform::GFx::AS3::Value::SetBool(&tf->mUnderline, 1);
      Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
      return;
    }
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "textIndent") )
  {
    v7 = Scaleform::SFstrtod(Size, (char *)pstr, &temp);
    p_mSize = &tf->mIndent;
    goto LABEL_58;
  }
LABEL_59:
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
}
