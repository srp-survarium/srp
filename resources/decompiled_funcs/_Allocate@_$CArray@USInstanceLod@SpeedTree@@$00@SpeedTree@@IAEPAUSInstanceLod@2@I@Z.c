int __stdcall SpeedTree::CArray<SpeedTree::SInstanceLod,1>::Allocate(int a1)
{
  return SpeedTree::st_new_array<SpeedTree::SInstanceLod>(a1, "CArray");
}
