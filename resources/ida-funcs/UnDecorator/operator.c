char *__thiscall UnDecorator::operator char *(UnDecorator *this)
{
  int v1; // eax
  DNameNode *node; // ecx
  unsigned int v3; // eax
  char v4; // al
  const DName *DecoratedName; // eax
  DName *v6; // eax
  DName *TemplateName; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // edx
  char v11; // cl
  DName v12; // [esp+0h] [ebp-18h] BYREF
  DName result; // [esp+8h] [ebp-10h] BYREF
  DName v14; // [esp+10h] [ebp-8h] BYREF

  v1 = *((_DWORD *)&v14 + 1);
  *((_DWORD *)&v14 + 1) &= 0xFFFF0000;
  node = 0;
  v14.node = 0;
  v3 = v1 & 0xFFFF0000;
  if ( UnDecorator::name )
  {
    if ( *UnDecorator::name == 63 )
    {
      v4 = UnDecorator::name[1];
      if ( v4 == 64 )
      {
        UnDecorator::gName += 2;
        DecoratedName = UnDecorator::getDecoratedName(&result);
        v6 = operator+(&v12, "CV: ", DecoratedName);
LABEL_9:
        node = v6->node;
        v3 = *((_DWORD *)v6 + 1);
        goto LABEL_10;
      }
      if ( v4 == 36 )
      {
        TemplateName = UnDecorator::getTemplateName(&v12, 0);
        node = TemplateName->node;
        v3 = *((_DWORD *)TemplateName + 1);
        if ( (_BYTE)v3 != 2 )
          goto LABEL_10;
        UnDecorator::gName = UnDecorator::name;
      }
    }
    v6 = UnDecorator::getDecoratedName(&v12);
    goto LABEL_9;
  }
LABEL_10:
  if ( (_BYTE)v3 == 3 )
    return 0;
  if ( (_BYTE)v3 == 2 || (UnDecorator::disableFlags & 0x1000) == 0 && *UnDecorator::gName )
  {
    DName::operator=(&v14, (char *)UnDecorator::name);
  }
  else
  {
    v14.node = node;
    *((_DWORD *)&v14 + 1) = v3;
  }
  v8 = UnDecorator::outputString;
  if ( UnDecorator::outputString )
    goto LABEL_21;
  if ( v14.node )
    v8 = (char *)v14.node->length(v14.node);
  UnDecorator::maxStringLength = (int)(v8 + 1);
  v8 = (char *)heap.pOpNew((unsigned int)(v8 + 8) & 0xFFFFFFF8);
  UnDecorator::outputString = v8;
  if ( v8 )
  {
LABEL_21:
    DName::getString(&v14, v8, UnDecorator::maxStringLength);
    v9 = UnDecorator::outputString;
    v10 = UnDecorator::outputString;
    while ( 1 )
    {
      v11 = *v9;
      if ( !*v9 )
        break;
      if ( v11 == 32 )
      {
        ++v9;
        *v10++ = 32;
        while ( *v9 == 32 )
          ++v9;
      }
      else
      {
        *v10++ = v11;
        ++v9;
      }
    }
    *v10 = 0;
    return UnDecorator::outputString;
  }
  return v8;
}
