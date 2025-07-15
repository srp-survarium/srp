int __cdecl Scaleform::GFx::AS2::ArrayObject::ParseIndex(const Scaleform::GFx::ASString *name)
{
  const char *pData; // ecx
  char v2; // al

  pData = name->pNode->pData;
  v2 = *pData;
  if ( !*pData )
    return atoi(name->pNode->pData);
  while ( v2 >= 48 && v2 <= 57 )
  {
    v2 = *++pData;
    if ( !v2 )
      return atoi(name->pNode->pData);
  }
  if ( *pData )
    return -1;
  else
    return atoi(name->pNode->pData);
}
