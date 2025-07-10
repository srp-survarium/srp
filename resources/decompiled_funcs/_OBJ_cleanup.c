void OBJ_cleanup()
{
  lhash_st *v0; // [esp-8h] [ebp-8h]

  if ( obj_cleanup_defer )
  {
    obj_cleanup_defer = 2;
  }
  else if ( added )
  {
    v0 = (lhash_st *)added;
    added[8].dummy = 0;
    lh_doall(v0, (void (__cdecl *)(void *))cleanup1_LHASH_DOALL);
    lh_doall((lhash_st *)added, (void (__cdecl *)(void *))cleanup2_LHASH_DOALL);
    lh_doall((lhash_st *)added, (void (__cdecl *)(void *))cleanup3_LHASH_DOALL);
    lh_free((lhash_st *)added);
    added = 0;
  }
}
