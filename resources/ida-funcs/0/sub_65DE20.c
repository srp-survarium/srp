int __cdecl sub_65DE20(_DWORD *a1, int a2)
{
  switch ( a2 )
  {
    case 15:
      return 39;
    case 21:
      *a1 = sub_65DDD0;
      return 39;
    case 36:
      *a1 = sub_65E210;
      a1[2] = 39;
      return 46;
    default:
      return sub_65E280(a1, a2);
  }
}
