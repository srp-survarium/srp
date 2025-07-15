int __cdecl Wm4::Query::Sort(int *iV0, int *iV1, int *iV2)
{
  int v3; // ebx
  int result; // eax
  int v5; // edi
  int v6; // edx
  int v7; // ecx
  int v8; // esi
  int v9; // ebx
  _DWORD v10[3]; // [esp+Ch] [ebp-Ch]

  v3 = *iV0;
  result = *iV1;
  v5 = *iV2;
  if ( *iV0 >= *iV1 )
  {
    if ( v5 >= result )
    {
      v7 = 1;
      if ( v5 < v3 )
      {
        v6 = 2;
        v8 = 0;
        goto LABEL_11;
      }
      v6 = 0;
      v8 = 2;
    }
    else
    {
      v6 = 1;
      v7 = 2;
      v8 = 0;
    }
    goto LABEL_13;
  }
  if ( v5 >= v3 )
  {
    v7 = 0;
    if ( v5 >= result )
    {
      v6 = 1;
      v8 = 2;
      goto LABEL_11;
    }
    v6 = 2;
    v8 = 1;
LABEL_13:
    LOBYTE(result) = 0;
    goto LABEL_14;
  }
  v6 = 0;
  v7 = 2;
  v8 = 1;
LABEL_11:
  LOBYTE(result) = 1;
LABEL_14:
  v10[0] = *iV0;
  v9 = *iV1;
  v10[2] = v5;
  v10[1] = v9;
  *iV0 = v10[v7];
  *iV1 = v10[v6];
  *iV2 = v10[v8];
  return result;
}


bool __cdecl Wm4::Query::Sort(int *iV0, int *iV1)
{
  int v2; // edi
  int v3; // ecx
  int v4; // edx
  bool result; // al
  _DWORD v6[2]; // [esp+Ch] [ebp-8h]

  v2 = *iV1;
  v3 = 0;
  v4 = 0;
  if ( *iV0 >= *iV1 )
  {
    v3 = 1;
    result = 0;
  }
  else
  {
    v4 = 1;
    result = 1;
  }
  v6[0] = *iV0;
  v6[1] = v2;
  *iV0 = v6[v3];
  *iV1 = v6[v4];
  return result;
}
