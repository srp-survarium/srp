engine_st *__usercall engine_table_select@<eax>(int a1@<ebx>, lhash_st **table, int nid)
{
  lhash_st **v3; // edi
  engine_st *v4; // esi
  lhash_st *v6; // eax
  void ***v7; // eax
  int v8; // ebp
  engine_st *v9; // eax
  int v10[4]; // [esp+8h] [ebp-10h] BYREF

  v3 = table;
  v4 = 0;
  if ( !*table )
    return 0;
  ERR_set_mark();
  CRYPTO_lock((int)table, a1, 9, 30, ".\\crypto\\engine\\eng_table.c", 258);
  v6 = *table;
  if ( *table )
  {
    v10[0] = nid;
    v7 = lh_retrieve(v6, v10);
    v3 = (lhash_st **)v7;
    if ( v7 )
    {
      if ( v7[2] && engine_unlocked_init((engine_st *)v7[2]) || v3[3] )
      {
        v4 = (engine_st *)v3[2];
      }
      else
      {
        v4 = (engine_st *)sk_value((const stack_st *)v3[1], 0);
        v8 = 1;
        if ( v4 )
        {
          while ( v4->funct_ref <= 0 && (table_flags & 1) != 0 || !engine_unlocked_init(v4) )
          {
            v4 = (engine_st *)sk_value((const stack_st *)v3[1], v8++);
            if ( !v4 )
              goto end_2;
          }
          if ( v3[2] != (lhash_st *)v4 && engine_unlocked_init(v4) )
          {
            v9 = (engine_st *)v3[2];
            if ( v9 )
              engine_unlocked_finish(v9, 0);
            v3[2] = (lhash_st *)v4;
          }
        }
      }
end_2:
      v3[3] = (lhash_st *)1;
    }
  }
  CRYPTO_lock((int)v3, a1, 10, 30, ".\\crypto\\engine\\eng_table.c", 328);
  ERR_pop_to_mark(a1);
  return v4;
}
