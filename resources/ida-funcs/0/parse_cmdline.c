void __usercall parse_cmdline(char *cmdstart@<edx>, int *numchars@<edi>, char **argv, char *args, int *numargs)
{
  int *v5; // ecx
  char *v7; // edx
  char **v8; // ebx
  char v9; // bl
  char *v10; // ecx
  char **v11; // eax
  int v12; // ebx
  unsigned int v13; // ecx
  unsigned __int8 v14; // al
  char *v15; // ecx
  char *v16; // ecx
  unsigned __int8 v17; // [esp-4h] [ebp-10h]
  BOOL v18; // [esp+8h] [ebp-4h]
  BOOL v19; // [esp+8h] [ebp-4h]

  v5 = numargs;
  *numchars = 0;
  v7 = args;
  *numargs = 1;
  if ( argv )
  {
    v8 = argv++;
    *v8 = args;
  }
  v18 = 0;
  do
  {
    if ( *cmdstart == 34 )
    {
      v9 = 34;
      ++cmdstart;
      v18 = !v18;
    }
    else
    {
      ++*numchars;
      if ( v7 )
      {
        *v7 = *cmdstart;
        args = v7 + 1;
      }
      v9 = *cmdstart;
      v17 = *cmdstart++;
      if ( _ismbblead(v17) )
      {
        ++*numchars;
        if ( args )
        {
          v10 = args++;
          *v10 = *cmdstart;
        }
        ++cmdstart;
      }
      v7 = args;
      v5 = numargs;
      if ( !v9 )
      {
        --cmdstart;
        goto LABEL_18;
      }
    }
  }
  while ( v18 || v9 != 32 && v9 != 9 );
  if ( v7 )
    *(v7 - 1) = 0;
LABEL_18:
  v19 = 0;
  while ( *cmdstart )
  {
    while ( *cmdstart == 32 || *cmdstart == 9 )
      ++cmdstart;
    if ( !*cmdstart )
      break;
    if ( argv )
    {
      v11 = argv++;
      *v11 = v7;
    }
    ++*v5;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *cmdstart == 92 )
      {
        ++cmdstart;
        ++v13;
      }
      if ( *cmdstart == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( v19 && cmdstart[1] == 34 )
          {
            ++cmdstart;
          }
          else
          {
            v12 = 0;
            v19 = !v19;
          }
        }
        v13 >>= 1;
      }
      if ( v13 )
      {
        do
        {
          --v13;
          if ( v7 )
            *v7++ = 92;
          ++*numchars;
        }
        while ( v13 );
        args = v7;
      }
      v14 = *cmdstart;
      if ( !*cmdstart || !v19 && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 )
      {
        if ( v7 )
        {
          if ( _ismbblead(v14) )
          {
            v15 = args++;
            *v15 = *cmdstart++;
            ++*numchars;
          }
          v16 = args++;
          *v16 = *cmdstart;
        }
        else if ( _ismbblead(v14) )
        {
          ++cmdstart;
          ++*numchars;
        }
        ++*numchars;
        v7 = args;
      }
      ++cmdstart;
    }
    if ( v7 )
    {
      *v7++ = 0;
      args = v7;
    }
    ++*numchars;
    v5 = numargs;
  }
  if ( argv )
    *argv = 0;
  ++*v5;
}
