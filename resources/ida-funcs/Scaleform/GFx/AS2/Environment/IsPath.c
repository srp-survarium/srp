char __cdecl Scaleform::GFx::AS2::Environment::IsPath(const Scaleform::GFx::ASString *varPath)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  char *pData; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax

  pNode = varPath->pNode;
  if ( (varPath->pNode->HashFlags & 0x4000000) != 0 )
    return 1;
  pData = (char *)pNode->pData;
  strchr((char *)pNode->pData, 0x3Au);
  if ( v4 || (strchr(pData, 0x2Fu), v5) || (strchr(pData, 0x2Eu), v6) )
  {
    varPath->pNode->HashFlags |= 0x4000000u;
    return 1;
  }
  else
  {
    varPath->pNode->HashFlags |= 0x6000000u;
    return 0;
  }
}
