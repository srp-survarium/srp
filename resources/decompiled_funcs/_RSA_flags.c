const rsa_st *__cdecl RSA_flags(const rsa_st *r)
{
  const rsa_st *result; // eax

  result = r;
  if ( r )
    return (const rsa_st *)r->meth->flags;
  return result;
}
