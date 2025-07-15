void __userpurge survarium::chat_handler::chat_handler(
        survarium::chat_handler *this@<ecx>,
        int a2@<edi>,
        survarium::game *game)
{
  survarium::flash_function_handler::flash_function_handler(
    (survarium::flash_function_handler *)this,
    (_DWORD *)(a2 + 4));
  *(_DWORD *)(a2 + 4) = &survarium::chat_handler::`vftable'{for `survarium::flash_function_handler'};
  *(_BYTE *)(a2 + 12) = 0;
  *(_BYTE *)(a2 + 13) = 0;
  *(_BYTE *)(a2 + 14) = 0;
  *(_DWORD *)a2 = &survarium::chat_handler::`vftable'{for `vostok::input::handler'};
  *(_DWORD *)(a2 + 16) = game;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 4;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
}
