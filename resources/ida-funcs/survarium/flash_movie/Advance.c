void __userpurge survarium::flash_movie::Advance(
        survarium::flash_movie *this@<ecx>,
        int a2@<eax>,
        const float delta_time,
        unsigned int frameCatchUpCount)
{
  (*(void (__stdcall **)(_DWORD, unsigned int, int))(**(_DWORD **)(a2 + 4) + 92))(
    LODWORD(delta_time),
    frameCatchUpCount,
    1);
}
