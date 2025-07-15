int __usercall vostok::collision::terrain_data::quad_dimension@<eax>(
        vostok::collision::terrain_data *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 4) - 1;
}
