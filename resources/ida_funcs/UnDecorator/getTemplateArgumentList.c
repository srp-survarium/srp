DName *__cdecl UnDecorator::getTemplateArgumentList(DName *result)
{
  const char *v1; // eax
  char v2; // dl
  unsigned int v3; // ecx
  DName *p_arg; // eax
  const char *v5; // eax
  DName *PrimaryDataType; // eax
  int v7; // eax
  char *Parameter; // eax
  DName *v9; // eax
  DNameNode *node; // ecx
  DName *v11; // eax
  DName *v12; // [esp-Ch] [ebp-80h]
  DName v13; // [esp+8h] [ebp-6Ch] BYREF
  DName v14; // [esp+10h] [ebp-64h] BYREF
  DName v15; // [esp+18h] [ebp-5Ch] BYREF
  DName v16; // [esp+20h] [ebp-54h] BYREF
  DName v17; // [esp+28h] [ebp-4Ch] BYREF
  char v18; // [esp+30h] [ebp-44h] BYREF
  DName v19; // [esp+38h] [ebp-3Ch] BYREF
  const char *oldGName; // [esp+40h] [ebp-34h]
  DName superType; // [esp+44h] [ebp-30h] BYREF
  DName dimension; // [esp+4Ch] [ebp-28h] BYREF
  int first; // [esp+54h] [ebp-20h]
  DName arg; // [esp+58h] [ebp-1Ch] BYREF
  char buffer[16]; // [esp+60h] [ebp-14h] BYREF

  *((_BYTE *)result + 4) = 0;
  *((_DWORD *)result + 1) &= 0xFFFF00FF;
  result->node = 0;
  UnDecorator::fGetTemplateArgumentList = 1;
  first = 1;
  if ( !*((_BYTE *)result + 4) )
  {
    while ( 1 )
    {
      v1 = UnDecorator::gName;
      if ( !*UnDecorator::gName || *UnDecorator::gName == 64 )
        goto LABEL_29;
      if ( first )
      {
        first = 0;
      }
      else
      {
        DName::operator+=(result, 44);
        v1 = UnDecorator::gName;
      }
      v2 = *v1;
      v3 = *v1 - 48;
      if ( v3 > 9 )
        break;
      UnDecorator::gName = v1 + 1;
      p_arg = Replicator::operator[](UnDecorator::pTemplateArgList, &v13, v3);
LABEL_28:
      DName::operator+=(result, p_arg);
      if ( *((_BYTE *)result + 4) )
        goto LABEL_29;
    }
    *((_DWORD *)&arg + 1) &= 0xFFFF0000;
    oldGName = v1;
    arg.node = 0;
    if ( v2 == 88 )
    {
      UnDecorator::gName = v1 + 1;
      DName::operator=(&arg, "void");
    }
    else
    {
      if ( v2 != 36 || (v5 = v1 + 1, *v5 == 36) )
      {
        if ( v2 == 63 )
        {
          UnDecorator::getSignedDimension(&dimension);
          if ( (UnDecorator::disableFlags & 0x4000) != 0 )
          {
            DName::getString(&dimension, buffer, 0x10u);
            v7 = atol(buffer);
            Parameter = UnDecorator::m_pGetParameter(v7);
            if ( Parameter )
            {
              DName::operator=(&arg, Parameter);
              goto LABEL_24;
            }
            v12 = &v14;
            v9 = operator+(&v16, "`template-parameter", &dimension);
          }
          else
          {
            v12 = (DName *)&v18;
            v9 = operator+(&v17, "`template-parameter", &dimension);
          }
          PrimaryDataType = DName::operator+(v9, v12, "'");
        }
        else
        {
          *((_DWORD *)&superType + 1) &= 0xFFFF0000;
          superType.node = 0;
          PrimaryDataType = UnDecorator::getPrimaryDataType(&v15, &superType);
        }
      }
      else
      {
        UnDecorator::gName = v5;
        PrimaryDataType = UnDecorator::getTemplateConstant(&v19);
      }
      node = PrimaryDataType->node;
      *((_DWORD *)&arg + 1) = *((_DWORD *)PrimaryDataType + 1);
      arg.node = node;
    }
LABEL_24:
    if ( UnDecorator::gName - oldGName > 1 && UnDecorator::pTemplateArgList->index != 9 )
      Replicator::operator+=(UnDecorator::pTemplateArgList, &arg);
    p_arg = &arg;
    goto LABEL_28;
  }
LABEL_29:
  v11 = result;
  UnDecorator::fGetTemplateArgumentList = 0;
  return v11;
}
