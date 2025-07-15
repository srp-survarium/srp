int __cdecl sub_654FE0(int a1, unsigned __int8 *a2, char *a3)
{
  int v3; // eax
  int v4; // edx
  int result; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // [esp+4h] [ebp-Ch]
  int v17; // [esp+Ch] [ebp-4h]
  char *v18; // [esp+1Ch] [ebp+Ch]
  char *v19; // [esp+1Ch] [ebp+Ch]
  char *v20; // [esp+20h] [ebp+10h]
  char *v21; // [esp+20h] [ebp+10h]

  while ( 2 )
  {
    if ( a2[1] )
      v17 = sub_64FDE0(a2[1], *a2);
    else
      v17 = *(unsigned __int8 *)(a1 + *a2 + 76);
    switch ( v17 )
    {
      case 5:
        goto LABEL_9;
      case 6:
        goto LABEL_7;
      case 7:
        v3 = *a3;
        v4 = (char)*a2;
        ++a3;
        ++a2;
        if ( v4 != v3 )
          return 0;
LABEL_7:
        v6 = *a3;
        v7 = (char)*a2;
        ++a3;
        ++a2;
        if ( v7 != v6 )
          return 0;
LABEL_9:
        v8 = *a3;
        v9 = (char)*a2;
        v20 = a3 + 1;
        v18 = (char *)(a2 + 1);
        if ( v9 != v8 )
          return 0;
        v10 = *v20;
        v11 = *v18;
        a3 = v20 + 1;
        a2 = (unsigned __int8 *)(v18 + 1);
        if ( v11 == v10 )
          continue;
        return 0;
      case 22:
      case 23:
      case 24:
      case 25:
      case 26:
      case 27:
      case 29:
        v12 = (char)*a2;
        v13 = *a3;
        v19 = (char *)(a2 + 1);
        v21 = a3 + 1;
        if ( v13 != v12 )
          return 0;
        v14 = *v19;
        v15 = *v21;
        a2 = (unsigned __int8 *)(v19 + 1);
        a3 = v21 + 1;
        if ( v15 == v14 )
          continue;
        return 0;
      default:
        if ( a3[1] )
          v16 = sub_64FDE0(a3[1], *a3);
        else
          v16 = *(unsigned __int8 *)(a1 + (unsigned __int8)*a3 + 76);
        switch ( v16 )
        {
          case 5:
          case 6:
          case 7:
          case 22:
          case 23:
          case 24:
          case 25:
          case 26:
          case 27:
          case 29:
            result = 0;
            break;
          default:
            result = 1;
            break;
        }
        return result;
    }
  }
}
