void __userpurge survarium::flash_movie::Advance(
        survarium::flash_movie *this@<ecx>,
        int a2@<eax>,
        float delta_time,
        unsigned int frameCatchUpCount)
{
  (*(void (__stdcall **)(_DWORD, _DWORD, int))(**(_DWORD **)(a2 + 4) + 92))(LODWORD(delta_time), 0, 1);
}
