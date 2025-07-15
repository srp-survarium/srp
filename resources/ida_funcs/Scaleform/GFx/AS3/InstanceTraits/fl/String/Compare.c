int __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::Compare(
        Scaleform::GFx::ASString *l,
        Scaleform::GFx::ASString *r)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int v3; // edi
  unsigned int Char_Advance0; // eax
  unsigned int v6; // esi
  unsigned int v7; // eax

  pNode = r->pNode;
  v3 = 0;
  if ( l->pNode == r->pNode )
    return 0;
  l = (Scaleform::GFx::ASString *)l->pNode->pData;
  r = (Scaleform::GFx::ASString *)pNode->pData;
  Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&l);
  if ( !Char_Advance0 )
    l = (Scaleform::GFx::ASString *)((char *)l - 1);
  while ( 1 )
  {
    v6 = Char_Advance0;
    v7 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&r);
    if ( !v7 )
      r = (Scaleform::GFx::ASString *)((char *)r - 1);
    if ( !v6 || !v7 )
      break;
    v3 = v7 - v6;
    if ( v7 != v6 )
      return v3;
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&l);
    if ( !Char_Advance0 )
      l = (Scaleform::GFx::ASString *)((char *)l - 1);
  }
  if ( v6 != v7 )
    return 2 * (v7 != 0) - 1;
  return v3;
}
