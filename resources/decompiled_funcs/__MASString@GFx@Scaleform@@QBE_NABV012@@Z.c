bool __thiscall Scaleform::GFx::ASString::operator<(
        Scaleform::GFx::ASString *this,
        const Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v3; // ecx
  int v4; // eax
  unsigned int Size; // ebx
  unsigned int v6; // edi
  unsigned int v7; // esi
  const char *pData; // ecx
  const char *v9; // edx
  int v10; // eax

  pNode = this->pNode;
  v3 = str->pNode;
  if ( pNode == str->pNode )
  {
    LOBYTE(v4) = 0;
    return v4;
  }
  Size = pNode->Size;
  v6 = v3->Size;
  v7 = Size;
  if ( Size >= v6 )
    v7 = v3->Size;
  pData = v3->pData;
  v9 = pNode->pData;
  if ( v7 < 4 )
  {
LABEL_8:
    if ( !v7 )
      goto LABEL_17;
  }
  else
  {
    while ( *(_DWORD *)v9 == *(_DWORD *)pData )
    {
      v7 -= 4;
      pData += 4;
      v9 += 4;
      if ( v7 < 4 )
        goto LABEL_8;
    }
  }
  v10 = *(unsigned __int8 *)v9 - *(unsigned __int8 *)pData;
  if ( v10 )
    goto LABEL_16;
  if ( v7 <= 1 )
    goto LABEL_17;
  v10 = *((unsigned __int8 *)v9 + 1) - *((unsigned __int8 *)pData + 1);
  if ( v10 )
    goto LABEL_16;
  if ( v7 <= 2 )
    goto LABEL_17;
  v10 = *((unsigned __int8 *)v9 + 2) - *((unsigned __int8 *)pData + 2);
  if ( v10 )
  {
LABEL_16:
    v4 = (v10 >> 31) | 1;
    goto LABEL_18;
  }
  if ( v7 > 3 )
  {
    v10 = *((unsigned __int8 *)v9 + 3) - *((unsigned __int8 *)pData + 3);
    goto LABEL_16;
  }
LABEL_17:
  v4 = 0;
LABEL_18:
  if ( v4 )
    LOBYTE(v4) = v4 < 0;
  else
    return Size < v6;
  return v4;
}
