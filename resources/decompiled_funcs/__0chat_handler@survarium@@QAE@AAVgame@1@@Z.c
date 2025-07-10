void __userpurge survarium::chat_handler::chat_handler(
        survarium::chat_handler *this@<ecx>,
        int a2@<edi>,
        survarium::game *game)
{
  Scaleform::MemoryHeap *v3; // ecx
  _DWORD *v4; // ebp
  _DWORD *v5; // eax
  survarium::flash_external_handler *v6; // ecx

  v3 = Scaleform::Memory::pGlobalHeap;
  v4 = (_DWORD *)(a2 + 4);
  *(_DWORD *)(a2 + 4) = &survarium::flash_function_handler::`vftable';
  v5 = v3->Alloc(v3, 12u, 0);
  if ( v5 )
  {
    *v5 = &Scaleform::RefCountImplCore::`vftable';
    v5[1] = 1;
    *v5 = &survarium::flash_function_handler_impl::`vftable';
    v5[2] = v4;
  }
  else
  {
    v5 = 0;
  }
  *(_DWORD *)(a2 + 8) = v5;
  survarium::flash_external_handler::flash_external_handler(v6, (_DWORD *)(a2 + 12));
  *(_DWORD *)(a2 + 12) = &survarium::chat_handler::`vftable'{for `survarium::flash_external_handler'};
  *v4 = &survarium::chat_handler::`vftable'{for `survarium::flash_function_handler'};
  *(_BYTE *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 21) = 0;
  *(_BYTE *)(a2 + 22) = 0;
  *(_DWORD *)(a2 + 24) = game;
  *(_DWORD *)a2 = &survarium::chat_handler::`vftable'{for `vostok::input::handler'};
  *(_DWORD *)(a2 + 28) = 0;
}
