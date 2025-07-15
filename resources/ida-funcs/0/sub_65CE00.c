int __cdecl sub_65CE00(_DWORD *a1, int a2)
{
  switch ( a2 )
  {
    case 15:
      return 11;
    case 18:
      *a1 = sub_65CEB0;
      return 9;
    case 22:
      *a1 = sub_65CE60;
      return 11;
    default:
      return sub_65E280(a1, a2);
  }
}
