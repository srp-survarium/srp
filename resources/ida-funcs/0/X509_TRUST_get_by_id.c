int __usercall X509_TRUST_get_by_id@<eax>(int a1@<edi>, int id)
{
  int v3; // eax
  int v4[6]; // [esp+0h] [ebp-18h] BYREF

  if ( (unsigned int)(id - 1) <= 7 )
    return id - 1;
  v4[0] = id;
  if ( !trtable )
    return -1;
  v3 = sk_find(a1, &trtable->stack, (char *)v4);
  if ( v3 == -1 )
    return -1;
  else
    return v3 + 8;
}
