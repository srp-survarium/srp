void __usercall vostok::animation::bone_name_index::bone_name_index(
        vostok::animation::bone_name_index *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 64) = -1;
  *(_DWORD *)(a2 + 68) = -1;
}
