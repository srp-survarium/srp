void __thiscall Scaleform::GFx::AS2::CSSStringBuilder::Visit(
        Scaleform::GFx::AS2::CSSStringBuilder *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::ASString *v4; // ebx
  const __m128i *pData; // esi
  Scaleform::GFx::ASStringNode *v7; // esi

  v4 = name;
  pData = (const __m128i *)name->pNode->pData;
  if ( !strcmp(pData->m128i_i8, "fontFamily") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"font-family", 0xFFFFFFFF);
  }
  else if ( !strcmp(name->pNode->pData, "fontSize") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"font-size", 0xFFFFFFFF);
  }
  else if ( !strcmp(name->pNode->pData, "fontStyle") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"font-style", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "fontWeight") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"font-weight", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "letterSpacing") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"letter-spacing", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "marginLeft") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"margin-left", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "marginRight") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"margin-right", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "textAlign") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"text-align", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "textDecoration") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"text-decoration", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "textIndent") )
  {
    Scaleform::String::AppendString(this->Dest, (const __m128i *)"text-indent", 0xFFFFFFFF);
  }
  else
  {
    Scaleform::String::AppendString(this->Dest, pData, 0xFFFFFFFF);
  }
  Scaleform::String::AppendString(this->Dest, (const __m128i *)":", 0xFFFFFFFF);
  Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&name, this->pEnv, -1, 0);
  v7 = (Scaleform::GFx::ASStringNode *)name;
  Scaleform::String::AppendString(this->Dest, (const __m128i *)name->pNode, 0xFFFFFFFF);
  if ( v7->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  Scaleform::String::AppendString(this->Dest, (const __m128i *)";", 0xFFFFFFFF);
}
