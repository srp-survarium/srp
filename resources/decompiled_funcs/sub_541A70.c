int __cdecl sub_541A70(_DWORD *a1, int a2)
{
  switch ( a2 )
  {
    case 15:
      return 11;
    case 18:
      *a1 = sub_541B20;
      return 9;
    case 22:
      *a1 = sub_541AD0;
      return 11;
    default:
      return sub_542EE0(a1, a2);
  }
}
