char __thiscall Scaleform::GFx::AS2::StringTokenizer::NextToken(Scaleform::GFx::AS2::StringTokenizer *this, char *sep)
{
  char *Str; // edi
  int v5; // eax
  const char *v6; // eax
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v9; // zf

  Str = (char *)this->Str;
  if ( this->Str >= this->EndStr )
    return 0;
  do
  {
    strchr((char *)this->Delimiters, *this->Str);
    if ( v5 )
      break;
    ++this->Str;
  }
  while ( this->Str < this->EndStr );
  *sep = *this->Str;
  v6 = this->Str;
  if ( Str == this->Str || v6 > this->EndStr )
    p_EmptyStringNode = &this->Token.pNode->pManager->EmptyStringNode;
  else
    p_EmptyStringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->Token.pNode->pManager, Str, v6 - Str);
  p_EmptyStringNode->RefCount += 2;
  pNode = this->Token.pNode;
  v9 = pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->Token.pNode = p_EmptyStringNode;
  v9 = p_EmptyStringNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
  ++this->Str;
  return 1;
}
