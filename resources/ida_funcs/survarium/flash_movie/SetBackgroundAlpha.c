void __userpurge survarium::flash_movie::SetBackgroundAlpha(
        survarium::flash_movie *this@<ecx>,
        int a2@<eax>,
        float value)
{
  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(a2 + 4) + 128))(LODWORD(value));
}
