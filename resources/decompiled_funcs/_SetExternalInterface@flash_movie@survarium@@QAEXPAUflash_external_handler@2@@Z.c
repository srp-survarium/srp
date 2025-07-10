void __userpurge survarium::flash_movie::SetExternalInterface(
        survarium::flash_movie *this@<ecx>,
        int a2@<eax>,
        survarium::flash_external_handler *handler)
{
  (*(void (__thiscall **)(int, int, survarium::flash_external_handler_impl *))(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 8) + 8))(
    *(_DWORD *)(a2 + 4) + 8,
    6,
    handler->impl);
}
