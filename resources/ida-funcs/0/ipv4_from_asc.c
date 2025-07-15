int __usercall ipv4_from_asc@<eax>(unsigned __int8 *v4@<esi>, int a2@<ebx>, char *in)
{
  unsigned __int8 dl4; // dl
  unsigned __int8 v5; // cl
  unsigned __int8 v6; // al
  unsigned int v7; // [esp+0h] [ebp-10h] BYREF
  unsigned int v8; // [esp+4h] [ebp-Ch] BYREF
  unsigned int v9; // [esp+8h] [ebp-8h] BYREF
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  if ( sscanf(a2, in, "%d.%d.%d.%d", &v7, &v8, &v9, &v10) != 4 )
    return 0;
  if ( v7 > 0xFF )
    return 0;
  dl4 = v8;
  if ( v8 > 0xFF )
    return 0;
  v5 = v9;
  if ( v9 > 0xFF )
    return 0;
  v6 = v10;
  if ( v10 > 0xFF )
    return 0;
  *v4 = v7;
  v4[3] = v6;
  v4[1] = dl4;
  v4[2] = v5;
  return 1;
}
