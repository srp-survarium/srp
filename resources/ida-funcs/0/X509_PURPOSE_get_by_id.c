int __usercall X509_PURPOSE_get_by_id@<eax>(int a1@<edi>, int purpose)
{
  int v3; // eax
  int v4[7]; // [esp+0h] [ebp-1Ch] BYREF

  if ( (unsigned int)(purpose - 1) <= 8 )
    return purpose - 1;
  v4[0] = purpose;
  if ( !xptable )
    return -1;
  v3 = sk_find(a1, &xptable->stack, (char *)v4);
  if ( v3 == -1 )
    return -1;
  else
    return v3 + 9;
}
