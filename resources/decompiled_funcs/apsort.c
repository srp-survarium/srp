int __cdecl apsort(float **a, float **b)
{
  double v2; // st7
  double v3; // st6

  v2 = **a;
  v3 = **b;
  if ( v3 >= v2 )
    return v3 > v2;
  else
    return (v3 > v2) - 1;
}
