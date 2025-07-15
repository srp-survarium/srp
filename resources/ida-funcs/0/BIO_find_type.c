bio_st *__cdecl BIO_find_type(bio_st *bio, int type)
{
  bio_st *result; // eax
  int v3; // ecx

  for ( result = bio; result; result = result->next_bio )
  {
    if ( result->method )
    {
      v3 = result->method->type;
      if ( (_BYTE)type )
      {
        if ( v3 == type )
          return result;
      }
      else if ( (v3 & type) != 0 )
      {
        return result;
      }
    }
  }
  return result;
}
