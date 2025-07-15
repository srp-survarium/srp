void __usercall vostok::animation::mixing::n_ary_tree_event_iterator::select_state(
        vostok::animation::mixing::n_ary_tree_event_iterator *this@<ecx>,
        int a2@<eax>)
{
  int v2; // edx
  __int16 v3; // cx
  __int64 v4; // [esp+8h] [ebp-Ch]

  if ( *(_DWORD *)(a2 + 28) >= *(_DWORD *)(a2 + 8) )
  {
    *(_QWORD *)(a2 + 36) = *(_QWORD *)a2;
    *(_QWORD *)(a2 + 44) = *(_QWORD *)(a2 + 8);
    *(_DWORD *)(a2 + 56) = 1;
    if ( *(_DWORD *)(a2 + 28) == *(_DWORD *)(a2 + 44) )
    {
      *(_DWORD *)(a2 + 56) = 3;
      *(_WORD *)(a2 + 48) |= *(_WORD *)(a2 + 32);
    }
  }
  else
  {
    *(_DWORD *)(a2 + 56) = 2;
    v2 = *(_DWORD *)(a2 + 28);
    v3 = *(_WORD *)(a2 + 32);
    *(_QWORD *)(a2 + 36) = 0xFDFDCDCDFFFFFFFFuLL;
    LODWORD(v4) = v2;
    WORD2(v4) = v3;
    HIWORD(v4) = -256;
    *(_QWORD *)(a2 + 44) = v4;
  }
}
