int __cdecl sub_65CBA0(_DWORD *a1, int a2)
{
  switch ( a2 )
  {
    case 15:
      return 3;
    case 17:
      *a1 = sub_65CA70;
      return 8;
    case 25:
      *a1 = sub_65CC00;
      return 7;
    default:
      return sub_65E280(a1, a2);
  }
}
