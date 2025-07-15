double __usercall vostok::collision::terrain_data::quad_size@<st0>(
        vostok::collision::terrain_data *this@<ecx>,
        int a2@<eax>)
{
  return *(float *)a2 / (double)(unsigned int)(*(_DWORD *)(a2 + 4) - 1);
}
