unsigned int __cdecl lh_num_items(const lhash_st *lh)
{
  if ( lh )
    return lh->num_items;
  else
    return 0;
}
