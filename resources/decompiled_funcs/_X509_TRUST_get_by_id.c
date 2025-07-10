int __cdecl X509_TRUST_get_by_id(int id)
{
  int v2; // eax
  int data[6]; // [esp+0h] [ebp-18h] BYREF

  if ( (unsigned int)(id - 1) <= 7 )
    return id - 1;
  data[0] = id;
  if ( !trtable )
    return -1;
  v2 = sk_find(&trtable->stack, (char *)data);
  if ( v2 == -1 )
    return -1;
  else
    return v2 + 8;
}
