void __userpurge survarium::flash_movie::SetViewAlignment(
        survarium::flash_movie *this@<ecx>,
        int a2@<eax>,
        survarium::flash_movie::AlignType align)
{
  (*(void (__thiscall **)(_DWORD, survarium::flash_movie::AlignType))(**(_DWORD **)(a2 + 4) + 60))(
    *(_DWORD *)(a2 + 4),
    align);
}
