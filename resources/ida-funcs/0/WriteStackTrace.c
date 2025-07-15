void __cdecl WriteStackTrace(
        unsigned __int64 (*ranOffsets)[2],
        unsigned int num_call_stack_lines,
        boost::function<bool __cdecl(unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int)> *callback,
        bool invert_order)
{
  unsigned __int64 *v4; // eax
  unsigned int i; // esi
  int v6; // eax
  int v7; // edi
  unsigned int v8; // ebx
  int v9; // edi
  unsigned __int64 *v10; // esi
  boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int> *v11; // ecx
  unsigned __int64 v12; // [esp-1Ch] [ebp-2344h]
  char a5[2]; // [esp+10h] [ebp-2318h] BYREF
  unsigned __int8 v14[8190]; // [esp+12h] [ebp-2316h] BYREF
  char a3[2]; // [esp+2010h] [ebp-318h] BYREF
  unsigned __int8 v16[518]; // [esp+2012h] [ebp-316h] BYREF
  char a2[2]; // [esp+2218h] [ebp-110h] BYREF
  unsigned __int8 dst[254]; // [esp+221Ah] [ebp-10Eh] BYREF
  unsigned int a6; // [esp+231Ch] [ebp-Ch] BYREF
  int a4; // [esp+2320h] [ebp-8h] BYREF
  int v21; // [esp+2324h] [ebp-4h]
  int v22; // [esp+233Ch] [ebp+14h]

  strcpy(a2, "?");
  memset((int)dst, 0, sizeof(dst));
  strcpy(a3, "?");
  memset((int)v16, 0, sizeof(v16));
  strcpy(a5, "?");
  memset((int)v14, 0, sizeof(v14));
  v4 = (unsigned __int64 *)ranOffsets;
  for ( i = 0; i < 0x200; ++i )
  {
    if ( !*v4 )
      break;
    if ( !v4[1] )
      break;
    v4 += 2;
  }
  v6 = invert_order ? i - 1 : 0;
  v7 = 2 * !invert_order - 1;
  v21 = v7;
  if ( invert_order )
    v22 = -1;
  else
    v22 = i;
  v8 = v6;
  if ( v6 != v22 )
  {
    v9 = 16 * v7;
    v10 = &(*ranOffsets)[2 * v6];
    do
    {
      GetSourceInfoFromAddress(*v10, a2, a3, (char *)&a4, &a6);
      LODWORD(v12) = a5;
      GetFunctionInfoFromAddresses(*v10, v12);
      if ( !(unsigned __int8)boost::function7<bool,unsigned int,unsigned int,char const *,char const *,int,char const *,unsigned int>::operator()(
                               v11,
                               callback,
                               v8,
                               num_call_stack_lines,
                               a2,
                               a3,
                               a4,
                               a5,
                               a6) )
        break;
      v8 += v21;
      v10 = (unsigned __int64 *)((char *)v10 + v9);
    }
    while ( v8 != v22 );
  }
}
