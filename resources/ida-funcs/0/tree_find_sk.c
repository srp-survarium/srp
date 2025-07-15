X509_POLICY_NODE_st *__usercall tree_find_sk@<eax>(
        int a1@<edi>,
        stack_st_X509_POLICY_NODE *nodes,
        const asn1_object_st *id)
{
  int v3; // eax
  char v5[12]; // [esp+4h] [ebp-1Ch] BYREF
  char v6; // [esp+10h] [ebp-10h] BYREF
  const asn1_object_st *v7; // [esp+14h] [ebp-Ch]

  v7 = id;
  *(_DWORD *)v5 = &v6;
  v3 = sk_find(a1, &nodes->stack, v5);
  if ( v3 == -1 )
    return 0;
  else
    return (X509_POLICY_NODE_st *)sk_value(&nodes->stack, v3);
}
