int __usercall CRYPTO_mem_ctrl@<eax>(unsigned int a1@<edi>, int mode)
{
  int v2; // esi
  crypto_threadid_st id; // [esp+4h] [ebp-8h] BYREF

  v2 = mh_mode;
  CRYPTO_lock(a1, 9, 20, ".\\crypto\\mem_dbg.c", 220);
  switch ( mode )
  {
    case 0:
      mh_mode = 0;
      num_disable = 0;
      break;
    case 1:
      mh_mode = 3;
      num_disable = 0;
      break;
    case 2:
      if ( (mh_mode & 1) != 0 )
      {
        if ( num_disable )
        {
          if ( !--num_disable )
          {
            mh_mode |= 2u;
            CRYPTO_lock(a1, 10, 27, ".\\crypto\\mem_dbg.c", 273);
          }
        }
      }
      break;
    case 3:
      if ( (mh_mode & 1) != 0 )
      {
        CRYPTO_THREADID_current(&id);
        if ( !num_disable || CRYPTO_THREADID_cmp(&disabling_threadid, &id) )
        {
          CRYPTO_lock(a1, 10, 20, ".\\crypto\\mem_dbg.c", 250);
          CRYPTO_lock(a1, 9, 27, ".\\crypto\\mem_dbg.c", 256);
          CRYPTO_lock(a1, 9, 20, ".\\crypto\\mem_dbg.c", 257);
          mh_mode &= ~2u;
          CRYPTO_THREADID_cpy(&disabling_threadid, &id);
        }
        ++num_disable;
      }
      break;
    default:
      break;
  }
  CRYPTO_lock(a1, 10, 20, ".\\crypto\\mem_dbg.c", 282);
  return v2;
}
