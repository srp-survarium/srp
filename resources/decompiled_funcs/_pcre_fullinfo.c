int __cdecl pcre_fullinfo(_DWORD *a1, _DWORD *a2, int a3, int *a4)
{
  int result; // eax
  int v5; // [esp+0h] [ebp-7Ch]
  BOOL v6; // [esp+4h] [ebp-78h]
  int v7; // [esp+8h] [ebp-74h]
  int v8; // [esp+Ch] [ebp-70h]
  int v9; // [esp+10h] [ebp-6Ch]
  int v10; // [esp+14h] [ebp-68h]
  _DWORD *v11; // [esp+1Ch] [ebp-60h]
  char v12[40]; // [esp+20h] [ebp-5Ch] BYREF
  int *v13; // [esp+48h] [ebp-34h]
  _BYTE v14[44]; // [esp+4Ch] [ebp-30h] BYREF

  v11 = a1;
  v13 = 0;
  if ( !a1 || !a4 )
    return -2;
  if ( a2 && (*a2 & 1) != 0 )
    v13 = (int *)a2[1];
  if ( *a1 != 1346589253 )
  {
    v11 = (_DWORD *)_pcre_try_flipped(a1, v12, v13, v14);
    if ( !v11 )
      return -4;
    if ( v13 )
      v13 = (int *)v14;
  }
  switch ( a3 )
  {
    case 0:
      *a4 = v11[2] & 0x27FC7A7F;
      goto LABEL_54;
    case 1:
      *a4 = v11[1];
      goto LABEL_54;
    case 2:
      *a4 = *((unsigned __int16 *)v11 + 8);
      goto LABEL_54;
    case 3:
      *a4 = *((unsigned __int16 *)v11 + 9);
      goto LABEL_54;
    case 4:
      if ( (v11[3] & 2) != 0 )
        v9 = *((unsigned __int16 *)v11 + 10);
      else
        v9 = ((v11[3] & 8) != 0) - 2;
      *a4 = v9;
      goto LABEL_54;
    case 5:
      if ( v13 && (v13[1] & 1) != 0 )
        v8 = a2[1] + 8;
      else
        v8 = 0;
      *a4 = v8;
      goto LABEL_54;
    case 6:
      if ( (v11[3] & 4) != 0 )
        v5 = *((unsigned __int16 *)v11 + 11);
      else
        v5 = -1;
      *a4 = v5;
      goto LABEL_54;
    case 7:
      *a4 = *((unsigned __int16 *)v11 + 13);
      goto LABEL_54;
    case 8:
      *a4 = *((unsigned __int16 *)v11 + 14);
      goto LABEL_54;
    case 9:
      *a4 = (int)v11 + *((unsigned __int16 *)v11 + 12);
      goto LABEL_54;
    case 10:
      if ( v13 )
        v10 = *v13;
      else
        v10 = 0;
      *a4 = v10;
      goto LABEL_54;
    case 11:
      *a4 = (int)&_pcre_default_tables;
      goto LABEL_54;
    case 12:
      *a4 = (v11[3] & 1) == 0;
      goto LABEL_54;
    case 13:
      *a4 = (v11[3] & 0x10) != 0;
      goto LABEL_54;
    case 14:
      *a4 = (v11[3] & 0x20) != 0;
      goto LABEL_54;
    case 15:
      if ( v13 && (v13[1] & 2) != 0 )
        v7 = v13[10];
      else
        v7 = -1;
      *a4 = v7;
      goto LABEL_54;
    case 16:
      v6 = a2 && (*a2 & 0x40) != 0 && a2[7];
      *a4 = v6;
      goto LABEL_54;
    case 17:
      *a4 = 0;
LABEL_54:
      result = 0;
      break;
    default:
      result = -3;
      break;
  }
  return result;
}
