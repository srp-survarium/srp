void __usercall vostok::ai::planning::base_lexeme_ptr::~base_lexeme_ptr(
        vostok::ai::planning::base_lexeme_ptr *this@<ecx>,
        int *a2@<eax>)
{
  int v2; // ecx

  v2 = *a2;
  if ( *a2 && *(_BYTE *)(v2 + 22) && !--*(_WORD *)(v2 + 20) )
    (**(void (__thiscall ***)(int, _DWORD))v2)(v2, 0);
}
