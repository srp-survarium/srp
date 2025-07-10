void __usercall vostok::render::volume_fog_parameters::volume_fog_parameters(
        vostok::render::volume_fog_parameters *this@<eax>,
        const vostok::render::volume_fog_parameters *__that@<edx>)
{
  qmemcpy(this, __that, sizeof(vostok::render::volume_fog_parameters));
}
