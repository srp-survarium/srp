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
