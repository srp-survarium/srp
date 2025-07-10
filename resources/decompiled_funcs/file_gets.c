unsigned int __cdecl file_gets(bio_st *bp, char *buf, int size)
{
  *buf = 0;
  if ( fgets(buf, size, (_iobuf *)bp->ptr) && *buf )
    return strlen(buf);
  else
    return 0;
}
