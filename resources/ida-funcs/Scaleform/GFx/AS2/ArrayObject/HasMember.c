char __userpurge Scaleform::GFx::AS2::ArrayObject::HasMember@<al>(
        Scaleform::GFx::AS2::ArrayObject *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        bool inclPrototypes)
{
  const char *pData; // ecx
  char v7; // al
  signed int v8; // eax
  int v9; // ecx
  bool v10; // zf
  char **v11; // eax
  char v12; // cl
  char result; // al

  pData = name->pNode->pData;
  v7 = *pData;
  if ( *pData )
  {
    while ( v7 >= 48 && v7 <= 57 )
    {
      v7 = *++pData;
      if ( !v7 )
        goto LABEL_7;
    }
    if ( *pData )
      return Scaleform::GFx::AS2::Object::HasMember(this, psc, name, inclPrototypes);
  }
LABEL_7:
  v8 = atoi(a2, (char *)name->pNode->pData);
  if ( v8 < 0 )
    return Scaleform::GFx::AS2::Object::HasMember(this, psc, name, inclPrototypes);
  result = 0;
  if ( v8 < (int)this->pWatchpoints )
  {
    v9 = *(_DWORD *)&this->ResolveHandler.Flags;
    v10 = *(_DWORD *)(v9 + 4 * v8) == 0;
    v11 = (char **)(v9 + 4 * v8);
    if ( !v10 )
    {
      v12 = **v11;
      if ( v12 )
      {
        if ( v12 != 10 && v12 != 1 )
          return 1;
      }
    }
  }
  return result;
}
