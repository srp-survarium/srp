void **__cdecl lh_retrieve(lhash_st *lh, const void *data)
{
  lhash_st *v2; // esi
  void **result; // eax
  const void *v4; // [esp-8h] [ebp-Ch]

  v2 = lh;
  v4 = data;
  lh->error = 0;
  result = (void **)*getrn(v2, v4, (unsigned int *)&lh);
  if ( result )
  {
    result = (void **)*result;
    ++v2->num_retrieve;
  }
  else
  {
    ++v2->num_retrieve_miss;
  }
  return result;
}
