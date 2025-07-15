int read_till_nl()
{
  int v0; // eax
  _iobuf *v2; // [esp+0h] [ebp-10h]
  char string[8]; // [esp+4h] [ebp-Ch] BYREF

  while ( fgets(string, 4, v2) )
  {
    strchr(string, 0xAu);
    if ( v0 )
      return 1;
  }
  return 0;
}
