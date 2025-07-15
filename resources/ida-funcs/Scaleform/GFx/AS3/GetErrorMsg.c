const char *__cdecl Scaleform::GFx::AS3::GetErrorMsg(int ind)
{
  int v1; // edx
  int v2; // esi
  int v3; // eax
  int v4; // ecx

  v1 = 0;
  v2 = 145;
  while ( 1 )
  {
    v3 = (v2 + v1) >> 1;
    v4 = errorMappingTable[v3];
    if ( ind == v4 )
      break;
    if ( ind >= v4 )
      v1 = v3 + 1;
    else
      v2 = v3 - 1;
    if ( v1 > v2 )
      goto LABEL_9;
  }
  v1 = (v2 + v1) >> 1;
LABEL_9:
  if ( errorMappingTable[v1] == ind )
    return errorConstants[v1];
  else
    return 0;
}
