void __usercall vostok::render::material_effects::~material_effects(
        vostok::render::material_effects *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::unmanaged_resource **v2; // esi
  int i; // ebx
  int v4; // eax

  v2 = (vostok::resources::unmanaged_resource **)(a2 + 912);
  for ( i = 28; i >= 0; --i )
  {
    v4 = (int)*--v2;
    if ( v4 )
    {
      this = (vostok::render::material_effects *)_InterlockedExchangeAdd(
                                                   (volatile signed __int32 *)(v4 + 208),
                                                   0xFFFFFFFF);
      if ( !this )
        vostok::resources::unmanaged_intrusive_base::destroy(&(*v2)->vostok::resources::unmanaged_intrusive_base, *v2);
    }
  }
  vostok::render::post_process_parameters::~post_process_parameters(&this->m_post_process_stage_parameters);
}
