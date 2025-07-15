unsigned int __usercall vostok::render::options::get_num_max_lights_per_particle@<eax>(
        vostok::render::options *this@<ecx>,
        int a2@<eax>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a2 + 224);
  if ( !v2 )
    return 1;
  if ( v2 == 1 )
    return 2;
  else
    return 3;
}
