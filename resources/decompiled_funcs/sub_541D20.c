int __cdecl sub_541D20(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int result; // eax

  switch ( a2 )
  {
    case -4:
      if ( a1[3] )
        goto LABEL_9;
      result = 0;
      break;
    case 15:
      result = 0;
      break;
    case 26:
      goto LABEL_9;
    case 33:
      *a1 = sub_542D60;
      result = 0;
      break;
    case 34:
      if ( a1[3] )
      {
        --a1[3];
        result = 0;
      }
      else
      {
LABEL_9:
        result = sub_542EE0(a1, a2);
      }
      break;
    default:
      result = sub_541870(a1, a2, a3, a4, a5);
      break;
  }
  return result;
}
