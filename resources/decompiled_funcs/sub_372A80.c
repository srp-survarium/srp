int __cdecl sub_372A80(_DWORD *a1)
{
  int v2; // eax
  char v4; // dl
  char v5; // cl
  char v6; // al

  while ( a1[99] || (*(_BYTE *)(a1[105] + 12) ? sub_3728C0(a1) : sub_3729E0(a1)) )
  {
    v2 = a1[99];
    switch ( v2 )
    {
      case 1:
      case 208:
      case 209:
      case 210:
      case 211:
      case 212:
      case 213:
      case 214:
      case 215:
        *(_DWORD *)(*a1 + 20) = 94;
        *(_DWORD *)(*a1 + 24) = a1[99];
        (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
        a1[99] = 0;
        continue;
      case 192:
        if ( !sub_371430(1, 0, 0, (int)a1) )
          return 0;
        a1[99] = 0;
        continue;
      case 193:
        v4 = 0;
        goto LABEL_12;
      case 194:
        if ( !sub_371430(0, 0, 1, (int)a1) )
          return 0;
        a1[99] = 0;
        continue;
      case 195:
      case 197:
      case 198:
      case 199:
      case 200:
      case 203:
      case 205:
      case 206:
      case 207:
        *(_DWORD *)(*a1 + 20) = 62;
        *(_DWORD *)(*a1 + 24) = a1[99];
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
        a1[99] = 0;
        continue;
      case 196:
        v6 = sub_371BB0(a1);
        goto LABEL_14;
      case 201:
        v4 = 1;
LABEL_12:
        v5 = 0;
        goto LABEL_13;
      case 202:
        v4 = 1;
        v5 = 1;
LABEL_13:
        v6 = sub_371430(0, v4, v5, (int)a1);
        goto LABEL_14;
      case 204:
        v6 = sub_371A20(a1);
        goto LABEL_14;
      case 216:
        if ( !sub_371380((int)a1) )
          return 0;
        goto LABEL_30;
      case 217:
        *(_DWORD *)(*a1 + 20) = 87;
        (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
        a1[99] = 0;
        return 2;
      case 218:
        if ( !sub_371740(a1) )
          return 0;
        a1[99] = 0;
        return 1;
      case 219:
        v6 = sub_371ED0(a1);
        goto LABEL_14;
      case 220:
        v6 = sub_372810(a1);
        goto LABEL_14;
      case 221:
        v6 = sub_372270(a1);
        goto LABEL_14;
      case 224:
      case 225:
      case 226:
      case 227:
      case 228:
      case 229:
      case 230:
      case 231:
      case 232:
      case 233:
      case 234:
      case 235:
      case 236:
      case 237:
      case 238:
      case 239:
        v6 = (*(int (__cdecl **)(_DWORD *))(a1[105] + 4 * v2 - 868))(a1);
        goto LABEL_14;
      case 254:
        v6 = (*(int (__cdecl **)(_DWORD *))(a1[105] + 24))(a1);
LABEL_14:
        if ( !v6 )
          return 0;
        a1[99] = 0;
        break;
      default:
        *(_DWORD *)(*a1 + 20) = 70;
        *(_DWORD *)(*a1 + 24) = a1[99];
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
LABEL_30:
        a1[99] = 0;
        continue;
    }
  }
  return 0;
}
