bool __usercall Scaleform::GFx::MatchFileNames@<al>(
        const Scaleform::String *path1@<eax>,
        const Scaleform::String *path2@<ecx>)
{
  _DWORD *v2; // edi
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // ecx
  char v6; // bl
  char v7; // dl
  int v8; // edx
  bool v9; // cc
  int v10; // ebx
  int v11; // edx

  v2 = (_DWORD *)(path1->HeapTypeBits & 0xFFFFFFFC);
  v3 = (_DWORD *)(path2->HeapTypeBits & 0xFFFFFFFC);
  v4 = (*v2 & 0x7FFFFFFF) - 1;
  v5 = (*v3 & 0x7FFFFFFF) - 1;
  if ( v4 >= 0 )
  {
    while ( v5 >= 0 )
    {
      v6 = *((_BYTE *)v2 + v4 + 8);
      if ( v6 == 92 || v6 == 47 )
      {
        v7 = *((_BYTE *)v3 + v5 + 8);
        if ( v7 == 92 || v7 == 47 )
          return 1;
      }
      v8 = v6;
      v9 = (unsigned int)(v6 - 65) <= 0x19;
      v10 = v6 + 32;
      if ( !v9 )
        v10 = v8;
      v11 = *((char *)v3 + v5 + 8);
      if ( (unsigned int)(v11 - 65) <= 0x19 )
        v11 += 32;
      if ( v10 != v11 )
        return 0;
      --v4;
      --v5;
      if ( v4 < 0 )
        return v4 == v5;
    }
  }
  return v4 == v5;
}
