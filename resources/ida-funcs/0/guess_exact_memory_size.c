unsigned int __cdecl guess_exact_memory_size(unsigned __int64 value)
{
  unsigned int v1; // ebp
  int v2; // edx
  unsigned __int64 v3; // rax
  unsigned int v4; // edx
  unsigned int v5; // eax
  unsigned __int64 v6; // rt0
  unsigned int v7; // ebx
  bool v8; // cc
  unsigned int result; // eax
  unsigned int v10; // esi
  int i; // [esp+10h] [ebp-10h]

  v1 = 0;
  v2 = 1;
  i = 1;
  if ( value > 1 )
  {
    while ( 1 )
    {
      v3 = 2 * __PAIR64__(v1, v2);
      v1 = HIDWORD(v3);
      i = v3;
      if ( v3 >= value )
        break;
      v2 = v3;
    }
    v2 = v3;
  }
  v4 = __PAIR64__(v1, v2) >> 1;
  LODWORD(v6) = v4;
  HIDWORD(v6) = v1 >> 1;
  v5 = v6 >> 1;
  LODWORD(v6) = v5;
  HIDWORD(v6) = v1 >> 2;
  v7 = v4 + (v6 >> 1);
  v8 = (__PAIR64__(v1 >> 1, v4) + __PAIR64__(v1 >> 3, v6 >> 1)) >> 32 <= HIDWORD(value);
  if ( (__PAIR64__(v1 >> 1, v4) + __PAIR64__(v1 >> 3, v6 >> 1)) >> 32 >= HIDWORD(value)
    && (!v8 || v7 >= (unsigned int)value) )
  {
    return v7;
  }
  v10 = (__PAIR64__(v1 >> 1, v4) + __PAIR64__(v1 >> 2, v5)) >> 32;
  result = v4 + v5;
  if ( __PAIR64__(v10, result) < value )
    return i;
  return result;
}
