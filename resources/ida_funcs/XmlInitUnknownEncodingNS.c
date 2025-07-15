_DWORD *__cdecl XmlInitUnknownEncodingNS(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *inited; // [esp+0h] [ebp-4h]

  inited = XmlInitUnknownEncoding(a1, a2, a3, a4);
  if ( inited )
    *((_BYTE *)inited + 134) = 23;
  return inited;
}
