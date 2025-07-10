int __cdecl sub_542A90(_DWORD *a1, int a2)
{
  switch ( a2 )
  {
    case 15:
      return 39;
    case 21:
      *a1 = sub_542A40;
      return 39;
    case 36:
      *a1 = sub_542E80;
      a1[2] = 39;
      return 46;
    default:
      return sub_542EE0(a1, a2);
  }
}
