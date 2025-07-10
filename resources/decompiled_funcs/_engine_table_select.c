engine_st *__cdecl engine_table_select(lhash_st **table, int nid)
{
  st_engine_table **v2; // edi
  engine_st *v3; // esi
  lhash_st *v5; // eax
  void **v6; // eax
  int v7; // ebp
  engine_st *v8; // eax
  int data[4]; // [esp+8h] [ebp-10h] BYREF

  v2 = (st_engine_table **)table;
  v3 = 0;
  if ( !*table )
    return 0;
  ERR_set_mark();
  CRYPTO_lock((unsigned int)table, 9, 30, ".\\crypto\\engine\\eng_table.c", 258);
  v5 = *table;
  if ( *table )
  {
    data[0] = nid;
    v6 = lh_retrieve(v5, data);
    v2 = (st_engine_table **)v6;
    if ( v6 )
    {
      if ( v6[2] && engine_unlocked_init((engine_st *)v6[2]) || v2[3] )
      {
        v3 = (engine_st *)v2[2];
      }
      else
      {
        v3 = (engine_st *)sk_value((const stack_st *)v2[1], 0);
        v7 = 1;
        if ( v3 )
        {
          while ( v3->funct_ref <= 0 && (table_flags & 1) != 0 || !engine_unlocked_init(v3) )
          {
            v3 = (engine_st *)sk_value((const stack_st *)v2[1], v7++);
            if ( !v3 )
              goto end_2;
          }
          if ( v2[2] != (st_engine_table *)v3 && engine_unlocked_init(v3) )
          {
            v8 = (engine_st *)v2[2];
            if ( v8 )
              engine_unlocked_finish(v8, 0);
            v2[2] = (st_engine_table *)v3;
          }
        }
      }
end_2:
      v2[3] = (st_engine_table *)1;
    }
  }
  CRYPTO_lock((unsigned int)v2, 10, 30, ".\\crypto\\engine\\eng_table.c", 328);
  ERR_pop_to_mark();
  return v3;
}
