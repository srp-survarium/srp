void __usercall BIO_free_all(int a1@<ebx>, bio_st *bio)
{
  bio_st *v2; // esi
  int references; // edi
  bio_st *v4; // eax

  v2 = bio;
  if ( bio )
  {
    do
    {
      references = v2->references;
      v4 = v2;
      v2 = v2->next_bio;
      BIO_free(references, a1, v4);
    }
    while ( references <= 1 && v2 );
  }
}
