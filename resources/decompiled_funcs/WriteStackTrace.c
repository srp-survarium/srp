void __usercall WriteStackTrace(
        unsigned int a1@<ebx>,
        unsigned __int64 (*ranOffsets)[2],
        unsigned int num_call_stack_lines,
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *callback,
        bool invert_order)
{
  const std::exception *v5; // eax
  int v6; // [esp+4h] [ebp-2474h]
  unsigned int v7; // [esp+8h] [ebp-2470h]
  unsigned int v8; // [esp+1Ch] [ebp-245Ch]
  int v9; // [esp+20h] [ebp-2458h]
  boost::bad_function_call v10; // [esp+44h] [ebp-2434h] BYREF
  unsigned int address_out; // [esp+154h] [ebp-2324h] BYREF
  int line; // [esp+158h] [ebp-2320h] BYREF
  unsigned int j; // [esp+15Ch] [ebp-231Ch]
  char szSourceInfo[2]; // [esp+160h] [ebp-2318h] BYREF
  unsigned __int8 v15[518]; // [esp+162h] [ebp-2316h] BYREF
  int v16; // [esp+368h] [ebp-2110h]
  unsigned int i; // [esp+36Ch] [ebp-210Ch]
  char szModuleInfo[2]; // [esp+370h] [ebp-2108h] BYREF
  unsigned __int8 dst[254]; // [esp+372h] [ebp-2106h] BYREF
  unsigned int v20; // [esp+470h] [ebp-2008h]
  int v21; // [esp+474h] [ebp-2004h]
  char szSymbol[2]; // [esp+478h] [ebp-2000h] BYREF
  unsigned __int8 v23[8190]; // [esp+47Ah] [ebp-1FFEh] BYREF

  strcpy(szModuleInfo, "?");
  memset((int)dst, 0, sizeof(dst));
  strcpy(szSourceInfo, "?");
  memset((int)v15, 0, sizeof(v15));
  strcpy(szSymbol, "?");
  memset((int)v23, 0, sizeof(v23));
  for ( i = 0; i < 0x200 && (*ranOffsets)[2 * i] && (*ranOffsets)[2 * i + 1]; ++i )
    ;
  if ( invert_order )
    v7 = i - 1;
  else
    v7 = 0;
  v20 = v7;
  v21 = invert_order ? -1 : 1;
  if ( invert_order )
    v6 = -1;
  else
    v6 = i;
  v16 = v6;
  for ( j = v20; j != v16; j += v21 )
  {
    GetSourceInfoFromAddress(a1, (*ranOffsets)[2 * j], szModuleInfo, 0x100u, szSourceInfo, 0x208u, &line, &address_out);
    GetFunctionInfoFromAddresses(a1, (*ranOffsets)[2 * j], (*ranOffsets)[2 * j + 1], szSymbol, 0x2000u);
    v8 = address_out;
    v9 = line;
    if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!(callback) )
    {
      boost::bad_function_call::bad_function_call(&v10);
      boost::throw_exception(v5);
      boost::bad_function_call::~bad_function_call(&v10);
    }
    if ( !(*(unsigned __int8 (__cdecl **)(vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *, unsigned int, unsigned int, char *, char *, int, char *, unsigned int))(((int)callback->m_object & 0xFFFFFFFE) + 4))(
            callback + 2,
            j,
            num_call_stack_lines,
            szModuleInfo,
            szSourceInfo,
            v9,
            szSymbol,
            v8) )
      break;
  }
}
