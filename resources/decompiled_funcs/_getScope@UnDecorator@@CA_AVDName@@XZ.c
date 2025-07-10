DName *__cdecl UnDecorator::getScope(DName *result)
{
  DName *v2; // eax
  const DName *v3; // eax
  const char *v4; // ecx
  DName *ZName; // eax
  DName *v6; // eax
  DName *v7; // eax
  const DName *v8; // eax
  DName *OperatorName; // eax
  const DName *v10; // eax
  const DName *DecoratedName; // eax
  DName *v12; // eax
  DName *v13; // eax
  DName *v14; // eax
  const DName *v15; // eax
  DName *v16; // eax
  DName *v17; // eax
  const DName *v18; // eax
  DName *v20; // [esp-8h] [ebp-ACh]
  const DName *v21; // [esp-4h] [ebp-A8h]
  DName v22; // [esp+Ch] [ebp-98h] BYREF
  DName resulta; // [esp+14h] [ebp-90h] BYREF
  char v24; // [esp+1Ch] [ebp-88h] BYREF
  DName v25; // [esp+24h] [ebp-80h] BYREF
  DName v26; // [esp+2Ch] [ebp-78h] BYREF
  DName v27; // [esp+34h] [ebp-70h] BYREF
  char v28; // [esp+3Ch] [ebp-68h] BYREF
  char v29; // [esp+44h] [ebp-60h] BYREF
  DName v30; // [esp+4Ch] [ebp-58h] BYREF
  DName v31; // [esp+54h] [ebp-50h] BYREF
  DName v32; // [esp+5Ch] [ebp-48h] BYREF
  DName v33; // [esp+64h] [ebp-40h] BYREF
  DName v34; // [esp+6Ch] [ebp-38h] BYREF
  DName v35; // [esp+74h] [ebp-30h] BYREF
  DName v36; // [esp+7Ch] [ebp-28h] BYREF
  DName v37; // [esp+84h] [ebp-20h] BYREF
  DName v38; // [esp+8Ch] [ebp-18h] BYREF
  DName v39; // [esp+94h] [ebp-10h] BYREF
  DName namespaceName; // [esp+9Ch] [ebp-8h] BYREF
  bool fNeedBracket; // [esp+AFh] [ebp+Bh]

  *((_BYTE *)result + 4) = 0;
  *((_DWORD *)result + 1) &= 0xFFFF00FF;
  result->node = 0;
  fNeedBracket = 0;
  while ( !*((_BYTE *)result + 4) && *UnDecorator::gName && *UnDecorator::gName != 64 )
  {
    if ( UnDecorator::fExplicitTemplateParams && !UnDecorator::fGetTemplateArgumentList )
      return result;
    if ( result->node )
    {
      v2 = operator+(&resulta, "::", result);
      DName::operator=(result, v2);
      if ( fNeedBracket )
      {
        v3 = operator+(&v26, 91, result);
        DName::operator=(result, v3);
        fNeedBracket = 0;
      }
    }
    if ( *UnDecorator::gName != 63 )
    {
      v21 = result;
      v20 = &v37;
      v14 = &v38;
      goto LABEL_26;
    }
    v4 = UnDecorator::gName + 1;
    UnDecorator::gName = v4;
    switch ( *v4 )
    {
      case '$':
        v21 = result;
        v20 = (DName *)&v28;
        UnDecorator::gName = v4 - 1;
        v14 = &v39;
LABEL_26:
        ZName = UnDecorator::getZName(v14, 1, 0);
LABEL_27:
        v15 = DName::operator+(ZName, v20, v21);
        DName::operator=(result, v15);
        break;
      case '%':
LABEL_22:
        DName::DName(&namespaceName, (char **)&UnDecorator::gName, 64);
        v13 = operator+(&v30, "`anonymous namespace'", result);
        DName::operator=(result, v13);
        if ( UnDecorator::pZNameList->index != 9 )
          Replicator::operator+=(UnDecorator::pZNameList, &namespaceName);
        break;
      case '?':
        if ( v4[1] != 95 || v4[2] != 63 )
        {
          v21 = result;
          v20 = (DName *)&v29;
          DecoratedName = UnDecorator::getDecoratedName(&v34);
          v12 = operator+(&v32, 96, DecoratedName);
          ZName = DName::operator+(v12, &v35, 39);
          goto LABEL_27;
        }
        UnDecorator::gName = v4 + 1;
        OperatorName = UnDecorator::getOperatorName(&v36, 0, 0);
        v10 = DName::operator+(OperatorName, &v31, result);
        DName::operator=(result, v10);
        if ( *UnDecorator::gName == 64 )
          ++UnDecorator::gName;
        break;
      case 'A':
        goto LABEL_22;
      default:
        v21 = result;
        if ( *v4 != 73 )
        {
          v20 = (DName *)&v24;
          ZName = UnDecorator::getLexicalFrame(&v22);
          goto LABEL_27;
        }
        UnDecorator::gName = v4 + 1;
        v6 = UnDecorator::getZName(&v27, 1, 0);
        v7 = DName::operator+(v6, &v33, 93);
        v8 = DName::operator+(v7, &v25, result);
        DName::operator=(result, v8);
        fNeedBracket = 1;
        break;
    }
  }
  if ( *UnDecorator::gName )
  {
    if ( *UnDecorator::gName != 64 )
      DName::operator=(result, DN_invalid);
  }
  else if ( result->node )
  {
    v16 = DName::DName(&v39, DN_truncated);
    v17 = DName::operator+(v16, &v37, "::");
    v18 = DName::operator+(v17, &v38, result);
    DName::operator=(result, v18);
  }
  else
  {
    DName::operator=(result, DN_truncated);
  }
  return result;
}
