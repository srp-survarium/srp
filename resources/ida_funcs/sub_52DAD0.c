int __cdecl sub_52DAD0(int *a1, int *a2)
{
  int result; // eax

  *a1 = *a2;
  result = *a1;
  a1[1] = *a1 + 4 * a2[2];
  return result;
}
