DName *__cdecl UnDecorator::getTemplateArgumentList(DName *result)
{
  const char *v1; // eax
  char v2; // dl
  unsigned int v3; // ecx
  DName *p_rd; // eax
  const char *v5; // eax
  DName *PrimaryDataType; // eax
  unsigned int v7; // eax
  char *Parameter; // eax
  DName *v9; // eax
  DNameNode *node; // ecx
  DName *v11; // eax
  DName *v12; // [esp-Ch] [ebp-80h]
  DName resulta; // [esp+8h] [ebp-6Ch] BYREF
  char v14; // [esp+10h] [ebp-64h] BYREF
  DName v15; // [esp+18h] [ebp-5Ch] BYREF
  DName v16; // [esp+20h] [ebp-54h] BYREF
  DName v17; // [esp+28h] [ebp-4Ch] BYREF
  char v18; // [esp+30h] [ebp-44h] BYREF
  DName v19; // [esp+38h] [ebp-3Ch] BYREF
  const char *v20; // [esp+40h] [ebp-34h]
  DName superType; // [esp+44h] [ebp-30h] BYREF
  DName v22; // [esp+4Ch] [ebp-28h] BYREF
  int v23; // [esp+54h] [ebp-20h]
  DName rd; // [esp+58h] [ebp-1Ch] BYREF
  char v25[16]; // [esp+60h] [ebp-14h] BYREF

  *((_BYTE *)result + 4) = 0;
  *((_DWORD *)result + 1) &= 0xFFFF00FF;
  result->node = 0;
  UnDecorator::fGetTemplateArgumentList = 1;
  v23 = 1;
  if ( !*((_BYTE *)result + 4) )
  {
    while ( 1 )
    {
      v1 = UnDecorator::gName;
      if ( !*UnDecorator::gName || *UnDecorator::gName == 64 )
        goto LABEL_29;
      if ( v23 )
      {
        v23 = 0;
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
      p_rd = Replicator::operator[](UnDecorator::pTemplateArgList, &resulta, v3);
LABEL_28:
      DName::operator+=(result, p_rd);
      if ( *((_BYTE *)result + 4) )
        goto LABEL_29;
    }
    *((_DWORD *)&rd + 1) &= 0xFFFF0000;
    v20 = v1;
    rd.node = 0;
    if ( v2 == 88 )
    {
      UnDecorator::gName = v1 + 1;
      DName::operator=(&rd, "void");
    }
    else
    {
      if ( v2 != 36 || (v5 = v1 + 1, *v5 == 36) )
      {
        if ( v2 == 63 )
        {
          UnDecorator::getSignedDimension(&v22);
          if ( (UnDecorator::disableFlags & 0x4000) != 0 )
          {
            DName::getString(&v22, v25, 0x10u);
            v7 = atol(0, v25);
            Parameter = UnDecorator::m_pGetParameter(v7);
            if ( Parameter )
            {
              DName::operator=(&rd, Parameter);
              goto LABEL_24;
            }
            v12 = (DName *)&v14;
            v9 = operator+(&v16, "`template-parameter", &v22);
          }
          else
          {
            v12 = (DName *)&v18;
            v9 = operator+(&v17, "`template-parameter", &v22);
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
      *((_DWORD *)&rd + 1) = *((_DWORD *)PrimaryDataType + 1);
      rd.node = node;
    }
LABEL_24:
    if ( UnDecorator::gName - v20 > 1 && UnDecorator::pTemplateArgList->index != 9 )
      Replicator::operator+=(UnDecorator::pTemplateArgList, &rd);
    p_rd = &rd;
    goto LABEL_28;
  }
LABEL_29:
  v11 = result;
  UnDecorator::fGetTemplateArgumentList = 0;
  return v11;
}
