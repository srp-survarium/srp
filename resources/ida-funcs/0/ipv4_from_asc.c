int __usercall ipv4_from_asc@<eax>(unsigned __int8 *v4@<esi>, char *in)
{
  unsigned __int8 v3; // dl
  unsigned __int8 cl5; // cl
  unsigned __int8 v5; // al
  unsigned int v6; // [esp+0h] [ebp-10h] BYREF
  unsigned int v7; // [esp+4h] [ebp-Ch] BYREF
  unsigned int v8; // [esp+8h] [ebp-8h] BYREF
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  if ( sscanf(in, "%d.%d.%d.%d", &v6, &v7, &v8, &v9) != 4 )
    return 0;
  if ( v6 > 0xFF )
    return 0;
  v3 = v7;
  if ( v7 > 0xFF )
    return 0;
  cl5 = v8;
  if ( v8 > 0xFF )
    return 0;
  v5 = v9;
  if ( v9 > 0xFF )
    return 0;
  *v4 = v6;
  v4[3] = v5;
  v4[1] = v3;
  v4[2] = cl5;
  return 1;
}
