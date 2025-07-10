int __cdecl sub_5286F0(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7, char a8)
{
  int v9; // eax
  int v10; // eax
  int v11; // [esp+0h] [ebp-CCh]
  int v12; // [esp+8h] [ebp-C4h]
  BOOL v13; // [esp+Ch] [ebp-C0h]
  bool v14; // [esp+14h] [ebp-B8h]
  bool v15; // [esp+18h] [ebp-B4h]
  int v16; // [esp+1Ch] [ebp-B0h]
  int v17; // [esp+20h] [ebp-ACh]
  int v18; // [esp+24h] [ebp-A8h]
  int v19; // [esp+28h] [ebp-A4h]
  char *v20; // [esp+2Ch] [ebp-A0h]
  int v21; // [esp+38h] [ebp-94h]
  int *v22; // [esp+3Ch] [ebp-90h]
  int v23; // [esp+40h] [ebp-8Ch]
  int v24; // [esp+44h] [ebp-88h]
  int v25; // [esp+48h] [ebp-84h]
  _DWORD *v26; // [esp+50h] [ebp-7Ch]
  int v27; // [esp+54h] [ebp-78h]
  int v28; // [esp+5Ch] [ebp-70h]
  int v29; // [esp+60h] [ebp-6Ch]
  int v30; // [esp+64h] [ebp-68h]
  int v31; // [esp+68h] [ebp-64h]
  int v32; // [esp+6Ch] [ebp-60h]
  int v33; // [esp+70h] [ebp-5Ch]
  int v34; // [esp+74h] [ebp-58h]
  int v35; // [esp+78h] [ebp-54h]
  int v36; // [esp+7Ch] [ebp-50h]
  int v37; // [esp+80h] [ebp-4Ch]
  int v38; // [esp+84h] [ebp-48h]
  int v39; // [esp+88h] [ebp-44h]
  int v40; // [esp+8Ch] [ebp-40h]
  _DWORD *v41; // [esp+94h] [ebp-38h]
  char v42; // [esp+9Bh] [ebp-31h]
  _DWORD *v43; // [esp+9Ch] [ebp-30h]
  char v44; // [esp+A3h] [ebp-29h]
  int v45; // [esp+A4h] [ebp-28h]
  int v46; // [esp+A8h] [ebp-24h]
  int v47; // [esp+ACh] [ebp-20h]
  int v48; // [esp+B0h] [ebp-1Ch]
  int v49; // [esp+B4h] [ebp-18h]
  char v50; // [esp+BBh] [ebp-11h]
  int v51; // [esp+BCh] [ebp-10h]
  _DWORD *v52; // [esp+C0h] [ebp-Ch]
  _DWORD *v53; // [esp+C4h] [ebp-8h]
  int v54; // [esp+C8h] [ebp-4h]
  int v55; // [esp+C8h] [ebp-4h]

  v51 = *(_DWORD *)(a1 + 356);
  if ( a2 == *(_DWORD *)(a1 + 144) )
  {
    v52 = (_DWORD *)(a1 + 288);
    v53 = (_DWORD *)(a1 + 292);
  }
  else
  {
    v52 = *(_DWORD **)(a1 + 300);
    v53 = v52 + 1;
  }
  while ( 1 )
  {
    v50 = 1;
    *v52 = a3;
    *v53 = a6;
    if ( a5 <= 0 )
      break;
LABEL_23:
    v49 = (*(int (__cdecl **)(int, int, int, int, int))(a1 + 256))(a1 + 256, a5, a3, a6, a2);
    switch ( v49 )
    {
      case -1:
        if ( a5 == 12 )
          return 17;
        if ( a5 == 28 )
          return 10;
        return 2;
      case 0:
        if ( a5 == 14 )
          v50 = 0;
        goto LABEL_422;
      case 1:
        v48 = sub_5281C0(a1, 0, a3, a6);
        if ( v48 )
          return v48;
        a2 = *(_DWORD *)(a1 + 144);
        v50 = 0;
        goto LABEL_422;
      case 2:
        if ( !*(_BYTE *)(a1 + 489) )
          goto LABEL_93;
        v42 = *(_BYTE *)(v51 + 129);
        *(_BYTE *)(v51 + 129) = 1;
        if ( !*(_DWORD *)(a1 + 492) || !*(_DWORD *)(a1 + 112) )
          goto LABEL_93;
        v41 = (_DWORD *)sub_52D5B0(a1, v51 + 132, &unk_88A2A4, 0x24u);
        if ( !v41 )
          return 1;
        v41[5] = *(_DWORD *)(a1 + 360);
        *(_BYTE *)(v51 + 131) = 0;
        if ( !(*(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 112))(
                *(_DWORD *)(a1 + 116),
                0,
                v41[5],
                v41[4],
                v41[6]) )
          return 21;
        if ( *(_BYTE *)(v51 + 131) )
        {
          if ( !*(_BYTE *)(v51 + 130)
            && *(_DWORD *)(a1 + 108)
            && !(*(int (__cdecl **)(_DWORD))(a1 + 108))(*(_DWORD *)(a1 + 4)) )
          {
            return 22;
          }
        }
        else
        {
          *(_BYTE *)(v51 + 129) = v42;
        }
LABEL_93:
        *(_DWORD *)(a1 + 280) = sub_527DC0;
        return sub_527DC0(a1, a3, a4, a7);
      case 3:
        if ( *(_DWORD *)(a1 + 84) )
          v50 = 0;
        goto LABEL_422;
      case 4:
        if ( !*(_DWORD *)(a1 + 84) )
          goto LABEL_31;
        *(_DWORD *)(a1 + 320) = sub_52DE00(a1 + 416, a2, a3, a6);
        if ( !*(_DWORD *)(a1 + 320) )
          return 1;
        *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
        *(_DWORD *)(a1 + 328) = 0;
        v50 = 0;
LABEL_31:
        *(_DWORD *)(a1 + 324) = 0;
        goto LABEL_422;
      case 5:
        *(_BYTE *)(a1 + 489) = 0;
        *(_BYTE *)(v51 + 129) = 1;
        if ( *(_DWORD *)(a1 + 84) )
        {
          *(_DWORD *)(a1 + 324) = sub_52DE00(a1 + 416, a2, *(_DWORD *)(a2 + 68) + a3, a6 - *(_DWORD *)(a2 + 68));
          if ( !*(_DWORD *)(a1 + 324) )
            return 1;
          *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
          v50 = 0;
        }
        else
        {
          *(_DWORD *)(a1 + 324) = &unk_88A2A4;
        }
        if ( !*(_BYTE *)(v51 + 130)
          && !*(_DWORD *)(a1 + 492)
          && *(_DWORD *)(a1 + 108)
          && !(*(int (__cdecl **)(_DWORD))(a1 + 108))(*(_DWORD *)(a1 + 4)) )
        {
          return 22;
        }
        if ( *(_DWORD *)(a1 + 316) )
          goto LABEL_195;
        *(_DWORD *)(a1 + 316) = sub_52D5B0(a1, v51 + 132, &unk_88A2A4, 0x24u);
        if ( !*(_DWORD *)(a1 + 316) )
          return 1;
        *(_DWORD *)(*(_DWORD *)(a1 + 316) + 24) = 0;
LABEL_195:
        if ( !*(_BYTE *)(v51 + 128) || !*(_DWORD *)(a1 + 316) )
          goto LABEL_422;
        *(_DWORD *)(*(_DWORD *)(a1 + 316) + 16) = sub_52DE00(
                                                    v51 + 80,
                                                    a2,
                                                    *(_DWORD *)(a2 + 68) + a3,
                                                    a6 - *(_DWORD *)(a2 + 68));
        if ( !*(_DWORD *)(*(_DWORD *)(a1 + 316) + 16) )
          return 1;
        *(_DWORD *)(*(_DWORD *)(a1 + 316) + 20) = *(_DWORD *)(a1 + 360);
        *(_DWORD *)(v51 + 96) = *(_DWORD *)(v51 + 92);
        if ( *(_DWORD *)(a1 + 136) )
          v50 = 0;
        goto LABEL_422;
      case 6:
        *(_BYTE *)(a1 + 489) = 0;
        *(_DWORD *)(a1 + 316) = sub_52D5B0(a1, v51 + 132, &unk_88A2A4, 0x24u);
        if ( !*(_DWORD *)(a1 + 316) )
          return 1;
        *(_BYTE *)(v51 + 129) = 1;
        if ( *(_DWORD *)(a1 + 84) )
        {
          if ( !(*(int (__cdecl **)(int, int, int, _DWORD *))(a2 + 56))(a2, a3, a6, v52) )
            return 32;
          v46 = sub_52DE00(a1 + 416, a2, *(_DWORD *)(a2 + 68) + a3, a6 - *(_DWORD *)(a2 + 68));
          if ( !v46 )
            return 1;
          sub_52D2B0(v46);
          *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
          *(_DWORD *)(a1 + 328) = v46;
          v50 = 0;
        }
        else
        {
LABEL_46:
          if ( !(*(int (__cdecl **)(int, int, int, _DWORD *))(a2 + 56))(a2, a3, a6, v52) )
            return 32;
        }
        if ( !*(_BYTE *)(v51 + 128) || !*(_DWORD *)(a1 + 316) )
          goto LABEL_422;
        v45 = sub_52DE00(v51 + 80, a2, *(_DWORD *)(a2 + 68) + a3, a6 - *(_DWORD *)(a2 + 68));
        if ( !v45 )
          return 1;
        sub_52D2B0(v45);
        *(_DWORD *)(*(_DWORD *)(a1 + 316) + 24) = v45;
        *(_DWORD *)(v51 + 96) = *(_DWORD *)(v51 + 92);
        if ( *(_DWORD *)(a1 + 136) )
          v50 = 0;
        goto LABEL_422;
      case 7:
        if ( *(_DWORD *)(a1 + 84) )
        {
          (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, int))(a1 + 84))(
            *(_DWORD *)(a1 + 4),
            *(_DWORD *)(a1 + 320),
            *(_DWORD *)(a1 + 324),
            *(_DWORD *)(a1 + 328),
            1);
          *(_DWORD *)(a1 + 320) = 0;
          sub_52DB80(a1 + 416);
          v50 = 0;
        }
        goto LABEL_422;
      case 8:
        if ( *(_DWORD *)(a1 + 320) )
        {
          (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 84))(
            *(_DWORD *)(a1 + 4),
            *(_DWORD *)(a1 + 320),
            *(_DWORD *)(a1 + 324),
            *(_DWORD *)(a1 + 328),
            0);
          sub_52DB80(a1 + 416);
          v50 = 0;
        }
        if ( !*(_DWORD *)(a1 + 324) && !*(_BYTE *)(a1 + 489) )
          goto LABEL_76;
        v44 = *(_BYTE *)(v51 + 129);
        *(_BYTE *)(v51 + 129) = 1;
        if ( !*(_DWORD *)(a1 + 492) || !*(_DWORD *)(a1 + 112) )
          goto LABEL_75;
        v43 = (_DWORD *)sub_52D5B0(a1, v51 + 132, &unk_88A2A4, 0x24u);
        if ( !v43 )
          return 1;
        if ( *(_BYTE *)(a1 + 489) )
          v43[5] = *(_DWORD *)(a1 + 360);
        *(_BYTE *)(v51 + 131) = 0;
        if ( !(*(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 112))(
                *(_DWORD *)(a1 + 116),
                0,
                v43[5],
                v43[4],
                v43[6]) )
          return 21;
        if ( *(_BYTE *)(v51 + 131) )
        {
          if ( !*(_BYTE *)(v51 + 130)
            && *(_DWORD *)(a1 + 108)
            && !(*(int (__cdecl **)(_DWORD))(a1 + 108))(*(_DWORD *)(a1 + 4)) )
          {
            return 22;
          }
        }
        else if ( !*(_DWORD *)(a1 + 324) )
        {
          *(_BYTE *)(v51 + 129) = v44;
        }
LABEL_75:
        *(_BYTE *)(a1 + 489) = 0;
LABEL_76:
        if ( *(_DWORD *)(a1 + 88) )
        {
          (*(void (__cdecl **)(_DWORD))(a1 + 88))(*(_DWORD *)(a1 + 4));
          v50 = 0;
        }
        goto LABEL_422;
      case 9:
        if ( (*(int (__cdecl **)(int, int, int))(a2 + 48))(a2, a3, a6) )
        {
          *(_DWORD *)(a1 + 316) = 0;
        }
        else if ( *(_BYTE *)(v51 + 128) )
        {
          v37 = sub_52DE00(v51 + 80, a2, a3, a6);
          if ( !v37 )
            return 1;
          *(_DWORD *)(a1 + 316) = sub_52D5B0(a1, v51, v37, 0x24u);
          if ( !*(_DWORD *)(a1 + 316) )
            return 1;
          if ( **(_DWORD **)(a1 + 316) == v37 )
          {
            *(_DWORD *)(v51 + 96) = *(_DWORD *)(v51 + 92);
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 24) = 0;
            *(_BYTE *)(*(_DWORD *)(a1 + 316) + 33) = 0;
            v15 = !*(_DWORD *)(a1 + 476) && !*(_DWORD *)(a1 + 300);
            *(_BYTE *)(*(_DWORD *)(a1 + 316) + 34) = v15;
            if ( *(_DWORD *)(a1 + 136) )
              v50 = 0;
          }
          else
          {
            *(_DWORD *)(v51 + 92) = *(_DWORD *)(v51 + 96);
            *(_DWORD *)(a1 + 316) = 0;
          }
        }
        else
        {
          *(_DWORD *)(v51 + 92) = *(_DWORD *)(v51 + 96);
          *(_DWORD *)(a1 + 316) = 0;
        }
        goto LABEL_422;
      case 10:
        if ( *(_BYTE *)(v51 + 128) )
        {
          v36 = sub_52DE00(v51 + 80, a2, a3, a6);
          if ( !v36 )
            return 1;
          *(_DWORD *)(a1 + 316) = sub_52D5B0(a1, v51 + 132, v36, 0x24u);
          if ( !*(_DWORD *)(a1 + 316) )
            return 1;
          if ( **(_DWORD **)(a1 + 316) == v36 )
          {
            *(_DWORD *)(v51 + 96) = *(_DWORD *)(v51 + 92);
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 24) = 0;
            *(_BYTE *)(*(_DWORD *)(a1 + 316) + 33) = 1;
            v14 = !*(_DWORD *)(a1 + 476) && !*(_DWORD *)(a1 + 300);
            *(_BYTE *)(*(_DWORD *)(a1 + 316) + 34) = v14;
            if ( *(_DWORD *)(a1 + 136) )
              v50 = 0;
          }
          else
          {
            *(_DWORD *)(v51 + 92) = *(_DWORD *)(v51 + 96);
            *(_DWORD *)(a1 + 316) = 0;
          }
        }
        else
        {
          *(_DWORD *)(v51 + 92) = *(_DWORD *)(v51 + 96);
          *(_DWORD *)(a1 + 316) = 0;
        }
        goto LABEL_422;
      case 11:
        if ( *(_BYTE *)(v51 + 128) && *(_DWORD *)(a1 + 136) )
          v50 = 0;
        goto LABEL_422;
      case 12:
        if ( !*(_BYTE *)(v51 + 128) )
          goto LABEL_422;
        v38 = sub_52BAE0(a1, a2, *(_DWORD *)(a2 + 68) + a3, a6 - *(_DWORD *)(a2 + 68));
        if ( *(_DWORD *)(a1 + 316) )
        {
          *(_DWORD *)(*(_DWORD *)(a1 + 316) + 4) = *(_DWORD *)(v51 + 120);
          *(_DWORD *)(*(_DWORD *)(a1 + 316) + 8) = *(_DWORD *)(v51 + 116) - *(_DWORD *)(v51 + 120);
          *(_DWORD *)(v51 + 120) = *(_DWORD *)(v51 + 116);
          if ( *(_DWORD *)(a1 + 136) )
          {
            *v53 = a3;
            (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 136))(
              *(_DWORD *)(a1 + 4),
              **(_DWORD **)(a1 + 316),
              *(unsigned __int8 *)(*(_DWORD *)(a1 + 316) + 33),
              *(_DWORD *)(*(_DWORD *)(a1 + 316) + 4),
              *(_DWORD *)(*(_DWORD *)(a1 + 316) + 8),
              *(_DWORD *)(a1 + 360),
              0,
              0,
              0);
            v50 = 0;
          }
        }
        else
        {
          *(_DWORD *)(v51 + 116) = *(_DWORD *)(v51 + 120);
        }
        if ( !v38 )
          goto LABEL_422;
        return v38;
      case 13:
        goto LABEL_195;
      case 14:
        goto LABEL_46;
      case 15:
        if ( *(_BYTE *)(v51 + 128) && *(_DWORD *)(a1 + 316) && *(_DWORD *)(a1 + 136) )
        {
          *v53 = a3;
          (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 136))(
            *(_DWORD *)(a1 + 4),
            **(_DWORD **)(a1 + 316),
            *(unsigned __int8 *)(*(_DWORD *)(a1 + 316) + 33),
            0,
            0,
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 20),
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 16),
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 24),
            0);
          v50 = 0;
        }
        goto LABEL_422;
      case 16:
        if ( !*(_BYTE *)(v51 + 128) || !*(_DWORD *)(a1 + 316) )
          goto LABEL_422;
        *(_DWORD *)(*(_DWORD *)(a1 + 316) + 28) = sub_52DE00(v51 + 80, a2, a3, a6);
        if ( !*(_DWORD *)(*(_DWORD *)(a1 + 316) + 28) )
          return 1;
        *(_DWORD *)(v51 + 96) = *(_DWORD *)(v51 + 92);
        if ( *(_DWORD *)(a1 + 92) )
        {
          *v53 = a3;
          (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 92))(
            *(_DWORD *)(a1 + 4),
            **(_DWORD **)(a1 + 316),
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 20),
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 16),
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 24),
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 28));
          v50 = 0;
        }
        else if ( *(_DWORD *)(a1 + 136) )
        {
          *v53 = a3;
          (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 136))(
            *(_DWORD *)(a1 + 4),
            **(_DWORD **)(a1 + 316),
            0,
            0,
            0,
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 20),
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 16),
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 24),
            *(_DWORD *)(*(_DWORD *)(a1 + 316) + 28));
          v50 = 0;
        }
        goto LABEL_422;
      case 17:
        if ( *(_DWORD *)(a1 + 96) )
          v50 = 0;
        goto LABEL_422;
      case 18:
        *(_DWORD *)(a1 + 340) = 0;
        *(_DWORD *)(a1 + 336) = 0;
        if ( !*(_DWORD *)(a1 + 96) )
          goto LABEL_422;
        *(_DWORD *)(a1 + 336) = sub_52DE00(a1 + 416, a2, a3, a6);
        if ( !*(_DWORD *)(a1 + 336) )
          return 1;
        *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
        v50 = 0;
        goto LABEL_422;
      case 19:
        if ( !*(_DWORD *)(a1 + 336) || !*(_DWORD *)(a1 + 96) )
          goto LABEL_265;
        v34 = sub_52DE00(a1 + 416, a2, *(_DWORD *)(a2 + 68) + a3, a6 - *(_DWORD *)(a2 + 68));
        if ( !v34 )
          return 1;
        *v53 = a3;
        (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, int, _DWORD))(a1 + 96))(
          *(_DWORD *)(a1 + 4),
          *(_DWORD *)(a1 + 336),
          *(_DWORD *)(a1 + 360),
          v34,
          *(_DWORD *)(a1 + 340));
        v50 = 0;
LABEL_265:
        sub_52DB80(a1 + 416);
        goto LABEL_422;
      case 20:
        if ( *(_DWORD *)(a1 + 340) && *(_DWORD *)(a1 + 96) )
        {
          *v53 = a3;
          (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 96))(
            *(_DWORD *)(a1 + 4),
            *(_DWORD *)(a1 + 336),
            *(_DWORD *)(a1 + 360),
            0,
            *(_DWORD *)(a1 + 340));
          v50 = 0;
        }
        goto LABEL_265;
      case 21:
        if ( !(*(int (__cdecl **)(int, int, int, _DWORD *))(a2 + 56))(a2, a3, a6, v52) )
          return 32;
        if ( !*(_DWORD *)(a1 + 336) )
          goto LABEL_422;
        v35 = sub_52DE00(a1 + 416, a2, *(_DWORD *)(a2 + 68) + a3, a6 - *(_DWORD *)(a2 + 68));
        if ( !v35 )
          return 1;
        sub_52D2B0(v35);
        *(_DWORD *)(a1 + 340) = v35;
        *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
        v50 = 0;
        goto LABEL_422;
      case 22:
        *(_DWORD *)(a1 + 348) = sub_52C610(a1, a2, a3, a6);
        if ( !*(_DWORD *)(a1 + 348) )
          return 1;
        *(_BYTE *)(a1 + 352) = 0;
        *(_DWORD *)(a1 + 332) = 0;
        *(_BYTE *)(a1 + 353) = 0;
LABEL_108:
        if ( *(_BYTE *)(v51 + 128) && *(_DWORD *)(a1 + 132) )
          v50 = 0;
        goto LABEL_422;
      case 23:
        *(_BYTE *)(a1 + 352) = 1;
        *(_DWORD *)(a1 + 332) = "CDATA";
        goto LABEL_108;
      case 24:
        *(_BYTE *)(a1 + 353) = 1;
        *(_DWORD *)(a1 + 332) = "ID";
        goto LABEL_108;
      case 25:
        *(_DWORD *)(a1 + 332) = "IDREF";
        goto LABEL_108;
      case 26:
        *(_DWORD *)(a1 + 332) = "IDREFS";
        goto LABEL_108;
      case 27:
        *(_DWORD *)(a1 + 332) = "ENTITY";
        goto LABEL_108;
      case 28:
        *(_DWORD *)(a1 + 332) = "ENTITIES";
        goto LABEL_108;
      case 29:
        *(_DWORD *)(a1 + 332) = "NMTOKEN";
        goto LABEL_108;
      case 30:
        *(_DWORD *)(a1 + 332) = "NMTOKENS";
        goto LABEL_108;
      case 31:
      case 32:
        if ( !*(_BYTE *)(v51 + 128) || !*(_DWORD *)(a1 + 132) )
          goto LABEL_422;
        if ( *(_DWORD *)(a1 + 332) )
        {
          v9 = sub_52DD80((_DWORD *)(a1 + 416), "|");
        }
        else
        {
          if ( v49 == 32 )
            v20 = "NOTATION(";
          else
            v20 = "(";
          v9 = sub_52DD80((_DWORD *)(a1 + 416), v20);
        }
        if ( !v9 )
          return 1;
        if ( !sub_52DC70(a1 + 416, a2, a3, a6) )
          return 1;
        *(_DWORD *)(a1 + 332) = *(_DWORD *)(a1 + 432);
        v50 = 0;
        goto LABEL_422;
      case 33:
        if ( *(_BYTE *)(v51 + 128) && *(_DWORD *)(a1 + 132) )
          v50 = 0;
        goto LABEL_422;
      case 34:
        *(_DWORD *)(a1 + 344) = sub_52E510(a1, a2, a3, a6);
        if ( *(_DWORD *)(a1 + 344) )
          goto LABEL_108;
        return 1;
      case 35:
      case 36:
        if ( !*(_BYTE *)(v51 + 128) )
          goto LABEL_422;
        if ( !sub_52C330(
                *(_DWORD *)(a1 + 344),
                *(_DWORD *)(a1 + 348),
                *(_BYTE *)(a1 + 352),
                *(_BYTE *)(a1 + 353),
                0,
                a1) )
          return 1;
        if ( !*(_DWORD *)(a1 + 132) || !*(_DWORD *)(a1 + 332) )
          goto LABEL_422;
        if ( **(_BYTE **)(a1 + 332) != 40
          && (**(_BYTE **)(a1 + 332) != 78 || *(_BYTE *)(*(_DWORD *)(a1 + 332) + 1) != 79) )
        {
          goto LABEL_146;
        }
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_52DE70(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 41;
          v19 = 1;
        }
        else
        {
          v19 = 0;
        }
        if ( !v19 )
          return 1;
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_52DE70(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 0;
          v18 = 1;
        }
        else
        {
          v18 = 0;
        }
        if ( !v18 )
          return 1;
        *(_DWORD *)(a1 + 332) = *(_DWORD *)(a1 + 432);
        *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
LABEL_146:
        *v53 = a3;
        (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, bool))(a1 + 132))(
          *(_DWORD *)(a1 + 4),
          **(_DWORD **)(a1 + 344),
          **(_DWORD **)(a1 + 348),
          *(_DWORD *)(a1 + 332),
          0,
          v49 == 36);
        sub_52DB80(a1 + 416);
        v50 = 0;
        goto LABEL_422;
      case 37:
      case 38:
        if ( !*(_BYTE *)(v51 + 128) )
          goto LABEL_422;
        v39 = sub_52B440(a1, a2, *(_BYTE *)(a1 + 352), *(_DWORD *)(a2 + 68) + a3, a6 - *(_DWORD *)(a2 + 68), v51 + 80);
        if ( v39 )
          return v39;
        v40 = *(_DWORD *)(v51 + 96);
        *(_DWORD *)(v51 + 96) = *(_DWORD *)(v51 + 92);
        if ( !sub_52C330(*(_DWORD *)(a1 + 344), *(_DWORD *)(a1 + 348), *(_BYTE *)(a1 + 352), 0, v40, a1) )
          return 1;
        if ( !*(_DWORD *)(a1 + 132) || !*(_DWORD *)(a1 + 332) )
          goto LABEL_422;
        if ( **(_BYTE **)(a1 + 332) != 40
          && (**(_BYTE **)(a1 + 332) != 78 || *(_BYTE *)(*(_DWORD *)(a1 + 332) + 1) != 79) )
        {
          goto LABEL_170;
        }
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_52DE70(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 41;
          v17 = 1;
        }
        else
        {
          v17 = 0;
        }
        if ( !v17 )
          return 1;
        if ( *(_DWORD *)(a1 + 428) != *(_DWORD *)(a1 + 424) || (unsigned __int8)sub_52DE70(a1 + 416) )
        {
          *(_BYTE *)(*(_DWORD *)(a1 + 428))++ = 0;
          v16 = 1;
        }
        else
        {
          v16 = 0;
        }
        if ( !v16 )
          return 1;
        *(_DWORD *)(a1 + 332) = *(_DWORD *)(a1 + 432);
        *(_DWORD *)(a1 + 432) = *(_DWORD *)(a1 + 428);
LABEL_170:
        *v53 = a3;
        (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, int, bool))(a1 + 132))(
          *(_DWORD *)(a1 + 4),
          **(_DWORD **)(a1 + 344),
          **(_DWORD **)(a1 + 348),
          *(_DWORD *)(a1 + 332),
          v40,
          v49 == 38);
        sub_52DB80(a1 + 416);
        v50 = 0;
        goto LABEL_422;
      case 39:
        if ( *(_DWORD *)(a1 + 128) )
          v50 = 0;
        goto LABEL_422;
      case 40:
        if ( !*(_DWORD *)(a1 + 128) )
          goto LABEL_422;
        *(_DWORD *)(a1 + 344) = sub_52E510(a1, a2, a3, a6);
        if ( !*(_DWORD *)(a1 + 344) )
          return 1;
        *(_DWORD *)(v51 + 180) = 0;
        *(_DWORD *)(v51 + 176) = 0;
        *(_BYTE *)(v51 + 160) = 1;
        v50 = 0;
        goto LABEL_422;
      case 41:
      case 42:
        if ( !*(_BYTE *)(v51 + 160) )
          goto LABEL_422;
        if ( !*(_DWORD *)(a1 + 128) )
          goto LABEL_360;
        v26 = (_DWORD *)(*(int (__cdecl **)(int))(a1 + 12))(20);
        if ( !v26 )
          return 1;
        v26[1] = 0;
        v26[2] = 0;
        v26[3] = 0;
        v26[4] = 0;
        *v26 = (v49 == 41) + 1;
        *v53 = a3;
        (*(void (__cdecl **)(_DWORD, _DWORD, _DWORD *))(a1 + 128))(*(_DWORD *)(a1 + 4), **(_DWORD **)(a1 + 344), v26);
        v50 = 0;
LABEL_360:
        *(_BYTE *)(v51 + 160) = 0;
        goto LABEL_422;
      case 43:
        if ( *(_BYTE *)(v51 + 160) )
        {
          *(_DWORD *)(28 * *(_DWORD *)(*(_DWORD *)(v51 + 184) + 4 * *(_DWORD *)(v51 + 180) - 4) + *(_DWORD *)(v51 + 164)) = 3;
          if ( *(_DWORD *)(a1 + 128) )
            v50 = 0;
        }
        goto LABEL_422;
      case 44:
        if ( *(_DWORD *)(a1 + 260) < *(_DWORD *)(a1 + 468) )
          goto LABEL_293;
        if ( *(_DWORD *)(a1 + 468) )
        {
          *(_DWORD *)(a1 + 468) *= 2;
          v32 = (*(int (__cdecl **)(_DWORD, _DWORD))(a1 + 16))(*(_DWORD *)(a1 + 464), *(_DWORD *)(a1 + 468));
          if ( !v32 )
            return 1;
          *(_DWORD *)(a1 + 464) = v32;
          if ( *(_DWORD *)(v51 + 184) )
          {
            v31 = (*(int (__cdecl **)(_DWORD, int))(a1 + 16))(*(_DWORD *)(v51 + 184), 4 * *(_DWORD *)(a1 + 468));
            if ( !v31 )
              return 1;
            *(_DWORD *)(v51 + 184) = v31;
          }
        }
        else
        {
          *(_DWORD *)(a1 + 468) = 32;
          *(_DWORD *)(a1 + 464) = (*(int (__cdecl **)(int))(a1 + 12))(32);
          if ( !*(_DWORD *)(a1 + 464) )
            return 1;
        }
LABEL_293:
        *(_BYTE *)(*(_DWORD *)(a1 + 464) + *(_DWORD *)(a1 + 260)) = 0;
        if ( !*(_BYTE *)(v51 + 160) )
          goto LABEL_422;
        v30 = sub_52E120(a1);
        if ( v30 < 0 )
          return 1;
        *(_DWORD *)(*(_DWORD *)(v51 + 184) + 4 * (*(_DWORD *)(v51 + 180))++) = v30;
        *(_DWORD *)(28 * v30 + *(_DWORD *)(v51 + 164)) = 6;
        if ( *(_DWORD *)(a1 + 128) )
          v50 = 0;
        goto LABEL_422;
      case 45:
        v55 = 0;
        goto LABEL_387;
      case 46:
        v55 = 2;
        goto LABEL_387;
      case 47:
        v55 = 1;
        goto LABEL_387;
      case 48:
        v55 = 3;
LABEL_387:
        if ( !*(_BYTE *)(v51 + 160) )
          goto LABEL_422;
        if ( *(_DWORD *)(a1 + 128) )
          v50 = 0;
        --*(_DWORD *)(v51 + 180);
        *(_DWORD *)(*(_DWORD *)(v51 + 164) + 28 * *(_DWORD *)(*(_DWORD *)(v51 + 184) + 4 * *(_DWORD *)(v51 + 180)) + 4) = v55;
        if ( *(_DWORD *)(v51 + 180) )
          goto LABEL_422;
        if ( v50 )
          goto LABEL_395;
        v21 = sub_52E310(a1);
        if ( !v21 )
          return 1;
        *v53 = a3;
        (*(void (__cdecl **)(_DWORD, _DWORD, int))(a1 + 128))(*(_DWORD *)(a1 + 4), **(_DWORD **)(a1 + 344), v21);
LABEL_395:
        *(_BYTE *)(v51 + 160) = 0;
        *(_DWORD *)(v51 + 168) = 0;
        goto LABEL_422;
      case 49:
        if ( *(_BYTE *)(*(_DWORD *)(a1 + 464) + *(_DWORD *)(a1 + 260)) == 44 )
          return 2;
        if ( *(_BYTE *)(v51 + 160) )
        {
          if ( !*(_BYTE *)(*(_DWORD *)(a1 + 464) + *(_DWORD *)(a1 + 260))
            && *(_DWORD *)(28 * *(_DWORD *)(*(_DWORD *)(v51 + 184) + 4 * *(_DWORD *)(v51 + 180) - 4)
                         + *(_DWORD *)(v51 + 164)) != 3 )
          {
            *(_DWORD *)(28 * *(_DWORD *)(*(_DWORD *)(v51 + 184) + 4 * *(_DWORD *)(v51 + 180) - 4)
                      + *(_DWORD *)(v51 + 164)) = 5;
            if ( *(_DWORD *)(a1 + 128) )
              v50 = 0;
          }
        }
        *(_BYTE *)(*(_DWORD *)(a1 + 464) + *(_DWORD *)(a1 + 260)) = 124;
        goto LABEL_422;
      case 50:
        if ( *(_BYTE *)(*(_DWORD *)(a1 + 464) + *(_DWORD *)(a1 + 260)) == 124 )
          return 2;
        *(_BYTE *)(*(_DWORD *)(a1 + 464) + *(_DWORD *)(a1 + 260)) = 44;
        if ( *(_BYTE *)(v51 + 160) && *(_DWORD *)(a1 + 128) )
          v50 = 0;
        goto LABEL_422;
      case 51:
        v54 = 0;
        goto LABEL_370;
      case 52:
        v54 = 2;
        goto LABEL_370;
      case 53:
        v54 = 1;
        goto LABEL_370;
      case 54:
        v54 = 3;
LABEL_370:
        if ( !*(_BYTE *)(v51 + 160) )
          goto LABEL_422;
        if ( v54 )
          v12 = a6 - *(_DWORD *)(a2 + 68);
        else
          v12 = a6;
        v25 = sub_52E120(a1);
        if ( v25 < 0 )
          return 1;
        *(_DWORD *)(28 * v25 + *(_DWORD *)(v51 + 164)) = 4;
        *(_DWORD *)(*(_DWORD *)(v51 + 164) + 28 * v25 + 4) = v54;
        v22 = (int *)sub_52E510(a1, a2, a3, v12);
        if ( !v22 )
          return 1;
        v23 = *v22;
        *(_DWORD *)(*(_DWORD *)(v51 + 164) + 28 * v25 + 8) = *v22;
        v24 = 0;
        do
        {
          v10 = *(char *)(v24 + v23);
          ++v24;
        }
        while ( v10 );
        *(_DWORD *)(v51 + 168) += v24;
        if ( *(_DWORD *)(a1 + 128) )
          v50 = 0;
        goto LABEL_422;
      case 55:
        if ( !sub_52BFC0(a1, a2, a3, a6) )
          return 1;
        v50 = 0;
        goto LABEL_422;
      case 56:
        if ( !sub_52C190(a1, a2, a3, a6) )
          return 1;
        v50 = 0;
LABEL_422:
        if ( v50 && *(_DWORD *)(a1 + 80) )
          sub_52C240(a1, a2, a3, a6);
        v11 = *(_DWORD *)(a1 + 480);
        if ( v11 == 2 )
          return 35;
        if ( v11 == 3 )
        {
          *a7 = a6;
          return 0;
        }
        a3 = a6;
        a5 = (*(int (__cdecl **)(int, int, int, int *))a2)(a2, a6, a4, &a6);
        break;
      case 57:
        v47 = sub_5281C0(a1, 1, a3, a6);
        if ( v47 )
          return v47;
        a2 = *(_DWORD *)(a1 + 144);
        v50 = 0;
        goto LABEL_422;
      case 58:
        if ( *(_DWORD *)(a1 + 80) )
          sub_52C240(a1, a2, a3, a6);
        v50 = 0;
        v33 = sub_52AC30(a1, a2, &a6, a4, a7, a8);
        if ( v33 )
          return v33;
        if ( a6 )
          goto LABEL_422;
        *(_DWORD *)(a1 + 280) = sub_52ABB0;
        return 0;
      case 59:
      case 60:
        *(_BYTE *)(v51 + 129) = 1;
        if ( *(_DWORD *)(a1 + 492) )
        {
          v28 = sub_52DE00(v51 + 80, a2, *(_DWORD *)(a2 + 68) + a3, a6 - *(_DWORD *)(a2 + 68));
          if ( !v28 )
            return 1;
          v29 = sub_52D5B0(a1, v51 + 132, v28, 0);
          *(_DWORD *)(v51 + 92) = *(_DWORD *)(v51 + 96);
          if ( *(_DWORD *)(a1 + 272)
            && (!*(_BYTE *)(v51 + 130)
              ? (v13 = *(unsigned __int8 *)(v51 + 129) == 0)
              : (v13 = *(_DWORD *)(a1 + 300) == 0),
                v13) )
          {
            if ( !v29 )
              return 11;
            if ( !*(_BYTE *)(v29 + 34) )
              return 24;
          }
          else if ( !v29 )
          {
            *(_BYTE *)(v51 + 128) = *(_BYTE *)(v51 + 130);
            if ( v49 == 60 && *(_DWORD *)(a1 + 120) )
            {
              (*(void (__cdecl **)(_DWORD, int, int))(a1 + 120))(*(_DWORD *)(a1 + 4), v28, 1);
              v50 = 0;
            }
            goto LABEL_422;
          }
          if ( *(_BYTE *)(v29 + 32) )
            return 12;
          if ( *(_DWORD *)(v29 + 4) )
          {
            v27 = sub_52B030(a1, v29, v49 == 60);
            if ( v27 )
              return v27;
            v50 = 0;
            goto LABEL_422;
          }
          if ( !*(_DWORD *)(a1 + 112) )
          {
            *(_BYTE *)(v51 + 128) = *(_BYTE *)(v51 + 130);
            goto LABEL_422;
          }
          *(_BYTE *)(v51 + 131) = 0;
          *(_BYTE *)(v29 + 32) = 1;
          if ( !(*(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(a1 + 112))(
                  *(_DWORD *)(a1 + 116),
                  0,
                  *(_DWORD *)(v29 + 20),
                  *(_DWORD *)(v29 + 16),
                  *(_DWORD *)(v29 + 24)) )
          {
            *(_BYTE *)(v29 + 32) = 0;
            return 21;
          }
          *(_BYTE *)(v29 + 32) = 0;
          v50 = 0;
          if ( !*(_BYTE *)(v51 + 131) )
          {
            *(_BYTE *)(v51 + 128) = *(_BYTE *)(v51 + 130);
            goto LABEL_422;
          }
        }
        else
        {
          *(_BYTE *)(v51 + 128) = *(_BYTE *)(v51 + 130);
        }
        if ( !*(_BYTE *)(v51 + 130)
          && *(_DWORD *)(a1 + 108)
          && !(*(int (__cdecl **)(_DWORD))(a1 + 108))(*(_DWORD *)(a1 + 4)) )
        {
          return 22;
        }
        goto LABEL_422;
      default:
        goto LABEL_422;
    }
  }
  if ( !a8 || !a5 )
  {
    switch ( a5 )
    {
      case -15:
        a5 = -a5;
        goto LABEL_23;
      case -4:
        if ( a2 == *(_DWORD *)(a1 + 144) || *(_BYTE *)(*(_DWORD *)(a1 + 300) + 20) )
        {
          if ( !*(_BYTE *)(a1 + 488) && a2 == *(_DWORD *)(a1 + 144) )
          {
            return 3;
          }
          else if ( (*(int (__cdecl **)(int, int, int, int, int))(a1 + 256))(a1 + 256, -4, a4, a4, a2) == -1 )
          {
            return 29;
          }
          else
          {
            *a7 = a3;
            return 0;
          }
        }
        else
        {
          *a7 = a3;
          return 0;
        }
      case -2:
        return 6;
      case -1:
        return 5;
      case 0:
        *v52 = a6;
        return 4;
      default:
        a5 = -a5;
        a6 = a4;
        goto LABEL_23;
    }
  }
  *a7 = a3;
  return 0;
}
