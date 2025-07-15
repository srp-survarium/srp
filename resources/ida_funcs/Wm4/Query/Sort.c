int *__cdecl Wm4::Query::Sort(int *iV0, int *iV1, int *iV2)
{
  int *result; // eax
  int v4; // ebx
  int v5; // ebp
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // esi
  int v10; // edx
  int aiValue[3]; // [esp+10h] [ebp-Ch]

  result = iV0;
  v4 = *iV0;
  v5 = *iV1;
  if ( *iV0 >= *iV1 )
  {
    result = iV2;
    v6 = *iV2;
    if ( *iV2 >= v5 )
    {
      v7 = 1;
      if ( v6 < v4 )
      {
        v8 = 2;
        v9 = 0;
        LOBYTE(result) = 1;
        goto LABEL_13;
      }
      v8 = 0;
      v9 = 2;
    }
    else
    {
      v7 = 2;
      v8 = 1;
      v9 = 0;
    }
    goto LABEL_12;
  }
  v6 = *iV2;
  if ( *iV2 >= v4 )
  {
    v7 = 0;
    if ( v6 >= v5 )
    {
      v8 = 1;
      v9 = 2;
      LOBYTE(result) = 1;
      goto LABEL_13;
    }
    v8 = 2;
    v9 = 1;
LABEL_12:
    LOBYTE(result) = 0;
    goto LABEL_13;
  }
  v7 = 2;
  v8 = 0;
  v9 = 1;
  LOBYTE(result) = 1;
LABEL_13:
  aiValue[2] = v6;
  aiValue[0] = v4;
  aiValue[1] = v5;
  v10 = aiValue[v8];
  *iV0 = aiValue[v7];
  *iV1 = v10;
  *iV2 = aiValue[v9];
  return result;
}


int __cdecl Wm4::Query::Sort(int *iV0, int *iV1)
{
  int v2; // esi
  int v3; // edx
  int v4; // ecx
  int result; // eax
  int v6; // edx
  int aiValue[2]; // [esp+10h] [ebp-8h]

  v2 = *iV0;
  if ( *iV0 >= *iV1 )
  {
    v3 = 0;
    v4 = 1;
    LOBYTE(result) = 0;
  }
  else
  {
    v3 = 1;
    v4 = 0;
    LOBYTE(result) = 1;
  }
  aiValue[1] = *iV1;
  aiValue[0] = v2;
  v6 = aiValue[v3];
  *iV0 = aiValue[v4];
  *iV1 = v6;
  return result;
}
