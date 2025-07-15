DName *__cdecl UnDecorator::getTemplateConstant(DName *result)
{
  char v1; // bl
  DName *v2; // eax
  DName *v3; // eax
  unsigned int v4; // eax
  char *Parameter; // eax
  DName *v6; // eax
  const DName *v7; // eax
  const DName *v8; // eax
  const DName *v9; // eax
  const DName *SignedDimension; // eax
  DName *v12; // [esp-8h] [ebp-E4h]
  DName *DecoratedName; // [esp-4h] [ebp-E0h]
  DName v14; // [esp+Ch] [ebp-D0h] BYREF
  DName v15; // [esp+14h] [ebp-C8h] BYREF
  DName v16; // [esp+1Ch] [ebp-C0h] BYREF
  DName v17; // [esp+24h] [ebp-B8h] BYREF
  DName v18; // [esp+2Ch] [ebp-B0h] BYREF
  DName v19; // [esp+34h] [ebp-A8h] BYREF
  DName v20; // [esp+3Ch] [ebp-A0h] BYREF
  DName v21; // [esp+44h] [ebp-98h] BYREF
  DName v22; // [esp+4Ch] [ebp-90h] BYREF
  DName v23; // [esp+54h] [ebp-88h] BYREF
  DName resulta; // [esp+5Ch] [ebp-80h] BYREF
  char v25; // [esp+64h] [ebp-78h] BYREF
  char v26; // [esp+65h] [ebp-77h] BYREF
  char v27; // [esp+66h] [ebp-76h]
  char v28[8]; // [esp+C8h] [ebp-14h] BYREF
  DName rd; // [esp+D0h] [ebp-Ch] BYREF

  v1 = *UnDecorator::gName++;
  if ( v1 <= 68 )
  {
    if ( v1 != 68 )
    {
      if ( v1 )
      {
        if ( v1 == 48 )
        {
          UnDecorator::getSignedDimension(result);
          return result;
        }
        if ( v1 == 49 )
        {
          if ( *UnDecorator::gName == 64 )
          {
            ++UnDecorator::gName;
            DName::DName(result, "NULL");
            return result;
          }
          DecoratedName = UnDecorator::getDecoratedName(&v21);
          v12 = result;
          v3 = DName::DName(&v17, "&");
LABEL_16:
          DName::operator+(v3, v12, DecoratedName);
          return result;
        }
        if ( v1 != 50 )
        {
LABEL_10:
          DName::DName(result, DN_invalid);
          return result;
        }
        UnDecorator::getSignedDimension(&resulta);
        UnDecorator::getSignedDimension(&rd);
        if ( *((char *)&resulta + 4) <= 1 && *((char *)&rd + 4) <= 1 )
        {
          if ( !DName::getString(&resulta, &v26, 0x64u) )
            goto LABEL_10;
          v25 = v26;
          if ( v26 == 45 )
          {
            v26 = v27;
            v27 = 46;
          }
          else
          {
            v26 = 46;
          }
          DecoratedName = &rd;
          v12 = result;
          v2 = DName::DName(&v14, &v25);
          v3 = DName::operator+(v2, &v19, 101);
          goto LABEL_16;
        }
      }
      else
      {
        --UnDecorator::gName;
      }
      DName::DName(result, DN_truncated);
      return result;
    }
    goto LABEL_30;
  }
  if ( v1 == 69 )
  {
    UnDecorator::getDecoratedName(result);
    return result;
  }
  if ( v1 <= 69 )
    goto LABEL_10;
  if ( v1 <= 74 )
  {
    DName::operator=(&resulta, 123);
    if ( v1 >= 72 && v1 <= 74 )
    {
      v7 = UnDecorator::getDecoratedName(&v22);
      DName::operator+=(&resulta, v7);
      DName::operator+=(&resulta, 44);
    }
    if ( v1 == 70 )
      goto LABEL_46;
    if ( v1 != 71 )
    {
      if ( v1 == 72 )
      {
LABEL_47:
        SignedDimension = UnDecorator::getSignedDimension(&v16);
        DName::operator+=(&resulta, SignedDimension);
        goto LABEL_48;
      }
      if ( v1 == 73 )
      {
LABEL_46:
        v9 = UnDecorator::getSignedDimension(&v18);
        DName::operator+=(&resulta, v9);
        DName::operator+=(&resulta, 44);
        goto LABEL_47;
      }
      if ( v1 != 74 )
      {
LABEL_48:
        DName::operator+(&resulta, result, 125);
        return result;
      }
    }
    v8 = UnDecorator::getSignedDimension(&v20);
    DName::operator+=(&resulta, v8);
    DName::operator+=(&resulta, 44);
    goto LABEL_46;
  }
  if ( v1 == 81 )
  {
LABEL_30:
    UnDecorator::getSignedDimension(&resulta);
    if ( (UnDecorator::disableFlags & 0x4000) != 0
      && (DName::getString(&resulta, v28, 0x10u), v4 = atol(v1, v28),
                                                  (Parameter = UnDecorator::m_pGetParameter(v4)) != 0) )
    {
      DName::DName(result, Parameter);
    }
    else
    {
      if ( v1 == 68 )
        v6 = operator+(&v23, "`template-parameter", &resulta);
      else
        v6 = operator+(&v15, "`non-type-template-parameter", &resulta);
      DName::operator+(v6, result, "'");
    }
    return result;
  }
  if ( v1 != 82 )
    goto LABEL_10;
  UnDecorator::getZName(&rd, 0, 0);
  UnDecorator::getSignedDimension(&resulta);
  *result = rd;
  return result;
}
