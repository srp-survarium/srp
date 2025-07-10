X509_POLICY_NODE_st *__cdecl tree_find_sk(stack_st_X509_POLICY_NODE *nodes, const asn1_object_st *id)
{
  int v2; // eax
  char data[12]; // [esp+4h] [ebp-1Ch] BYREF
  char v5; // [esp+10h] [ebp-10h] BYREF
  const asn1_object_st *v6; // [esp+14h] [ebp-Ch]

  v6 = id;
  *(_DWORD *)data = &v5;
  v2 = sk_find(&nodes->stack, data);
  if ( v2 == -1 )
    return 0;
  else
    return (X509_POLICY_NODE_st *)sk_value(&nodes->stack, v2);
}
