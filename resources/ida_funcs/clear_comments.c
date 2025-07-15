void __usercall clear_comments(conf_st *conf@<edi>, char *p)
{
  char *v2; // eax
  _WORD *meth_data; // esi
  int v4; // edx
  __int16 v5; // cx

  v2 = p;
  meth_data = conf->meth_data;
  if ( (meth_data[(unsigned __int8)*p] & 0x800) == 0 )
  {
    while ( (meth_data[(unsigned __int8)*v2] & 0x10) != 0 )
    {
      v4 = (unsigned __int8)*++v2;
      if ( (meth_data[v4] & 0x800) != 0 )
      {
        *v2 = 0;
        return;
      }
    }
    while ( SLOBYTE(meth_data[(unsigned __int8)*v2]) >= 0 )
    {
      v5 = meth_data[(unsigned __int8)*v2];
      if ( (v5 & 0x400) != 0 )
      {
        v2 = scan_dquote(conf, v2);
      }
      else if ( (v5 & 0x40) != 0 )
      {
        v2 = scan_quote(conf, v2);
      }
      else
      {
        if ( (v5 & 0x20) == 0 )
        {
          if ( (v5 & 8) != 0 )
            return;
LABEL_14:
          ++v2;
          continue;
        }
        if ( (meth_data[(unsigned __int8)v2[1]] & 8) != 0 )
          goto LABEL_14;
        v2 += 2;
      }
    }
  }
  *v2 = 0;
}
