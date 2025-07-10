char __thiscall Scaleform::GFx::AS2::ArrayObject::HasMember(
        Scaleform::GFx::AS2::ArrayObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::ASString *name,
        bool inclPrototypes)
{
  const char *pData; // ecx
  char v6; // al
  int v7; // eax
  int v8; // ecx
  bool v9; // zf
  char **v10; // eax
  char v11; // cl
  char result; // al

  pData = name->pNode->pData;
  v6 = *pData;
  if ( *pData )
  {
    while ( v6 >= 48 && v6 <= 57 )
    {
      v6 = *++pData;
      if ( !v6 )
        goto LABEL_7;
    }
    if ( *pData )
      return Scaleform::GFx::AS2::Object::HasMember(this, psc, name, inclPrototypes);
  }
LABEL_7:
  v7 = atoi(name->pNode->pData);
  if ( v7 < 0 )
    return Scaleform::GFx::AS2::Object::HasMember(this, psc, name, inclPrototypes);
  result = 0;
  if ( v7 < (int)this->pWatchpoints )
  {
    v8 = *(_DWORD *)&this->ResolveHandler.Flags;
    v9 = *(_DWORD *)(v8 + 4 * v7) == 0;
    v10 = (char **)(v8 + 4 * v7);
    if ( !v9 )
    {
      v11 = **v10;
      if ( v11 )
      {
        if ( v11 != 10 && v11 != 1 )
          return 1;
      }
    }
  }
  return result;
}
