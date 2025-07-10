void __usercall bio_destroy_pair(bio_st *bio@<edi>)
{
  int *ptr; // eax
  int v2; // edx
  _DWORD *v3; // ecx

  ptr = (int *)bio->ptr;
  if ( ptr )
  {
    v2 = *ptr;
    if ( *ptr )
    {
      v3 = *(_DWORD **)(v2 + 32);
      *v3 = 0;
      *(_DWORD *)(v2 + 12) = 0;
      v3[2] = 0;
      v3[3] = 0;
      *ptr = 0;
      bio->init = 0;
      ptr[2] = 0;
      ptr[3] = 0;
    }
  }
}
