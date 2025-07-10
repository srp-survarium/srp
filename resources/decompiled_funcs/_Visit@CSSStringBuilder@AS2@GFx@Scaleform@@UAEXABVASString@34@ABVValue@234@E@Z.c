void __thiscall Scaleform::GFx::AS2::CSSStringBuilder::Visit(
        Scaleform::GFx::AS2::CSSStringBuilder *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        unsigned __int8 flags)
{
  Scaleform::GFx::ASString *v4; // ebx
  char *pData; // esi
  Scaleform::GFx::ASStringNode *v7; // esi

  v4 = name;
  pData = (char *)name->pNode->pData;
  if ( !strcmp(pData, "fontFamily") )
  {
    Scaleform::String::AppendString(this->Dest, "font-family", 0xFFFFFFFF);
  }
  else if ( !strcmp(name->pNode->pData, "fontSize") )
  {
    Scaleform::String::AppendString(this->Dest, "font-size", 0xFFFFFFFF);
  }
  else if ( !strcmp(name->pNode->pData, "fontStyle") )
  {
    Scaleform::String::AppendString(this->Dest, "font-style", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(name, "fontWeight") )
  {
    Scaleform::String::AppendString(this->Dest, "font-weight", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "letterSpacing") )
  {
    Scaleform::String::AppendString(this->Dest, "letter-spacing", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "marginLeft") )
  {
    Scaleform::String::AppendString(this->Dest, "margin-left", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "marginRight") )
  {
    Scaleform::String::AppendString(this->Dest, "margin-right", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "textAlign") )
  {
    Scaleform::String::AppendString(this->Dest, "text-align", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "textDecoration") )
  {
    Scaleform::String::AppendString(this->Dest, "text-decoration", 0xFFFFFFFF);
  }
  else if ( Scaleform::GFx::ASString::operator==(v4, "textIndent") )
  {
    Scaleform::String::AppendString(this->Dest, "text-indent", 0xFFFFFFFF);
  }
  else
  {
    Scaleform::String::AppendString(this->Dest, pData, 0xFFFFFFFF);
  }
  Scaleform::String::AppendString(this->Dest, (char *)&stru_95963C.m_max_end, 0xFFFFFFFF);
  Scaleform::GFx::AS2::Value::ToStringImpl(val, (Scaleform::GFx::ASString *)&name, this->pEnv, -1, 0);
  v7 = (Scaleform::GFx::ASStringNode *)name;
  Scaleform::String::AppendString(this->Dest, (char *)name->pNode, 0xFFFFFFFF);
  if ( v7->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  Scaleform::String::AppendString(this->Dest, ";", 0xFFFFFFFF);
}
