int __fastcall post_Y(int pos, int *B, int *A)
{
  int v3; // ecx
  int result; // eax
  int v5; // ecx

  v3 = pos;
  result = A[v3];
  if ( result < 0 )
    return B[v3];
  v5 = B[v3];
  if ( v5 >= 0 )
    return (v5 + result) >> 1;
  return result;
}
