const char *__cdecl sub_5091D0(int a1)
{
  const char *v3; // [esp+0h] [ebp-4h]

  v3 = "no error";
  while ( a1 > 0 )
  {
    while ( *v3++ )
      ;
    if ( !*v3 )
      return "Error text not found (please report)";
    --a1;
  }
  return v3;
}
