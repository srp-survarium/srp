void __cdecl Scaleform::GFx::AS3::CSSStringBuilder::processSub(
        Scaleform::String *dest,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS3::Value *val)
{
  Scaleform::GFx::ASString *v3; // edi
  const __m128i *pData; // esi
  int v5; // esi
  const __m128i *v6; // eax
  const __m128i *v7; // eax
  const __m128i *v8; // eax
  Scaleform::StringBuffer buff; // [esp+0h] [ebp-30h] BYREF
  Scaleform::StringBuffer sval; // [esp+18h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&buff, Scaleform::Memory::pGlobalHeap);
  Scaleform::StringBuffer::StringBuffer(&sval, Scaleform::Memory::pGlobalHeap);
  v3 = name;
  pData = (const __m128i *)name->pNode->pData;
  if ( !strcmp(pData->m128i_i8, "fontFamily") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"font-family", 0xFFFFFFFF);
  }
  else if ( !strcmp(name->pNode->pData, "fontSize") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"font-size", 0xFFFFFFFF);
  }
  else if ( !strcmp(name->pNode->pData, "fontStyle") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"font-style", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "fontWeight") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"font-weight", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v3, "letterSpacing") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"letter-spacing", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v3, "marginLeft") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"margin-left", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v3, "marginRight") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"margin-right", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v3, "textAlign") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"text-align", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v3, "textDecoration") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"text-decoration", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v3, "textIndent") )
  {
    Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)"text-indent", 0xFFFFFFFF);
  }
  else
  {
    Scaleform::StringBuffer::AppendString(&buff, pData, 0xFFFFFFFF);
  }
  Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)":", 0xFFFFFFFF);
  Scaleform::GFx::AS3::Value::Convert2String(val, (Scaleform::GFx::AS3::CheckResult *)&name, &sval);
  v5 = 0;
  if ( sval.Size )
  {
    while ( !isspace(sval.pData[v5]) )
    {
      if ( ++v5 >= sval.Size )
        goto LABEL_25;
    }
    Scaleform::StringBuffer::AppendChar(&buff, 0x22u);
    v8 = (const __m128i *)sval.pData;
    if ( !sval.pData )
      v8 = (const __m128i *)uri;
    Scaleform::StringBuffer::AppendString(&buff, v8, sval.Size);
    Scaleform::StringBuffer::AppendChar(&buff, 0x22u);
  }
  else
  {
LABEL_25:
    v6 = (const __m128i *)sval.pData;
    if ( !sval.pData )
      v6 = (const __m128i *)uri;
    Scaleform::StringBuffer::AppendString(&buff, v6, 0xFFFFFFFF);
  }
  Scaleform::StringBuffer::AppendString(&buff, (const __m128i *)";", 0xFFFFFFFF);
  v7 = (const __m128i *)buff.pData;
  if ( !buff.pData )
    v7 = (const __m128i *)uri;
  Scaleform::String::AppendString(dest, v7, 0xFFFFFFFF);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&sval);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&buff);
}
