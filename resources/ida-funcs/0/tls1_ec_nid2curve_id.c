int __cdecl tls1_ec_nid2curve_id(int nid)
{
  int result; // eax

  if ( nid > 708 )
  {
    switch ( nid )
    {
      case 709:
        result = 16;
        break;
      case 710:
        result = 17;
        break;
      case 711:
        result = 18;
        break;
      case 712:
        result = 20;
        break;
      case 713:
        result = 21;
        break;
      case 714:
        result = 22;
        break;
      case 715:
        result = 24;
        break;
      case 716:
        result = 25;
        break;
      case 721:
        result = 1;
        break;
      case 722:
        result = 2;
        break;
      case 723:
        result = 3;
        break;
      case 724:
        result = 4;
        break;
      case 725:
        result = 5;
        break;
      case 726:
        result = 6;
        break;
      case 727:
        result = 7;
        break;
      case 728:
        result = 8;
        break;
      case 729:
        result = 9;
        break;
      case 730:
        result = 10;
        break;
      case 731:
        result = 11;
        break;
      case 732:
        result = 12;
        break;
      case 733:
        result = 13;
        break;
      case 734:
        result = 14;
        break;
      default:
        return 0;
    }
  }
  else
  {
    switch ( nid )
    {
      case 708:
        return 15;
      case 409:
        return 19;
      case 415:
        return 23;
      default:
        return 0;
    }
  }
  return result;
}
