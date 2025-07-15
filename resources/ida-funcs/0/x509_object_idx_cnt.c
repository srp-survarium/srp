int __usercall x509_object_idx_cnt@<eax>(
        stack_st_X509_OBJECT *h@<edi>,
        X509_name_st *name@<ecx>,
        int *pnmatch@<ebx>,
        int type)
{
  const x509_st *v5; // eax
  int v6; // eax
  int v7; // ebp
  int v8; // esi
  char *v9; // eax
  unsigned int v10; // eax
  int v11; // [esp+0h] [ebp-120h] BYREF
  const X509_crl_st *v12; // [esp+4h] [ebp-11Ch]
  char v13; // [esp+Ch] [ebp-114h] BYREF
  X509_name_st *v14; // [esp+14h] [ebp-10Ch]
  char v15; // [esp+34h] [ebp-ECh] BYREF
  X509_name_st *v16; // [esp+48h] [ebp-D8h]
  char *v17; // [esp+68h] [ebp-B8h] BYREF
  char *v18; // [esp+B4h] [ebp-6Ch] BYREF

  v11 = type;
  if ( type == 1 )
  {
    v5 = (const x509_st *)&v18;
    v18 = &v15;
    v16 = name;
  }
  else
  {
    if ( type != 2 )
      return -1;
    v5 = (const x509_st *)&v17;
    v17 = &v13;
    v14 = name;
  }
  v12 = (const X509_crl_st *)v5;
  v6 = sk_find((int)h, &h->stack, (char *)&v11);
  v7 = v6;
  if ( v6 >= 0 )
  {
    if ( pnmatch )
    {
      *pnmatch = 1;
      v8 = v6 + 1;
      if ( v6 + 1 < sk_num(&h->stack) )
      {
        while ( 1 )
        {
          v9 = sk_value(&h->stack, v8);
          if ( *(_DWORD *)v9 != v11 )
            return v7;
          if ( *(_DWORD *)v9 == 1 )
            break;
          if ( *(_DWORD *)v9 == 2 )
          {
            v10 = X509_CRL_cmp(*((const X509_crl_st **)v9 + 1), v12);
            goto LABEL_14;
          }
LABEL_15:
          ++*pnmatch;
          if ( ++v8 >= sk_num(&h->stack) )
            return v7;
        }
        v10 = X509_subject_name_cmp(*((const x509_st **)v9 + 1), (const x509_st *)v12);
LABEL_14:
        if ( v10 )
          return v7;
        goto LABEL_15;
      }
    }
  }
  return v7;
}
