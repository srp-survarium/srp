int __cdecl EC_GROUP_get_basis_type(const ssl_st *group)
{
  int v1; // esi
  const ssl_st *v2; // eax
  int *p_d1; // eax

  v1 = 0;
  v2 = (const ssl_st *)EVP_CIPHER_CTX_cipher(group);
  if ( EVP_CIPHER_CTX_cipher(v2) != 407 )
    return 0;
  p_d1 = (int *)&group->d1;
  if ( !group->d1 )
    return 0;
  do
  {
    ++p_d1;
    ++v1;
  }
  while ( *p_d1 );
  if ( v1 == 4 )
    return 683;
  if ( v1 == 2 )
    return 682;
  else
    return 0;
}
