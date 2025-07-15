int __cdecl sub_525AC0(int a1, int a2, int a3, char *a4, char *a5, char **a6, char a7)
{
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp+0h] [ebp-B8h]
  int v13; // [esp+8h] [ebp-B0h] BYREF
  void (__cdecl *v14)(_DWORD, char *, int); // [esp+Ch] [ebp-ACh]
  int v15; // [esp+10h] [ebp-A8h] BYREF
  int v16; // [esp+14h] [ebp-A4h]
  char v17; // [esp+1Bh] [ebp-9Dh] BYREF
  char v18[4]; // [esp+1Ch] [ebp-9Ch] BYREF
  int v19; // [esp+20h] [ebp-98h]
  int v20; // [esp+24h] [ebp-94h]
  _BYTE *v21; // [esp+28h] [ebp-90h]
  _BYTE *v22; // [esp+2Ch] [ebp-8Ch]
  _BYTE *v23; // [esp+30h] [ebp-88h]
  void *rhs; // [esp+34h] [ebp-84h]
  unsigned int siz; // [esp+38h] [ebp-80h]
  int v26; // [esp+3Ch] [ebp-7Ch]
  int v27; // [esp+40h] [ebp-78h]
  int v28; // [esp+44h] [ebp-74h]
  char v29; // [esp+4Bh] [ebp-6Dh]
  char *v30; // [esp+4Ch] [ebp-6Ch]
  int v31[6]; // [esp+50h] [ebp-68h] BYREF
  int v32; // [esp+68h] [ebp-50h] BYREF
  int v33; // [esp+6Ch] [ebp-4Ch]
  int v34; // [esp+70h] [ebp-48h]
  _BYTE *v35; // [esp+74h] [ebp-44h]
  int v36; // [esp+78h] [ebp-40h]
  int v37; // [esp+7Ch] [ebp-3Ch] BYREF
  int v38; // [esp+80h] [ebp-38h]
  _BYTE *v39; // [esp+84h] [ebp-34h] BYREF
  _DWORD *v40; // [esp+88h] [ebp-30h]
  int v41; // [esp+8Ch] [ebp-2Ch]
  int v42; // [esp+90h] [ebp-28h]
  char v43; // [esp+97h] [ebp-21h] BYREF
  int v44; // [esp+98h] [ebp-20h]
  int v45; // [esp+9Ch] [ebp-1Ch]
  char v46; // [esp+A3h] [ebp-15h] BYREF
  char *v47; // [esp+A4h] [ebp-14h] BYREF
  int v48; // [esp+A8h] [ebp-10h]
  int v49; // [esp+ACh] [ebp-Ch]
  void **v50; // [esp+B0h] [ebp-8h]
  void **v51; // [esp+B4h] [ebp-4h]

  v49 = *(_DWORD *)(a1 + 356);
  if ( a3 == *(_DWORD *)(a1 + 144) )
  {
    v50 = (void **)(a1 + 288);
    v51 = (void **)(a1 + 292);
  }
  else
  {
    v50 = *(void ***)(a1 + 300);
    v51 = (void **)(*(_DWORD *)(a1 + 300) + 4);
  }
  *v50 = a4;
  while ( 2 )
  {
    v47 = a4;
    v48 = (*(int (__cdecl **)(int, char *, char *, char **))(a3 + 4))(a3, a4, a5, &v47);
    *v51 = v47;
    switch ( v48 )
    {
      case -5:
        if ( a7 )
        {
          *a6 = a4;
          return 0;
        }
        else
        {
          if ( *(_DWORD *)(a1 + 60) )
          {
            if ( *(_BYTE *)(a3 + 72) )
            {
              (*(void (__cdecl **)(_DWORD, char *, int))(a1 + 60))(*(_DWORD *)(a1 + 4), a4, a5 - a4);
            }
            else
            {
              v15 = *(_DWORD *)(a1 + 44);
              (*(void (__cdecl **)(int, char **, char *, int *, _DWORD))(a3 + 60))(
                a3,
                &a4,
                a5,
                &v15,
                *(_DWORD *)(a1 + 48));
              (*(void (__cdecl **)(_DWORD, _DWORD, int))(a1 + 60))(
                *(_DWORD *)(a1 + 4),
                *(_DWORD *)(a1 + 44),
                v15 - *(_DWORD *)(a1 + 44));
            }
          }
          else if ( *(_DWORD *)(a1 + 80) )
          {
            sub_52C240(a1, a3, a4, a5);
          }
          if ( a2 )
          {
            if ( *(_DWORD *)(a1 + 312) == a2 )
            {
              *a6 = a5;
              return 0;
            }
            else
            {
              *v50 = a5;
              return 13;
            }
          }
          else
          {
            *v50 = a5;
            return 3;
          }
        }
      case -4:
        if ( a7 )
        {
          *a6 = a4;
          return 0;
        }
        else if ( a2 <= 0 )
        {
          return 3;
        }
        else if ( *(_DWORD *)(a1 + 312) == a2 )
        {
          *a6 = a4;
          return 0;
        }
        else
        {
          return 13;
        }
      case -3:
        if ( a7 )
        {
          *a6 = a4;
          return 0;
        }
        else
        {
          *v51 = a5;
          if ( *(_DWORD *)(a1 + 60) )
          {
            v46 = 10;
            (*(void (__cdecl **)(_DWORD, char *, int))(a1 + 60))(*(_DWORD *)(a1 + 4), &v46, 1);
          }
          else if ( *(_DWORD *)(a1 + 80) )
          {
            sub_52C240(a1, a3, a4, a5);
          }
          if ( a2 )
          {
            if ( *(_DWORD *)(a1 + 312) == a2 )
            {
              *a6 = a5;
              return 0;
            }
            else
            {
              return 13;
            }
          }
          else
          {
            return 3;
          }
        }
      case -2:
        if ( !a7 )
          return 6;
        *a6 = a4;
        return 0;
      case -1:
        if ( !a7 )
          return 5;
        *a6 = a4;
        return 0;
      case 0:
        *v50 = v47;
        return 4;
      case 1:
      case 2:
        if ( *(_DWORD *)(a1 + 368) )
        {
          v40 = *(_DWORD **)(a1 + 368);
          *(_DWORD *)(a1 + 368) = **(_DWORD **)(a1 + 368);
        }
        else
        {
          v40 = (_DWORD *)(*(int (__cdecl **)(int))(a1 + 12))(48);
          if ( !v40 )
            return 1;
          v40[9] = (*(int (__cdecl **)(int))(a1 + 12))(32);
          if ( !v40[9] )
          {
            (*(void (__cdecl **)(_DWORD *))(a1 + 20))(v40);
            return 1;
          }
          v40[10] = v40[9] + 32;
        }
        v40[11] = 0;
        *v40 = *(_DWORD *)(a1 + 364);
        *(_DWORD *)(a1 + 364) = v40;
        v40[4] = 0;
        v40[5] = 0;
        v40[1] = &a4[*(_DWORD *)(a3 + 68)];
        v8 = (*(int (__cdecl **)(int, _DWORD))(a3 + 32))(a3, v40[1]);
        v40[2] = v8;
        ++*(_DWORD *)(a1 + 312);
        v36 = v40[2] + v40[1];
        v37 = v40[1];
        v39 = (_BYTE *)v40[9];
        while ( 2 )
        {
          (*(void (__cdecl **)(int, int *, int, _BYTE **, int))(a3 + 60))(a3, &v37, v36, &v39, v40[10] - 1);
          v35 = &v39[-v40[9]];
          if ( v37 == v36 )
          {
            v40[6] = v35;
            v40[3] = v40[9];
            *v39 = 0;
            v9 = sub_526B20(a1, a3, a4, v40 + 3, v40 + 11);
            v38 = v9;
            if ( !v9 )
            {
              if ( *(_DWORD *)(a1 + 52) )
              {
                (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD))(a1 + 52))(
                  *(_DWORD *)(a1 + 4),
                  v40[3],
                  *(_DWORD *)(a1 + 392));
              }
              else if ( *(_DWORD *)(a1 + 80) )
              {
                sub_52C240(a1, a3, a4, v47);
              }
              sub_52DB80(a1 + 416);
              goto LABEL_194;
            }
            return v38;
          }
          else
          {
            v34 = 2 * (v40[10] - v40[9]);
            v33 = (*(int (__cdecl **)(_DWORD, int))(a1 + 16))(v40[9], v34);
            if ( v33 )
            {
              v40[9] = v33;
              v40[10] = v34 + v33;
              v39 = &v35[v33];
              continue;
            }
            return 1;
          }
        }
      case 3:
      case 4:
        v30 = &a4[*(_DWORD *)(a3 + 68)];
        v32 = 0;
        v29 = 1;
        v10 = (*(int (__cdecl **)(int, char *))(a3 + 32))(a3, v30);
        v31[0] = sub_52DE00(a1 + 416, a3, v30, &v30[v10]);
        if ( !v31[0] )
          return 1;
        *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
        v28 = sub_526B20(a1, a3, a4, v31, &v32);
        if ( !v28 )
        {
          *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
          if ( *(_DWORD *)(a1 + 52) )
          {
            (*(void (__cdecl **)(_DWORD, int, _DWORD))(a1 + 52))(*(_DWORD *)(a1 + 4), v31[0], *(_DWORD *)(a1 + 392));
            v29 = 0;
          }
          if ( *(_DWORD *)(a1 + 56) )
          {
            if ( *(_DWORD *)(a1 + 52) )
              *v50 = *v51;
            (*(void (__cdecl **)(_DWORD, int))(a1 + 56))(*(_DWORD *)(a1 + 4), v31[0]);
            v29 = 0;
          }
          if ( v29 && *(_DWORD *)(a1 + 80) )
            sub_52C240(a1, a3, a4, v47);
          sub_52DB80(a1 + 416);
          while ( v32 )
          {
            v27 = v32;
            if ( *(_DWORD *)(a1 + 104) )
              (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 104))(*(_DWORD *)(a1 + 4), **(_DWORD **)v27);
            v32 = *(_DWORD *)(v32 + 4);
            *(_DWORD *)(v27 + 4) = *(_DWORD *)(a1 + 376);
            *(_DWORD *)(a1 + 376) = v27;
            *(_DWORD *)(*(_DWORD *)v27 + 4) = *(_DWORD *)(v27 + 8);
          }
          if ( *(_DWORD *)(a1 + 312) )
            goto LABEL_194;
          return sub_52ADD0(a1, v47, a5, a6);
        }
        return v28;
      case 5:
        if ( *(_DWORD *)(a1 + 312) == a2 )
          return 13;
        v26 = *(_DWORD *)(a1 + 364);
        *(_DWORD *)(a1 + 364) = *(_DWORD *)v26;
        *(_DWORD *)v26 = *(_DWORD *)(a1 + 368);
        *(_DWORD *)(a1 + 368) = v26;
        rhs = &a4[2 * *(_DWORD *)(a3 + 68)];
        siz = (*(int (__cdecl **)(int, void *))(a3 + 32))(a3, rhs);
        if ( siz == *(_DWORD *)(v26 + 8) && !memcmp(*(unsigned __int8 **)(v26 + 4), (unsigned __int8 *)rhs, siz) )
        {
          --*(_DWORD *)(a1 + 312);
          if ( *(_DWORD *)(a1 + 56) )
          {
            v23 = *(_BYTE **)(v26 + 16);
            if ( *(_BYTE *)(a1 + 236) && v23 )
            {
              v21 = (_BYTE *)(*(_DWORD *)(v26 + 28) + *(_DWORD *)(v26 + 12));
              while ( *v23 )
                *v21++ = *v23++;
              v22 = *(_BYTE **)(v26 + 20);
              if ( *(_BYTE *)(a1 + 237) && v22 )
              {
                *v21++ = *(_BYTE *)(a1 + 472);
                while ( *v22 )
                  *v21++ = *v22++;
              }
              *v21 = 0;
            }
            (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 56))(*(_DWORD *)(a1 + 4), *(_DWORD *)(v26 + 12));
          }
          else if ( *(_DWORD *)(a1 + 80) )
          {
            sub_52C240(a1, a3, a4, v47);
          }
          while ( *(_DWORD *)(v26 + 44) )
          {
            v20 = *(_DWORD *)(v26 + 44);
            if ( *(_DWORD *)(a1 + 104) )
              (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 104))(*(_DWORD *)(a1 + 4), **(_DWORD **)v20);
            *(_DWORD *)(v26 + 44) = *(_DWORD *)(*(_DWORD *)(v26 + 44) + 4);
            *(_DWORD *)(v20 + 4) = *(_DWORD *)(a1 + 376);
            *(_DWORD *)(a1 + 376) = v20;
            *(_DWORD *)(*(_DWORD *)v20 + 4) = *(_DWORD *)(v20 + 8);
          }
          if ( *(_DWORD *)(a1 + 312) )
            goto LABEL_194;
          return sub_52ADD0(a1, v47, a5, a6);
        }
        else
        {
          *v50 = rhs;
          return 7;
        }
      case 6:
        v14 = *(void (__cdecl **)(_DWORD, char *, int))(a1 + 60);
        if ( v14 )
        {
          if ( *(_BYTE *)(a3 + 72) )
          {
            v14(*(_DWORD *)(a1 + 4), a4, v47 - a4);
          }
          else
          {
            while ( 1 )
            {
              v13 = *(_DWORD *)(a1 + 44);
              (*(void (__cdecl **)(int, char **, char *, int *, _DWORD))(a3 + 60))(
                a3,
                &a4,
                v47,
                &v13,
                *(_DWORD *)(a1 + 48));
              *v51 = a4;
              v14(*(_DWORD *)(a1 + 4), *(char **)(a1 + 44), v13 - *(_DWORD *)(a1 + 44));
              if ( a4 == v47 )
                break;
              *v50 = a4;
            }
          }
        }
        else if ( *(_DWORD *)(a1 + 80) )
        {
          sub_52C240(a1, a3, a4, v47);
        }
        goto LABEL_194;
      case 7:
        if ( *(_DWORD *)(a1 + 60) )
        {
          v17 = 10;
          (*(void (__cdecl **)(_DWORD, char *, int))(a1 + 60))(*(_DWORD *)(a1 + 4), &v17, 1);
        }
        else if ( *(_DWORD *)(a1 + 80) )
        {
          sub_52C240(a1, a3, a4, v47);
        }
        goto LABEL_194;
      case 8:
        if ( *(_DWORD *)(a1 + 72) )
        {
          (*(void (__cdecl **)(_DWORD))(a1 + 72))(*(_DWORD *)(a1 + 4));
        }
        else if ( *(_DWORD *)(a1 + 80) )
        {
          sub_52C240(a1, a3, a4, v47);
        }
        v16 = sub_527E30(a1, a3, &v47, a5, a6, a7);
        if ( v16 )
          return v16;
        if ( !v47 )
        {
          *(_DWORD *)(a1 + 280) = sub_527D10;
          return v16;
        }
LABEL_194:
        a4 = v47;
        *v50 = v47;
        v12 = *(_DWORD *)(a1 + 480);
        if ( v12 != 2 )
        {
          if ( v12 == 3 )
          {
            *a6 = v47;
            return 0;
          }
          continue;
        }
        return 35;
      case 9:
        v43 = (*(int (__cdecl **)(int, char *, char *))(a3 + 48))(
                a3,
                &a4[*(_DWORD *)(a3 + 68)],
                &v47[-*(_DWORD *)(a3 + 68)]);
        if ( v43 )
        {
          if ( *(_DWORD *)(a1 + 60) )
          {
            (*(void (__cdecl **)(_DWORD, char *, int))(a1 + 60))(*(_DWORD *)(a1 + 4), &v43, 1);
          }
          else if ( *(_DWORD *)(a1 + 80) )
          {
            sub_52C240(a1, a3, a4, v47);
          }
          goto LABEL_194;
        }
        v44 = sub_52DE00(v49 + 80, a3, &a4[*(_DWORD *)(a3 + 68)], &v47[-*(_DWORD *)(a3 + 68)]);
        if ( !v44 )
          return 1;
        v45 = sub_52D5B0(a1, v49, v44, 0);
        *(_DWORD *)(v49 + 92) = *(_DWORD *)(v49 + 96);
        if ( *(_BYTE *)(v49 + 129) && !*(_BYTE *)(v49 + 130) )
        {
          if ( !v45 )
          {
            if ( *(_DWORD *)(a1 + 120) )
            {
              (*(void (__cdecl **)(_DWORD, int, _DWORD))(a1 + 120))(*(_DWORD *)(a1 + 4), v44, 0);
            }
            else if ( *(_DWORD *)(a1 + 80) )
            {
              sub_52C240(a1, a3, a4, v47);
            }
            goto LABEL_194;
          }
        }
        else
        {
          if ( !v45 )
            return 11;
          if ( !*(_BYTE *)(v45 + 34) )
            return 24;
        }
        if ( *(_BYTE *)(v45 + 32) )
          return 12;
        if ( *(_DWORD *)(v45 + 28) )
          return 15;
        if ( *(_DWORD *)(v45 + 4) )
        {
          if ( *(_BYTE *)(a1 + 308) )
          {
            v42 = sub_52B030(a1, v45, 0);
            if ( v42 )
              return v42;
          }
          else if ( *(_DWORD *)(a1 + 120) )
          {
            (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD))(a1 + 120))(*(_DWORD *)(a1 + 4), *(_DWORD *)v45, 0);
          }
          else if ( *(_DWORD *)(a1 + 80) )
          {
            sub_52C240(a1, a3, a4, v47);
          }
        }
        else if ( *(_DWORD *)(a1 + 112) )
        {
          *(_BYTE *)(v45 + 32) = 1;
          v41 = sub_52C920(a1);
          *(_BYTE *)(v45 + 32) = 0;
          if ( !v41 )
            return 1;
          if ( !(*(int (__cdecl **)(_DWORD, int, _DWORD, _DWORD, _DWORD))(a1 + 112))(
                  *(_DWORD *)(a1 + 116),
                  v41,
                  *(_DWORD *)(v45 + 20),
                  *(_DWORD *)(v45 + 16),
                  *(_DWORD *)(v45 + 24)) )
            return 21;
          *(_DWORD *)(a1 + 428) = *(_DWORD *)(a1 + 432);
        }
        else if ( *(_DWORD *)(a1 + 80) )
        {
          sub_52C240(a1, a3, a4, v47);
        }
        goto LABEL_194;
      case 10:
        v19 = (*(int (__cdecl **)(int, char *))(a3 + 44))(a3, a4);
        if ( v19 < 0 )
          return 14;
        if ( *(_DWORD *)(a1 + 60) )
        {
          v11 = XmlUtf8Encode(v19, v18);
          (*(void (__cdecl **)(_DWORD, char *, int))(a1 + 60))(*(_DWORD *)(a1 + 4), v18, v11);
        }
        else if ( *(_DWORD *)(a1 + 80) )
        {
          sub_52C240(a1, a3, a4, v47);
        }
        goto LABEL_194;
      case 11:
        if ( sub_52BFC0(a1, a3, a4, v47) )
          goto LABEL_194;
        return 1;
      case 12:
        return 17;
      case 13:
        if ( sub_52C190(a1, a3, a4, v47) )
          goto LABEL_194;
        return 1;
      default:
        if ( *(_DWORD *)(a1 + 80) )
          sub_52C240(a1, a3, a4, v47);
        goto LABEL_194;
    }
  }
}
