int __cdecl UnDecorator::getTypeEncoding()
{
  const char *i; // ecx
  int v1; // esi
  char v2; // al
  char v3; // bl
  const char *v4; // ecx
  int v5; // eax
  const char *v6; // ecx
  int v7; // eax
  int v8; // eax
  bool v9; // zf
  int v10; // eax
  int v11; // esi
  int v12; // esi
  unsigned int v13; // esi
  int v14; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  char v19; // al
  int v20; // eax
  int v21; // eax
  int v22; // eax
  char v23; // al
  int v24; // esi
  char v25; // al
  unsigned int v26; // esi
  unsigned int v27; // esi
  unsigned int v28; // esi
  int v29; // eax
  int v30; // eax
  char v31; // al
  unsigned int v32; // esi
  unsigned int v33; // esi
  unsigned int v34; // esi
  unsigned int v35; // esi

  for ( i = UnDecorator::gName; ; UnDecorator::gName = i )
  {
    v1 = 0;
    if ( *i == 95 )
    {
      ++i;
      v1 = 0x4000;
      UnDecorator::gName = i;
    }
    v2 = *i;
    if ( *i >= 65 && v2 <= 90 )
      break;
    if ( v2 != 36 )
    {
      v31 = *i;
      if ( *i >= 48 && v31 <= 56 )
      {
        v32 = v1 & 0xFFFF7FFF;
        UnDecorator::gName = i + 1;
        switch ( v31 )
        {
          case '0':
            if ( (v32 & 0x8000) != 0 )
              v33 = v32 & 0xFFFFF8FF | 0x200;
            else
              v33 = v32 & 0xFFFF9FFF;
            if ( (v33 & 0x8000) != 0 )
              return v33 & 0xFFFFFF3F | 0x40;
            else
              return v33 & 0xFFFFE7FF | 0x800;
          case '1':
            if ( (v32 & 0x8000) != 0 )
              v34 = v32 & 0xFFFFF8FF | 0x200;
            else
              v34 = v32 & 0xFFFF9FFF;
            if ( (v34 & 0x8000) != 0 )
              return v34 & 0xFFFFFF3F | 0x80;
            else
              return v34 & 0xFFFFE7FF | 0x1000;
          case '2':
            if ( (v32 & 0x8000) != 0 )
              v35 = v32 & 0xFFFFF8FF | 0x200;
            else
              v35 = v32 & 0xFFFF9FFF;
            if ( (v35 & 0x8000) != 0 )
              return v35 & 0xFFFFFF3F;
            else
              return v35 & 0xFFFFE7FF;
          case '3':
            return v32 & 0xFFFF9FFF | 0x4000;
          case '4':
            return v32 & 0xFFFF9FFF | 0x2000;
          case '5':
            return v32 & 0xFFFF83FF | 0x6000;
          case '6':
            return v32 & 0xFFFF83FF | 0x6800;
          case '7':
            return v32 & 0xFFFF83FF | 0x7000;
          case '8':
            return v32 & 0xFFFF83FF | 0x7800;
          default:
            return 0xFFFF;
        }
      }
      if ( v31 != 57 )
        return (v31 != 0) + 65534;
      UnDecorator::gName = i + 1;
      return 65533;
    }
    v3 = 0;
    v4 = i + 1;
    UnDecorator::gName = v4;
    v5 = *v4;
    if ( v5 > 66 )
    {
      v20 = v5 - 67;
      if ( v20 )
      {
        v21 = v20 - 1;
        if ( v21 )
        {
          v22 = v21 - 1;
          if ( v22 )
          {
            if ( v22 != 13 )
              return 0xFFFF;
            UnDecorator::gName = ++v4;
            v23 = *v4;
            v3 = 1;
            if ( *v4 < 48 || v23 > 53 )
              return (v23 == 0) + 65534;
LABEL_70:
            v24 = v1 | 0x8000;
            v25 = *v4 - 48;
            if ( (v24 & 0x8000) != 0 )
              v26 = v24 & 0xFFFFE7FF | 0x800;
            else
              v26 = v24 & 0xFFFF9FFF;
            if ( v3 )
              v27 = v26 & 0xFFFFF8FF | 0x600;
            else
              v27 = v26 & 0xFFFFF8FF | 0x500;
            if ( (v25 & 1) != 0 )
              v28 = v27 | 0x2000;
            else
              v28 = v27 & 0xFFFFDFFF;
            v29 = v25 & 6;
            if ( v29 )
            {
              v30 = v29 - 2;
              if ( v30 )
              {
                if ( v30 != 2 )
                  return 0xFFFF;
                if ( (v28 & 0x8000) != 0 )
                  v12 = v28 & 0xFFFFFF3F;
                else
                  v12 = v28 & 0xFFFFE7FF;
              }
              else if ( (v28 & 0x8000) != 0 )
              {
                v12 = v28 & 0xFFFFFF3F | 0x80;
              }
              else
              {
                v12 = v28 & 0xFFFFE7FF | 0x1000;
              }
            }
            else if ( (v28 & 0x8000) != 0 )
            {
              v12 = v28 & 0xFFFFFF3F | 0x40;
            }
            else
            {
              v12 = v28 & 0xFFFFE7FF | 0x800;
            }
          }
          else
          {
            v12 = v1 & 0xFFFF64FF | 0x9200;
          }
        }
        else
        {
          v12 = v1 & 0xFFFF64FF | 0x9100;
        }
      }
      else
      {
        v12 = v1 | 0x7C00;
      }
LABEL_95:
      UnDecorator::gName = v4 + 1;
      return v12;
    }
    if ( v5 == 66 )
    {
      v12 = v1 | 0x9800;
      goto LABEL_95;
    }
    if ( !*v4 )
    {
      v12 = 65534;
      --v4;
      goto LABEL_95;
    }
    if ( v5 != 36 )
    {
      if ( v5 <= 47 )
        return 0xFFFF;
      if ( v5 > 53 )
      {
        if ( v5 == 65 )
        {
          v12 = v1 & 0xFFFF64FF | 0x9000;
          goto LABEL_95;
        }
        return 0xFFFF;
      }
      goto LABEL_70;
    }
    if ( v4[1] == 80 )
      ++v4;
    v6 = v4 + 1;
    UnDecorator::gName = v6;
    v7 = *v6;
    if ( v7 > 74 )
    {
      if ( v7 < 76 )
        return 0xFFFF;
      if ( v7 <= 77 )
        goto LABEL_23;
      if ( v7 <= 79 )
      {
LABEL_58:
        v4 = v6 + 1;
        UnDecorator::gName = v4;
        v19 = *v4;
        if ( *v4 >= 48 && v19 <= 57 )
        {
          UnDecorator::gName = &v4[v19 - 47];
          return (unsigned int)&_sbh_sizeHeaderList | UnDecorator::getTypeEncoding();
        }
        v12 = 0xFFFF;
        goto LABEL_95;
      }
      v9 = v7 == 81;
      goto LABEL_22;
    }
    if ( v7 == 74 )
      goto LABEL_58;
    if ( !*v6 )
      return 65534;
    v8 = v7 - 70;
    if ( v8 )
    {
      v9 = v8 == 2;
LABEL_22:
      if ( !v9 )
        return 0xFFFF;
    }
LABEL_23:
    i = v6 + 1;
  }
  v10 = *i - 65;
  v11 = v1 | 0x8000;
  UnDecorator::gName = i + 1;
  if ( (v10 & 1) != 0 )
    v12 = v11 | 0x2000;
  else
    v12 = v11 & 0xFFFFDFFF;
  if ( v10 < 24 )
  {
    if ( (v12 & 0x8000) != 0 )
      v13 = v12 & 0xFFFFE7FF | 0x800;
    else
      v13 = v12 & 0xFFFF9FFF;
    v14 = v10 & 0x18;
    if ( (v10 & 0x18) != 0 )
    {
      if ( v14 == 8 )
      {
        if ( (v13 & 0x8000) != 0 )
          v12 = v13 & 0xFFFFFF3F | 0x80;
        else
          v12 = v13 & 0xFFFFE7FF | 0x1000;
      }
      else
      {
        if ( v14 != 16 )
          return 0xFFFF;
        if ( (v13 & 0x8000) != 0 )
          v12 = v13 & 0xFFFFFF3F;
        else
          v12 = v13 & 0xFFFFE7FF;
      }
    }
    else if ( (v13 & 0x8000) != 0 )
    {
      v12 = v13 & 0xFFFFFF3F | 0x40;
    }
    else
    {
      v12 = v13 & 0xFFFFE7FF | 0x800;
    }
    v16 = v10 & 6;
    if ( v16 )
    {
      v17 = v16 - 2;
      if ( v17 )
      {
        v18 = v17 - 2;
        if ( v18 )
        {
          if ( v18 != 2 )
            return 0xFFFF;
          return v12 & 0xFFFFF8FF | 0x400;
        }
        else
        {
          return v12 & 0xFFFFF8FF | 0x100;
        }
      }
      else if ( (v12 & 0x8000) != 0 )
      {
        return v12 & 0xFFFFF8FF | 0x200;
      }
      else
      {
        return v12 & 0xFFFF9FFF;
      }
    }
  }
  return v12;
}
