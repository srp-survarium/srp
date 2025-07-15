void __userpurge survarium::chat_handler::tick(survarium::chat_handler *this@<ecx>, int a2@<eax>, unsigned int delta)
{
  float v3; // [esp+0h] [ebp-Ch]

  v3 = (double)delta * 0.001;
  (*(void (__stdcall **)(_DWORD, _DWORD, int))(**(_DWORD **)(*(_DWORD *)(*(_DWORD *)(a2 + 28) + 264) + 4) + 92))(
    LODWORD(v3),
    0,
    1);
}
