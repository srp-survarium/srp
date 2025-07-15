int read_till_nl()
{
  int v1; // eax
  _iobuf *v3; // [esp+0h] [ebp-10h]
  char string[8]; // [esp+4h] [ebp-Ch] BYREF

  while ( fgets(string, 4, v3) )
  {
    strchr(string, 0xAu);
    if ( v1 )
      return 1;
  }
  return 0;
}
