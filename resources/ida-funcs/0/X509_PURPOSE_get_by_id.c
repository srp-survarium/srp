int __cdecl X509_PURPOSE_get_by_id(int purpose)
{
  int v2; // eax
  int data[7]; // [esp+0h] [ebp-1Ch] BYREF

  if ( (unsigned int)(purpose - 1) <= 8 )
    return purpose - 1;
  data[0] = purpose;
  if ( !xptable )
    return -1;
  v2 = sk_find(&xptable->stack, (char *)data);
  if ( v2 == -1 )
    return -1;
  else
    return v2 + 9;
}
