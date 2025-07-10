int __usercall build_bl_tree@<eax>(internal_state *s@<eax>)
{
  int result; // eax

  scan_tree((ct_data_s *)&s[37], s[711].dummy, s);
  scan_tree((ct_data_s *)&s[610], s[714].dummy, s);
  build_tree(s, (tree_desc_s *)&s[716]);
  result = 18;
  while ( !HIWORD(s[bl_order[result] + 671].dummy) )
  {
    if ( HIWORD(s[*((unsigned __int8 *)&extra_lbits[28] + result + 3) + 671].dummy) )
    {
      --result;
      s[1450].dummy += 3 * result + 17;
      return result;
    }
    if ( HIWORD(s[*((unsigned __int8 *)&extra_lbits[28] + result + 2) + 671].dummy) )
    {
      result -= 2;
      s[1450].dummy += 3 * result + 17;
      return result;
    }
    if ( HIWORD(s[*((unsigned __int8 *)&extra_lbits[28] + result + 1) + 671].dummy) )
    {
      result -= 3;
      break;
    }
    result -= 4;
    if ( result < 3 )
    {
      s[1450].dummy += 3 * result + 17;
      return result;
    }
  }
  s[1450].dummy += 3 * result + 17;
  return result;
}
