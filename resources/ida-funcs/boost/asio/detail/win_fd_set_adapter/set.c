char __userpurge boost::asio::detail::win_fd_set_adapter::set@<al>(
        boost::asio::detail::win_fd_set_adapter *this@<ecx>,
        unsigned int **a2@<eax>,
        unsigned int descriptor)
{
  unsigned int *v4; // eax
  int *v5; // ecx
  unsigned int v6; // edx
  _DWORD *v7; // eax
  unsigned int v8; // eax
  unsigned int *v9; // edi
  int *v10; // ebx
  unsigned int v11; // eax
  _DWORD *v12; // ecx

  v4 = *a2;
  v5 = (int *)*v4;
  v6 = 0;
  if ( *v4 )
  {
    v7 = v4 + 1;
    while ( *v7 != descriptor )
    {
      ++v6;
      ++v7;
      if ( v6 >= **a2 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v8 = (unsigned int)a2[1];
    if ( v5 == (int *)v8 )
    {
      v9 = (unsigned int *)(v8 + (v8 >> 1));
      v10 = (int *)operator new(4 * (_DWORD)v9 + 4);
      *v10 = **a2;
      v11 = 0;
      if ( **a2 )
      {
        v12 = v10 + 1;
        do
          *v12++ = (*a2)[++v11];
        while ( v11 < **a2 );
      }
      operator delete(*a2);
      *a2 = (unsigned int *)v10;
      a2[1] = v9;
    }
    (*a2)[++**a2] = descriptor;
  }
  return 1;
}
