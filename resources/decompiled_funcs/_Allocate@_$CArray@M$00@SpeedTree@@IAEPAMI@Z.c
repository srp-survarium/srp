int __stdcall SpeedTree::CArray<float,1>::Allocate(int a1)
{
  return SpeedTree::st_new_array<int>(a1, "CArray");
}
