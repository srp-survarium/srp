void __cdecl BIO_free_all(bio_st *bio)
{
  bio_st *v1; // esi
  signed int references; // edi
  bio_st *v3; // eax

  v1 = bio;
  if ( bio )
  {
    do
    {
      references = v1->references;
      v3 = v1;
      v1 = v1->next_bio;
      BIO_free(references, v3);
    }
    while ( references <= 1 && v1 );
  }
}
