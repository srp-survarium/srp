int __fastcall post_Y(int pos, int *B, int *A)
{
  int result; // eax
  int v4; // ecx

  result = A[pos];
  if ( result < 0 )
    return B[pos];
  v4 = B[pos];
  if ( v4 >= 0 )
    return (v4 + result) >> 1;
  return result;
}
