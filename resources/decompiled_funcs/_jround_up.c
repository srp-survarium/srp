int __cdecl jround_up(int a1, int a2)
{
  return a1 + a2 - 1 - (a1 + a2 - 1) % a2;
}
